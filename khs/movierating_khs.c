#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crud_khs.h"
int main(void){
    Movie *s=malloc(sizeof(Movie));
    int menu;
    extern int count;
    loadData(s);
    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1){
            listMovie(s);
        }
        else if (menu == 2){
            createMovie(s);
        }
        else if (menu == 3){
            updateMovie(s);
        }
        else if (menu == 4){
            deleteMovie(s);
        }
        else if (menu == 5){
            saveData(s);
        }
        else if (menu == 6){
            searchMovie(s,count);
        }
        else if (menu == 7){
            sortMovie(s,count);
        }
    }
    printf("종료됨!\n");
    free(s);
    return 0;
}

