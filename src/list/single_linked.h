#ifndef DATA_STRUCTURES_SINGLE_LINKED_H
#define DATA_STRUCTURES_SINGLE_LINKED_H

#include <stdbool.h>

typedef struct SingleLinkedListNode {
    int value;
    struct SingleLinkedListNode *next;
} SingleLinkedListNode;

typedef struct SingleLinkedList {
    SingleLinkedListNode* head;
    SingleLinkedListNode* tail;
} SingleLinkedList;


bool single_linked_list_is_empty(SingleLinkedList list);
void single_linked_list_push_front(SingleLinkedList *list, int value, int *error);
int single_linked_list_top_front(SingleLinkedList *list, int *error);
int single_linked_list_pop_front(SingleLinkedList *list, int *error);

void single_linked_list_push_back(SingleLinkedList *list, int value, int *error);
int single_linked_list_top_back(SingleLinkedList *list, int *error);
int single_linked_list_pop_back(SingleLinkedList *list, int *error);

SingleLinkedListNode *single_linked_list_find(SingleLinkedList list, int value);
void single_linked_list_remove(SingleLinkedList *list, int value, int *error);
void single_linked_list_add_before(SingleLinkedList *list, int before, int value, int *error);

#endif