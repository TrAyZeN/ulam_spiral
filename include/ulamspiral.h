#ifndef ULAMSPIRAL_H_
#define ULAMSPIRAL_H_

#include <SDL2/SDL.h>

#define uchr unsigned char
#define uint unsigned int

typedef struct ulamSpiral {
    uint length;
    uchr *array;
} UlamSpiral;

UlamSpiral *createUlamSpiral(uint length);
void drawUlamSpiral(UlamSpiral *us, SDL_Renderer *renderer);

#endif
