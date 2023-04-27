#ifndef FONCTION_H
#define FONCTION_H
#ifndef ES_H
#define ES_H
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

#define SCREEN_H 660
#define SCREEN_W 960
typedef struct
{
	char *url;
	SDL_Rect pos_img_affiche;//Partie de l'image qui doit etre affichee
	SDL_Rect pos_img_ecran;//Position de l'image par rapport l'ecran
	SDL_Surface *img;
}image;

typedef struct
{
	SDL_Surface *txt;
	SDL_Rect pos_txt;
	SDL_Colour color_txt;
	TTF_Font *police;
}texte;
typedef struct{
        char *url;
        SDL_Surface *img;
        int exist;
        int dir;
        SDL_Rect pos;
        int pos_max;
        int pos_min;
	SDL_Rect sprite;
}Ennemi;

//image
void initialiser_imageBACK(image *imge);
void initialiser_imageBOUTON1(image *imgbtn);
void initialiser_imageBOUTON2(image *imgbtn);
void initialiser_imageBOUTON3(image *imgbtn);
void initialiser_imageBARSOUND0(image *imgbtn);
void initialiser_imageBARSOUND1(image *imgbtn);
void initialiser_imageBARSOUND2(image *imgbtn);
void initialiser_imageBARSOUND3(image *imgbtn);
void initialiser_imageBARSOUND4(image *imgbtn);
void initialiser_imageBARSOUND5(image *imgbtn);
void initialiser_imageSOUNDPLUS(image *imgbtn);
void initialiser_imageSOUNDMINUS(image *imgbtn);
void afficher_imageBMP(SDL_Surface *screen,image imge);
void afficher_imageBTN1(SDL_Surface *screen,image imge);
void afficher_imageBTN2(SDL_Surface *screen,image imge);
void afficher_imageBTN3(SDL_Surface *screen,image imge);
void afficher_imageSOUNDBAR0(SDL_Surface *screen,image imge);
void afficher_imageSOUNDBAR1(SDL_Surface *screen,image imge);
void afficher_imageSOUNDBAR2(SDL_Surface *screen,image imge);
void afficher_imageSOUNDBAR3(SDL_Surface *screen,image imge);
void afficher_imageSOUNDBAR4(SDL_Surface *screen,image imge);
void afficher_imageSOUNDBAR5(SDL_Surface *screen,image imge);
void afficher_imageSOUNDPLUS(SDL_Surface *screen,image imge);
void afficher_imageSOUNDMINUS(SDL_Surface *screen,image imge);
void liberer_image(image imge);
//audio
void initialiser_audio(Mix_Music *music,int audio);
void liberer_musique(Mix_Music *music);
void initialiser_audiobref(Mix_Chunk *music);
void liberer_musiquebref(Mix_Chunk *music);
void off_audio(Mix_Music *music);
//texte
void initialiser_texte(texte *txte);
void afficher_texte(SDL_Surface *screen,texte txte);
void liberer_texte(texte txte);
//=============================================================enemy
//background
void initialiser_imageBACKGAME(image *imge);
void afficher_imageBACKGAME(SDL_Surface *screen,image imge);
void liberer_back(image imge);
//ennemi
void initialiser_ennemi(Ennemi* imag);
void afficher_ennemi(SDL_Surface *screen,Ennemi imag);
void liberer_image_ennemi(Ennemi imag);
void move(Ennemi *e);
void animer_ennemi(Ennemi *e);
int CollisionBB(SDL_Rect ep,SDL_Rect pp);
#endif
#endif
