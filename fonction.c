#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "fonction.h"


/*****TRAITEMENT DES IMAGES*****/
void initialiser_imageBACK(image *imge)
{
  imge->url="final.jpg";
  imge->img=IMG_Load(imge->url);
  if(imge->img == NULL){
	printf("- Unable to load background image %s \n",SDL_GetError());
        return;}
  imge->pos_img_ecran.x=0;
  imge->pos_img_ecran.y=0;
  imge->pos_img_affiche.x=0;
  imge->pos_img_affiche.y=0;
  imge->pos_img_affiche.h=700;
  imge->pos_img_affiche.w=1000;
}

void initialiser_imageSETTINGSBG(image *imge)
{
  imge->url="settingsbg.png";
  imge->img=IMG_Load(imge->url);
  if(imge->img == NULL){
	printf("- Unable to load settings background image %s \n",SDL_GetError());
        return;}
  imge->pos_img_ecran.x=0;
  imge->pos_img_ecran.y=0;
  imge->pos_img_affiche.x=0;
  imge->pos_img_affiche.y=0;
  imge->pos_img_affiche.h=700;
  imge->pos_img_affiche.w=1000;
}

void initialiser_imageMOREBG(image *imge)
{
  imge->url="morebg.png";
  imge->img=IMG_Load(imge->url);
  if(imge->img == NULL){
	printf("- Unable to load MORE background image %s \n",SDL_GetError());
        return;}
  imge->pos_img_ecran.x=0;
  imge->pos_img_ecran.y=0;
  imge->pos_img_affiche.x=0;
  imge->pos_img_affiche.y=0;
  imge->pos_img_affiche.h=700;
  imge->pos_img_affiche.w=1000;
}

void initialiser_imageQUITMORE(image *imgbtn)
{
  //Chargement de l'image
  imgbtn->url="quit.png";
  imgbtn->img=IMG_Load(imgbtn->url);
  if(imgbtn->img == NULL){
	printf("- Unable to load QUIT MORE image %s \n",SDL_GetError());
	return;}
  imgbtn->pos_img_affiche.x=0;
  imgbtn->pos_img_affiche.y=0;
  imgbtn->pos_img_affiche.w=237;
  imgbtn->pos_img_affiche.h=80;
  imgbtn->pos_img_ecran.x=(SCREEN_W/2)-270;
  imgbtn->pos_img_ecran.y=(2*(SCREEN_H/3))+20;
}

void initialiser_imageSOUNDPLUS(image *imgbtn)
{
  //Chargement de l'image
  imgbtn->url="plus.png";
  imgbtn->img=IMG_Load(imgbtn->url);
  if(imgbtn->img == NULL){
	printf("- Unable to load PLUS SOUND image %s \n",SDL_GetError());
	return;}
  imgbtn->pos_img_affiche.x=0;
  imgbtn->pos_img_affiche.y=0;
  imgbtn->pos_img_affiche.w=51;
  imgbtn->pos_img_affiche.h=50;
  imgbtn->pos_img_ecran.x=(SCREEN_W/2)+200;
  imgbtn->pos_img_ecran.y=(SCREEN_H/2)-20;
}

void initialiser_imageSOUNDMINUS(image *imgbtn)
{
  //Chargement de l'image
  imgbtn->url="minus.png";
  imgbtn->img=IMG_Load(imgbtn->url);
  if(imgbtn->img == NULL){
	printf("- Unable to load MINUS SOUND image %s \n",SDL_GetError());
	return;}
  imgbtn->pos_img_affiche.x=0;
  imgbtn->pos_img_affiche.y=0;
  imgbtn->pos_img_affiche.w=51;
  imgbtn->pos_img_affiche.h=50;
  imgbtn->pos_img_ecran.x=(SCREEN_W/2)-220;
  imgbtn->pos_img_ecran.y=(SCREEN_H/2)-18;
}


void initialiser_imageSOUNDBAR0(image *imgbtn)
{
  //Chargement de l'image
  imgbtn->url="sound0.png";
  imgbtn->img=IMG_Load(imgbtn->url);
  if(imgbtn->img == NULL){
	printf("- Unable to load BAR SOUND  image %s \n",SDL_GetError());
	return;}
  imgbtn->pos_img_affiche.x=0;
  imgbtn->pos_img_affiche.y=0;
  imgbtn->pos_img_affiche.w=700;
  imgbtn->pos_img_affiche.h=400;
  imgbtn->pos_img_ecran.x=(SCREEN_W-780);
  imgbtn->pos_img_ecran.y=(SCREEN_H-460);
}

void initialiser_imageSOUNDBAR1(image *imgbtn)
{
  //Chargement de l'image
  imgbtn->url="sound1.png";
  imgbtn->img=IMG_Load(imgbtn->url);
  if(imgbtn->img == NULL){
	printf("- Unable to load BAR SOUND  image %s \n",SDL_GetError());
	return;}
  imgbtn->pos_img_affiche.x=0;
  imgbtn->pos_img_affiche.y=0;
  imgbtn->pos_img_affiche.w=700;
  imgbtn->pos_img_affiche.h=400;
  imgbtn->pos_img_ecran.x=(SCREEN_W-780);
  imgbtn->pos_img_ecran.y=(SCREEN_H-460);
}

void initialiser_imageSOUNDBAR2(image *imgbtn)
{
  //Chargement de l'image
  imgbtn->url="sound2.png";
  imgbtn->img=IMG_Load(imgbtn->url);
  if(imgbtn->img == NULL){
	printf("- Unable to load BAR SOUND  image %s \n",SDL_GetError());
	return;}
  imgbtn->pos_img_affiche.x=0;
  imgbtn->pos_img_affiche.y=0;
  imgbtn->pos_img_affiche.w=700;
  imgbtn->pos_img_affiche.h=400;
  imgbtn->pos_img_ecran.x=(SCREEN_W-780);
  imgbtn->pos_img_ecran.y=(SCREEN_H-460);
}

void initialiser_imageSOUNDBAR3(image *imgbtn)
{
  //Chargement de l'image
  imgbtn->url="sound3.png";
  imgbtn->img=IMG_Load(imgbtn->url);
  if(imgbtn->img == NULL){
	printf("- Unable to load BAR SOUND  image %s \n",SDL_GetError());
	return;}
  imgbtn->pos_img_affiche.x=0;
  imgbtn->pos_img_affiche.y=0;
  imgbtn->pos_img_affiche.w=700;
  imgbtn->pos_img_affiche.h=400;
  imgbtn->pos_img_ecran.x=(SCREEN_W-780);
  imgbtn->pos_img_ecran.y=(SCREEN_H-460);
}

void initialiser_imageSOUNDBAR4(image *imgbtn)
{
  //Chargement de l'image
  imgbtn->url="sound4.png";
  imgbtn->img=IMG_Load(imgbtn->url);
  if(imgbtn->img == NULL){
	printf("- Unable to load BAR SOUND  image %s \n",SDL_GetError());
	return;}
  imgbtn->pos_img_affiche.x=0;
  imgbtn->pos_img_affiche.y=0;
  imgbtn->pos_img_affiche.w=700;
  imgbtn->pos_img_affiche.h=400;
  imgbtn->pos_img_ecran.x=(SCREEN_W-780);
  imgbtn->pos_img_ecran.y=(SCREEN_H-460);
}

void initialiser_imageSOUNDBAR5(image *imgbtn)
{
  //Chargement de l'image
  imgbtn->url="sound5.png";
  imgbtn->img=IMG_Load(imgbtn->url);
  if(imgbtn->img == NULL){
	printf("- Unable to load BAR SOUND  image %s \n",SDL_GetError());
	return;}
  imgbtn->pos_img_affiche.x=0;
  imgbtn->pos_img_affiche.y=0;
  imgbtn->pos_img_affiche.w=700;
  imgbtn->pos_img_affiche.h=400;
  imgbtn->pos_img_ecran.x=(SCREEN_W-780);
  imgbtn->pos_img_ecran.y=(SCREEN_H-460);
}

void initialiser_imageQUITMORES(image *imgbtn)
{
  //Chargement de l'image
  imgbtn->url="quitS.png";
  imgbtn->img=IMG_Load(imgbtn->url);
  if(imgbtn->img == NULL){
	printf("- Unable to load QUIT MORE image %s \n",SDL_GetError());
	return;}
  imgbtn->pos_img_affiche.x=0;
  imgbtn->pos_img_affiche.y=0;
  imgbtn->pos_img_affiche.w=237;
  imgbtn->pos_img_affiche.h=80;
  imgbtn->pos_img_ecran.x=(SCREEN_W/2)-270;
  imgbtn->pos_img_ecran.y=(2*(SCREEN_H/3))+20;
}

void initialiser_imageQUITSETTINGS(image *imgbtn)
{
  //Chargement de l'image
  imgbtn->url="quit.png";
  imgbtn->img=IMG_Load(imgbtn->url);
  if(imgbtn->img == NULL){
	printf("- Unable to load QUIT SETTINGS image %s \n",SDL_GetError());
	return;}
  imgbtn->pos_img_affiche.x=0;
  imgbtn->pos_img_affiche.y=0;
  imgbtn->pos_img_affiche.w=237;
  imgbtn->pos_img_affiche.h=80;
  imgbtn->pos_img_ecran.x=(SCREEN_W/2)-100;
  imgbtn->pos_img_ecran.y=(2*(SCREEN_H/3))-15;
}

void initialiser_imageQUITSETTINGSS(image *imgbtn)
{
  //Chargement de l'image
  imgbtn->url="quitS.png";
  imgbtn->img=IMG_Load(imgbtn->url);
  if(imgbtn->img == NULL){
	printf("- Unable to load QUIT SETTINGS S image %s \n",SDL_GetError());
	return;}
  imgbtn->pos_img_affiche.x=0;
  imgbtn->pos_img_affiche.y=0;
  imgbtn->pos_img_affiche.w=237;
  imgbtn->pos_img_affiche.h=80;
  imgbtn->pos_img_ecran.x=(SCREEN_W/2)-100;
  imgbtn->pos_img_ecran.y=(2*(SCREEN_H/3))-15;
}
void initialiser_imageMORE(image *imgbtn)
{
  //Chargement de l'image
  imgbtn->url="more.png";
  imgbtn->img=IMG_Load(imgbtn->url);
  if(imgbtn->img == NULL){
	printf("- Unable to load MORE image %s \n",SDL_GetError());
	return;}
  imgbtn->pos_img_affiche.x=0;
  imgbtn->pos_img_affiche.y=0;
  imgbtn->pos_img_affiche.w=237;
  imgbtn->pos_img_affiche.h=80;
  imgbtn->pos_img_ecran.x=(SCREEN_W-287);
  imgbtn->pos_img_ecran.y=(SCREEN_H-100);
}

void initialiser_imageMORES(image *imgbtn)
{
  //Chargement de l'image
  imgbtn->url="moreS.png";
  imgbtn->img=IMG_Load(imgbtn->url);
  if(imgbtn->img == NULL){
	printf("- Unable to load MORES image %s \n",SDL_GetError());
	return;}
  imgbtn->pos_img_affiche.x=0;
  imgbtn->pos_img_affiche.y=0;
  imgbtn->pos_img_affiche.w=237;
  imgbtn->pos_img_affiche.h=80;
  imgbtn->pos_img_ecran.x=(SCREEN_W-287);
  imgbtn->pos_img_ecran.y=(SCREEN_H-100);
}

void initialiser_imageBOUTON1(image *imgbtn)
{
  //Chargement de l'image
  imgbtn->url="play.png";
  imgbtn->img=IMG_Load(imgbtn->url);
  if(imgbtn->img == NULL){
	printf("- Unable to load BT1 image %s \n",SDL_GetError());
	return;}
  imgbtn->pos_img_affiche.x=0;
  imgbtn->pos_img_affiche.y=0;
  imgbtn->pos_img_affiche.w=237;
  imgbtn->pos_img_affiche.h=58;
  imgbtn->pos_img_ecran.x=(SCREEN_W/2)-100;
  imgbtn->pos_img_ecran.y=(SCREEN_H/2)+20;
}

void initialiser_imageBOUTON1S(image *imgbtn)
{
  //Chargement de l'image
  imgbtn->url="playS.png";
  imgbtn->img=IMG_Load(imgbtn->url);
  if(imgbtn->img == NULL){
	printf("- Unable to load BT1S image %s \n",SDL_GetError());
	return;}
  imgbtn->pos_img_affiche.x=0;
  imgbtn->pos_img_affiche.y=0;
  imgbtn->pos_img_affiche.w=237;
  imgbtn->pos_img_affiche.h=58;
  imgbtn->pos_img_ecran.x=(SCREEN_W/2)-105;
  imgbtn->pos_img_ecran.y=(SCREEN_H/2)+25;
}

void initialiser_imageBOUTON2(image *imgbtn)
{
  //Chargement de l'image
  imgbtn->url="settings.png";
  imgbtn->img=IMG_Load(imgbtn->url);
  if(imgbtn->img == NULL){
	printf("- Unable to load BT2 image %s \n",SDL_GetError());
	return;}
  imgbtn->pos_img_affiche.x=0;
  imgbtn->pos_img_affiche.y=0;
  imgbtn->pos_img_affiche.w=237;
  imgbtn->pos_img_affiche.h=58;
  imgbtn->pos_img_ecran.x=(SCREEN_W/2)-97;
  imgbtn->pos_img_ecran.y=2*(SCREEN_H/3);
}

void initialiser_imageBOUTON2S(image *imgbtn)
{
  //Chargement de l'image
  imgbtn->url="settingsS.png";
  imgbtn->img=IMG_Load(imgbtn->url);
  if(imgbtn->img == NULL){
	printf("- Unable to load BT2S image %s \n",SDL_GetError());
	return;}
  imgbtn->pos_img_affiche.x=0;
  imgbtn->pos_img_affiche.y=0;
  imgbtn->pos_img_affiche.w=237;
  imgbtn->pos_img_affiche.h=58;
  imgbtn->pos_img_ecran.x=(SCREEN_W/2)-97;
  imgbtn->pos_img_ecran.y=2*(SCREEN_H/3);
}
 
 void initialiser_imageBOUTON3(image *imgbtn)
{
  //Chargement de l'image
  imgbtn->url="quit.png";
  imgbtn->img=IMG_Load(imgbtn->url);
  if(imgbtn->img == NULL){
	printf("- Unable to load BTN3 image %s \n",SDL_GetError());
	return;}
  imgbtn->pos_img_affiche.x=0;
  imgbtn->pos_img_affiche.y=0;
  imgbtn->pos_img_affiche.w=237;
  imgbtn->pos_img_affiche.h=58;
  imgbtn->pos_img_ecran.x=(SCREEN_W/2)-100;
  imgbtn->pos_img_ecran.y=(2*(SCREEN_H/3))+75;
}

void initialiser_imageBOUTON3S(image *imgbtn)
{
  //Chargement de l'image
  imgbtn->url="quitS.png";
  imgbtn->img=IMG_Load(imgbtn->url);
  if(imgbtn->img == NULL){
	printf("- Unable to load BTN3S image %s \n",SDL_GetError());
	return;}
  imgbtn->pos_img_affiche.x=0;
  imgbtn->pos_img_affiche.y=0;
  imgbtn->pos_img_affiche.w=237;
  imgbtn->pos_img_affiche.h=58;
  imgbtn->pos_img_ecran.x=(SCREEN_W/2)-110;
  imgbtn->pos_img_ecran.y=(2*(SCREEN_H/3))+75;
}
void afficher_imageBMP(SDL_Surface *screen,image imge)
{
  //Coller et Afficher l'image du back dans screen
  SDL_BlitSurface(imge.img,&imge.pos_img_affiche,screen,&imge.pos_img_ecran);
}

void afficher_imageSETTINGSBG(SDL_Surface *screen,image imge)
{
  //Coller et Afficher l'image du SETTINGS dans screen
  SDL_BlitSurface(imge.img,&imge.pos_img_affiche,screen,&imge.pos_img_ecran);
}

void afficher_imageMOREBG(SDL_Surface *screen,image imge)
{
  //Coller et Afficher l'image du SETTINGS dans screen
  SDL_BlitSurface(imge.img,&imge.pos_img_affiche,screen,&imge.pos_img_ecran);
}

void afficher_imageQUITMORE(SDL_Surface *screen,image imge)
{
  //Coller et Afficher l'image du SETTINGS dans screen
  SDL_BlitSurface(imge.img,&imge.pos_img_affiche,screen,&imge.pos_img_ecran);
}
void afficher_imageQUITMORES(SDL_Surface *screen,image imge)
{
  //Coller et Afficher l'image du SETTINGS dans screen
  SDL_BlitSurface(imge.img,&imge.pos_img_affiche,screen,&imge.pos_img_ecran);
}


void afficher_imageQUITSETTINGS(SDL_Surface *screen,image imge)
{
  //Coller et Afficher l'image du back dans screen
  SDL_BlitSurface(imge.img,&imge.pos_img_affiche,screen,&imge.pos_img_ecran);
}

void afficher_imageQUITSETTINGSS(SDL_Surface *screen,image imge)
{
  //Coller et Afficher l'image du back dans screen
  SDL_BlitSurface(imge.img,&imge.pos_img_affiche,screen,&imge.pos_img_ecran);
}

void afficher_imageMORE(SDL_Surface *screen,image imge)
{
  SDL_BlitSurface(imge.img,&imge.pos_img_affiche,screen,&imge.pos_img_ecran);
}

void afficher_imageMORES(SDL_Surface *screen,image imge)
{
  SDL_BlitSurface(imge.img,&imge.pos_img_affiche,screen,&imge.pos_img_ecran);
}


void afficher_imageBTN1(SDL_Surface *screen,image imge)
{
  //Coller et Afficher l'image du btn play dans screen
  SDL_BlitSurface(imge.img,NULL,screen,&imge.pos_img_ecran);
}

void afficher_imageBTN1S(SDL_Surface *screen,image imge)
{
  //Coller et Afficher l'image du btn play dans screen
  SDL_BlitSurface(imge.img,NULL,screen,&imge.pos_img_ecran);
}

void afficher_imageBTN2(SDL_Surface *screen,image imge)
{
  //Coller et Afficher l'image du btn settings dans screen
  SDL_BlitSurface(imge.img,NULL,screen,&imge.pos_img_ecran);
}

void afficher_imageBTN2S(SDL_Surface *screen,image imge)
{
  //Coller et Afficher l'image du btn settings dans screen
  SDL_BlitSurface(imge.img,NULL,screen,&imge.pos_img_ecran);
}
void afficher_imageBTN3(SDL_Surface *screen,image imge)
{
  //Coller et Afficher l'image du btn quit dans screen
  SDL_BlitSurface(imge.img,NULL,screen,&imge.pos_img_ecran);
}

void afficher_imageBTN3S(SDL_Surface *screen,image imge)
{
  //Coller et Afficher l'image du btn quit dans screen
  SDL_BlitSurface(imge.img,NULL,screen,&imge.pos_img_ecran);
}

void afficher_imageSOUNDBAR0(SDL_Surface *screen,image imge)
{
  //Coller et Afficher l'image du btn quit dans screen
  SDL_BlitSurface(imge.img,NULL,screen,&imge.pos_img_ecran);
}

void afficher_imageSOUNDBAR1(SDL_Surface *screen,image imge)
{
  //Coller et Afficher l'image du btn quit dans screen
  SDL_BlitSurface(imge.img,NULL,screen,&imge.pos_img_ecran);
}

void afficher_imageSOUNDBAR2(SDL_Surface *screen,image imge)
{
  //Coller et Afficher l'image du btn quit dans screen
  SDL_BlitSurface(imge.img,NULL,screen,&imge.pos_img_ecran);
}

void afficher_imageSOUNDBAR3(SDL_Surface *screen,image imge)
{
  //Coller et Afficher l'image du btn quit dans screen
  SDL_BlitSurface(imge.img,NULL,screen,&imge.pos_img_ecran);
}

void afficher_imageSOUNDBAR4(SDL_Surface *screen,image imge)
{
  //Coller et Afficher l'image du btn quit dans screen
  SDL_BlitSurface(imge.img,NULL,screen,&imge.pos_img_ecran);
}

void afficher_imageSOUNDBAR5(SDL_Surface *screen,image imge)
{
  //Coller et Afficher l'image du btn quit dans screen
  SDL_BlitSurface(imge.img,NULL,screen,&imge.pos_img_ecran);
}
void afficher_imageSOUNDPLUS(SDL_Surface *screen,image imge)
{
  //Coller et Afficher l'image du btn PLUS dans screen
  SDL_BlitSurface(imge.img,NULL,screen,&imge.pos_img_ecran);
}
void afficher_imageSOUNDMINUS(SDL_Surface *screen,image imge)
{
  //Coller et Afficher l'image du btn MINUS dans screen
  SDL_BlitSurface(imge.img,NULL,screen,&imge.pos_img_ecran);
}


void liberer_image(image imge)
{
  SDL_FreeSurface(imge.img);
}

/***********TRAITEMENT MUSIQUE*********/

void initialiser_audio(Mix_Music *music,int audio)
{
  if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1){
	printf("%s",SDL_GetError());
  }
  music=Mix_LoadMUS("CODEX Installer Music.mp3");//chargement de la musique
  Mix_PlayMusic(music,-1);//Jouer la musique
  Mix_VolumeMusic(MIX_MAX_VOLUME/audio);
}

void off_audio(Mix_Music *music)
{
  if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1){
	printf("%s",SDL_GetError());
  }
  music=Mix_LoadMUS("CODEX Installer Music.mp3");//chargement de la musique
  Mix_PlayMusic(music,-1);//Jouer la musique
  Mix_VolumeMusic(0);
}

void liberer_musique(Mix_Music *music)
{
  Mix_FreeMusic(music);
}

void initialiser_audiobref(Mix_Chunk *music)
{
  Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
  music=Mix_LoadWAV("simple.wav");
  Mix_PlayChannel(-1,music,0);
  if(music==NULL) printf("%s",SDL_GetError());
}

void liberer_musiquebref(Mix_Chunk *music)
{
  Mix_FreeChunk(music);
}

/*************TRAITEMENT TEXTE*************/
void initialiser_texte(texte *txte)
{
  TTF_Init();//Initialiser SDL_ttf
  txte->police=TTF_OpenFont("ka1.ttf",100);
  //Chargement d'une police et initialiser la taille
  txte->color_txt.r=255;
  txte->color_txt.g=200;
  txte->color_txt.b=0;
  txte->pos_txt.x=120;
  txte->pos_txt.y=150;
}

void afficher_texte(SDL_Surface *screen,texte txte)
{
  txte.txt=TTF_RenderText_Blended(txte.police,"FUTURISMO",txte.color_txt);
  //Ecrire le message "Bienvenue"
  SDL_BlitSurface(txte.txt,NULL,screen,&txte.pos_txt);//Coller la surface
}

void liberer_texte(texte txte)
{
  TTF_CloseFont(txte.police);//Fermer la police
  TTF_Quit();//Arreter la SDL_ttf
}
//============================================================================================================================ENNEMI
void initialiser_imageBACKGAME(image *imge)
{
 	imge->url="Desktop/FUTURISMO/back.png";
	imge->img=IMG_Load(imge->url);
	if(imge->img==NULL)
	  {
            printf("unable to load background image %s \n",SDL_GetError());
	    return ;

	   }
	imge->pos_img_ecran.x=0;
	imge->pos_img_ecran.y=0;
        
}
//===============================================================================================
void afficher_imageBACKGAME(SDL_Surface *screen,image imge)
{
	SDL_BlitSurface(imge.img,NULL,screen,&imge.pos_img_ecran);
}
//===============================================================================================
void liberer_back(image imge)
{
        SDL_FreeSurface(imge.img);
}
//===============================================================================================
void initialiser_ennemi(Ennemi* imag)
{
      imag->url="Desktop/FUTURISMO/spritesheet.png";
      imag->img=IMG_Load(imag->url);
      
      if(imag->img == NULL)
	  {
            printf("unable to load ENEMY SPRITE image %s \n",SDL_GetError());
	    return ;

	   }
      imag->pos.y=510;
      imag->pos.x=500;
      imag->pos_max=850;
      imag->pos_min=560;
      imag->sprite.x=0;
      imag->sprite.y=0;
      imag->sprite.w=90;
      imag->sprite.h=141;
}
//================================================================================================
void afficher_ennemi(SDL_Surface *screen,Ennemi imag)
{
     SDL_BlitSurface(imag.img,&imag.sprite,screen,&imag.pos);

}
//================================================================================================
void liberer_image_ennemi(Ennemi imag)
{
        SDL_FreeSurface(imag.img);
}
//================================================================================================
void move(Ennemi *e)
{
     if(e->pos.x<e->pos_min)
     {
	e->dir=0;
     }
     if(e->pos.x>e->pos_max)
     {
	e->dir=1;
     }
     switch(e->dir)
     {
          case 0:
               e->pos.x+=10;
               break;
          case 1:
               e->pos.x-=10;
               break;
     }
}
//================================================================================================
void animer_ennemi(Ennemi * e)
{
    e->sprite.x = e->sprite.x + 90;
    if(e->sprite.x >= 360)
    {
        e->sprite.x=0;
    }
    SDL_Delay(200);
    
}
//================================================================================================
int CollisionBB(SDL_Rect ep,SDL_Rect pp)
{
	int col=0;
	if((pp.x + pp.w < ep.x)||(pp.x >  ep.x + ep.w)||(pp.y + pp.h < ep.y)||(pp.y>ep.y + ep.h))
	{
	    col=0;
	}
	else 
	{
	     if((pp.x + pp.w == ep.x)||(pp.x ==  ep.x + ep.w)||(pp.y + pp.h == ep.y)||(pp.y == ep.y + ep.h))
	     {
	        col=1;
	     }
	}
        return col;
}

