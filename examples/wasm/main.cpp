#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#include <GLES2/gl2.h>
#include <emscripten.h>

static void main_loop();

SDL_Window*     window;
SDL_Renderer*   renderer;
SDL_GLContext   context;

int main(int argc, const char* argv[])
{
    SDL_CreateWindowAndRenderer(1280, 720, SDL_WINDOW_OPENGL, &window, &renderer);
    // SDL_Init(SDL_INIT_VIDEO);

    // SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
    // SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    // SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

    // window = SDL_CreateWindow("Window", SDL_WINDOWPOS_UNDEFINED,
    //     SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_OPENGL);

    context = SDL_GL_CreateContext(window);
    if (context == nullptr)
    {
        printf("Context is null :(\n");
        printf("%s\n", SDL_GetError());

        return -1;
    }

    emscripten_set_main_loop(main_loop, 60, 1);
    return 0;
}

void main_loop()
{
    static float t = 0.0f;

    t += 0.01f;

    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            SDL_GL_DeleteContext(context);
            SDL_DestroyWindow(window);
            SDL_Quit();

            context = nullptr;
            window = nullptr;
            break;
        }

        SDL_GL_MakeCurrent(window, context);
        
        glClearColor(t, t, t, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        
        SDL_GL_SwapWindow(window);
    }
}

//! LEAVE AN EMPTY LINE HERE, REQUIRE BY GCC/G++
