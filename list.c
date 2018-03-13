#include "list.h"
#include <stddef.h>
listToHash *hashtable[SIZE];

int hashCode(int kk) {
    long long k = kk;
    return ((2 * k * k + 10 * k + 3) % SIZE);
}

void init() {
    for (int i = 0; i < SIZE; i++) {
        listToHash *l = malloc(sizeof *l);
        l->next = NULL;
        l->prev = NULL;
        l->number = -1;
        hashtable[i] = l;
    }
}

void removeList(list *l) {
    while (l != NULL) {
        list *prev = l;
        l = l->next;
        free(prev);
    }
}

void removeListToHash(listToHash *l) {
    while (l != NULL) {
        listToHash *prev = l;
        l = l->next;
        free(prev);
    }
}

void removeHashtable() {
    for(int i = 0; i < SIZE; i++) {
        removeListToHash(hashtable[i]);
    }
}

void push(int k, list *ptr) {
    listToHash *New = malloc(sizeof *New);
    New->node = ptr;
    New->prev = NULL;
    New->number = k;
    listToHash *l = hashtable[hashCode(k)];
    New->next = l;
    l->prev = New;
    hashtable[hashCode(k)] = New;
}

list *take(int k) {
    listToHash *l = hashtable[hashCode(k)];
    while (l->next != NULL) {
        if (l->number == k) {
           return l->node;
        }
        l = l->next;
    }
    return NULL;
}

void insertOnEnd(list *New, list *List) {
    New->next = List->next;
    list *LastOne = List->next->prev;
    LastOne->next = New;
    New->prev = LastOne;
    List->next->prev = New;
}

void insertListBetween(list *NewList, list *Prev, list *Next) {
    if (NewList->prev->next != NewList->next) {
       list *FirstSon = NewList->prev->next;
       list *LastSon = NewList->next->prev;
       FirstSon->prev = Prev;
       LastSon->next = Next;
       Prev->next = FirstSon;
       Next->prev = LastSon;
    }
    else  {
        Prev->next = Next;
        Next->prev = Prev;
    }
}
