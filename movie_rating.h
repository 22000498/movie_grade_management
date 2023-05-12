#ifndef MOVIE_RATING_H
#define MOVIE_RATING_H

#include "Single_Linked_List.h"
#include <string.h>
#include <stdbool.h>

void readLine(char _str[], int _buf, FILE* _fp);
void reviseData(Node* _Head);
void searchTitle(Node* _Head);
void loadDataFromFile(Node** _Head, size_t* _NodeCnt);
void saveDataToFile(Node* _Head);
int selectNo();

#endif