#include "minimap.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>

void init_map (minimap *m)
{ m -> map = IMG_Load("minimap.jpg");
  m-> minijoueur = IMG_Load("joueurmini.png");
  m->positionmap.x =252;
  m->positionmap.y =19;
  m->positionminijoueur.x =250;
  m->positionminijoueur.y =21;
}


void MAJMinimap(SDL_Rect pos_Joueur,  minimap * m, SDL_Rect camera, int redimensionnement)
{
  SDL_Rect posJoueurABS;
  posJoueurABS.x = 0;
  posJoueurABS.y = 0;
  posJoueurABS.x = pos_Joueur.x + camera.x;
  posJoueurABS.y = pos_Joueur.y + camera.y;
  m->positionminijoueur.x=(posJoueurABS.x * redimensionnement/100)+250;
  m->positionminijoueur.y=(posJoueurABS.y * redimensionnement/100)+21;
}

void afficherminimap (minimap m, SDL_Surface * screen)
{
  SDL_BlitSurface(m.map,NULL,screen,&m.positionmap);
  SDL_BlitSurface(m.minijoueur,NULL,screen,&m.positionminijoueur);
}

//////////////////////////////////temps
void init_temps(temps *t)
{
 t->texte = NULL; 
 t->position.x=100;
   t->position.y=50;
     t->police = NULL;
  t->police = TTF_OpenFont("outils/avocado.ttf", 20);
    strcpy( t->entree,"");
(t->secondesEcoulees)=0;
time(&(t->t1)); //temps du debut



}


void afficher_temps(temps *t,SDL_Surface *ecran)
{	
SDL_Color couleurBlanche= {0, 0, 0};

    	time(&(t->t2));// temps actuel

		t->secondesEcoulees = t->t2 - t->t1;

        t->min=((t->secondesEcoulees/60)%60);
	t->sec= ((t->secondesEcoulees)%60);

	 sprintf(t->entree,"%02d:%02d",t->min,t->sec);
        t->texte = TTF_RenderUTF8_Solid(t->police, t->entree, couleurBlanche);
      

SDL_BlitSurface(t->texte, NULL, ecran, &(t->position)); /* Blit du texte */
  

//SDL_Delay(80);
 
	
}

void free_temps(temps *t,SDL_Surface *ecran)
{SDL_FreeSurface(t->texte);
 TTF_CloseFont(t->police);
}

/////////////////////////////collision


SDL_Color GetPixel(SDL_Surface *pSurface ,int x,int y)
{
    SDL_Color color;
    Uint32 col=0;
    char *pPosition = (char *) pSurface -> pixels;
    pPosition+=(pSurface->pitch *y);
    pPosition+=(pSurface ->format->BytesPerPixel *x);
    memcpy (&col,pPosition,pSurface ->format ->BytesPerPixel);

SDL_GetRGB(col,pSurface -> format,&color.r ,&color.g ,&color.b);
return (color);
}



int collision_right(SDL_Surface *mask , SDL_Rect pos_joueur )
{  SDL_Color col,colp;
SDL_Rect pos[8];
int collision = 0;
int i,w,h;

col.r=0;
col.g=0;
col.b=0;// cad : col c'est le couleur noir 

w=44;
h=70;


pos[5].x = pos_joueur.x +w;
pos[5].y = pos_joueur.y;



pos[6].x = pos_joueur.x +w;
pos[6].y = pos_joueur.y+ h/2;



pos[7].x = pos_joueur.x +w;
pos[7].y = pos_joueur.y +h;



for (i =5;(i < 8)&&(collision == 0); i++)
{
    colp = GetPixel(mask,pos[i].x ,pos[i].y);
    if((col.r==colp.r) && (col.g == colp.g) && (col.b ==colp.b))
    collision = 1;
}


return (collision);
}



int collision_left(SDL_Surface *mask, SDL_Rect pos_joueur)
{
SDL_Color col,colp;
SDL_Rect pos[8];
int collision = 0;
int i,w,h;
col.r=0;
col.g=0;
col.b=0;


w=44;
h=70;


pos[0].x = pos_joueur.x;
pos[0].y = pos_joueur.y;

pos[1].x = pos_joueur.x;
pos[1].y = pos_joueur.y + h /2;

pos[2].x = pos_joueur.x;
pos[2].y = pos_joueur.y + h;


for (i =0;(i < 3)&&(collision == 0); i++)
{
col = GetPixel(mask,pos[i].x ,pos[i].y);
if((col.r==colp.r) && (col.g == colp.g) && (col.b ==colp.b))
collision = 1;
}
    return (collision);
}


int collision_up(SDL_Surface *mask, SDL_Rect pos_joueur)
{
SDL_Color col,colp;
SDL_Rect pos;
int collision = 0;
int i,w,h;
col.r=0;
col.g=0;
col.b=0;


w=44;
h=70;



pos.x = pos_joueur.x + w/2;
pos.y = pos_joueur.y;

col = GetPixel(mask,pos.x ,pos.y);


if((col.r==colp.r) && (col.g == colp.g) && (col.b ==colp.b))   collision = 1;


return (collision);
}




int collision_down(SDL_Surface *mask, SDL_Rect pos_joueur)
{
SDL_Color col,colp;
SDL_Rect pos;
int collision = 0;
int i,w,h;
col.r=0;
col.g=0;
col.b=0;


w=44;
h=70;



pos.x = pos_joueur.x+ w /2;
pos.y = pos_joueur.y +h;


col = GetPixel(mask,pos.x ,pos.y);

if((col.r==colp.r) && (col.g == colp.g) && (col.b ==colp.b)) collision = 1;

return (collision);
}



