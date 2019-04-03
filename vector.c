#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
#define MAXSIZE 10000
#define VECTOR_DEFAULT_SIZE 101

typedef struct __vector{

    int size_;
    char *array_;

} vector;

_Bool visitados[MAXSIZE]

void make_vector(vector *__adj);
void push_back(vector *adj, char);

int m, n;

void main ()
{

    vector adj[MAXSIZE];
    make_vector(adj);

    




}

void make_vector(vector *__adj)
{

    int i;
    for (i = 0; i < MAXSIZE; ++i)
        __adj->array_ = NULL, __adj->size_ = 0;

}

void push_back(vector *__adj, char a)
{

    static int RESERVED_SIZE = 1;

    if (__adj->size_ == RESERVED_SIZE)
    {

        RESERVED_SIZE << 1;
        __adj->array_ = (char *) realloc(__adj->array_, RESERVED_SIZE);

    }

    if (__adj->array_ == NULL)
        __adj->array_ = (char *) malloc(sizeof(char *) * VECTOR_DEFAULT_SIZE);

    __adj->array_[__adj->size_++] = a;

}
