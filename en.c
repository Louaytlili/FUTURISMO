#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "enigme.h"
#include <time.h>

void initialiser_enigme(enigme *e)
{
	e->image[0]=IMG_Load("multimedia/background/backg0.jpg");
	e->image[1]=IMG_Load("multimedia/background/backg1.jpg");
	e->image[2]=IMG_Load("multimedia/background/backg2.jpg");
	e->image[3]=IMG_Load("multimedia/background/backg3.jpg");
	e->image[4]=IMG_Load("multimedia/background/backg4.jpg"); 
	e->image[5]=IMG_Load("multimedia/background/backg5.jpg");
	e->image[6]=IMG_Load("multimedia/background/backg6.jpg");
	e->image[7]=IMG_Load("multimedia/background/backg7.jpg");
	e->image[8]=IMG_Load("multimedia/background/backg8.jpg"); 
	e->image[9]=IMG_Load("multimedia/background/backg9.jpg");
	e->image[10]=IMG_Load("multimedia/background/backg10.jpg");
	e->image[11]=IMG_Load("multimedia/background/backg11.jpg");
	e->image[12]=IMG_Load("multimedia/background/backg12.jpg");
	e->image[13]=IMG_Load("multimedia/background/backg13.jpg");
	e->image[14]=IMG_Load("multimedia/background/backg14.jpg");
	e->background_lose=IMG_Load("multimedia/background/lost.jpg");
	e->background_win=IMG_Load("multimedia/background/win.jpg");
	e->position_background.x=0;
	e->position_background.y=0;
	e->current_frame=0;
	e->position_enigme.x=100;
	e->position_enigme.y=50;
}
void generer_enigme(enigme *e)
{
	int nb,reponse_correct;
	char chemin_enigme[50];
	FILE* fichier;
	nb=generate_random_number(1,5);
	switch(nb)
	{
		case 1:
		{
			strcpy(chemin_enigme,"multimedia/enigma/1/jeu.jpg");
			fichier=fopen("multimedia/enigma/1/reponse_correcte.txt","r");
			fscanf(fichier,"%d",&reponse_correct);
			break;
		}
		case 2:
		{
			strcpy(chemin_enigme,"multimedia/enigma/2/jeu.jpg");
			fichier=fopen("multimedia/enigma/2/reponse_correcte.txt","r");
			fscanf(fichier,"%d",&reponse_correct);
			break;
		}
		case 3:
		{
			strcpy(chemin_enigme,"multimedia/enigma/3/jeu.jpg");
			fichier=fopen("multimedia/enigma/3/reponse_correcte.txt","r");
			fscanf(fichier,"%d",&reponse_correct);
			break;
		}
		case 4:
		{
			strcpy(chemin_enigme,"multimedia/enigma/4/jeu.jpg");
			fichier=fopen("multimedia/enigma/4/reponse_correcte.txt","r");
			fscanf(fichier,"%d",&reponse_correct);
			break;
		}
		case 5:
		{
			strcpy(chemin_enigme,"multimedia/enigma/5/jeu.jpg");
			fichier=fopen("multimedia/enigma/5/reponse_correcte.txt","r");
			fscanf(fichier,"%d",&reponse_correct);
			break;
		}
	}
	e->image_enigme=IMG_Load(chemin_enigme);
	e->reponse_correct=reponse_correct;
}
void animer_enigme(enigme *e)
{
	if (e->current_frame==13) 
	{
			
		e->current_frame=0; 
	}
    	else 
	{	
		e->current_frame++;
	}
}
int generate_random_number (int a,int b)// fonction tgeneri noumrou aleatoire fi interval enti tdakhlou en parametres
{
    srand(time(NULL)); // Seed the random number generator
    return (a + rand() % (b - a + 1));
}
void afficher_enigme(SDL_Surface *screen , enigme e)
{
	SDL_BlitSurface(e.image[e.current_frame], NULL, screen, &e.position_background); // affichage de la background animee 
	SDL_BlitSurface(e.image_enigme, NULL, screen, &e.position_enigme); // affichage taswiret l enigme
}
void initialiser_audio(Mix_Music *music)
{
	//initialiser les fonctions audio de SDL_mixer
	if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
	{
		printf("%s",SDL_GetError());
	}
	music=Mix_LoadMUS("music_enigme.mp3");//chargement de la musique
	Mix_PlayMusic(music,-1);//jouer la musique
	Mix_VolumeMusic(MIX_MAX_VOLUME/3.5);

}

void run_enigme(SDL_Surface *screen, enigme e)
{
    int boucle = 1;
    int interface = 4;

    while(boucle)
    {
        if(interface == 4) 
        { 
            afficher_enigme(screen, e);
            animer_enigme(&e);
        }
        if(interface == 5) 
        {
            SDL_BlitSurface(e.background_win, NULL, screen, &e.position_background); 
            SDL_Flip(screen);
            SDL_Delay(3000);
            boucle = 0;
        }
        if(interface == 6) 
        {
            SDL_BlitSurface(e.background_lose, NULL, screen, &e.position_background); 
            SDL_Flip(screen);
            SDL_Delay(3000);
            boucle = 0;
        }
        
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT :
                    boucle = 0;
                    break;
                case SDL_KEYDOWN:
                {
                    switch (event.key.keysym.sym)
                    {
                        case SDLK_ESCAPE :
                            boucle = 0;
                            break;
                        case SDLK_a :
                            if (e.reponse_correct==1) interface=5;
                            else interface=6;
                            break;
                        case SDLK_b :
                            if (e.reponse_correct==2) interface=5;
                            else interface=6;
                            break;
                        case SDLK_c :
                            if (e.reponse_correct==3) interface=5;
                            else interface=6;
                            break;
                        case SDLK_d :
                            if (e.reponse_correct==4) interface=5;
                            else interface=6;
                            break;
                        case SDLK_e :
                            if (e.reponse_correct==5) interface=5;
                            else interface=6;
                            break;
                        case SDLK_f :
                            if (e.reponse_correct==6) interface=5;
                            else interface=6;
                            break;
                        case SDLK_g:
                            if (e.reponse_correct==7) interface=5;
                            else interface=6;
                            break;
                        case SDLK_h :
                            if (e.reponse_correct==8) interface=5;
                            else interface=6;
                            break;
                        case SDLK_i :
                            if (e.reponse_correct==9) interface=5;
                            else interface=6;
                            break;
                    }
                }
            } 
        }
        SDL_Flip(screen);
        SDL_Delay(40);
    }
}


