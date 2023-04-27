#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "fonction.h"

int main()
{
  //Declaration des variables
  SDL_Surface *screen;
  image IMAGE,IMAGE_BTN1,IMAGE_BTN2,IMAGE_BTN1S,IMAGE_BTN2S,imgbtn,IMAGE_BTN3,IMAGE_BTN3S,IMAGE_BTNM,IMAGE_BTNMS;
  image IMAGE_SETTINGSBG,IMAGE_QUITSETTINGS,IMAGE_QUITSETTINGSS;
  image IMAGE_MOREBG,IMAGE_QUITMORE,IMAGE_QUITMORES;
  image IMAGE_SOUNDBAR0,IMAGE_SOUNDBAR1,IMAGE_SOUNDBAR2,IMAGE_SOUNDBAR3,IMAGE_SOUNDBAR4,IMAGE_SOUNDBAR5;
  image IMAGE_SOUNDPLUS,IMAGE_SOUNDMINUS;
  image IMAGE_LOADINGBG,IMAGE_LOADINGBAR;
  Mix_Music *music;
  Mix_Chunk *mus;
  texte txte;
  SDL_Event event;
  int boucle=1,quit=1;
  int etat=0,etatquit=0;
  int settings=0,sound=5,audio=1;
  int more=0;
  int play=0,game=0;
  //Initialisation de la SDL
  if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER)==-1)
  {
  	printf("- Could not initialize SDL: %s \n",SDL_GetError());
  	return -1;
  }
  //Reglage de la fenetre
  screen=SDL_SetVideoMode(SCREEN_W,SCREEN_H,32,SDL_SWSURFACE|SDL_DOUBLEBUF);
  //Initialisation
  initialiser_imageBACK(&IMAGE);
  initialiser_imageSETTINGSBG(&IMAGE_SETTINGSBG);
  initialiser_imageQUITSETTINGS(&IMAGE_QUITSETTINGS);
  initialiser_imageQUITSETTINGSS(&IMAGE_QUITSETTINGSS);
  initialiser_imageMOREBG(&IMAGE_MOREBG);
  initialiser_imageQUITMORE(&IMAGE_QUITMORE);
  initialiser_imageQUITMORES(&IMAGE_QUITMORES);
  initialiser_imageMORE(&IMAGE_BTNM);
  initialiser_imageMORES(&IMAGE_BTNMS);
  initialiser_imageBOUTON1(&IMAGE_BTN1);
  initialiser_imageBOUTON2(&IMAGE_BTN2);
  initialiser_imageBOUTON3(&IMAGE_BTN3);
  initialiser_imageBOUTON1S(&IMAGE_BTN1S);
  initialiser_imageBOUTON2S(&IMAGE_BTN2S);
  initialiser_imageBOUTON3S(&IMAGE_BTN3S);
  initialiser_imageSOUNDBAR0(&IMAGE_SOUNDBAR0);
  initialiser_imageSOUNDBAR1(&IMAGE_SOUNDBAR1);
  initialiser_imageSOUNDBAR2(&IMAGE_SOUNDBAR2);
  initialiser_imageSOUNDBAR3(&IMAGE_SOUNDBAR3);
  initialiser_imageSOUNDBAR4(&IMAGE_SOUNDBAR4);
  initialiser_imageSOUNDBAR5(&IMAGE_SOUNDBAR5);
  initialiser_imageSOUNDPLUS(&IMAGE_SOUNDPLUS);
  initialiser_imageSOUNDMINUS(&IMAGE_SOUNDMINUS);
  initialiser_audio(music,audio);
  initialiser_audiobref(mus);
  initialiser_texte(&txte);
  //=======================================
  image bg;
  Ennemi enm;
  int interface=3;
  int input =-1;
  enm.exist = 1;
  enm.dir=0;
  initialiser_imageBACKGAME(&bg);
  initialiser_ennemi(&enm);
  /*************BOUCLE DU MENU************/
  while(boucle)
  {
  	//AFFICHAGE
  	afficher_imageBMP(screen,IMAGE);//Pour afficher l'image du background
  	afficher_texte(screen,txte);//PROBLEM
  	afficher_imageMORE(screen,IMAGE_BTNM);
        if(etat==0)
  	{
  		  afficher_imageBTN1(screen,IMAGE_BTN1);//Afficher la bouton PLAY
  	          afficher_imageBTN2(screen,IMAGE_BTN2);//Afficher la bouton SETTINGS 
  		  afficher_imageBTN3(screen,IMAGE_BTN3);//Afficher la bouton QUITTER
  		  afficher_imageMORE(screen,IMAGE_BTNM);//Afficher la bouton MORE
  	}
  	if(etat==1)
  	{
  	          afficher_imageBTN1S(screen,IMAGE_BTN1S);//Afficher la bouton PLAY Selectionne
  	          afficher_imageBTN2(screen,IMAGE_BTN2);//Afficher la bouton SETTINGS
  		  afficher_imageBTN3(screen,IMAGE_BTN3);//Afficher la bouton QUITTER
  		  afficher_imageMORE(screen,IMAGE_BTNM);//Afficher la bouton MORE
        }
  	if(etat==2)
  	{
  		  afficher_imageBTN2S(screen,IMAGE_BTN2S);//Afficher la bouton SETTINGS Selectionne
  		  afficher_imageBTN3(screen,IMAGE_BTN3);//Afficher la bouton QUITTER
  		  afficher_imageBTN1(screen,IMAGE_BTN1);//Afficher la bouton PLAY
  		  afficher_imageMORE(screen,IMAGE_BTNM);//Afficher la bouton MORE
        }
        if(etat==3)
  	{
  		  afficher_imageBTN3S(screen,IMAGE_BTN3S);//Afficher la bouton QUITTER Selectionne
  		  afficher_imageBTN2(screen,IMAGE_BTN2);//Afficher la bouton SETTINGS
  		  afficher_imageBTN1(screen,IMAGE_BTN1);//Afficher la bouton PLAY
  		  afficher_imageMORE(screen,IMAGE_BTNM);//Afficher la bouton MORE
        }
        if(etat==4)
  	{
  		  afficher_imageMORES(screen,IMAGE_BTNMS); //Afficher la bouton MORE Selectionne
  		  afficher_imageBTN3(screen,IMAGE_BTN3);//Afficher la bouton QUITTER 
  		  afficher_imageBTN2(screen,IMAGE_BTN2);//Afficher la bouton SETTINGS
  		  afficher_imageBTN1(screen,IMAGE_BTN1);//Afficher la bouton PLAY
        }
        //MORE:
        if(more)
        {
                  afficher_imageMOREBG(screen,IMAGE_MOREBG);
                  if(etatquit==1)
                  {
		  	 afficher_imageQUITMORES(screen,IMAGE_QUITMORES);
		  }
		  else
		  {
		  	 afficher_imageQUITMORE(screen,IMAGE_QUITMORE);
		  }
        	  while(SDL_PollEvent(&event))
        	  {
        	  	 switch(event.type)
        	  	 {
        	  	 	case SDL_MOUSEBUTTONDOWN:
        	  	 	if(event.button.button==SDL_BUTTON_LEFT && (event.motion.y<=540   && event.motion.y>=460   && (event.motion.x<=447  && event.motion.x>=210 )))
        	  	 	{
        	  	 		 more=0;
        	  	 	}
        	  	 	break;
        	  	 	case SDL_MOUSEMOTION:
        	  	 	if(event.motion.y<=540   && event.motion.y>=460  && (event.motion.x<=447   && event.motion.x>=210 ))
        	  	 	{
        	  	 		 etatquit=1;
        	  	 	}
        	  	 	else
        	  	 	{
        	  	 		 etatquit=0;
        	  	 	}
        	  	 	break;
        	  	 }
        	  }
        	  
        }
        //SETTINGS :
        if(settings)
        {
         	  afficher_imageSETTINGSBG(screen,IMAGE_SETTINGSBG);
         	  afficher_imageSOUNDPLUS(screen,IMAGE_SOUNDPLUS);
         	  afficher_imageSOUNDMINUS(screen,IMAGE_SOUNDMINUS);
         	  if(etatquit==0)
         	  {
         	  	 afficher_imageQUITSETTINGS(screen,IMAGE_QUITSETTINGS);
         	  }
         	  if(etatquit==1)
         	  {
         	  	 afficher_imageQUITSETTINGSS(screen,IMAGE_QUITSETTINGSS);
         	  }
         	  if(sound==0)
         	  {
         	  	 afficher_imageSOUNDBAR0(screen,IMAGE_SOUNDBAR0);
         	  	 off_audio(music);
         	  }
         	  if(sound==1)
         	  {
         	  	 afficher_imageSOUNDBAR1(screen,IMAGE_SOUNDBAR1);
         	  	 audio=5;
         	  	 initialiser_audio(music,audio); 
         	  }
         	  if(sound==2)
         	  {
         	  	 afficher_imageSOUNDBAR2(screen,IMAGE_SOUNDBAR2);
         	  	 audio=4;
         	  	 initialiser_audio(music,audio);
         	  }
         	  if(sound==3)
         	  {
         	  	 afficher_imageSOUNDBAR3(screen,IMAGE_SOUNDBAR3);
         	  	 audio=3;
         	  	 initialiser_audio(music,audio);
         	  }
         	  if(sound==4)
         	  {
         	  	 afficher_imageSOUNDBAR4(screen,IMAGE_SOUNDBAR4);
         	  	 audio=2;
         	  	 initialiser_audio(music,audio);
         	  }
         	  if(sound==5)
         	  {
         	  	 afficher_imageSOUNDBAR5(screen,IMAGE_SOUNDBAR5);
         	  	 audio=1;
         	  	 initialiser_audio(music,audio);
         	  }
         	  while(SDL_PollEvent(&event))
         	  {
         	  	switch(event.type)
         	  	{
         	  	        case SDL_MOUSEBUTTONDOWN://Quitter SETTINGS
         	  	        if(event.button.button==SDL_BUTTON_LEFT && (event.motion.y<=505 && event.motion.y>=425 && (event.motion.x<=617 && event.motion.x>=380)))
         	  	        {
         	  	        	 settings=0;//Quitter SETTINGS
         	  	        }
         	  	        if(event.button.button==SDL_BUTTON_LEFT && (event.motion.y<=360 && event.motion.y>=310 && (event.motion.x<=731 && event.motion.x>=680)))
         	  	        {
         	  	        	if(sound<5)
         	  	        	{
         	  	        		sound=sound+1;
         	  	        	}
         	  	        	
         	  	        }
         	  	        if(event.button.button==SDL_BUTTON_LEFT && (event.motion.y<=362 && event.motion.y>=312  && (event.motion.x<=311 && event.motion.x>=260)))
         	  	        {
         	  	        	if(sound>0)
         	  	        	{
         	  	        		sound=sound-1;
         	  	        	}
         	  	        }
         	  	        break;
         	  	        case SDL_MOUSEMOTION:
         	  	        if(event.motion.y<=505 && event.motion.y>=425 && (event.motion.x<=617 && event.motion.x>=380))
         	  	        {
         	  	        	 etatquit=1;
         	  	        }
         	  	        else
         	  	        {
         	  	        	etatquit=0;
         	  	        }	 
         	  	        break;      
         	        }
         	  }
        }
        if(play)
        {
        	 //while(game==1)
                 //{
	             //if(interface==3)
                     //{
                     afficher_imageBACKGAME(screen,bg);
                     afficher_ennemi(screen,enm);
                     //}
                     while(SDL_PollEvent(&event))
	             {
		           input=-1;
        	           switch(event.type)
        	           {
        	                case SDL_KEYDOWN:
        	                     if(event.key.keysym.sym == SDLK_ESCAPE)
			             {
			                 input=0;
        	                     }break;
        	                case SDL_QUIT:
        	                     input=0;
        	                     break;
        	           }
	             }
	             if(input==0)
	             {
	 	            game=0;
	             }
                     if(interface==3 && enm.exist==1)
                     {		
		            move(&enm);
		            animer_ennemi(&enm);
	             }
	             SDL_Flip(screen);
              //}
        }
  	while(SDL_PollEvent((&event)))
  	{
  		switch(event.type)
  		{
  			case SDL_QUIT:
  			boucle=0;
  			break;
  			case SDL_MOUSEBUTTONDOWN://Quitter le menu
  			if(event.button.button==SDL_BUTTON_LEFT && (event.motion.y<=573 && event.motion.y>=515 && (event.motion.x<=617 && event.motion.x>=380)))
  			{
  				boucle=0;//Quitter le menu)
  			}
  			if(event.button.button==SDL_BUTTON_LEFT && (event.motion.y<=498 && event.motion.y>=440 &&(event.motion.x<=620 && event.motion.x>=383)))
  			{
  				settings=1;//Aller au SETTINGS
  			}
  			if(event.button.button==SDL_BUTTON_LEFT && (event.motion.y<=620 && event.motion.y>=560 && (event.motion.x<=910 && event.motion.x>=673)))
  			{
  				more=1;//Aller au MORE
  			}
  			if(event.button.button==SDL_BUTTON_LEFT && (event.motion.y<=408 && event.motion.y>=350 &&(event.motion.x<=617 && event.motion.x>=380)))
  			{
  				play=1;//Aller au GAME
  			}
  			
  			break;
  			case SDL_MOUSEMOTION://Jouer un son bref
  			if(event.motion.y<=408 && event.motion.y>=350 &&(event.motion.x<=617 && event.motion.x>=380))
  			{
  				initialiser_audiobref(mus);//Jouer un sonbref
  				etat=1;
  			}
  			if(event.motion.y<=498 && event.motion.y>=440 &&(event.motion.x<=620 && event.motion.x>=383))
  			{
  				initialiser_audiobref(mus);//Jouer un sonbref
  				etat=2;
  			}
  			if(event.motion.y<=573 && event.motion.y>=515 && (event.motion.x<=617 && event.motion.x>=380))
  			{
  				initialiser_audiobref(mus);//Jouer un sonbref
  				etat=3;
  			}
  			if(event.motion.y<=620 && event.motion.y>=560 && (event.motion.x<=910 && event.motion.x>=673))
  			{
  				etat=4;
  				initialiser_audiobref(mus);//Jouer un sonbref
  			}
  			
  			break;
  		}
  	}
  	/*if(event.button.button==SDL_BUTTON_LEFT)
  	{
  		boucle=0;
  	}*/
  	SDL_Flip(screen);
     
  }
  //Liberer les surfaces
  liberer_image(IMAGE);
  liberer_image(IMAGE_BTNM);
  liberer_image(IMAGE_BTNMS);
  liberer_image(IMAGE_BTN1);
  liberer_image(IMAGE_BTN1S);
  liberer_image(IMAGE_BTN2S);
  liberer_image(IMAGE_BTN2);
  liberer_image(IMAGE_BTN3S);
  liberer_image(IMAGE_BTN3);
  liberer_image(IMAGE_SETTINGSBG);
  liberer_image(IMAGE_QUITSETTINGS);
  liberer_image(IMAGE_QUITSETTINGSS);
  liberer_image(IMAGE_MOREBG);
  liberer_image(IMAGE_QUITMORE);
  liberer_image(IMAGE_QUITMORES);
  liberer_image(IMAGE_SOUNDBAR0);
  liberer_image(IMAGE_SOUNDBAR1);
  liberer_image(IMAGE_SOUNDBAR2);
  liberer_image(IMAGE_SOUNDBAR3);
  liberer_image(IMAGE_SOUNDBAR4);
  liberer_image(IMAGE_SOUNDBAR5);
  liberer_image(IMAGE_SOUNDPLUS);
  liberer_image(IMAGE_SOUNDMINUS);
  //Liberer la musique
  liberer_musique(music);
  liberer_musiquebref(mus);
  //Liberer texte
  liberer_texte(txte);
  //Liberer ennemi
  //liberer_image(enm->img);
  liberer_back(bg);
  //Quitter la SDL
  SDL_Quit();
  return 0;
} 	
