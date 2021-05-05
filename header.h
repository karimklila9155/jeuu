#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
/** 
* @struct Background 
* @brief struct for backround 
*/ 

typedef struct
{
SDL_Surface *image; /*!< Surface. */
SDL_Rect camera; /*!< Rectangle*/ 
}
background;


void init_background(background* bg, char image[], int x, int y, int w, int h);
void affiche_background(background* bg, SDL_Surface *ecran, SDL_Rect bg1);
void scrolling (SDL_Rect* camera, int speed,int x, int l);




#endif // HEADER_H_INCLUDED
