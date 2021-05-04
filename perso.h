/**
* @struct pesonnage image
* @brief struct for image et personagee
*/
#ifndef FNC_H_
#define FNC_H_

typedef struct image
{ 
	SDL_Rect positiond; /*!< position*/
        SDL_Surface* back;  /*!< surface */
}image;

typedef struct personagee

{

	SDL_Surface *personage[15];/*!< surface */
	SDL_Surface *personage1[3]; /*!< surface*/
        SDL_Rect positionpersonage; /*!< position personage */
        int score; /*!< score */
        int vie;/*!< vie*/
        SDL_Surface *sco;
        SDL_Surface *vi;
        SDL_Rect posscore;
        SDL_Rect posvie;
}personagee;
/*typedef struct score
{
SDL_Rect ps;
 SDL_Surface *fond1;
}score;

void init_score( score *s);
int afficherscore(score *s,SDL_Surface *screen  );
*/
image init_img(char nomimage[100],int x,int y);
void display(SDL_Surface *ecran,image img);
personagee init_perso();
personagee init_perso2();
void afficher_perso(SDL_Surface *ecran,personagee pers,int i,SDL_Rect positionpersonage,int recule);
int deplacerperso(personagee *pers,int i,int *continuer,int *recule);
void afficher_perso2(SDL_Surface *ecran,personagee pers,int i,SDL_Rect positionpersonage2,int recule);
int deplacerperso2(personagee *pers,int i,int *continuer,int *recule);








#endif
