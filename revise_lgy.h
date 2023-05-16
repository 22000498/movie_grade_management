#ifndef REVISE_LGY_H
#define REVISE_LGY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUF_MAX 256
#define BUF 30

typedef struct Movie {
    char title[BUF];
    char genre[BUF];
    char director[BUF];
    float rating;
    char distributor[BUF];
} Movie;

int selectNo();
int readStr(FILE* _fp, char* _str, int _buf);
void createMovie(Movie** _movie, size_t* _movieCnt);
void reviseMovie(Movie* _movie);
void readMovie(Movie* _movie, size_t _movieCnt);
void deleteMovie(Movie* _movie, size_t* _movieCnt, size_t dNo);
void allDeleteMovie(Movie** _movie, size_t* _movieCnt);
void searchTitle(Movie** _movie, size_t _movieCnt);
void loadDataFromFile(Movie** _movie, size_t* _movieCnt);
void saveDataToFile(Movie** _movie, size_t _movieCnt);
void Swap(Movie* _movie, int _sour, int _dest);
void Sort(Movie* _movie, int _a, int _b);

#endif