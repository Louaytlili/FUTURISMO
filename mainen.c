#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "enigme.h"
#include <time.h>

void main()
{
	SDL_Surface* screen;
	Mix_Music *music;
	enigme e;
	SDL_Event event;
	int boucle = 1;
        int interface=4; //interface=4 si enigme;
    	SDL_Init(SDL_INIT_EVERYTHING);
    	SDL_WM_SetCaption("ENIGME", NULL);
    	screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	initialiser_enigme(&e);
	generer_enigme(&e);
	initialiser_audio(music);
	run_enigme(screen, e); // Exécutez l'énigme	
}
