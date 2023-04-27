#ifndef player_H_INCLUDED
#define player_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "input.h"

typedef struct
{
    SDL_Surface *allMvt;
    SDL_Rect heroPos;
    SDL_Rect rects[80];

    int frame;
    float xStep, yStep;
    int score;
    float velocity, speed;
    int currentMode;

} Hero;

void setrects(SDL_Rect *crop);
void init_hero(Hero *h);
void afficher_Hero(Hero *h, SDL_Surface *screen);
void idleAnimation(Hero *h);
void runAnimation(Hero *h);
void jumpAnimation(Hero *h, SDL_Surface *screen, SDL_Surface *bg, SDL_Rect bgPos,SDL_Surface *hp, SDL_Rect hpPos, SDL_Surface *score, SDL_Rect scorePos, int run);
void attackAnimation(Hero *h, SDL_Surface *screen, SDL_Surface *bg, SDL_Rect bgPos, SDL_Surface *hp, SDL_Rect hpPos, SDL_Surface *score, SDL_Rect scorePos);
void leftAndRightHeroMvt(Hero *hero, Input I);
void leftAndRightHeroMvtR(Hero *hero, Input I);
void jumpHeroMvt(Hero *hero, Input I, int *run);

#endif