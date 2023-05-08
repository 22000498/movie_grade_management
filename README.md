## Demo1 : MRM CRUD Program with SLL

```C
typedef struct Node {
  Field Data;
  struct Node *NextNode;
} Node;

typedef struct List {
  Node *Head;
  Node *Tail;
  Node *Curr;
} List;
```
