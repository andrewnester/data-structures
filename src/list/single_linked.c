#include <stdlib.h>
#include "single_linked.h"


bool single_linked_list_is_empty(SingleLinkedList list) {
    return list.head == NULL;
}

void single_linked_list_push_front(SingleLinkedList *list, int value, int *error) {
    SingleLinkedListNode *node = (SingleLinkedListNode *)malloc(sizeof(struct SingleLinkedListNode));
    if (node == NULL) {
        *error = 1;
        return;
    }

    node->value = value;
    node->next = list->head;
    list->head = node;
    if (list->tail == NULL) {
        list->tail = list->head;
    }
}

int single_linked_list_top_front(SingleLinkedList *list, int *error) {
    if (list->head == NULL) {
        *error = 1;
        return -1;
    }

    return list->head->value;
}

int single_linked_list_pop_front(SingleLinkedList *list, int *error) {
    if (list->head == NULL) {
        *error = 1;
        return -1;
    }

    SingleLinkedListNode *node = list->head;
    list->head = list->head->next;
    if (list->head == NULL) {
        list->tail = NULL;
    }

    int value = node->value;
    free(node);
    return value;
}

void single_linked_list_push_back(SingleLinkedList *list, int value, int *error) {
    SingleLinkedListNode *node = (SingleLinkedListNode *)malloc(sizeof(struct SingleLinkedListNode));
    if (node == NULL) {
        *error = 1;
        return;
    }

    node->value = value;
    node->next = NULL;
    if (list->tail != NULL) {
        list->tail->next = node;
    }
    list->tail = node;
    if (list->head == NULL) {
        list->head = list->tail;
    }
}

int single_linked_list_top_back(SingleLinkedList *list, int *error) {
    if (list->tail == NULL) {
        *error = 1;
        return -1;
    }

    return list->tail->value;
}

int single_linked_list_pop_back(SingleLinkedList *list, int *error) {
    if (list->tail == NULL) {
        *error = 1;
        return -1;
    }

    SingleLinkedListNode *node = list->tail;
    if (list->head != list->tail) {
        SingleLinkedListNode *n = list->head;
        while (n->next != list->tail) {
            n = n->next;
        }
        n->next = NULL;
        list->tail = n;
    } else {
        list->head = NULL;
        list->tail = NULL;
    }
    int value = node->value;
    free(node);
    return value;
}

SingleLinkedListNode *single_linked_list_find(SingleLinkedList list, int value) {
    SingleLinkedListNode *n = list.head;
    while (n != NULL) {
        if (n->value == value) {
            return n;
        }
        n = n->next;
    }
    return NULL;
}

void single_linked_list_remove(SingleLinkedList *list, int value, int *error) {
    SingleLinkedListNode *n = list->head;
    SingleLinkedListNode *prev = NULL;

    while (n != NULL) {
        if (n->value != value) {
            prev = n;
            n = n->next;
            continue;
        }

        if (prev != NULL) {
            prev->next = n->next;
        } else {
            list->head = n->next;
        }

        if (list->head == NULL) {
            list->tail = NULL;
        }
        free(n);
        return;
    }
    *error = 1;
}

void single_linked_list_add_before(SingleLinkedList *list, int before, int value, int *error) {
    SingleLinkedListNode *n = list->head;
    while (n->next != NULL) {
        if (n->next->value == before) {
            SingleLinkedListNode *new_node = (SingleLinkedListNode *)malloc(sizeof(struct SingleLinkedListNode));
            if (new_node == NULL) {
                *error = -1;
                return;
            }
            new_node->value = value;
            new_node->next = n->next;
            n->next = new_node;
            return;
        }
        n = n->next;
    }
    *error = 1;
}