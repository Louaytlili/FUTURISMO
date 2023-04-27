#include "player.h"
#include "input.h"

int main()
{
    int done = 1, run = 0,run1=0;
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    SDL_Surface *screen, *bg,*score,*hp;

    screen = SDL_SetVideoMode(1920, 1080, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("perso", NULL); //window title

    SDL_Rect bgPos,scorePos,hpPos;
    bgPos.x = 0;
    bgPos.y = 0;

    scorePos.x = 850;
    scorePos.y = 30;

    hpPos.h = 100;
    hpPos.w = 500;
    //----------------------------------------------------------------------------------------------------------------------
    Hero hero,hero1;
    Input I,I1;
    init_hero(&hero);
    init_input(&I);
    init_hero(&hero1);
    init_input(&I1);

    TTF_Init();
    TTF_Font *police;
    police = TTF_OpenFont("DelaGothicOne-Regular.ttf", 30);
    SDL_Color black={0, 0, 0};
    char direction[50];
    char scoreT[50];


    //----------------------------------------------------------------------------------------------------------------------

    bg = IMG_Load("bg.jpg");
    hp = IMG_Load("hp_bars/hp_5.png");

    SDL_BlitSurface(bg, NULL, screen, &bgPos);
    SDL_Flip(screen);

    SDL_Event event;

    SDL_EnableKeyRepeat(1, 0);

    while (done)
    {
        

        if (hero.currentMode == 0 || hero.currentMode == 2 || hero.currentMode == 4 || hero.currentMode == 6)
        {
            strcpy(direction, "right");
        }
        else
        {
            strcpy(direction, "left");
        }

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:

                done = 0;
                break;

            case SDL_KEYDOWN:

                switch (event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    done = 0;
                    break;

                case SDLK_SPACE:
                    I.jump = 1;
                    
                    break;
                    
                case SDLK_v:
                    I.acc=1;
                    break;

                case SDLK_RIGHT:
                    I.right = 1;
                    hero.currentMode = 2;
                    
                    break;

                case SDLK_LEFT:
                    I.left = 1;
                    hero.currentMode = 3;
                    
                    break;

                case SDLK_x:
                    I.attack = 1;
                    if (strcmp(direction, "right") == 0)
                    {
                        hero.currentMode = 6;
                    }
                    else
                    {
                        hero.currentMode = 7;
                    }
                    
                    break;
                    
                    
                    
                ///deuxieme joueur    
                    
                    
                    case SDLK_z:
                    I1.jump = 1;
                    
                    break;
                    
                case SDLK_a:
                    I1.acc=1;
                    break;

                case SDLK_d:
                    I1.right = 1;
                    hero1.currentMode = 2;
                    
                    
                    break;

                case SDLK_q:
                    I1.left = 1;
                    hero1.currentMode = 3;
                   
                    
                    break;

                case SDLK_e:
                    I1.attack = 1;
                    if (strcmp(direction, "right") == 0)
                    {
                        hero1.currentMode = 6;
                    }
                    else
                    {
                        hero1.currentMode = 7;
                    }
                    
                    break;
                }
                break;


               /// KEY UP


            case SDL_KEYUP:
                switch (event.key.keysym.sym)
                {
                case SDLK_SPACE:
                    I.jump = 0;
                    if (I.right == 1)
                    {
                        hero.currentMode = 2;
                    }
                    else if (I.left == 1)
                    {
                        hero.currentMode = 3;
                    }
                    else
                    {
                        if (strcmp(direction, "right") == 0)
                        {
                            hero.currentMode = 0;
                        }
                        else
                        {
                            hero.currentMode = 1;
                        }
                    }

                    break;
  
                case SDLK_RIGHT:
                    I.right = 0;
                    hero.currentMode = 0;
                    run = 0;
                    break;
                     case SDLK_v:
                    I.acc=0;
                    break;

                case SDLK_LEFT:
                    I.left = 0;
                    hero.currentMode = 1;
                    run = 0;

                    break;
                case SDLK_x:
                    I.attack = 0;
                    if (strcmp(direction, "right") == 0)
                    {
                        hero.currentMode = 0;
                    }
                    else
                    {
                        hero.currentMode = 1;
                    }
                    break;
                    
                    
                    // deuxieme joueur
                    
                    
                    case SDLK_z:
                    I1.jump = 0;
                    if (I1.right == 1)
                    {
                        hero1.currentMode = 2;
                    }
                    else if (I1.left == 1)
                    {
                        hero1.currentMode = 3;
                    }
                    else
                    {
                        if (strcmp(direction, "right") == 0)
                        {
                            hero1.currentMode = 0;
                        }
                        else
                        {
                            hero1.currentMode = 1;
                        }
                    }

                    break;
  
                case SDLK_d:
                    I1.right = 0;
                    hero1.currentMode = 0;
                    run1 = 0;

                    break;
                     case SDLK_a:
                    I1.acc=0;
                    break;

                case SDLK_q:
                    I1.left = 0;
                    hero1.currentMode = 1;
                    run1 = 0;

                    break;
                case SDLK_e:
                    I1.attack = 0;
                    if (strcmp(direction, "right") == 0)
                    {
                        hero1.currentMode = 0;
                    }
                    else
                    {
                        hero1.currentMode = 1;
                    }
                    break;
                }
                break;
            }

        }

        //affichage score et bg
        sprintf(scoreT, "Score : %d", hero.score);
        score = TTF_RenderText_Blended(police,scoreT, black);
        SDL_BlitSurface(bg, NULL, screen, &bgPos);
        SDL_BlitSurface(hp, &hpPos, screen, &hpPos);
        SDL_BlitSurface(score, NULL, screen, &scorePos);

        //run left and right
        leftAndRightHeroMvtR(&hero, I);
        leftAndRightHeroMvt(&hero, I);
        //run left and right
        //jump movement
        jumpHeroMvt(&hero, I, &run);
        //jump movement
        idleAnimation(&hero);
        runAnimation(&hero);
        jumpAnimation(&hero, screen, bg, bgPos,hp,hpPos,score,scorePos ,run);
        attackAnimation(&hero, screen, bg, bgPos,hp,hpPos,score,scorePos);
        afficher_Hero(&hero, screen);

        //second player
        leftAndRightHeroMvtR(&hero1, I1);
        leftAndRightHeroMvt(&hero1, I1);
        //run left and right
        //jump movement
        jumpHeroMvt(&hero1, I1, &run1);
        //jump movement
        idleAnimation(&hero1);
        runAnimation(&hero1);
        jumpAnimation(&hero1, screen, bg, bgPos,hp,hpPos,score,scorePos ,run1);
        attackAnimation(&hero1, screen, bg, bgPos,hp,hpPos,score,scorePos);
        afficher_Hero(&hero1, screen);
      
        SDL_Flip(screen);
        SDL_Delay(20);
    }

    SDL_FreeSurface(screen);
    SDL_Quit();
    return 0;
}
