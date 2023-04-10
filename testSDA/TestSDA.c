#include "TestSDA.h"


HashMap *createHashMap() {
    HashMap *map = (HashMap*) malloc(sizeof(HashMap));
    for (int i = 0; i < TABLE_SIZE; i++) {
        map->table[i] = NULL;
    }
    return map;
}

int hash(char *name) {
    int hashValue = 0;
    for (int i = 0; i < strlen(name); i++) {
        hashValue = hashValue * 31 + name[i];
    }
    return hashValue % TABLE_SIZE;
}

int addPlane(HashMap *map, Plane plane) {
    int index = hash(plane.name);
    HashNode *node = map->table[index];
    while (node != NULL) {
        if (strcmp(node->plane.name, plane.name) == 0) {
            return 0;
        }
        node = node->next;
    }
    HashNode *newNode = (HashNode*) malloc(sizeof(HashNode));
    newNode->plane = plane;
    newNode->next = map->table[index];
    map->table[index] = newNode;
    return 1;
}

Plane *searchPlane(HashMap *map, char *name) {
    int index = hash(name);
    HashNode *node = map->table[index];
    while (node != NULL) {
        if (strcmp(node->plane.name, name) == 0) {
            return &(node->plane);
        }
        node = node->next;
    }
    return NULL;
}

void showPlanes(HashMap *map) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        HashNode *node = map->table[i];
        while (node != NULL) {
            printf("%s (%d) - Max Speed: %.2f\n", node->plane.name, node->plane.year, node->plane.maxSpeed);
            node = node->next;
        }
    }
}
