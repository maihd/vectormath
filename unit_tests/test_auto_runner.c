#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <Windows.h>
#else
#error Auto test runner work on Windows
#endif

static void RunTests(const char* directory, const char* watchDirectory, const char* compiler);

int main(const int argc, const char* const argv[])
{
	const char* compiler = "gcc";
	if (argc > 1)
	{
		compiler = argv[1];
	}

	const char* buildDirectory = "";

	const char* watchFiles[] = {};//{ "../vectormath.h", "../vectormath.inl" };
	enum { watchFilesCount = sizeof(watchFiles) / sizeof(watchFiles[0]) };

	const char* watchDirectories[] = { "cases" };
	enum { watchDirectoriesCount = sizeof(watchDirectories) / sizeof(watchDirectories[0]) };

	HANDLE dwChangeHandles[watchFilesCount + watchDirectoriesCount];
	enum { dwChangeHandlesCount = sizeof(dwChangeHandles) / sizeof(dwChangeHandles[0]) };

	for (int i = 0; i < dwChangeHandlesCount; i++)
	{
		DWORD filter = FILE_NOTIFY_CHANGE_FILE_NAME;
		if (i >= watchFilesCount)
		{
			filter |= FILE_NOTIFY_CHANGE_DIR_NAME;
			filter |= FILE_NOTIFY_CHANGE_LAST_WRITE;
		}

		// Watch the directory for file creation and deletion. 
		dwChangeHandles[i] = 
			FindFirstChangeNotificationA(
				i < watchFilesCount ? watchFiles[i] : watchDirectories[i - watchFilesCount],
				i >= watchFilesCount,
				filter
			);

		// Make a validation check on our handles.
		if (dwChangeHandles[i] == INVALID_HANDLE_VALUE || dwChangeHandles[i] == NULL)
		{
			printf("ERROR: FindFirstChangeNotificationA function failed.\n");
			return -1;
		}
	}

	//
	const char* watchDirectory 	= 0;
	DWORD nextTimeRunTests 		= 0;
	DWORD prevTimeRunTests 		= 0;
	DWORD timeWaitRunTests 		= 2000;
	DWORD timeWaitFileChanged 	= 1000;

	// Change notification is set. Now wait on both notification 
	// handles and refresh accordingly. 
	while (1)
	{	
		// Run tests if have queued
		if (nextTimeRunTests > prevTimeRunTests && GetTickCount() >= nextTimeRunTests)
		{
			prevTimeRunTests = nextTimeRunTests;
			RunTests(buildDirectory, watchDirectory, compiler);
			continue;
		}

		// Wait to file changed
		const DWORD dwWaitStatus = WaitForMultipleObjects(dwChangeHandlesCount, dwChangeHandles, FALSE, timeWaitFileChanged);
		if (dwWaitStatus >= WAIT_OBJECT_0 && dwWaitStatus < WAIT_OBJECT_0 + dwChangeHandlesCount)
		{
			int index = (int)(dwWaitStatus - WAIT_OBJECT_0);
			int fileIndex = index;
			int directoryIndex = index - watchFilesCount;

			if (nextTimeRunTests <= prevTimeRunTests)
			{
				watchDirectory = directoryIndex >= 0 ? watchDirectories[directoryIndex] : watchFiles[fileIndex];
				nextTimeRunTests = GetTickCount() + timeWaitRunTests;
			}

			// Continue check file changed
			if (FindNextChangeNotification(dwChangeHandles[index]) == FALSE)
			{
				printf("ERROR: FindNextChangeNotification function failed.\n");
				return -1;
			}
		}
		else if (dwWaitStatus == WAIT_TIMEOUT)
		{
			// A timeout occurred, this would happen if some value other 
			// than INFINITE is used in the Wait call and no changes occur.
			// In a single-threaded environment you might not want an
			// INFINITE wait.
			//printf("No changes in the timeout period.\n");
		}
		else
		{
			printf("[%s] ERROR: Unhandled dwWaitStatus.\n", argv[0]);
			return -1;
		}
	}

	for (int i = 0; i < dwChangeHandlesCount; i++)
	{
		CloseHandle(dwChangeHandles[i]);
		dwChangeHandles[i] = 0;
	}

    return 0;
}

void RunTests(const char* buildDirectory, const char* watchDirectory, const char* compiler)
{
	char buildInput[1024] = "";
	if (strcmp(watchDirectory, "../vectormath.h") == 0 || strcmp(watchDirectory, "../vectormath.inl") == 0)
	{
		snprintf(buildInput, sizeof(buildInput), "RUN_ALLS=true");
	}

	char buildCommand[1024];
	snprintf(buildCommand, sizeof(buildCommand), "make CC=%s %s --quiet", compiler, buildInput);

    char command[1024];
	if (strlen(buildDirectory) > 0)
	{
    	snprintf(command, sizeof(command), "cd %s && %s", buildDirectory, buildCommand);
	}
	else
	{
		snprintf(command, sizeof(command), "%s", buildCommand);
	}

	system(command);
}
