/**
* @file fnc.c
* @brief Testing Program.
* @author twisted minds
* @version 0.1
* @date Apr 26, 2021
*
* Testing program for perso animation
*
*/
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "perso.h"
/**
* @brief To initialize the image .
* @param char: image name 
* @param x ,y
* @return img
*/
image init_img(char nomimage[100],int x,int y)
{
image img;
img.back=IMG_Load(nomimage);
img.positiond.x=x;
img.positiond.y=y;
return img;
}
/**
* @brief To display .
* @param ecran surface
* @param img image
* @return nothing
*/
void display(SDL_Surface *ecran,image img)
{
SDL_BlitSurface(img.back,NULL,ecran,&img.positiond);

}
/**
* @brief pour deplace perso .
* @param pers pesonage
* @param recule to direction
* @return i
*/
int deplacerperso(personagee* pers,int i,int *continuer,int *recule)
{ int t;
SDL_Event event;
    SDL_WaitEvent(&event);
        switch(event.type)
        {
          
            case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
             
                case SDLK_RIGHT:
               *recule=0;
                pers->positionpersonage.x +=40;
                i++;
                
                break;

                case SDLK_LEFT:
               *recule=1;
                pers->positionpersonage.x -=40;
                i++;
                break;
                
                case SDLK_UP:
                pers->positionpersonage.y-=150;
                i++;
                break;
           }
           break;             
        
        }
return i;
}
int deplacerperso2(personagee* pers,int i,int *continuer,int *recule)
{ int t;
SDL_Event event;
    SDL_WaitEvent(&event);
        switch(event.type)
        {
          
            case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
             
                case SDLK_d:
               *recule=0;
                pers->positionpersonage.x +=40;
                i++;
                
                break;

                case SDLK_q:
               *recule=1;
                pers->positionpersonage.x -=40;
                i++;
                break;
                
                case SDLK_z:
                pers->positionpersonage.y-=150;
                i++;
                break;
           }
           break;             
        
        }
return i;
}
/**
* @brief To initialize personage .
* @return pers
*/
personagee init_perso()
{

    personagee pers;
    pers.personage[0] = IMG_Load("droite1.png");
    pers.personage[1] = IMG_Load("droite3.png");
    pers.personage[2] = IMG_Load("droite2.png");
    pers.personage[3] = IMG_Load("droite4.png");
    pers.personage[4] = IMG_Load("gauche1.png");
    pers.personage[5] = IMG_Load("gauche2.png");
    pers.personage[6] = IMG_Load("gauche3.png");
    pers.personage[7] = IMG_Load("gauche4.png");
    pers.personage[8] = IMG_Load("gauche5.png");
    /*pers.vi = IMG_Load("vie.png");
    
   pers.posvie.x = 0;
   pers.posvie.y = 0;
    */
      pers.positionpersonage.x = 0;
    pers.positionpersonage.y = 350; 
     
  return pers;

}  personagee init_perso2()
{

personagee pers;
    pers.personage[8] = IMG_Load("droite11.png");
    pers.personage[9] = IMG_Load("droite33.png");
    pers.personage[10] = IMG_Load("droite22.png");
    pers.personage[11] = IMG_Load("droite44.png");
    pers.personage[12] = IMG_Load("gauche11.png");
    pers.personage[13] = IMG_Load("gauche22.png");
    pers.personage[14] = IMG_Load("gauche33.png");
    pers.personage[15] = IMG_Load("gauche44.png");
    /*pers.vi = IMG_Load("vie.png");
    
   pers.posvie.x = 0;
   pers.posvie.y = 0;
    */
      pers.positionpersonage.x = 0;
    pers.positionpersonage.y = 350; 
     
  return pers;

}  
/*void init_score( score *s)
{
s->ps.x=0;
s->ps.y=0;
s->fond1=NULL;
}
int afficherscore(score *s,SDL_Surface *ecran  )
{  char img[30];
int i;
   for(i=0;i<11;i++)
{

sprintf(img,"s%d.png",i);
s->fond1=IMG_Load(img);
SDL_FillRect(ecran,	NULL,SDL_MapRGB(ecran->format,0,0,0));
//SDL_BlitSurface(s->fond1,NULL, ecran,&s->ps);
SDL_Delay(4000);
SDL_Flip(ecran);
}

return i;
}
*/
/**
* @brief To afficher perso .
* @param positionpersonage position de perso 
* @param personegee pers
* @param resule direction
* @return Nothing
*/
void afficher_perso(SDL_Surface *ecran ,personagee pers,int i,SDL_Rect positionpersonage,int recule)
{
//SDL_BlitSurface(pers.vi, NULL, ecran,&posvie);
    if (recule==0)
SDL_BlitSurface(pers.personage[i],NULL,ecran,&positionpersonage);
else if (recule==1)
i>3;
SDL_BlitSurface(pers.personage[i],NULL,ecran,&positionpersonage);

}
void afficher_perso2(SDL_Surface *ecran ,personagee pers,int i,SDL_Rect positionpersonage,int recule)
{
//SDL_BlitSurface(pers.vi, NULL, ecran,&posvie);
    if (recule==0)
SDL_BlitSurface(pers.personage[i],NULL,ecran,&positionpersonage);
else if (recule==1)
i>3;
SDL_BlitSurface(pers.personage[i],NULL,ecran,&positionpersonage);

}








