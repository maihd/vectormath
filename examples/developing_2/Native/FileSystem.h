#pragma once

#include <stdint.h>

#ifndef __cplusplus
#include <stdbool.h>
#endif

typedef enum FileMode
{
    FileMode_None,
    FileMode_Read       = 1 << 0,
    FileMode_Write      = 1 << 1,
    FileMode_Append     = 1 << 2,
    FileMode_Binary     = 1 << 3,

    FileMode_ReadBinary         = FileMode_Read | FileMode_Binary,
    FileMode_WriteBinary        = FileMode_Write | FileMode_Binary,

    FileMode_ReadWrite          = FileMode_Read | FileMode_Write,
    FileMode_ReadWriteBinary    = FileMode_Read | FileMode_Write | FileMode_Binary,
} FileMode;

typedef enum SeekBaseOffset
{
    SeekBaseOffset_StartOfFile,
    SeekBaseOffset_CurrentPosition,
    SeekBaseOffset_EndOfFile,
} SeekBaseOffset;

typedef enum MemoryStreamFlags
{
    MemoryStreamFlags_None,
    MemoryStreamFlags_BufferOwner = 1 << 0
} MemoryStreamFlags; 

typedef struct MemoryStream
{
    void*               buffer;
    int32_t             length;
    int32_t             cursor;
    uint32_t            flags;
} MemoryStream;

typedef struct FileStream
{
    struct FileSystem*  system;
    union
    {
        void*           handle;
        MemoryStream    memory;
    };
} FileStream;

typedef struct FileSystem
{
    bool                (*Close)(FileStream* stream);

    int32_t             (*Read)(FileStream* stream, void* outputBuffer, int32_t bufferSizeInBytes);
    int32_t             (*Write)(FileStream* stream, const void* inputBuffer, int32_t bufferSizeInBytes);

    bool                (*Seek)(FileStream* stream, SeekBaseOffset offset, int32_t position);
    int32_t             (*GetSize)(const FileStream* stream);
    int32_t             (*GetCursor)(const FileStream* stream);
    
    bool                (*Flush)(FileStream* stream);
    bool                (*IsAtEnd)(const FileStream* stream);
} FileSystem;

// -------------------------------------------------------------
// FilePath functions
// -------------------------------------------------------------

// -------------------------------------------------------------
// FileStream functions
// -------------------------------------------------------------

bool FileStream_OpenFromPath(const char* path, FileMode mode, FileStream* outStream);
bool FileStream_OpenFromMemory(void* buffer, int32_t bufferSizeInBytes, FileStream* outStream);

inline bool FileStream_Close(FileStream* stream)
{
    return stream->system->Close(stream);
}

inline int32_t FileStream_Read(FileStream* stream, void* outputBuffer, int32_t bufferSizeInBytes)
{
    return stream->system->Read(stream, outputBuffer, bufferSizeInBytes);
}

inline int32_t FileStream_Write(FileStream* stream, const void* inputBuffer, int32_t bufferSizeInBytes)
{
    return stream->system->Write(stream, inputBuffer, bufferSizeInBytes);
}

inline bool FileStream_Seek(FileStream* stream, SeekBaseOffset offset, int32_t position)
{
    return stream->system->Seek(stream, offset, position);
}

inline int32_t FileStream_GetSize(const FileStream* stream)
{
    return stream->system->GetSize(stream);
}

inline int32_t FileStream_GetCursor(const FileStream* stream)
{
    return stream->system->GetCursor(stream);
}

inline bool FileStream_Flush(FileStream* stream)
{
    return stream->system->Flush(stream);
}

inline bool FileStream_IsAtEnd(const FileStream* stream)
{
    return stream->system->IsAtEnd(stream);
}
