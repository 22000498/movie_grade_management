#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define gets(s) gets_s(s)
#define BUF 30

typedef struct Node {
    char title[BUF];
    char genre[BUF];
    char director[BUF];
    float rating;
    char distributor[BUF];
    struct Node* Next;
} Node;

void readLine(char _str[], int _buf, FILE *_fp){
	int ch, len = 0;
    getchar();
	while ((ch = fgetc(_fp)) != '\n' && ch != EOF)
		if (len < _buf - 1)
			_str[len++] = ch;
	_str[len] = '\0';
}

void inputData(Node *_NewNode){
    printf("\n*=* =* =* =* Movie *= *= *= *=*\n");
    printf("영화 : ");
    readLine(_NewNode->title, BUF, stdin);
    printf("장르 : ");
    readLine(_NewNode->genre, BUF, stdin);
    printf("감독 : ");
    readLine(_NewNode->director, BUF, stdin);
    printf("평점 : ");
    scanf("%f", &_NewNode->rating);
    printf("배급사 : ");
    readLine(_NewNode->distributor, BUF, stdin);
    printf("\n*=* =* =* =* *=*=* *= *= *= *=*\n");
}

Node* CreateNode(){
    Node* NewNode = (Node*)malloc(sizeof(Node));
    if(NewNode == NULL){
        printf("🚨 CreateNode Error : malloc failed.\n");
        exit(1);
    }
    inputData(NewNode);
    NewNode->Next = NULL;
    return NewNode;
}

void InsertNodeAfter(Node** _Head, size_t* _NodeCnt){
    Node* NewNode = CreateNode();
    if(*_Head == NULL){
        *_Head = NewNode;
    } else {
        Node* CurNode = *_Head;
        while(CurNode->Next != NULL)
            CurNode = CurNode->Next;
        CurNode->Next = NewNode;
    }
    (*_NodeCnt)++;
    printf("✅ (%zu)InsertNodeAfter Success.\n", *_NodeCnt);
}

Node* GetNodeAt(Node* _Head, int _Location){
    Node* CurNode = _Head;
    while(CurNode != NULL && --_Location)
        CurNode = CurNode->Next;
    return CurNode;
}

void reviseData(Node* _Head){
    int no;
    printf("\nRevise(No.) : ");
    scanf("%d", &no);
    Node* RevNode = GetNodeAt(_Head, no);
    inputData(RevNode);
    printf("✅ (%d)reviseData Success.\n", no);
}

void DeleteNode(Node* _Head, size_t* _NodeCnt){
    int no;
    printf("\nDelete(No.) : ");
    scanf("%d", &no);
    Node* PreNode = GetNodeAt(_Head, no - 1);
    Node* DelNode = GetNodeAt(_Head, no);
    PreNode->Next = DelNode->Next;
    free(DelNode);
    (*_NodeCnt)--;
    printf("✅ (%d) DeleteNode Success.\n", no);
}

void DisplayNode(Node* _Head, size_t _NodeCnt){
    size_t i = 0;
    if(_Head == NULL){
        printf("🚨 DisplayNode Error : not data list.\n");
    } else {
        Node* CurNode = _Head;
        printf("\n*=* =* =* =* Movie *= *= *= *=*\n");
        for(; i < _NodeCnt; i++){
            printf("%s %s %s %.1f %s\n", CurNode->title, CurNode->genre, CurNode->director, CurNode->rating, CurNode->distributor);
            CurNode = CurNode->Next;
        }
        printf("*=* =* =* =* *=*=* *= *= *= *=*\n");
    }
    printf("✅ (%zu)DisplayNode Success.\n", i);
}

void AllDeleteNode(Node* _Head, size_t* _NodeCnt){
    Node* DelNode = _Head;
    while(_Head != NULL){
        _Head = _Head->Next;
        free(DelNode);
        DelNode = _Head;
        (*_NodeCnt)--;
    }
    _Head = NULL;
    DelNode = NULL;
    printf("✅ (%zu)AllDeleteNode Success.\n", *_NodeCnt);
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