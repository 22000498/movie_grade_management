#include "revise_lgy.h"

int main(void){
    printf("\n🎬 MRM Load.\n");
    init();
    bool exit = false;
    loadFile();
    while(!exit){
        int no = selectNo();
        switch(no)
        {
        case 1:
            createMovie();
            break;
        case 2:
            reviseMovie();
            break;
        case 3:
            readMovie();
            break;
        case 4:
            deleteMovie();
            break;
        case 5:
            sortRating();
            break;
        case 6:
            searchTitle();
            break;
        case 7:
            saveFile();
            break;
        case 0:
            allDeleteMovie();
            exit = true;
            break;
        default:
            printf("🚨 selectNo Wranning : %d not implement.\n", no);
            break;
        }
    }
    printf("\n🎬 MRM Exit.\n");
    return 0;
}