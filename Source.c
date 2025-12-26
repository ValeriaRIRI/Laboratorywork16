#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "array.h"
#define N 1000

#define MIN 10.0
#define MAX 50.0


int task_11(int size);
int task_14(int size);
int task_16_1(int size);
int task_16_2(int size);
int task16_h(int size);
int task_17(int size);

int main() {
    setlocale(LC_ALL, "Russian");
    int size;
    printf("Введите размер массива > ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        puts("Некорректный размер");
        return 1;
    }
    //task_11(size);
    //task_14(size);
    //task_16_1(size);
    //task_16_2(size);
    //task16_h(size);
    task_17(size);
}
int task_11(int size) {
    int temp;
    float* A = (float*)malloc(size * sizeof(float));

    for (int i = 0; i < size; i++) {
        printf("a[%d] = ", i + 1);
        scanf("%f", &temp);
        A[i] = temp;
    }
    double min_average = (A[0] + A[1]) / 2.0;
    for (int i = 1; i < size - 1; i++) {
        double average = (A[i] + A[i + 1]) / 2.0;
        if (average < min_average) {
            min_average = average;
        }

    }
    printf("Наименьшее среднее значение элементов массива: %f", min_average);
    return 0;
}

int task_14(int size) {
    double array[N];

    
    double x_start, step;
    printf("Введите начальное x: ");
    scanf("%lf", &x_start);
    printf("Введите шаг: ");
    scanf("%lf", &step);

    int c;
    do {
        printf("Выберите операцию: 1 - вывод элементов массива до и после обработки значений; 2 - поиск элемента; 3 - сумма элементов на заданном диапазоне; 4 - поиск максимального числа, не равного А; 0 - выход из программы");

        scanf("%d", &c);
        switch (c) {
        case 1: {
            full_elements(array, size);
            put_elements(array, size);

            calc_elements(array, size);
            put_elements(array, size);
            break;
        }
        case 2: {

            int begin, end;
            double search;
            printf("Введите начальный индекс: ");
            scanf("%d", &begin);
            printf("Введите конечный индекс: ");
            scanf("%d", &end);

            printf("Введите элемент для поиска: ");
            scanf("%lf", &search);
            int idx = find_element(array, size, search);
            if (idx != -1) {
                printf("Элемент %.2f найден на индексе %d\n", search, idx);
            }
            else {
                printf("Элемент %.2f не найден\n", search);
            }
            break;
        }
        case 3: {
            int begin, end;
            printf("Введите начальный индекс: ");
            scanf("%d", &begin);
            printf("Введите конечный индекс: ");
            scanf("%d", &end);

            printf("Сумма элементов [%d..%d] = %.2f\n", begin, end, sum_elements(array, begin, end, size));
            break;
        }
        case 4: {
            double A;
            printf("Введите A для поиска максимального х, не равного А: ");
            scanf("%lf", &A);
            double max_Abs = max_abs(array, size, A);
            printf("Максимальное по модулю значение не равное %.2f = %.2f\n", A, max_Abs);
            break;
        }
        case 5: {
            int begin, end;
            printf("Введите начальный индекс K: ");
            scanf("%d", &begin);
            printf("Введите конечный индекс L: ");
            scanf("%d", &end);

            double diff = max_min_diff(array, begin, end, size);
            if (diff >= 0) {
                printf("Разность max-min в диапазоне [%d..%d] = %.5f\n", begin, end, diff);
            }
            else {
                printf("Неверный диапазон [%d..%d]\n", begin, end);
            }
            break;
        }
        default:
            printf("Операция не найдена");

        }
    } while (c != 0);
    return 0;
}

int task_16_1(int size){

    double* ptr_array = malloc(size * sizeof(double));
    double* ptr_result = malloc(size * sizeof(double));


    if (!ptr_array || !ptr_result) { puts("error"); return 1; }
    full_elements(ptr_array, size);           

    for (int i = 0; i < size; i++)
        ptr_result[i] = ptr_array[i];
    calc_elements(ptr_result, size);          

    printf("Исходный массив:\n");
    put_elements(ptr_array, size);            

    printf("Преобразованный массив:\n");
    put_elements(ptr_result, size);           

    free(ptr_array);
    free(ptr_result);

    
    return 0;


}
int task_16_2(int size) {

    double* ptr_array = calloc(size, sizeof(double));
    if (!ptr_array) return 1;

    for (int i = 0; i < size; i++) {
        ptr_array[i] = MIN + (rand() / (double)RAND_MAX)*(MAX - MIN);
        printf("a[%d] = %.5f\n", i, ptr_array[i]);
    }
    printf("Исходный массив:\n");
    put_elements(ptr_array, size);

    
    int old_size = size;
    size = delete_negatives(ptr_array, size);

    printf("После удаления отрицательных значений:\n");
    put_elements(ptr_array, size);

  
    for (int i = size; i < old_size; i++) {
        ptr_array[i] = 0.0;
    }


    ptr_array = insert(ptr_array, &size);
    printf("После вставки значения -999:\n", size);
    put_elements(ptr_array, size);

    free(ptr_array);
    return 0;
}


int task16_h(int size) {
    srand(time(NULL));  

    int size_a, size_b, size_c, size_d;

    
    double* arr_a = generate_array(&size_a);
    double* arr_b = generate_array(&size_b);
    double* arr_c = generate_array(&size_c);

    double* d = create_arr_d(arr_a, arr_b, arr_c, size_a, size_b, size_c, &size_d);

    put_elements(arr_a, size_a);
    put_elements(arr_b, size_b);
    put_elements(arr_c, size_c);
    put_elements(d, size_d); 
}


int task_17(int size) {
    int sizes[] = { 100, 1000, 10000 };
    char* sorts[] = { "Выбором", "Пузырек", "Коктейль", "Вставки" };

    printf("| Размер | %8s | %8s | %8s | %8s |\n",
        sorts[0], sorts[1], sorts[2], sorts[3]);
    printf("|--------|--------|--------|--------|--------|\n");

    for (int s = 0; s < 3; s++) {
        int size = sizes[s];
        printf("| %6d |", size);

        for (int i = 0; i < 4; i++) {
            double avg_time = 0;
            for (int j = 0; j < 100; j++) {
                double* arr = malloc(size * sizeof(double));
                srand(time(NULL)); full_elements(arr, size);

                clock_t t = clock();
                switch (i) {
                case 0: sort_select(arr, size); break;
                case 1: sort_bubble(arr, size); break;
                case 2: sort_cocktail(arr, size); break;
                case 3: sort_insert(arr, size); break;
                }
                avg_time += (clock() - t) * 1. / CLOCKS_PER_SEC;
                free(arr);
            }
            printf(" %7.4f |", avg_time / 10);
        }
        printf("\n");
    }
    return 0;
}

