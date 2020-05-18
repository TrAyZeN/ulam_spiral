#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>

#include "ulamspiral.h"
#include "utils.h"

UlamSpiral *createUlamSpiral(uint length)
{
    uint i;
    static UlamSpiral *us;
    us = (UlamSpiral *) malloc(sizeof(UlamSpiral));
    if (us == NULL)
        return NULL;

    us->length = length;

    us->array = (uchr *) malloc(length * length * sizeof(uchr));
    if (us->array == NULL)
        return NULL;

    for (i = 0; i < length*length; i++)
        us->array[i] = isPrime(i + 1);

    return us;
}

void drawUlamSpiral(UlamSpiral *us, SDL_Renderer *renderer)
{
    uint i, j, x, y, ox, oy, e, size;
    // current position
    x = 0;
    y = 0;
    // center
    ox = us->length / 2;
    oy = us->length / 2;
    e = 1;
    // area of the plane / size of the 1D array
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

void freeUlamSpiral(UlamSpiral *us)
{
    free(us->array);
    free(us);
}
