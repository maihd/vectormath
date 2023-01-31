#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#include <GLES2/gl2.h>
#include <emscripten.h>

int main(int argc, const char* argv[])
{
    SDL_Window*     window;
    SDL_Renderer*   renderer;
    SDL_GLContext   context;

    int init_result = SDL_CreateWindowAndRenderer(1280, 720, SDL_WINDOW_OPENGL, &window, &renderer);
    if (init_result != 0)
    {
        printf("Cannot init SDL :(\n");
        printf("%s\n", SDL_GetError());
        return 0;
    }

    context = SDL_GL_CreateContext(window);
    if (context == nullptr)
    {
        printf("Context is null :(\n");
        printf("%s\n", SDL_GetError());

        return -1;
    }

    float t = 0.0f;
    bool quit = false;
    while (!quit)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
                break;
            }
        }

        SDL_GL_MakeCurrent(window, context);
        
        glClearColor(t, t, t, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        
        SDL_GL_SwapWindow(window);

        emscripten_sleep(16);
        t += 0.001f;
    }
    
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

//! LEAVE AN EMPTY LINE HERE, REQUIRE BY GCC/G++
