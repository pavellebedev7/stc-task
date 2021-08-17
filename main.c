#include <stdio.h>
#include <stdlib.h>
#include "header.h"

// Функция поиска максимального значения в массиве
float find_max_value(float input[], int n){
    int i;
    float maxvalue = input[0];
    for(i = 1; i < n; i++){
        if(input[i] > maxvalue) maxvalue = input[i];
    }
    return maxvalue;
}

/*
 * Функция вывода результата по заданию
 * Выводится список индексов входного массива,
 * которые не отличаются больше, чем на K% от наибольшего (включая наибольшое)
 */
void print_output(float k, int n, float input[]){
    int count = 0;      // Счетчик для индексов
    int length = 0;     // Длина списка
    int i;              // Переменная для цикла
    float max_value;    // Максималное значение массива

    // Поиск максимального значения
    max_value = find_max_value(input, n);

    // Вычисление нижней границы интервала
    float lower_bound = max_value * (1 - k * 0.01);

    // Получение длины искомого списка
    for(i = 0; i < n; i++){
        if(input[i] >= lower_bound) count++;
    }
    length = count;

    // Вывод по заданному формату
    printf("\nK = %f\n", k);
    printf("N = %d\n", n);
    printf("Input: ");
    for(i = 0; i < n; i++){
        if(n-i == 1) printf("%f\n", input[i]);  // Последний элемент без запятой
        else printf("%f, ", input[i]);          // Не последний с запятой
    }
    printf("Output: [");
    for(i = 0; i < n; i++){
        if(input[i] >= lower_bound){
            if(--count) printf("%d, ", i);  // Не последний элемент с запятой
            else printf("%d", i);           // Последний - без
        }
    }
    printf("], %d\n\n", length);
}

int main(void)
{
    int n;      // Длина массива
    float k;    // Интервал в процентах
    int i;      // Переменная для цикла

    // Бесконечный цикл для удобства ввода
    while(1){
        // Ввод исходных данных
        scanf("%f", &k);
        scanf("%d", &n);
        if(k < 0 || n <= 0){
            printf("Invalid input\n\n");
            while(getchar() != '\n');
            continue;
        }

        // Выделение памяти под массив
        float *array = (float*)malloc(n*sizeof(float));

        // Ввод массива
        for(i = 0; i < n; i++){
            scanf("%f", &array[i]);
        }
        while(getchar() != '\n');

        // Вывод результата
        print_output(k, n, array);

        // Освобождение памяти
        free(array);
    }
}

