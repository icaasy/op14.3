#include <stdio.h>
#include "libs/data_structures/bitset/bitset.h"
#include "libs/data_structures/array_set/unordered_array_set.h"
#include "libs/data_structures/array_set/ordered_array_set.h"
#include "libs/data_structures/vector/vector.h"
#include "libs/data_structures/vector/vectorVoid.h"


void test_createVector() {
    vector vec = createVector(5);

    assert(vec.capacity == 5);
    assert(vec.size == 0);
    assert(vec.data != NULL);

    deleteVector(&vec);
}

void test_reserve() {
    vector vec = createVector(5);
    reserve(&vec, 8);

    assert(vec.capacity == 8);
    assert(vec.size == 0);
    assert(vec.data != NULL);

    reserve(&vec, 3);

    assert(vec.capacity == 3);
    assert(vec.size == 0);
    assert(vec.data != NULL);

    pushBack(&vec, 1);
    pushBack(&vec, 2);
    pushBack(&vec, 3);

    reserve(&vec, 2);

    assert(vec.capacity == 2);
    assert(vec.size == 2);
    assert(vec.data != NULL);
}

void test_clear() {
    vector vec = createVector(5);

    pushBack(&vec, 1);
    pushBack(&vec, 2);
    pushBack(&vec, 3);

    assert(vec.capacity == 5);
    assert(vec.size == 3);
    assert(vec.data != NULL);

    clear(&vec);

    assert(vec.capacity == 5);
    assert(vec.size == 0);
    assert(vec.data != NULL);
}

void test_shrinkToFit() {
    vector vec = createVector(6);

    shrinkToFit(&vec);

    assert(vec.capacity == 0);
    assert(vec.size == 0);
    assert(vec.data != NULL);
}

void test_deleteVector() {
    vector vec = createVector(6);

    deleteVector(&vec);

    assert(vec.capacity == 0);
    assert(vec.size == 0);
    assert(vec.data == NULL);
}
//
bool test_isEmpty() {
    vector vec = createVector(6);

    bool res = isEmpty(&vec);

    assert(res);
}

bool test_isFull() {
    vector vec = createVector(6);

    bool res = isFull(&vec);

    assert(!res);
}

int test_getVectorValue() {
    vector vec = createVector(6);

    int x = 4;

    pushBack(&vec, 1);
    pushBack(&vec, 2);
    pushBack(&vec, x);

    int res = getVectorValue(&vec, 2);

    assert(res == x);
}

void test_pushBack_emptyVector() {
    vector vec = createVector(0);

    assert(vec.capacity == 0);
    assert(vec.size == 0);
    assert(vec.data != NULL);

    int x = 4;
    pushBack(&vec, x);

    assert(vec.capacity == 1);
    assert(vec.size == 1);
    assert(vec.data != NULL);

    assert(vec.data[0] == 4);
}

void test_pushBack_fullVector() {
    vector vec = createVector(2);

    assert(vec.capacity == 2);
    assert(vec.size == 0);
    assert(vec.data != NULL);

    int x = 4;
    pushBack(&vec, 1);
    pushBack(&vec, x);

    assert(vec.capacity == 2);
    assert(vec.size == 2);
    assert(vec.data != NULL);

    assert(vec.data[1] == x);

    int y = 5;
    pushBack(&vec, y);

    assert(vec.capacity == 4);
    assert(vec.size == 3);
    assert(vec.data != NULL);

    assert(vec.data[2] == y);
}

void test_popBack() {
    vector vec = createVector(0);
    pushBack(&vec, 10);

    assert(vec.size == 1);

    popBack(&vec);

    assert(vec.size == 0);
    assert(vec.capacity == 1);
}

void test_atVector_notEmptyVector() {
    vector vec = createVector(5);
    int val = 3;
    pushBack(&vec, 1);
    pushBack(&vec, 2);
    pushBack(&vec, val);
    pushBack(&vec, 4);
    pushBack(&vec, 5);

    assert(vec.size > 0);

    int *res = atVector(&vec, 2);

    assert(val == *res);
}

void test_atVector_requestToLastElement() {
    vector vec = createVector(5);
    int val = 5;
    pushBack(&vec, 1);
    pushBack(&vec, 2);
    pushBack(&vec, 3);
    pushBack(&vec, 4);
    pushBack(&vec, val);

    int *res = atVector(&vec, 4);

    assert(val == *res);
}

void test_back_oneElementInVector() {
    vector vec = createVector(1);

    pushBack(&vec, 1);
    pushBack(&vec, 2);

    int *res = back(&vec);

    assert(&vec.data[1] == res);
}

void test_front_oneElementInVector() {
    vector vec = createVector(1);

    pushBack(&vec, 1);
    pushBack(&vec, 2);

    int *res = front(&vec);

    assert(&vec.data[0] == res);
}

//--------------------------------------------------------

vectorVoid test_createVectorV() {
    vectorVoid vec = createVectorV(5, sizeof(int));

    assert(vec.capacity == 5);
    assert(vec.size == 0);
    assert(vec.data != NULL);
    assert(vec.baseTypeSize == sizeof(int));

    deleteVectorV(&vec);
}

void test_reserveV() {
    vectorVoid vec = createVectorV(5, sizeof(int));
    reserveV(&vec, 8);

    assert(vec.capacity == 8);
    assert(vec.size == 0);
    assert(vec.data != NULL);
    assert(vec.baseTypeSize == sizeof(int));

    reserveV(&vec, 3);

    assert(vec.capacity == 3);
    assert(vec.size == 0);
    assert(vec.data != NULL);
    assert(vec.baseTypeSize == sizeof(int));

    int i = 1;
    pushBackV(&vec, &i);
    i = 2;
    pushBackV(&vec, &i);
    i = 3;
    pushBackV(&vec, &i);

    reserveV(&vec, 2);

    assert(vec.capacity == 2);
    assert(vec.size == 2);
    assert(vec.data != NULL);
    assert(vec.baseTypeSize == sizeof(int));
}

void test_shrinkToFitV() {
    vectorVoid vec = createVectorV(6, sizeof(int));

    shrinkToFitV(&vec);

    assert(vec.capacity == 0);
    assert(vec.size == 0);
    assert(vec.data != NULL);
}

void test_clearV() {
    vectorVoid vec = createVectorV(5, sizeof(int));

    int i = 1;
    pushBackV(&vec, &i);
    i = 2;
    pushBackV(&vec, &i);
    i = 3;
    pushBackV(&vec, &i);

    assert(vec.capacity == 5);
    assert(vec.size == 3);
    assert(vec.data != NULL);

    clearV(&vec);

    assert(vec.capacity == 5);
    assert(vec.size == 0);
    assert(vec.data != NULL);
}

void test_deleteVectorV() {
    vectorVoid vec = createVectorV(6, sizeof(int));

    deleteVectorV(&vec);

    assert(vec.capacity == 0);
    assert(vec.size == 0);
    assert(vec.data == NULL);
}
//
bool test_isEmptyV() {
    vectorVoid vec = createVectorV(6, sizeof(int));

    bool res = isEmptyV(&vec);

    assert(res);
}

bool test_isFullV() {
    vectorVoid vec = createVectorV(6, sizeof(int));

    bool res = isFullV(&vec);

    assert(!res);
}

void test_getVectorValueV() {
    vectorVoid vec = createVectorV(6, sizeof(int));

    int x = 4;

    int i = 1;
    pushBackV(&vec, &i);
    i = 2;
    pushBackV(&vec, &i);
    i = 3;
    pushBackV(&vec, &x);

    int j = 3;
    getVectorValueV(&vec, 2, &j);

    assert(&j != &i);
}

void test_setVectorValueV() {
    vectorVoid vec = createVectorV(6, sizeof(int));

    int x = 4;

    int i = 1;
    pushBackV(&vec, &i);
    i = 2;
    pushBackV(&vec, &i);
    i = 3;
    setVectorValueV(&vec, 1, &x);

    int j = 3;
    getVectorValueV(&vec, 1, &j);

    assert(&j != &i);
}

void test_popBackV() {
    vectorVoid vec = createVectorV(0, sizeof(int));

    int j = 10;
    pushBackV(&vec, &j);

    assert(vec.size == 1);

    popBackV(&vec);

    assert(vec.size == 0);
    assert(vec.capacity == 1);
}

void test_pushBack_emptyVectorV() {
    vectorVoid vec = createVectorV(0, sizeof(int));

    assert(vec.capacity == 0);
    assert(vec.size == 0);
    assert(vec.data != NULL);

    int x = 4;
    pushBackV(&vec, &x);

    assert(vec.capacity == 1);
    assert(vec.size == 1);
    assert(vec.data != NULL);

    assert(((int *) vec.data)[0] == 4);
}

void test_pushBack_fullVectorV() {
    vectorVoid vec = createVectorV(2, sizeof(int));

    assert(vec.capacity == 2);
    assert(vec.size == 0);
    assert(vec.data != NULL);

    int a = 1;
    int x = 4;
    pushBackV(&vec, &a);
    pushBackV(&vec, &x);

    assert(vec.capacity == 2);
    assert(vec.size == 2);
    assert(vec.data != NULL);

    assert(((int *) vec.data)[1] == 4);

    int y = 5;
    pushBackV(&vec, &y);

    assert(vec.capacity == 4);
    assert(vec.size == 3);
    assert(vec.data != NULL);

    assert(((int *) vec.data)[0] == 1);
    assert(((int *) vec.data)[2] == 5);
}

void test_functional1() {
    int n = 10;

    int test_data[] = {3, 6, 7, 1, 0, 8, 9, 3, 2, 16};

    vectorVoid v = createVectorV(0, sizeof(int));
    for (int i = 0; i < n; i++) {
        int x = test_data[i];
        pushBackV(&v, &x);
    }
    for (int i = 0; i < n; i++) {
        int x;
        getVectorValueV(&v, i, &x);
        assert(x == test_data[i]);
    }
}

void test_functional2() {
    int n = 10;

    float test_data[] = {3.12f, 6.124f, 7.14f, 1.891f, 0.13f, 8.1245f, 9.03f, 3.463f, 2.124f, 16.096f};

    vectorVoid v = createVectorV(0, sizeof(float));
    for (int i = 0; i < n; i++) {
        float x = test_data[i];
        pushBackV(&v, &x);
    }
    for (int i = 0; i < n; i++) {
        float x;
        getVectorValueV(&v, i, &x);
        assert(x == test_data[i]);
    }
}

void test() {
    test_createVector();
    test_reserve();
    test_clear();
    test_shrinkToFit();
    test_deleteVector();
    test_isEmpty();
    test_isFull();
    test_getVectorValue();
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();

    //--------------------------------------------------------

    test_createVectorV();
    test_reserveV();
    test_shrinkToFitV();
    test_clearV();
    test_deleteVectorV();
    test_isEmptyV();
    test_isFullV();
    test_getVectorValueV();
    test_setVectorValueV();
    test_popBackV();
    test_pushBack_emptyVectorV();
    test_pushBack_fullVectorV();
    test_functional1();
    test_functional2();
}

int main() {
    test();
    vectorVoid test;



    return 0;
}
