#ifndef REVISE_LGY_H
#define REVISE_LGY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define CAPACITY 30
#define BUF 30

typedef struct Movie {
    char title[BUF];
    char genre[BUF];
    char director[BUF];
    float rating;
    char distributor[BUF];
} Movie;

void init();
int selectNo();
void createMovie();
void reviseMovie();
void readMovie();
void deleteMovie();
void sortRating();
void allDeleteMovie();
void searchTitle();
void loadFile();
void saveFile();

#endif