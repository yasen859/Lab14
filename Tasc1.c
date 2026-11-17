#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>

#define N 100


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

int main(void)
{
    setlocale(LC_ALL, ".UTF8");
    double array[N];
    int size;

    printf("Введите размер массива > ");
    scanf_s("%d", &size);

    if (size <= 0 || size > N) {
        printf("Некорректный размер массива\n");
        return 1;
    }

    full_elements(array, size);
    printf("\nИсходный массив (y = x*x + sin(5x)):\n");
    put_elements(array, size);

    calc_elements(array, size);
    printf("\nМассив после удвоения элементов:\n");
    put_elements(array, size);

    return 0;
}