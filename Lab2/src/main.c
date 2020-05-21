#include <stdio.h>
#include "IntVector.h"

int main()
{
    IntVector *a, *b;
    a = int_vector_new(7);//
    printf("\n-- new_vector --");
    for (int i = 0; i < 6; i++)
    {
        a->size++;
        a->arr[i] = i;
    }
    printf("\nA = ");//
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", a->arr[i]);
    }
    b = int_vector_copy(a);//
    printf("\n\n-- copy --");
    printf("\nB = ");//
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", b->arr[i]);
    }
    printf("\n\n-- push_back ==> 7 --");
    int_vector_push_back(b, 7);//
    printf("\narr[6] ==> %d \ncapacity ==> %zd \nsize ==> %zd\n", b->arr[6], 
int_vector_get_capacity(b), int_vector_get_size(b));//
    printf("\nB = ");//
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", b->arr[i]);//
    }
    int_vector_push_back(b, 7);
    printf("\narr[6] ==> %d \ncapacity ==> %zd \nsize ==> %zd\n", b->arr[6], 
int_vector_get_capacity(b), int_vector_get_size(b));//
    printf("\nB = ");//
    int_vector_set_item(b, 0, 9);
    printf("get item ==> %d\n", int_vector_get_item(b, 0));//
    int_vector_pop_back(b);
    printf("\n-- pop_back --");
    printf("\ncapacity ==> %zd\nsize ==> %zd\n", int_vector_get_capacity(b), 
int_vector_get_size(b));//
    int_vector_shrink_to_fit(b);
    printf("\n-- shrink_to_fit --");
    printf("\ncapacity ==> %zd\n", int_vector_get_capacity(b));//
    int_vector_resize(b, 5);
    printf("get_size ==> %zd\n", int_vector_get_size(b));//
    int_vector_reserve(b, 5);
    printf("\n-- reserve ==> 5 --");
    for (int i = 0; i < 5; i++)
    {
        printf("\n arr:: %d ", b->arr[i]);//
    }
    printf("\ncapacity ==> %zd\n", int_vector_get_capacity(b));//
    int_vector_free(b);
    int_vector_free(a);
    return 0;
}
