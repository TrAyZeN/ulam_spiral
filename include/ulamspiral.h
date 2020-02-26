#ifndef ULAMSPIRAL_H_
#define ULAMSPIRAL_H_

#include <SDL2/SDL.h>

#define uchr unsigned char

#define WIDTH 600

uchr *createUlamSpiral(unsigned int width);
void drawUlamSpiral(uchr *ulamSpiral, SDL_Renderer *renderer);

#endif
