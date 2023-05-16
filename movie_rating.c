#include "movie_rating.h"

void readLine(char _str[], int _buf, FILE *_fp){
    rewind(stdin);
    int ch, len = 0;
    while ((ch = fgetc(_fp)) != '\n' && ch != EOF)
	if (len < _buf - 1)
	    _str[len++] = ch;
	_str[len] = '\0';
}

void reviseData(Node* _Head){
    int no;
    printf("\nRevise(No.) : ");
    scanf("%d", &no);
    Node* RevNode = GetNodeAt(_Head, no);
    inputData(RevNode);
    printf("✅ (%d)reviseData Success.\n", no);
}

void searchTitle(Node* _Head){
    char title[BUF];
    printf("\nSearch(Title) : ");
    readLine(title, BUF, stdin);
    Node* CurNode = _Head;
    while(CurNode != NULL){
        if(strcmp(title, CurNode->title) == 0) break;
        CurNode = CurNode->Next;
    }
    printf("\n*=* =* =* =* Movie *= *= *= *=*\n");
    printf("%s %s %s %.1f %s\n", CurNode->title, CurNode->genre, CurNode->director, CurNode->rating, CurNode->distributor);
    printf("*=* =* =* =* *=*=* *= *= *= *=*\n");
}

void loadDataFromFile(Node** _Head, size_t* _NodeCnt){
    FILE* fp = fopen("movie.txt", "rt");
    if(fp == NULL){
        printf("🚨 saveDataToFile Error : fopen failed.\n");
        exit(1);
    }
    while(true){
        Node* tmpNode = (Node*)malloc(sizeof(Node));
        tmpNode->Next = NULL;
        if(fscanf(fp, "%s %s %s %f %s\n", tmpNode->title, tmpNode->genre, tmpNode->director, &tmpNode->rating, tmpNode->distributor) == 5){
            if(*_Head == NULL){
                *_Head = tmpNode;
            } else {
                Node* CurNode = *_Head;
                while(CurNode->Next != NULL)
                    CurNode = CurNode->Next;
                CurNode->Next = tmpNode;
            }
            (*_NodeCnt)++;
        } else {
            free(tmpNode);
            break;
        }
    }
    fclose(fp);
    printf("✅ (%zu)loadDataFromFile Success.\n", *_NodeCnt);
}

void saveDataToFile(Node* _Head){
    FILE* fp = fopen("movie.txt", "wt");
    if(fp == NULL){
        printf("🚨 saveDataToFile Error : fopen failed.\n");
        exit(1);
    }
    Node* CurNode = _Head;
    while(CurNode != NULL){
        fprintf(fp, "%s %s %s %.1f %s\n", CurNode->title, CurNode->genre, CurNode->director, CurNode->rating, CurNode->distributor);
        CurNode = CurNode->Next;
    }
    fclose(fp);
    printf("✅ saveDataToFile Success.\n");
}

int selectNo(){
    printf("\n= = = = = = * MRM * = = = = = =\n");
    printf("| 1. Create Movie data       |\n");
    printf("| 2. Revise Movie data       |\n");
    printf("| 3. Display Movie data list |\n");
    printf("| 4. Delete Movie data       |\n");
    printf("| 5. All Delete Movie data   |\n");
    printf("| 6. Search Movie title info |\n");
    printf("| 7. Save movie.txt file     |\n");
    printf("| 0. Exit                    |\n");
    printf("= = = = = = = = = = = = = = = =\n");
    int no;
    printf("No : ");
    scanf("%d", &no);
    return no;
}
