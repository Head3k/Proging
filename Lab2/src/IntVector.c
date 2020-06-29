#include <stdlib.h>
#include <string.h>
#include "IntVector.h"
 
IntVector *int_vector_new(size_t initial_capacity){ // create vector
    IntVector *a;                                   // create pointer
    a = (IntVector *)malloc(sizeof(IntVector));     // allocation memory
    if (!a){                                        // if false
        return NULL;                                // error
    }                                               //
    a->array = (int *)                              //
    malloc(initial_capacity * sizeof(int));         //
    if (!a->array){                           // if false
        free(a);                              // free malloc memory
        return NULL;                          // error
    }                                         //
    a->capacity = initial_capacity;           // add capacity
    a->size = 0;                              // add size
    return a;                                 // array
}
 
IntVector *int_vector_copy(const IntVector *v){ // copy vector
    IntVector *a = int_vector_new(v->capacity); // create new vector
    if (!a){                                    // if false
        return NULL;                            //error
    }                                           //
    a->array = memcpy(a->array, v->array,       //
    (sizeof(int) * (v->size)));       // copy vector a => vector b
    if (!a->array){                   // if false
        free(a);                      // free malloc memory
        return NULL;                  // error
    }                                 //
    a->size = v->size;                // add size
    return a;                         // array
}
 
void int_vector_free(IntVector *v){ // clean vector
    free(v->array);                 // check pointer
    free(v);                        // clean array
}
 
int int_vector_get_item(const IntVector *v, size_t index){ // check item by index
    return v->array[index];                                // item
}
 
void int_vector_set_item(IntVector *v, size_t index, int item){ // change item
    v->array[index] = item;                                     // array[i] = item
}
 
size_t int_vector_get_size(const IntVector *v){ // check size array
    return v->size;                             // size
} 
 
size_t int_vector_get_capacity(const IntVector *v){ // check capacity array
    return v->capacity;                             // capacity
}
 
int int_vector_push_back(IntVector *v, int item){ // add element in back array
    if (v->size == v->capacity){                  // if size == capacity 
        int *array = realloc(v->array,            //
        (v->capacity * sizeof(int) * 2));         // create array
        if (!array){                              // if false
            return -1;                            // return
        }                                         //
        v->array = array;                 // update array
        v->capacity *= 2;                 // increase capacity
    }                                     //
    v->array[v->size] = item;             // add item
    v->size++;                            // add size
    return 0;                             // return
}
 
void int_vector_pop_back(IntVector *v){    // delete last element in array
    if (v->size != 0 && v->capacity != 0){ // if size && capacity != 0
        v->array[v->size - 1] = 0;         // last element = 0  
        v->size--;                         // delete size
    }                                      //
} 
 
int int_vector_shrink_to_fit(IntVector *v){ // capacity vector = size vector
    int *array = realloc(v->array,          //
    (v->size * sizeof(int)));               // create array
    if (!array){                            // if false
        return -1;                          // return
    }                                       //
    v->array = array;                       // completion refactor array
    v->capacity = v->size;                  // capacity = size
    return 0;                               // return 
}
 
int int_vector_resize(IntVector *v, size_t new_size){ // resize vector
    if (v->size < new_size){                          // if size < new size
        int *array = realloc(v->array,                // 
        (new_size * sizeof(int)));                    // create array
        if (!array){                                  // if false
            return -1;                                // return
        }                                             //
        v->array = array;                             // completion array
        for (size_t i = v->size; i < new_size; i++)   // completion new element
            v->array[i] = 0;                    // new element = 0
        v->size = new_size;                     // size = new size
        v->capacity = new_size;                 // capacity = new size
    }                                           //
    if (v->size > new_size){                    // if size > new size
        v->size = new_size;                                //
    }                                           // size = new size
    return 0;                                   //
}
 
int int_vector_reserve(IntVector *v, size_t new_capacity){ // reserve vector 
    if (v->capacity >= new_capacity){                      // if capacity >= new capacity
        return 0;                                          // return 
    }                                                      //
    int *array = realloc(v->array,                         //
    (new_capacity * sizeof(int)));                 // create array
    if (!array){                                   // if false
        return -1;                                 // return
    }                                              //
    v->array = array;                              // completion array
    v->capacity = new_capacity;                    // capacity = new capacity
    return 0;                                      //
}
