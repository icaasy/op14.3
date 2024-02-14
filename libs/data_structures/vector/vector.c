#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

vector createVector(size_t capacity) {
    int *data = (int*) malloc(capacity * sizeof(int));
    if (data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    return (vector) {data, 0, capacity};
}

void reserve(vector *v, size_t newCapacity) {
    int *data = (int*) realloc(v, newCapacity * sizeof(int));
    if (data == NULL) {
        v->data = NULL;
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    newCapacity = v->capacity;

    if (newCapacity < v->capacity) {
        v->size = newCapacity;
    }
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    v->capacity = v->size;
}

void deleteVector(vector *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}