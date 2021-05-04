/**
* @file main.c
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
void  main(SDL_Surface *ecran)
{
    personagee pers;

    SDL_Event event;
    int continuer=1,i=0,t;
    int k;
       //score s;

    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);
    ecran=SDL_SetVideoMode(1000, 667, 32,SDL_HWSURFACE);

  int recule=0;
    image img,img1;
    pers=init_perso();
    pers=init_perso2();
    img=init_img("background.jpg",0,0);
    img1=init_img("vie.png",780,-50);
//init_score( &s);
  // afficherscore(&s,ecran  );
    SDL_EnableKeyRepeat(10,10); 
    
    while (continuer)
    {
         SDL_PollEvent(&event);
       switch(event.type)
          {
            case SDL_QUIT:
            continuer= 0;
            break;
          }
            i=deplacerperso(&pers,i,&continuer,&recule);
            i=deplacerperso2(&pers,i,&continuer,&recule);
           printf("%d\n",recule);
            if (i==3)
            {
            i=0;
            }
             SDL_Delay(100);
//afficherscore(&s,ecran  );
             display(ecran,img);
             display(ecran,img1);
            afficher_perso(ecran,pers,i,pers.positionpersonage,recule);
            afficher_perso2(ecran,pers,i,pers.positionpersonage,recule);
         // afficherscore(&s,ecran  );
            SDL_Flip(ecran);
           if (pers.positionpersonage.x>800)
            {
            pers.positionpersonage.x=0; 
            
            }
         if (pers.positionpersonage.y<400)
         pers.positionpersonage.y=350;
SDL_Flip(ecran);
  
  }    


   for(i=0;i<=3;i++)
    SDL_FreeSurface(pers.personage[i]);
     for(i=0;i<=3;i++)
    SDL_FreeSurface(pers.personage1[i]);

}







