#include "revise_lgy.h"

int main(void){
    printf("\n🎬 MRM Load.\n");
    Movie *movie = NULL;
    size_t movieCnt = 0;
    bool exit = false;
    loadDataFromFile(&movie, &movieCnt);
    while(!exit){
        int no = selectNo();
        switch(no)
        {
        case 1:
            createMovie(&movie, &movieCnt);
            printf("✅ (%zu) createMovie Success.\n", movieCnt);
            break;
        case 2:
        {   int rNo;
            printf("\nRevise(No.) : ");
            scanf("%d", &rNo);
            if(rNo < 1 || rNo > movieCnt){
                printf("🚨 reviseMovie Error : No revise %d number.\n", rNo);
            } else {
                reviseMovie(&movie[rNo - 1]);
                printf("✅ (%d) reviseMovie Success.\n", rNo);
            }
            break;
        }
        case 3:
            readMovie(&movie, movieCnt);
            break;
        case 4:
            deleteMovie(&movie, &movieCnt);
            printf("✅ (%zu) deleteMovie Success.\n", movieCnt);
            break;
        case 5:
            Sort(movie, 0, movieCnt - 1);
            printf("✅ (%zu)Sort Success.\n", movieCnt);
            readMovie(&movie, movieCnt);
            break;
        case 6:    
            searchTitle(&movie, movieCnt);
            break;
        case 7:
            saveDataToFile(&movie, movieCnt);
            break;
        case 0:
            allDeleteMovie(&movie, &movieCnt);
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