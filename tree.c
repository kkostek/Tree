#include "list.h"
#include "tree.h"

struct tree {
    int number;
    list *sons;
};

typedef struct tree tree;

int nodeCounter = 0;
int nodeNumber = 0;

int nextNode() {
    ++nodeNumber;
    return (nodeCounter++);
}

void OK() {
    printf("OK\n");
}

tree *createNew() {
    tree *New = malloc(sizeof *New);
    New->number = nextNode();
    list *leftGuard = malloc(sizeof *leftGuard);
    list *rightGuard = malloc(sizeof *rightGuard);
    leftGuard->prev = NULL;
    leftGuard->next = rightGuard;
    leftGuard->node = NULL;
    rightGuard->next = NULL;
    rightGuard->node = NULL;
    rightGuard->prev = leftGuard;
    list *NewSons = malloc(sizeof *NewSons);
    NewSons->prev = leftGuard;
    NewSons->next = rightGuard;
    New->sons = NewSons;
    return New;
}

void rootBirth() {
    init();
    tree *root = createNew();
    list *rootList = malloc(sizeof *rootList);
    rootList->node = root;
    rootList->prev = NULL;
    rootList->next = NULL;

    push(0, rootList);
}

void addNode(int k) {

    list *kNodePointer = take(k);
    tree *kNode = kNodePointer->node;
    tree *New = createNew();
    list *newSon = malloc(sizeof *newSon);
    newSon->node = New;
    insertOnEnd(newSon, kNode->sons);
    push(New->number, newSon);
    OK();
}

void rightmostChild(int k) {

    list *kNodePointer = take(k);
    tree *kNode = kNodePointer->node;
    if(kNode->sons->next->prev->node != NULL) {
        printf("%d\n", (kNode->sons->next->prev->node->number));
    }
    else {
        printf("-1\n");
    }
}

void deleteNode(int k) {

    list *kNodePointer = take(k);
    tree *kNode = kNodePointer->node;
    list *PrevNodePointer = kNodePointer->prev;
    list *NextNodePointer = kNodePointer->next;
    insertListBetween(kNode->sons, PrevNodePointer, NextNodePointer);
    --nodeNumber;
    free(kNode->sons->prev);
    free(kNode->sons->next);
    free(kNode->sons);
    free(kNode);
    free(kNodePointer);
    OK();
}

void recursiveDelete(list *NodeList) {
    tree *Node = NodeList->node;
    list *l = Node->sons->prev;
    while(l != NULL) {
        list *lPrev = l;
        l = l->next;
        if(lPrev->node != NULL) {
            recursiveDelete(lPrev);
        }
    }
    l = Node->sons->prev;
    removeList(l);
    free(Node->sons);
    free(Node);
    list *NodeListPrev = NodeList->prev;
    list *NodeListNext = NodeList->next;
    if (NodeListNext != NULL) {
        NodeListNext->prev = NodeListPrev;
    }
    if (NodeListPrev != NULL) {
        NodeListPrev->next = NodeListNext;
    }
    free(NodeList);
    --nodeNumber;
}

void deleteSubtree(int k) {
    list *kNodePointer = take(k);
    recursiveDelete(kNodePointer);
}

void splitNode(int k, int w) {
    tree *New = createNew();
    list *kNodePointer = take(k);
    list *wNodePointer = take(w);
    tree *kNode = kNodePointer->node;
    if (wNodePointer->next != kNode->sons->next) {
        New->sons->prev->next = wNodePointer->next;
        New->sons->prev->next->prev = New->sons->prev;
        New->sons->next->prev = kNode->sons->next->prev;
        New->sons->next->prev->next = New->sons->next;
    }
    list *newSon = malloc(sizeof *newSon);
    newSon->node = New;
    kNode->sons->next->prev = wNodePointer;
    wNodePointer->next = kNode->sons->next;
    insertOnEnd(newSon, kNode->sons);
    push(New->number, newSon);
    OK();
}

void delHashtable() {
    removeHashtable();
}

void Nodes() {
    fprintf(stderr, "NODES: %d\n", nodeNumber);
}
