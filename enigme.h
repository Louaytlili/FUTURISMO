#define SCREEN_W 600  //ordh l ecran
#define SCREEN_H 400 //toul l ecran
typedef struct
{
	SDL_Surface *image[14];
	SDL_Rect position_background;
	SDL_Surface *image_enigme;
	SDL_Rect position_enigme;
	int reponse_correct;
	int current_frame;
	SDL_Surface *background_lose, *background_win;
	
}enigme;

void initialiser_audio(Mix_Music *music);
void initialiser_enigme(enigme *e);
void run_enigme(SDL_Surface *screen, enigme e);
void generer_enigme(enigme *e);
void afficher_enigme(SDL_Surface *screen , enigme e);
void animer_enigme(enigme *e);
int generate_random_number (int a,int b);



