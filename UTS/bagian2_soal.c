#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int a, b;
    float val;
    struct Node* next;
} Node;

typedef struct {
    int size;
    Node* head;
} Data;

void f1(Data* x, int a, int b, float val) {
    if (val == 0.0) return;
    Node* n = malloc(sizeof(Node));
    n->a = a;
    n->b = b;
    n->val = val;
    n->next = x->head;
    x->head = n;
}

void f2(Data* x, int a, int b, float* val) {
    Node* p = x->head;
    *val = 0.0;
    while (p != NULL) {
        if (p->a == a && p->b == b) {
            *val = p->val;
            return;
        }
        p = p->next;
    }
}

void f3(Data* x1, Data* x2) {
    x2->size = x1->size;
    x2->head = NULL;
    Node* p = x1->head;
    while (p != NULL) {
        f1(x2, p->b, p->a, p->val);
        p = p->next;
    }
}

void f4(Data* x1, Data* x2) {
    x2->size = 2;
    x2->head = NULL;
    float a, b, c, d;

    f2(x1, 0, 0, &a); f2(x1, 0, 1, &b);
    f2(x1, 1, 0, &c); f2(x1, 1, 1, &d);

    float det = a * d - b * c;
    if (det == 0) return;

    f1(x2, 0, 0,  d / det);
    f1(x2, 0, 1, -b / det);
    f1(x2, 1, 0, -c / det);
    f1(x2, 1, 1,  a / det);
}

void f5(Data* x1, Data* x2, Data* x3) {
    x3->size = x1->size;
    x3->head = NULL;
    for (int i = 0; i < x3->size; i++) {
        for (int j = 0; j < x3->size; j++) {
            float v1, v2, sum;
            f2(x1, i, j, &v1);
            f2(x2, i, j, &v2);
            sum = v1 + v2;
            if (sum != 0.0) f1(x3, i, j, sum);
        }
    }
}

void f6(Data* x1, Data* x2, Data* x3) {
    x3->size = 2;
    x3->head = NULL;
    for (int i = 0; i < x3->size; i++) {
        for (int j = 0; j < x3->size; j++) {
            float sum = 0.0;
            for (int k = 0; k < x3->size; k++) {
                float v1, v2;
                f2(x1, i, k, &v1);
                f2(x2, k, j, &v2);
                sum += v1 * v2;
            }
            if (sum != 0.0) f1(x3, i, j, sum);
        }
    }
}

void f7(Data* x) {
    printf("Data: \n");
    for (int i = 0; i < x->size; i++) {
        for (int j = 0; j < x->size; j++) {
            float val;
            f2(x, i, j, &val);
            printf("%.3f ", val);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    Data x1 = {2, NULL};
    Data x2 = {2, NULL};
    
    f1(&x1, 0, 0, 2);
    f1(&x1, 0, 1, 1);
    f1(&x1, 1, 0, 1);
    f1(&x1, 1, 1, 1);
    f1(&x2, 0, 0, 1);
    f1(&x2, 0, 1, -1);
    f1(&x2, 1, 0, -1);
    f1(&x2, 1, 1, 2);

    f7(&x1);

    f7(&x2);

    Data x3 = {0, NULL};
    f3(&x1, &x3);
    f7(&x3);

    Data x4 = {0, NULL};
    f5(&x1, &x2, &x4);
    f7(&x4);

    Data x5 = {0, NULL};
    f6(&x1, &x2, &x5);
    f7(&x5);

    Data x6 = {0, NULL};
    f4(&x1, &x6);
    f7(&x6);

    Data x7 = {0, NULL};
    f6(&x6, &x2, &x7);
    f7(&x7);

    return 0;
}