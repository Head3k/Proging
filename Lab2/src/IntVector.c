#include <stdlib.h>
#include <string.h>
#include "IntVector.h"
 
IntVector *int_vector_new(size_t initial_capacity)
{
    IntVector *a;
    a = (IntVector *)malloc(sizeof(IntVector));
    if (!a)
    {
        return NULL;
    }
    a->arr = (int *)malloc(initial_capacity * sizeof(int));
    if (!a->arr)
    {
        free(a);
        return NULL;
    }
    a->capacity = initial_capacity;
    a->size = 0;
    return a;
}
 
IntVector *int_vector_copy(const IntVector *v)
{
    IntVector *a = int_vector_new(v->capacity);
    if (!a)
    {
        return NULL;
    }
    a->arr = memcpy(a->arr, v->arr, (sizeof(int) * (v->size)));
    if (!a->arr)
    {
        free(a);
        return NULL;
    }
    a->size = v->size;
    return a;
}
 
void int_vector_free(IntVector *v)
{
    free(v->arr);
    free(v);
}
 
int int_vector_get_item(const IntVector *v, size_t index)
{
    return v->arr[index];
}
 
void int_vector_set_item(IntVector *v, size_t index, int item)
{
    v->arr[index] = item;
}
 
size_t int_vector_get_size(const IntVector *v)
{
    return v->size;
}
 
size_t int_vector_get_capacity(const IntVector *v)
{
    return v->capacity;
}
 
int int_vector_push_back(IntVector *v, int item)
{
    if (v->size == v->capacity)
    {
        int *array = realloc(v->arr, (v->capacity * sizeof(int) * 2));
        if (!array)
        {
            return -1;
        }
        v->arr = array;
        v->capacity *= 2;
    }
    v->arr[v->size] = item;
    v->size++;
    return 0;
}
 
void int_vector_pop_back(IntVector *v)
{
    if (v->size != 0 && v->capacity != 0)
    {
        v->arr[v->size - 1] = 0;
        v->size--;
    }
}
 
int int_vector_shrink_to_fit(IntVector *v)
{
    int *array = realloc(v->arr, (v->size * sizeof(int)));
    if (!array)
    {
        return -1;
    }
    v->arr = array;
    v->capacity = v->size;
    return 0;
}
 
int int_vector_resize(IntVector *v, size_t new_size)
{
    if (v->size < new_size)
    {
        int *array = realloc(v->arr, (new_size * sizeof(int)));
        if (!array)
        {
            return -1;
        }
        v->arr = array;
        for (size_t i = v->size; i < new_size; i++)
            v->arr[i] = 0;
        v->size = new_size;
        v->capacity = new_size;
    }
    if (v->size > new_size)
    {
        v->size = new_size;
    }
    return 0;
}
 
int int_vector_reserve(IntVector *v, size_t new_capacity)
{
    if (v->capacity >= new_capacity)
    {
        return 0;
    }
    int *array = realloc(v->arr, (new_capacity * sizeof(int)));
    if (!array)
    {
        return -1;
    }
    v->arr = array;
    v->capacity = new_capacity;
    return 0;
}