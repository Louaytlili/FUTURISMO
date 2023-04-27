#ifndef BACKGROUND_H_INCLUDE
#define BACKGROUND_H_INCLUDE
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "pres.h"
#define SCREEN_W 1360
#define SCREEN_H 765
typedef struct
{
	SDL_Surface *imgback;
        SDL_Surface *boutton;
        TTF_Font *police; 
        SDL_Rect pos_reponse1txt;
	SDL_Rect pos_reponse2txt;
	SDL_Rect pos_reponse3txt;
        SDL_Rect pos_meilleurtxt;
	SDL_Surface *reponses[4];
        SDL_Rect positionbotton;
	SDL_Rect posback2;
	SDL_Rect camera2;
	Mix_Music *son;
        Mix_Music *son1;
	SDL_Surface *image_flower;  
	SDL_Rect pos_image_flower;
	SDL_Rect single_flower;	
	int flower_num;


}background;
void initBack2(background *b);
void initbouton(background *b);
void affichebouton(background b,SDL_Surface *screen);
void afficheBack2 (background b, SDL_Surface *ecran,Personne p);
void scrolling (background *b,int direction);
void animerBackground(background *b);
void displayFlower(background b,SDL_Surface *ecran);
void sauvegarder(int score,char nomfichier[]);
void meilleur (char nomfichier[],background *b);
void afficher(background b,SDL_Surface *ecran);
void affichageMeilleur(SDL_Surface *screen,background b);

#endif  

