#include <stdio.h>
#include <stdlib.h>

int* init(int* arr, int n)
{
    arr = malloc(n * sizeof(int)); //выделение места по кол-ву элементов * тип
                                   //переменной
    int i;                    //инициализация i для цикла
    for (i = 0; i < n; ++i) { //цикл
        arr[i] = i;
    }
    return arr; //возвращение указателя
}

int main()
{
    int* arr = NULL;
    int n = 10;               //кол-во элементов массива
    arr = init(arr, n);       //обращение к функции
    int i;                    // инициализация i для цикла
    for (i = 0; i < n; ++i) { //цикл
        printf("%d\n", arr[i]);
    }
    return 0;
}
