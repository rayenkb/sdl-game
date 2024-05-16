#include "temps.h"
#include "enemy.h"
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
  t->color.r = 255 ; 
  t->color.g = 255 ; 
  t->color.b = 255 ; 

  strcpy(t->entree, "");
  (t->secondesEcoulees) = 0;
  time(&(t->t1)); // temps du debut
}

void afficher_temps(temps *t, SDL_Surface *ecran, SDL_Rect heroPos, ennemi *e)
{ 
    SDL_Rect pos_score;
    char sscore[100];
    int scoreScaleFactor = 2;

    pos_score.x = 800;
    pos_score.y = 50;

    // Get current time
    time(&(t->t2));

    t->secondesEcoulees = t->t2 - t->t1;

    // Calculate elapsed minutes and seconds
    t->min = ((t->secondesEcoulees / 60) % 60);
    t->sec = ((t->secondesEcoulees) % 60);

    // Format the elapsed time as a string
    sprintf(t->entree, "%02d:%02d", t->min, t->sec);

    // Render the time as text
    t->texte = TTF_RenderText_Blended(t->police, t->entree, t->color);

    // Blit the time surface onto the screen
    SDL_BlitSurface(t->texte, NULL, ecran, &(t->position));

    // Calculate the score based on elapsed time with scaling
    t->s = (t->sec / scoreScaleFactor) * 10 + (t->min * 600);

    // Format the score as a string
    sprintf(sscore, "%02d", t->s); 

    // Render the score as text
    t->score = TTF_RenderText_Blended(t->police, sscore, t->color);

    // Blit the score surface onto the screen
    SDL_BlitSurface(t->score, NULL, ecran, &pos_score);

    if (checkCollisionPlayerEnnemi(heroPos, e->posScreen)) {
        // Player killed the enemy, increase score
        t->s += 100;
        sprintf(sscore, "%02d", t->s); // Update the score string
        SDL_FreeSurface(t->score); // Free the previous score surface
        t->score = TTF_RenderText_Blended(t->police, sscore, t->color); // Render updated score
    }
}


void free_temps(temps *t)
{ 
 SDL_FreeSurface(t->texte);
  SDL_FreeSurface(t->sscore);
  TTF_CloseFont(t->police);
}
