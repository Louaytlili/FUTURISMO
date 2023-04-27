#include "background.h"
#include "pres.h"
#include <SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>

void initBack2 (background *b)
{

b->imgback=IMG_Load("map.bmp");
b->posback2.x=0;
b->posback2.y=0;

b->camera2.x=0;
b->camera2.y=0;
b->camera2.w=SCREEN_W; 
b->camera2.h=SCREEN_H;

        b->son=Mix_LoadMUS("son.mp3"); 
        b->son1=Mix_LoadMUS("musique.mp3"); 
	b->image_flower=IMG_Load("flower.png");  
	b->pos_image_flower.x=500;
	b->pos_image_flower.y=100;
	b->single_flower.w=56;
	b->single_flower.h=107;
	b->single_flower.x=0;
	b->single_flower.y=0;
	b->flower_num=0;

}

void initbouton(background *b)
{

b->boutton= IMG_Load("boutton.png");
b->positionbotton.x =0;
b->positionbotton.y =550;
}
void affichebouton(background b,SDL_Surface *screen)
{

SDL_BlitSurface(b.boutton, NULL, screen, &b.positionbotton);
}

void afficheBack2(background b, SDL_Surface *ecran,Personne p)
{
 

if(p.pos_perso.x<513)
{
Mix_PlayMusic(b.son1, -1); 
}
else if(513<p.pos_perso.x<650)
{
Mix_PlayMusic(b.son, -1); 
}
SDL_BlitSurface(b.imgback,&b.camera2,ecran,&b.posback2);
displayFlower(b,ecran);

}


void scrolling (background *b,int direction)
{
 const int speed=1;
if (direction ==0){  


	b->camera2.x+= speed;
	
        }
else if (direction ==1){        


	b->camera2.x-=speed; 
	}

else if (direction ==2){


         b->camera2.y-= speed;
	}
else if (direction ==3){         


	 b->camera2.y+= speed;
	 }

}


void displayFlower(background b,SDL_Surface *ecran){
			
 		SDL_BlitSurface(b.image_flower,&(b.single_flower), ecran, &b.pos_image_flower);
}
void animerBackground(background *b){
		 	
	if (b->flower_num >=0 && b->flower_num <8) {
	b->single_flower.x=b->flower_num * b->single_flower.w;
	b->flower_num++;
	}
	
	if ( b->flower_num == 8) {
	b->single_flower.x=b->flower_num * b->single_flower.w;
	b->flower_num=0;
	}
 
	 
}

void sauvegarder(int score,char nomfichier[])
{
	FILE *f;
        int i=0;
	f=fopen(nomfichier, "a");
	if(f==NULL){
        printf("Erreur lors de l'ouverture d'un fichier");
	
       }
 	fprintf(f, "%d\n", score);
	fclose(f);
}

void meilleur (char nomfichier[],background *b)
{
TTF_Init();
int i=0;
FILE *f;
char text1[30];
char text2[30];
char text3[30];
      int tmp;
    int tab[50];
    f = fopen("test.txt", "r");

 if(f==NULL)
	{
        printf("Erreur lors de l'ouverture d'un fichier");
        }
while(fscanf(f,"%d\n",&tab[i])==1)
{
	i++;
}
for(int j=0;j<i;j++) 
 	{printf("score : %d\n", tab[j]);
}
    	fclose(f);


 for (int k=0 ; k < i-1; k++)
  {
    for (int j=0 ; j < i-k-1; j++)
    {
      
      if (tab[j] > tab[j+1]) 
      {
        tmp = tab[j];
        tab[j] = tab[j+1];
        tab[j+1] = tmp;
      }
    }
  }

for(int j=0;j<i;j++)
 	{printf(" tri score : %d\n", tab[j]);
}
printf("i est  %d\n",i);
sprintf(text1, "%d",tab[i-1]);
sprintf(text2, "%d",tab[i-2]);
sprintf(text3, "%d",tab[i-3]);

printf("text1 est  %s\n",text1);
printf("text2 est  %s\n",text2);
printf("text3 est  %s\n",text3);



	SDL_Color couleur = {0,0,0}; 
	SDL_Color couleur1 = {255,0,0}; 

	(*b).police = TTF_OpenFont("pol.ttf", 30);
 	b->reponses[0]=TTF_RenderText_Blended(b->police,text1, couleur); 
 	b->reponses[1]=TTF_RenderText_Blended(b->police,text2, couleur); 
 	b->reponses[2]=TTF_RenderText_Blended(b->police,text3, couleur); 
        b->reponses[3]=TTF_RenderText_Blended(b->police,"les 3 meilleurs scores:", couleur1); 
        b->pos_reponse1txt.x=50;
	b->pos_reponse1txt.y=300;
	b->pos_reponse2txt.x=50;
	b->pos_reponse2txt.y=400;
	b->pos_reponse3txt.x=50;
	b->pos_reponse3txt.y=500;
        b->pos_meilleurtxt.x=50;
        b->pos_meilleurtxt.y=200;
}
   

void afficher(background b,SDL_Surface *ecran)
{

 SDL_BlitSurface(b.reponses[0], NULL, ecran, &b.pos_reponse1txt);
 SDL_BlitSurface(b.reponses[1], NULL, ecran, &b.pos_reponse2txt);
 SDL_BlitSurface(b.reponses[2], NULL, ecran, &b.pos_reponse3txt);
 SDL_BlitSurface(b.reponses[3], NULL, ecran, &b.pos_meilleurtxt);
   SDL_Flip(ecran);
}


void affichageMeilleur(SDL_Surface *screen,background b)
{
    SDL_Surface *NGame = NULL;

    SDL_Rect positionNGame;

    SDL_Event event;

    int continuer = 1;

    NGame = IMG_Load("NewGame.jpg");

    positionNGame.x = 0;
    positionNGame.y = 0;
    while (continuer)
    {

        SDL_PollEvent(&event);

        switch (event.type)
        {
        case SDL_QUIT:
            continuer = 0;
            screen = SDL_SetVideoMode(1360,765, 32, SDL_HWSURFACE | SDL_DOUBLEBUF); 
            SDL_WM_SetCaption("Game Menu", NULL);
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                continuer = 0;
                screen = SDL_SetVideoMode(1360,765, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
                SDL_WM_SetCaption("Game Menu", NULL);
                break;
            }
            break;
        }
        SDL_BlitSurface(NGame, NULL, screen, &positionNGame);
       afficher(b,screen);
        SDL_Flip(screen);
    }
}











