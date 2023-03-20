#ifndef LAB3_DOUBLELINKEDLISTS_H
#define LAB3_DOUBLELINKEDLISTS_H

typedef struct node_type{
    int key;
    struct node_type *next;
    struct node_type *prev;
} Node;

typedef struct list_header{
    struct node_type *first;
    struct node_type *last;
} listHeader;

Node* createNode(int);
void insertFirst(listHeader*, int);
void insertLast(listHeader*, int);
void insertAfterKey(listHeader*, int);
void printForword(listHeader*);
void printBackword(listHeader*);
void deleteFirst(listHeader*)

#endif //LAB3_DOUBLELINKEDLISTS_H
