#include "minimap.h"
#include "background.h"


void init_map(minimap *m)
{
    m->map = IMG_Load("outils/minimaplevel2.png");
    m->minijoueur = IMG_Load("outils/joueurmini.png");
    m->positionmap.x = 0;
    m->positionmap.y = 0;
    m->positionminijoueur.x = 0;
    m->positionminijoueur.y = 0;
}
void init_map2(minimap *m)
{
    m->map = IMG_Load("image_level/minimaplevel1.png");
    m->minijoueur = IMG_Load("outils/joueurmini.png");
    m->positionmap.x = 0;
    m->positionmap.y = 0;
    m->positionminijoueur.x = 0;
    m->positionminijoueur.y = 0;
}

void MAJMinimap(SDL_Rect posJoueur, minimap *m, SDL_Rect camera, int redimensionnement)
{
    SDL_Rect posJoueurABS;
    posJoueurABS.x = 0;
    posJoueurABS.y = 0;
    posJoueurABS.x = posJoueur.x ;
    posJoueurABS.y = posJoueur.y;
    m->positionminijoueur.x = (posJoueurABS.x * redimensionnement / 100)-10 ;
    m->positionminijoueur.y = (posJoueurABS.y * 35 / 100)+20  ;
}
void MAJMinimap2(SDL_Rect posJoueur, minimap *m, SDL_Rect camera, int redimensionnement)
{
    SDL_Rect posJoueurABS;
    posJoueurABS.x = 0;
    posJoueurABS.y = 0;
    posJoueurABS.x = posJoueur.x ;
    posJoueurABS.y = posJoueur.y;
    m->positionminijoueur.x = (posJoueurABS.x * 33 / 100)-10 ;
    m->positionminijoueur.y = (posJoueurABS.y * 35 / 100)+20  ;
}

void afficherminimap(minimap m,background b, SDL_Surface *screen)
{
    SDL_Rect pos_aff;
    pos_aff.x=b.pos_background2.x *20 /100;
    pos_aff.y=0;
    pos_aff.w=500;
    pos_aff.h=250;

    SDL_BlitSurface(m.map, &pos_aff, screen, &m.positionmap);
    SDL_BlitSurface(m.minijoueur, NULL, screen, &m.positionminijoueur);
}
void afficherminimap2(minimap m,background b, SDL_Surface *screen)
{
    SDL_Rect pos_aff;
    pos_aff.x=b.pos_background2.x *33 /100;
    pos_aff.y=0;
    pos_aff.w=500;
    pos_aff.h=250;

    SDL_BlitSurface(m.map, &pos_aff, screen, &m.positionmap);
    SDL_BlitSurface(m.minijoueur, NULL, screen, &m.positionminijoueur);
}