#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H
#include <stdbool.h>

typedef struct node Node;
typedef struct list List;
List* createList();
bool isEmpty(List* list);
void printList(List* list);
Node* atPos(List* list, int index);
void push(List* list, int num);
int indexOf(List* list, Node* node);
void search(List* list, int num);
void erase(List* list, int index);
void insert(List* list, int num);
void max(List* list);
void min(List* list);
void pop(List* list);
void listSize(List* list);
void testNullConj(List* list);
void Union(List* listA, List* listB);
void Intersection(List* listA, List* listB);
void equalConj(List* listA, List* listB);
void difference(List* listA, List* listB);

#endif
