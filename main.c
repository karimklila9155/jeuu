/** 
* @file main.c 
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

int main()
{
    background bg,bg2;
    SDL_Surface *ecran =NULL;
    SDL_Surface *perso1 =NULL;
    SDL_Surface *perso2 =NULL;
    SDL_Event event;
    init_background(&bg,"bg.png",0,0,600,600);
    init_background(&bg2,"bg.png",0,0,600,600);
    SDL_Rect pos1;
    pos1.x = 200;
    pos1.y = 300;
    SDL_Rect pos2;
    pos2.x = 800;
    pos2.y = 300;
    SDL_Rect posbg1;
    posbg1.x = 0;
    posbg1.y = 0;
    SDL_Rect posbg2;
    posbg2.x = 600;
    posbg2.y = 0;

    int done=1,x=0, speed=25, l;

if (SDL_Init(SDL_INIT_VIDEO)!=0)
{
printf("unable to initialize SDL : %s \n",SDL_GetError());
return 1;
}

ecran = SDL_SetVideoMode(1200,600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
 putenv("SDL_VIDEO_CENTERED=1");
SDL_WM_SetCaption("GAME", NULL);
if (ecran==NULL)
{
printf("unable to set video mode : %s \n",SDL_GetError());
 return 1;
}
    perso1=IMG_Load("carre.png");
    perso2=IMG_Load("carre.png");

SDL_EnableKeyRepeat(60,120);
while(done)

{

   SDL_WaitEvent(&event);
   switch (event.type)
 {

       case SDL_QUIT:
         done=0;
          break;


      case SDL_KEYDOWN:
           switch (event.key.keysym.sym) 
            {

              case SDLK_ESCAPE:
               done = 0;
                 break;
 
              case SDLK_RIGHT:
		l=0;
		if(pos1.x <=270)
		 pos1.x+=10;
            	scrolling (&(bg.camera), speed, x, l);
              break; 

              case SDLK_LEFT:
		l=1;
		if(pos1.x >=100)
		 pos1.x-=10;
                scrolling (&(bg.camera), speed, x, l);
              break;
              case SDLK_d:
		l=0;
		if(pos2.x <=870)
		 pos2.x+=10;
            	scrolling (&(bg2.camera), speed, x, l);
              break; 

              case SDLK_q:
		l=1;
		if(pos2.x >=700)
		 pos2.x-=10;
                scrolling (&(bg2.camera), speed, x, l);
              break;



              
          } 
 }

affiche_background(&bg, ecran, posbg1);
affiche_background(&bg2, ecran, posbg2);
SDL_BlitSurface(perso1, NULL, ecran, &pos1);
SDL_BlitSurface(perso2, NULL, ecran, &pos2);
SDL_Flip(ecran);


}
    SDL_Quit();

    return 0;

}



