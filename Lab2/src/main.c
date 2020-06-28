#include <stdio.h>
#include "IntVector.h"

int main()
{
    IntVector *a, *b;//
    a = int_vector_new(7);// void create array
    printf("\n-- new_vector --"); //
    for (int i = 0; i < 6; i++){ // completion array
        a->arr[i] = i; // completion element
	    a->size++; // count size
    }//
    printf("\nA = ");//
    for (int i = 0; i < 6; i++){ // print array 
        printf("%d ", a->arr[i]); // print element
    }//
    //
    //
    b = int_vector_copy(a); // void copy array
    printf("\n\n-- copy --");//
    printf("\nB = "); //
    for (int i = 0; i < 6; i++) // print second array
    {
        printf("%d ", b->arr[i]); // print element
    }
    printf("\n\n-- push_back ==> 7 --");
    //
    //
    int_vector_push_back(b, 7); // void add to last element
    //
    printf("\narray ==> %ld", int_vector_get_size(b));//
    printf("\ncapacity ==> %zd", int_vector_get_capacity(b));//
    printf("\nsize ==> %zd",int_vector_get_size(b));//
    //
    printf("\nB = ");//
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", b->arr[i]);//
    }
    //
    //
    printf("\n\n-- NEW push_back ==> 7 --");
    int_vector_push_back(b, 7); // void add to
    //
    printf("\narray ==> %ld", int_vector_get_size(b));//
    printf("\ncapacity ==> %zd", int_vector_get_capacity(b));//
    printf("\nsize ==> %zd",int_vector_get_size(b));//
    //
    printf("\nB = ");//
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", b->arr[i]);//
    }
    //
    //
    printf("\n\n-- set_item i[0] ==> 9 --");//
    int_vector_set_item(b, 0, 9); // void 9 --> i[0] from the array b
    //
    //
    printf("\n\n-- get_item i[0] -- \n"); // 
    printf("item[0] = %d", int_vector_get_item(b, 0)); // void get item i[0] from the array b
    for (int i = 0; i < 8; i++)
    {
        printf("\n arr:: %d ", b->arr[i]);//
    }
    //
    //
    printf("\n\n-- pop_back --"); //
    int_vector_pop_back(b); // void delete last element array
    //
    for (int i = 0; i < 8; i++)
    {
        printf("\n arr:: %d ", b->arr[i]);//
    }
    //
    //
    printf("\ncapacity ==> %zd", int_vector_get_capacity(b));//
    printf("\nsize ==> %zd",int_vector_get_size(b));//
    //
    //
    printf("\n\n-- shrink_to_fit --"); // void 
    int_vector_shrink_to_fit(b);//
    //
    printf("\ncapacity ==> %zd", int_vector_get_capacity(b));//
    printf("\nsize ==> %zd",int_vector_get_size(b));//
    //
    //
    printf("\n\n-- resize ==> 10 --"); //
    int_vector_resize(b, 10); //
    //
    printf("\ncapacity ==> %zd", int_vector_get_capacity(b));//
    printf("\nsize ==> %zd",int_vector_get_size(b));//
    //
    //
    printf("\n\n-- reserve ==> 15 --");
    int_vector_reserve(b, 15);
    //
    printf("\ncapacity ==> %zd", int_vector_get_capacity(b));//
    printf("\nsize ==> %zd\n",int_vector_get_size(b));//
    //
    //
    int_vector_free(b);
    int_vector_free(a);
    return 0;
}
