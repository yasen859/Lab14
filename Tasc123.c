#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>

#define N 100

//Задание 1
double* full_elements(double* ptr_array, int n)
{
    for (int i = 0; i < n; i++) {
        double x = i + 1;                     
        ptr_array[i] = x * x + sin(5.0 * x);
    }
    return ptr_array;
}

// Печать элементов массива
int put_elements(double* ptr_array, int n)
{
    for (int i = 0; i < n; i++)
        printf("a[%d] = %.4f\n", i, ptr_array[i]);
    return n;
}

// Обработка: удвоить значение каждого элемента массива */
double* calc_elements(double* ptr_array, int n)
{
    for (int i = 0; i < n; i++)
        ptr_array[i] *= 2;
    return ptr_array;
}


//Задание 2

double sum_elements(double* ptr_array, int begin, int end)
{
    double sum = 0;
    for (int i = begin; i <= end; i++)
        sum += ptr_array[i];
    return sum;
}

int find_element(double* ptr_array, int n, double element)
{
    for (int i = 0; i < n; i++)
        if (ptr_array[i] == element)
            return i;
    return -1;
}

//Задание 3
double max_elements(double* ptr_array, int K, int M)
{
    
    double max = ptr_array[K];
    for (int i = K + 1; i <= M; i++)
        if (ptr_array[i] > max)
            max = ptr_array[i];
    return max;
}


int main(void)
{
    setlocale(LC_ALL, ".UTF8");
    double array[N];
    int size;
    int begin, end;
    double a;
    int K, M;


    printf("Введите размер массива > ");
    scanf_s("%d", &size);

    //Задание 1
    full_elements(array, size);
    printf("\nИсходный массив (y = x*x + sin(5x)):\n");
    put_elements(array, size);

    calc_elements(array, size);
    printf("\nМассив после удвоения элементов:\n");
    put_elements(array, size);



    //Задание 2
    printf("\nВведите begin, end (индексы) для суммы > ");
    scanf_s("%d %d", &begin, &end);
    printf("Сумма элементов от %d до %d = %.4f\n",
        begin, end, sum_elements(array, begin, end));

    printf("\nВведите искомый элемент a = ");
    scanf_s("%lf", &a);
    int idx = find_element(array, size, a);
    if (idx != -1)
        printf("Элемент %.4f найден на индексе %d\n", a, idx);
    else
        printf("Элемент %.4f не найден (возвращено -1)\n", a);


    //Здание 3
    printf("\nВведите K, M (индексы) для поиска максимума ");
    scanf_s("%d %d", &K, &M);
    printf("Максимум в интервале [%d, %d] = %.4f\n",
        K, M, max_elements(array, K, M));

    return 0;
}
