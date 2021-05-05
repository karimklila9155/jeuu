#ifndef minimap_H
#define minimao_H
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include <time.h>

typedef struct 
{SDL_Surface *map;
SDL_Surface  *minijoueur;
SDL_Rect positionmap;
SDL_Rect positionminijoueur;
}minimap;

typedef struct temps
{
SDL_Surface *texte;//image qui contient le temps
 SDL_Rect position;// position du clock
  
    TTF_Font *police ;

 char entree[100]; // chaine de caractere . forme "mm:ss"
 int secondesEcoulees; // variable entier qui contient le nbre de secondes ecoulés
SDL_Color couleurBlanche;// couleur de texte a afficher
time_t t1,t2; //t1 temps initiale ,,, t2 temps actuel
int min, sec;// minutes et secondes
}temps;

void init_map (minimap *m);
void MAJMinimap(SDL_Rect posJoueur,  minimap * m, SDL_Rect camera, int redimensionnement);
void afficherminimap (minimap m, SDL_Surface * screen);
void init_temps(temps *t);
void afficher_temps(temps *t, SDL_Surface *ecran);
void free_temps(temps *t,SDL_Surface *ecran);
SDL_Color GetPixel(SDL_Surface *pSurface , int x,int y);
int collision_right(SDL_Surface *mask , SDL_Rect pos_joueur );
int collision_left(SDL_Surface *mask , SDL_Rect pos_joueur );
int collision_up(SDL_Surface *mask , SDL_Rect pos_joueur );
int collision_down(SDL_Surface *mask , SDL_Rect pos_joueur );

#endif

