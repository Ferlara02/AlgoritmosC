/*
  @file ranking.c
  @brief Implements store structure and methods
*/
#include <stdlib.h>
#include "ranking.h"
#include <string.h>

static const int NUMBER_OF_RANKING_VARS = 6;

Ranking ranking_from_file(FILE *file) {

  Ranking ranking;
  int a,b,c;
  char d[20], e[20];
  float f;
   

    
  /* se leyo correctamente? */
    int res = fscanf(file, "%d %d %d %19s %19s %f", &a, &b, &c, d, e, &f);
      
    if (res != NUMBER_OF_RANKING_VARS) {
        fprintf(stderr, "Invalid format in ranking line.\n");
        exit(EXIT_FAILURE);
    }
    if (a < 1 || b < 1 || f < 0.0) {
        fprintf(stderr, "Invalid format in ranking position or points.\n");
        exit(EXIT_FAILURE);
    }


    /* COMPLETAR: campos de ranking */
    ranking.pos = a;
    ranking.pos_prev = b;
    ranking.diff = c;
    strcpy(ranking.name, d);
    strcpy(ranking.team, e);
    ranking.points = f;
  
    return ranking;
}

float  total_track_points_per_team(RankingTable a, char *team_name) {
  float sum = 0;
  for (int i = 0; i < NO_PLAYERS; i++)
  {
    if(strcmp(a[i][1].team, team_name) == 0) {
      sum += a[i][1].points;
    }
  }
  
  return sum;
} 
