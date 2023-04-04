#include <stdio.h>
#include <stdlib.h>
#define M 7 //dimensiunea tabelei de dispersie

typedef struct node{
    int val;
    struct node *next;
}NodeT;

int hFunction(int key){
    return key%M;
}

void insert(NodeT* hTable[M], int key){
    
}


NodeT* search(NodeT* hTable[M], int key){
    return NULL;
}


void deleteKey(NodeT* hTable[M], int key){

}

//afisarea tuturor elmentelor din tebela de dispersie
void showAll(NodeT* hTable[M]){
    int i;
    for(i = 0; i < M; i++)
    {
        printf(" %d :",i);
        //verificam daca la slotul i am adaugat ceva
        if(hTable[i] != NULL)
        {

            NodeT *p;
            p = hTable[i];
            while (p != NULL)
            {
                printf(" %d ",p->val);
                p = p->next;
            }
        }
        printf("\n");
    }
    printf("\n");
}


int main(){

    //initializare
    NodeT* hTable[M];
    for(int i = 0; i < M; i++){
        hTable[i] = NULL;
    }

    //test inserare
    int vals[] = {36, 18, 6, 43, 72, 10, 5, 15};
    for(int i=0; i<sizeof(vals)/sizeof(int); i++)
        insert(hTable, vals[i]);
    showAll(hTable);

    // 0:
    // 1: 15 43 36
    // 2: 72
    // 3: 10
    // 4: 18
    // 5: 5
    // 6: 6

    //test stergere
    int todel[] = {43, 36, 10, 61, -5};
    for(int i=0; i<sizeof(todel)/sizeof(int); i++)
        deleteKey(hTable, todel[i]);
    showAll(hTable);

    // 0:
    // 1: 15
    // 2: 72
    // 3:
    // 4: 18
    // 5: 5
    // 6: 6

    return 0;
}
