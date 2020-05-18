#ifndef ULAMSPIRAL_H_
#define ULAMSPIRAL_H_

#include "utils.h"
#include <SDL2/SDL.h>

typedef struct ulamSpiral {
    uint length;
    uchr *array;
} UlamSpiral;

UlamSpiral *createUlamSpiral(uint length);
void drawUlamSpiral(UlamSpiral *us, SDL_Renderer *renderer);
void freeUlamSpiral(UlamSpiral *us);

#endif
