#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "minimap.h"


int main()
{
TTF_Init();
SDL_Init(SDL_INIT_VIDEO);
SDL_Surface *screen , *mask, *perso;
screen=SDL_SetVideoMode (800,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
SDL_WM_SetCaption("test\t1",NULL);
temps t;
minimap m;
SDL_Rect pos_perso,camera;
SDL_Event event;
mask=IMG_Load("mask.png");
perso=IMG_Load("hero.png");
init_temps(&t);
init_map(&m);
pos_perso.x=0;
pos_perso.y=0;
camera.x=0;
camera.y=0;
camera.w=800;
camera.h=600;
int continuer=1;
SDL_EnableKeyRepeat(100,10);////
while(continuer)
{
    
while(SDL_PollEvent(&event))
	{

		switch(event.type)
		{
		case SDL_QUIT:

			continuer=0;
		break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
                case SDLK_LEFT:
                 
                    if (collision_left(mask,pos_perso)==0)   pos_perso.x-=5;
                
                break;
                case SDLK_RIGHT:
                   if (collision_right(mask,pos_perso)==0)
                      pos_perso.x+=5;
                  
                break;
                case SDLK_UP:
                     if (collision_up(mask,pos_perso)==0)
                     pos_perso.y-=5;
                break;  
                case SDLK_DOWN:
                if (collision_down(mask,pos_perso)==0)
                     pos_perso.y+=5;
                break;  

            }
            break;
            
        }
    }   
MAJMinimap(pos_perso,&m,camera,20);
SDL_BlitSurface(mask,NULL,screen,NULL);
afficherminimap(m,screen);
SDL_BlitSurface(perso,NULL,screen,&pos_perso);
afficher_temps(&t,screen);
SDL_Flip(screen);
SDL_Delay(50);

}

}



