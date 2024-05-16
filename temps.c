#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "temps.h" // Include your header file

void initialiser_temps(temps *t)
{
    t->texte = NULL; // surface li bech nblitiwha (forme mm:ss)
    t->score = NULL;
    t->s = 0;
    t->position.x = 500;
    t->position.y = 50;
    t->police = NULL;
    t->police = TTF_OpenFont("outils/avocado.ttf", 40);
    if (t->police == NULL)
    {
        printf("error loading font \n ");
    }
    t->color.r = 255;
    t->color.g = 0;
    t->color.b = 0;

    strcpy(t->entree, "");
    (t->secondesEcoulees) = 0;
    time(&(t->t1)); // temps du debut
}

void afficher_temps(temps *t, SDL_Surface *ecran)
{
    SDL_Rect pos_score;
    char sscore[100];
    pos_score.x = 800;
    pos_score.y = 50;

    time(&(t->t2)); // temps actuel

    t->secondesEcoulees = t->t2 - t->t1;

    t->min = ((t->secondesEcoulees / 60) % 60);
    t->sec = ((t->secondesEcoulees) % 60);

    sprintf(t->entree, "%02d:%02d", t->min, t->sec); // "%d:%d",t->min,t->sec resultat : entree="02:30"

    t->texte = TTF_RenderText_Blended(t->police, t->entree, t->color);

    SDL_BlitSurface(t->texte, NULL, ecran, &(t->position)); /* Blit du temps */

    t->s = (t->sec * 10 + t->min * 20);
    sprintf(sscore, "%03d", t->s);

    t->score = TTF_RenderText_Blended(t->police, sscore, t->color);

    SDL_BlitSurface(t->score, NULL, ecran, &pos_score); /* Blit du score */

    // Display HP
    SDL_Rect pos_hp;
    char hp_text[100];
    pos_hp.x = 1000;
    pos_hp.y = 50;

    // Assuming hp is an integer variable representing health points
    int hp = 100; // Example HP value, replace with your actual HP value
    sprintf(hp_text, "HP: %d", hp);

    SDL_Surface *hp_surface = TTF_RenderText_Blended(t->police, hp_text, t->color);
    SDL_BlitSurface(hp_surface, NULL, ecran, &pos_hp);
    SDL_FreeSurface(hp_surface);
}

void free_temps(temps *t)
{
    SDL_FreeSurface(t->texte);
    SDL_FreeSurface(t->score);
    TTF_CloseFont(t->police);
}

