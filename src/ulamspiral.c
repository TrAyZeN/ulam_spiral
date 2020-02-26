#include <stdlib.h>
#include <SDL2/SDL.h>

#include "ulamspiral.h"
#include "utils.h"

UlamSpiral *createUlamSpiral(uint length)
{
    uint i;
    uchr *array;
    static UlamSpiral us;

    array = (uchr *) malloc(length * length * sizeof(uchr));
    for (i = 0; i < length*length; i++)
        array[i] = isPrime(i + 1);

    us = (UlamSpiral) { length, array };
    return &us;
}

void drawUlamSpiral(UlamSpiral *us, SDL_Renderer *renderer)
{
    uint i, j, x, y, ox, oy, e, size;
    x = 0;
    y = 0;
    ox = us->length / 2;
    oy = us->length / 2;
    e = 1;
    size = us->length * us->length;

    for (i = 0; i < size; i += (2 * e))
    {
        for (j = 0; j < e; j++)
        {
            if (e%2 == 0)
                x--;
            else
                x++;
            if (us->array[i + j])
                SDL_RenderDrawPoint(renderer, ox + x, oy + y);
        }
        for (j = 0; j < e; j++)
        {
            if (e%2 == 0)
                y++;
            else
                y--;
            if (us->array[i + j + e])
                SDL_RenderDrawPoint(renderer, ox + x, oy + y);
        }

        e++;
    }
}

