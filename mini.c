#include"collisionparfaite.h"

SDL_Color getpixel(SDL_Surface *pSurface,int x,int y)
{	
	SDL_Color color;
	Uint32 col=0;
	char* pPosition=(char* ) pSurface->pixels;
	pPosition+= (pSurface->pitch * y);
	pPosition+= (pSurface->format->BytesPerPixel *x);
	memcpy(&col ,pPosition ,pSurface->format->BytesPerPixel);
	SDL_GetRGB(col,pSurface->format, &color.r, &color.g, &color.b);
	return (color);
}
int  collisionparfaite(SDL_Surface *psurface,personne p)
{	
	int tabx[7],taby[7],i;
	SDL_Color color1,color;
	color1.r = 0;
	color1.g = 0;
	color1.b = 0;
	tabx[0]=p.pos_perso.x;
	tabx[1]=(p.pos_perso.x)+((p.pos_perso.w)/2);
	tabx[2]=(p.pos_perso.x+p.pos_perso.w);
	tabx[3]=p.pos_perso.x;
	tabx[4]=p.pos_perso.x;
	tabx[5]=(p.pos_perso.x)+((p.pos_perso.w)/2);
	tabx[6]=(p.pos_perso.x+p.pos_perso.w);
	tabx[7]=(p.pos_perso.x+p.pos_perso.w);
	taby[0]=p.pos_perso.y;
	taby[1]=p.pos_perso.y;
	taby[2]=p.pos_perso.y;
	taby[3]=(p.pos_perso.y)+((p.pos_perso.h)/2);
	taby[4]=(p.pos_perso.y+p.pos_perso.h);
	taby[5]=(p.pos_perso.y+p.pos_perso.h);
	taby[6]=(p.pos_perso.y+p.pos_perso.h);
	taby[7]=(p.pos_perso.y)+((p.pos_perso.h)/2);
	
	for(i=0;i<8;i++)
	{
	color=getpixel(psurface,tabx[i],taby[i]);
	if(color.r==color1.r && color.b==color1.b && color.g==color1.g)
	{
		return i; 

	}
	}
	return 10;
	
}	

void collision(SDL_Surface *psurface,personne *p)
{	int i;
	i=collisionparfaite(psurface,*p);

	switch (i)
	{
		case 0 :p->pos_perso.y=p->pos_perso.y+20;
			break;
		case 1 :p->pos_perso.y=p->pos_perso.y+20;
			 break;
		case 2 :p->pos_perso.y=p->pos_perso.y+20;
			break;
		case 3 :p->pos_perso.x=p->pos_perso.x+20;
			break;
	        case 4 :p->pos_perso.y=p->pos_perso.y-20;
			break;
		case 5 :p->pos_perso.y=p->pos_perso.y-50; 
			break;
		case 6 :p->pos_perso.y=p->pos_perso.y-30; 
			break;
		case 7 :p->pos_perso.x=p->pos_perso.x-20;
			break;
		

	}
}

#include "map.h"

void initialiser_map (map *m,SDL_Surface *screen)
{
	m->map=IMG_Load("minimap.bmp");
	m->pos_map.x =500;
	m->pos_map.y = 100;
	m->mini_perso=SDL_CreateRGBSurface(SDL_HWSURFACE|SDL_DOUBLEBUF,10,10,32,0,0,0,0);
	SDL_FillRect(m->mini_perso,NULL,SDL_MapRGB(screen->format,0,255,0)); 
	m->perso_pos_map.x=0;
	m->perso_pos_map.y=0;

}


void perso_map(map *m,personne *p)
{
	m->perso_pos_map.x=p->pos_perso.x/12+m->pos_map.x;
	m->perso_pos_map.y=p->pos_perso.y/12+10+m->pos_map.y;
}



void affiche_map(map m , SDL_Surface *screen)
{
	SDL_BlitSurface(m.map, NULL, screen,&m.pos_map);
	SDL_BlitSurface(m.mini_perso, NULL, screen,&m.perso_pos_map);
}

#include "pres.h"

void initialiserperso(personne *p)
{	
	p->image_p=IMG_Load("hero.bmp");;
	p->pos_perso.x=0;
	p->pos_perso.y=0;
	p->pos_perso.w=100;
	p->pos_perso.h=100;
}

void afficher_perso(SDL_Surface *screen,personne p)
{	
	SDL_BlitSurface(p.image_p,NULL,screen,&p.pos_perso);
}

void deplacer_perso(personne *p,SDL_Event event)
{	
	SDL_PollEvent(&event);
         switch(event.type)
            {
                case SDL_KEYDOWN:
                       switch(event.key.keysym.sym)
                        {
                        
                        case SDLK_UP:
                            p->pos_perso.y=p->pos_perso.y-10;
                            break;
                        case SDLK_DOWN:
                            p->pos_perso.y=p->pos_perso.y+10;
                            break;
                        case SDLK_RIGHT:
                            p->pos_perso.x=p->pos_perso.x+10;
                            break;
                        case SDLK_LEFT:
                            p->pos_perso.x=p->pos_perso.x-10;
                            break;
                        }
                 break;
             }
}
void free_perso(personne p)
{
	SDL_FreeSurface(p.image_p);
}
#include "time.h"

void Timer(int *tempsdebut)//t5rjli kdch 3ndi min seconde mili bdit nl3eb 
{
    
   if( SDL_GetTicks() - *tempsdebut >= 1000 )//kain el wkt b3ed ili bdit fih -wakt bdit fih 3mlt seconde rw tempsdebut hot fih wakt el jdid 
    {
        *tempsdebut = SDL_GetTicks() ;
      
      
    }
  
}

void inittemps(Time *t)
{   int test; 
	t->tempsdebut=SDL_GetTicks();//thseblk kdch el wakt ili bdit fih execution 
	t->mm=0;
	t->ss=0;
	test=initTexttime(&t->temps);
}
void inittempsenig(Time *t)
{   int test; 
	t->tempsdebut=0;
	t->mm=0;
	t->ss=0;
	test=initTexttimeenig(&t->temps);
}
int initTexttime(Text* T)
{ int testload;
    T->couleurTxt.r = 255; 
    T->couleurTxt.g = 255; 
    T->couleurTxt.b = 255;

    strcpy(T->txt,"");
    T->positionText.x = 550;
    T->positionText.y = 20; 
    testload=loadFonttime(T,"angelina.TTF");//fct 3mltha bich tlodili el font trj3li zero kain loadfont sar mrigl  
    T->textSurface=NULL;
    return testload;   
}
int initTexttimeenig(Text* T)
{ int testload;
    T->couleurTxt.r = 255; 
    T->couleurTxt.g = 255; 
    T->couleurTxt.b = 255;

    strcpy(T->txt, "");
    T->positionText.x = 0;
    T->positionText.y = 0; 
    testload=loadFonttime(T,"angelina.TTF");
    T->textSurface=NULL;
    return testload;   
}
int loadFonttime(Text* T, char* path)
{
    if(TTF_Init() == -1) {
        printf("Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
        return -1;
    }
    T->police= TTF_OpenFont(path,30);//pathn hoa esm l font o 60 l taile 
    if (T->police == NULL) {
        printf("Unable to load Font: %s\n", SDL_GetError());
        return (-1);
    }
    return (0);
}

void update_time(Time* T)
{   int ts;
    Timer(&T->tempsdebut);//raj3tli kdch min milliseconde
    ts=T->tempsdebut/1000;//rdithom b seconde 
    T->mm=ts/60;//kdch min min
    T->ss=ts % 60;//kdch min seconde ts mode 60
    if(T->mm<10&&T->ss<10)
       sprintf(T->temps.txt,"*** time :0%d:0%d  ***",T->mm,T->ss);
    else if(T->mm<10&&T->ss>10)
        sprintf(T->temps.txt,"*** time :0%d:%d  ***",T->mm,T->ss);
    else if(T->mm>10&&T->ss<10)
          sprintf(T->temps.txt,"*** time :%d:0%d  ***",T->mm,T->ss);//s y3ni chnktb fi variable chaine 
    else
         sprintf(T->temps.txt,"*** time :%d:%d  ***",T->mm,T->ss); 
  
    T->temps.textSurface=TTF_RenderText_Solid(T->temps.police,T->temps.txt,T->temps.couleurTxt);//ttfrender tekho l police o txt o couleur taa l text eli besh taficchiih
}
void update_timeenig(Time* T)
{   int ts;
    
    Timer(&T->tempsdebut);
    ts=T->tempsdebut/1000;
    T->mm=ts/ 60;
    T->ss=ts % 60;
    if(T->mm<10&&T->ss<10)//idhkain minute et seconde asgher min 10 
       sprintf(T->temps.txt,"*** time :0%d:0%d  ***",T->mm,T->ss);
    else if(T->mm<10&&T->ss>10)
        sprintf(T->temps.txt,"*** time :0%d:%d  ***",T->mm,T->ss);
    else if(T->mm>10&&T->ss<10)
          sprintf(T->temps.txt,"*** time :%d:0%d  ***",T->mm,T->ss);
    else
         sprintf(T->temps.txt,"*** time :%d:%d  ***",T->mm,T->ss); 
    T->temps.textSurface=TTF_RenderText_Solid(T->temps.police,T->temps.txt,T->temps.couleurTxt);//ttfrender tekho l police o txt o couleur taa l text eli besh taficchiih
}
void displaytime(Time T,SDL_Surface *screen)
{
    
     
     SDL_BlitSurface(T.temps.textSurface,NULL,screen,&(T.temps.positionText));

}

void freeTexttime(Text T)
{
    TTF_CloseFont(T.police); 
    TTF_Quit();    
}

