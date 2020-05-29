#include <stdio.h>
#include <stdlib.h>

int* init(int* arr, int n) {         
    arr = malloc(n * sizeof(int));  // memory allocation for array
    int i;                             
    for (i = 0; i < n; ++i)       // filling array  
        arr[i] = i;              //        
    return arr;                 // absented return arr;
}

int main() {                           
    int* arr = NULL;                  //  init array
    int n = 10;                          
    arr = init(arr, n);             //  use function "init"
    int i;                         
    for (i = 0; i < n; ++i)       //  print array
        printf("%d\n", arr[i]);  //
    return 0;                   
}
