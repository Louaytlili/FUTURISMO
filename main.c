#include<stdio.h>
#include"SDL/SDL.h"
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "background.h"
#include "pres.h"

int main(void)
{	
	int continuer=1;
	SDL_Surface *screen=NULL;
	background ba;
        int score=0;
	Personne perso;
	SDL_Event event;
	
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);

	screen=SDL_SetVideoMode(1360,765,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
	if(screen==NULL)
	{
		printf("unable to set video mode:%s\n",SDL_GetError());
		return 1;
	}
Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
            Mix_VolumeMusic(MIX_MAX_VOLUME / 2);
           
	initBack2(&ba);
	

	initialiserperso(&perso);
	initbouton(&ba);
              meilleur("test.txt",&ba);
	while (continuer)
	{		
		deplacer_perso(&perso,event);
		
		SDL_PollEvent(&event);
     	switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
			case SDLK_RIGHT:
			 

				scrolling(&ba,0);		

		
					
                        break;
                        case SDLK_LEFT:
                    

				scrolling(&ba,1);


		 
                        break;
			 case SDLK_UP:
			 

					scrolling(&ba,2);		

                        break;
 			 case SDLK_DOWN:
 			 

					scrolling(&ba,3);		
                        break;	
      		 }
      		 	
            break;

         case SDL_MOUSEBUTTONUP: 
                if (event.button.button == SDL_BUTTON_LEFT)
                {

                  if (event.button.x >0 && event.button.x < 400 && event.button.y > 550 && event.button.y <850)

                   {
                               
                                            affichageMeilleur(screen,ba);


                   }
               }
       
  
 	}  


               		animerBackground(&ba);	
			afficheBack2(ba,screen,perso);
                        affichebouton(ba,screen);

			afficher_perso(screen,perso);	
                   if(perso.pos_perso.x<590)
                   {
                    score=2500;
                   }
                  else if(590 <perso.pos_perso.x<650)
                    {
                       score=670;
                    }

			SDL_Flip(screen);
	}

                        sauvegarder(score,"test.txt");

	
	SDL_Quit();
      Mix_FreeMusic (ba.son);
      Mix_FreeMusic (ba.son1);
 Mix_CloseAudio();

	return 1;
}

