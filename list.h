#ifndef LIST_H
#define LIST_H
#include <stdlib.h>
#include <stdio.h>
#define SIZE 997
struct tree;
struct list;
struct listToHash;

typedef struct tree tree;
typedef struct list list;
typedef struct listToHash listToHash;

struct list {
    list *prev, *next;
    tree *node;
};

struct listToHash {
    listToHash *prev, *next;
    int number;
    list *node;
};

void init();

void push(int k, list *ptr);

list *take(int k);

void insertOnEnd(list *New, list *List);

void removeList(list *l);

void removeListToHash(listToHash *l);

void removeHashtable();

void insertListBetween(list *NewList, list *Prev, list *Next);

#endif /* LIST_H */
