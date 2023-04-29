#ifndef collisionparfaite_H_INCLUDED
#define collisionparfaite_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "pres.h"
 

SDL_Color getpixel(SDL_Surface *psurface,int x,int y);
int collisionparfaite(SDL_Surface *psurface,personne perso);
void collision(SDL_Surface *psurface,personne *perso);
#endif
#ifndef map_H_INCLUDED
#define map_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
//#include <SDL/SDL_mixer.h>
#include "pres.h"

typedef struct 
{	
	SDL_Surface *map ;
	SDL_Rect pos_map;
	SDL_Surface *mini_perso;
	SDL_Rect perso_pos_map;

}map;//structure  bich tnks 3lina les variables 

	void initialiser_map (map *m,SDL_Surface *screen) ;
	void perso_map(map *m,personne *p);
	void affiche_map(map m, SDL_Surface *screen);

#endif
#ifndef PERS_H_INCLUDED
#define PERS_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>



typedef struct
{
  	SDL_Surface *image_p;
  	SDL_Rect pos_perso;
}personne;

void initialiserperso(personne *p);
void deplacer_perso(personne *p,SDL_Event event);
void afficher_perso(SDL_Surface *screen,personne p);
void free_perso(personne p);


#endif
#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <string.h>



typedef struct  {
    SDL_Surface* textSurface;
    SDL_Rect positionText;
    char txt[20];
    SDL_Color couleurTxt;
    TTF_Font* police;
}Text;// structure text besh tekteb l temps 


typedef struct
{
    int tempsdebut;
    int mm; 
    int ss;
    Text temps;
    
} Time;



void inittemps(Time *t);// initialisaton lel temps l koulo 
void inittempsenig(Time *t);
void Timer(int *tempsdebut);// tehseb l temps 
int initTexttime(Text* T);//initialisation du text  khw eli besh nektbo bih
int initTexttimeenig(Text* T);
int loadFonttime(Text* T, char* angelina);//tloadi l font mtaa l text
void update_time(Time* T);//mise a jour du temps 
void update_timeenig(Time* T);
void displaytime(Time T,SDL_Surface *screen);//afficher le temps aal back
void freeTexttime(Text T);//besh ykoun fema optimisation 


#endif
