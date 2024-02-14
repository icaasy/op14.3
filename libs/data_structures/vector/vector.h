#ifndef LAB_VECTOR_H
#define LAB_VECTOR_H

# include <stdint.h>
# include <stdbool.h>

typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;

vector createVector(size_t capacity);

void reserve(vector *v, size_t newCapacity);

void clear(vector *v);

void shrinkToFit(vector *v);

void deleteVector(vector *v);

#endif //LAB_VECTOR_H
