#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>

#include "ulamspiral.h"

#define WIDTH 600

int main(int argc, char *argv[])
{
    SDL_Window *window;
    SDL_Renderer *renderer;

    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow(
        "Ulam spiral",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WIDTH, WIDTH, SDL_WINDOW_OPENGL);
    if (window == NULL)
    {
        fprintf(stderr, "Failed to create window : %s\n",
            SDL_GetError());
        goto fail_create_window;
    }

    renderer = SDL_CreateRenderer(window, -1,
        SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        fprintf(stderr, "Failed to create renderer : %s\n",
            SDL_GetError());
        goto fail_create_renderer;
    }

    UlamSpiral *ulamSpiral = createUlamSpiral(WIDTH);
    if (ulamSpiral == NULL)
    {
        fprintf(stderr, "Failed to create ulam spiral\n");
        goto fail_create_ulamspiral;
    }

    // Clears the screen
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    drawUlamSpiral(ulamSpiral, renderer);

    SDL_RenderPresent(renderer);

    bool running = true;
    while (running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    running = false;
                break;

                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                        running = false;
                break;
            }
        }

        SDL_Delay(100);     // Add delay to reduce CPU usage
    }

    freeUlamSpiral(ulamSpiral);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;

fail_create_ulamspiral:
    SDL_DestroyRenderer(renderer);
fail_create_renderer:
    SDL_DestroyWindow(window);
fail_create_window:
    SDL_Quit();

    return 1;
}
