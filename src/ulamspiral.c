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
    int i, j, x, y, ox, oy, e, size;
    x = 0;
    y = 0;
    ox = WIDTH / 2;
    oy = WIDTH / 2;
    e = 1;
    size = WIDTH * WIDTH;

    for (i = 0; i < size; i += (2 * e))
    {
        for (j = 0; j < e; j++)
        {
            if (e%2 == 0)
                x--;
            else
                x++;
            if (ulamSpiral[i + j])
                SDL_RenderDrawPoint(renderer, ox + x, oy + y);
        }
        for (j = 0; j < e; j++)
        {
            if (e%2 == 0)
                y++;
            else
                y--;
            if (ulamSpiral[i + j + e])
                SDL_RenderDrawPoint(renderer, ox + x, oy + y);
        }

        e++;
    }
}
