#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

#define BUF 30

typedef struct Node {
    char title[BUF];
    char genre[BUF];
    char director[BUF];
    float rating;
    char distributor[BUF];
    struct Node* Next;
} Node;

void inputData(Node* _NewNode);
Node* CreateNode();
void InsertNodeAfter(Node** _Head, size_t* NodeCnt);
Node* GetNodeAt(Node* _Head, int _Location);
void DeleteNode(Node* _Head, size_t* _NodeCnt);
void DisplayNode(Node* _Head, size_t _NodeCnt);
void AllDeleteNode(Node* _Head, size_t* _NodeCnt);

#endif