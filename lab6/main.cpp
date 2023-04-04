#include <stdio.h>
#include <stdlib.h>
#include "HashTable.h"

int main() {
    HASH_TABLE hash;
    initHashTable(&hash);

    hashInsert(&hash, 10);
    hashInsert(&hash, 111);
    hashInsert(&hash, 80);
    hashInsert(&hash, 300);
    hashInsert(&hash, 95);
    hashInsert(&hash, 32);
    hashInsert(&hash, 75);


    printf("%d is %s found\n", 10, hashSearch(&hash, 10) ? "" : "not ");
    hashDelete(&hash, 10);
    printf("%d is %s found\n", 10, hashSearch(&hash, 10) ? "" : "not ");
    printf("%d is %s found\n", 111, hashSearch(&hash, 111) ? "" : "not ");

    return 0;
}