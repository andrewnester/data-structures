#include <stdlib.h>
#include "vector.h"

size_t size(vector v) {
    return v.size;
}

bool is_empty(vector v) {
    return v.size == 0;
}

int get(vector v, int i, int *error) {
    if (i >= v.size) {
        *error = 1;
        return 0;
    }
    return *(v.data + sizeof(int) * i);
}

vector init_vector() {
    void *ptr = malloc(sizeof(int) * INITIAL_CAPACITY);
    vector v = {.size=0, .capacity=INITIAL_CAPACITY, .data=ptr};
    return v;
}

void push_back(vector *v, int val, int *error) {
    if (v->size == v->capacity) {
        __resize(v, error);
        if (*error) {
            return;
        }
    }
    *(v->data + sizeof(int) * v->size) = val;
    v->size++;
}

void insert(vector *v, int index, int val, int *error) {
    if (index > v->size || index < 0) {
        *error = 1;
        return;
    }

    if (v->size == v->capacity) {
        __resize(v, error);
        if (*error) {
            return;
        }
    }
    for (size_t i = v->size-1; i >= index; i--) {
        *(v->data + (i + 1) * sizeof(int)) = *(v->data + i * sizeof(int));
    }
    *(v->data + index * sizeof(int)) = val;
    v->size++;
}

void remove(vector *v, int index, int *error) {
    if (index > v->size || index < 0) {
        *error = 1;
        return;
    }
    for (int i = index; i < v->size - 1; i++) {
        *(v->data + i * sizeof(int)) = *(v->data + (i+1) * sizeof(int));
    }
    v->size--;
}

void __resize(vector *v, int *error) {
    size_t new_capacity = v->capacity * 2;
    int* ptr = realloc(v->data, new_capacity * sizeof(int));
    if (ptr == NULL) {
        *error = 1;
        return;
    }
    v->data = ptr;
    v->capacity = new_capacity;
}