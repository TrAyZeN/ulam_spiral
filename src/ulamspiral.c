#include <stdlib.h>
#include <SDL2/SDL.h>

#include "ulamspiral.h"
#include "utils.h"

uchr *createUlamSpiral(unsigned int width)
{
    unsigned int i;
    static uchr *ulamSpiral;
    ulamSpiral = (uchr *) malloc(width * width * sizeof(uchr));

    for (i = 0; i < width*width; i++)
        ulamSpiral[i] = isPrime(i + 1);

    return ulamSpiral;
}

void drawUlamSpiral(uchr *ulamSpiral, SDL_Renderer *renderer)
{
    int X = WIDTH / 2;
    int Y = WIDTH / 2;
    int x = 0;
    int y = 0;
    int e = 1;

    for (int i = 0; i < (WIDTH * WIDTH); i += (2 * e))
    {
        for (int j = 0; j < e; j++)
        {
            if (e%2 == 0)
                x--;
            else
                x++;
            if (ulamSpiral[i + j] == 1)
                SDL_RenderDrawPoint(renderer, X + x, Y + y);
        }
        for (int j = 0; j < e; j++)
        {
            if (e%2 == 0)
                y++;
            else
                y--;
            if (ulamSpiral[i + j + e] == 1)
                SDL_RenderDrawPoint(renderer, X + x, Y + y);
        }
        e++;
    }
}
