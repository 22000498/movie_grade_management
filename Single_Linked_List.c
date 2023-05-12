#include "Single_Linked_List.h"
#include "movie_rating.h"

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