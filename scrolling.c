/** 
* @file scrolling.c 
* @brief Testing Program. 
* @author Ember 
* @version 0.1 
* @date Apr 22, 2021
* 
* Testing program for background scrollilng * 
*/
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include"header.h"

/** 
* @brief To initialize the background b . 
* @param bg the background   
* @return Nothing 
*/ 

void init_background(background* bg, char image[], int x, int y, int w, int h)
{
bg->image=NULL;
bg->image=IMG_Load(image);
bg->camera.x=x;
bg->camera.y=y;
bg->camera.w=w;
bg->camera.h=h;
}

/** 
* @brief To show the background b . 
* @param ecran the screen 
* @param bg the background 
* @return Nothing 
*/ 
void affiche_background(background* bg, SDL_Surface *ecran, SDL_Rect bg1)
{
SDL_BlitSurface(bg->image, &(bg->camera), ecran, &bg1);
}

/** 
* @brief To scroll the background to the right . 
* @param camera the camera
* @param speed the speed
* @param x the distance
* @param l the direction
* @return Nothing 
*/ 

void scrolling (SDL_Rect* camera, int speed,int x, int l)
{




if(l==0)
	{
		if (camera->x <= 1200) {
		x += speed;
            	camera->x += speed;	}
	}		


else if (l==1)
	{
		if (camera->x >= 50) {
                 x -= speed;

           	 camera->x -= speed;
}
    
        }
	  
}


