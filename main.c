#include "movie_rating.h"

int main(void){
    printf("\n🎬 MRM Load.\n");
    Node* Head = NULL;
    size_t NodeCnt = 0;
    loadDataFromFile(&Head, &NodeCnt);
    bool exit = false;
    while(!exit){
        int no = selectNo();
        switch(no)
        {
        case 1:
            InsertNodeAfter(&Head, &NodeCnt);
            break;
        case 2:
            reviseData(Head);
            break;
        case 3:
            DisplayNode(Head, NodeCnt);
            break;
        case 4:
            DeleteNode(Head, &NodeCnt);
            break;
        case 5:
            AllDeleteNode(Head, &NodeCnt);
            break;
        case 6:
            searchTitle(Head);
            break;
        case 7:
            saveDataToFile(Head);
            break;
        case 0:
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