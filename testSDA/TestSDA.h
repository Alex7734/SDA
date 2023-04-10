#ifndef COPACI_TESTSDA_H
#define COPACI_TESTSDA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

typedef struct Plane {
    char name[15];
    int year;
    float maxSpeed;
} Plane;

typedef struct HashNode {
    Plane plane;
    struct HashNode *next;
} HashNode;

typedef struct HashMap {
    HashNode *table[TABLE_SIZE];
} HashMap;


HashMap *createHashMap();
int hash(char *name);
int addPlane(HashMap *map, Plane plane);
Plane *searchPlane(HashMap *map, char *name);
void showPlanes(HashMap *map);

#endif //COPACI_TESTSDA_H
