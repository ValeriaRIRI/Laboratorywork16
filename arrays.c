#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "array.h"  

double* full_elements(double* ptr_array, int size) {
    for (int i = 0; i < size; i++) {
        ptr_array[i] = fa(i); 
    }
    return ptr_array;
}

int put_elements(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.5f ", ptr_array[i]);
    }
    printf("\n");
    return n;
}

double* calc_elements(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        if (ptr_array[i] < 0.0) {
            ptr_array[i] = 0.0;
        }
    }
    return ptr_array;
}

double sum_elements(double* ptr_array, int begin, int end, int n) {
    double sum = 0.0;
    if (begin < 0 || end >= n || begin > end) {
        return 0.0;
    }
    for (int i = begin; i <= end; i++) {
        sum += ptr_array[i];
    }
    return sum;
}

int find_element(double* ptr_array, int n, double element) {
    for (int i = 0; i < n; i++) {
        if (ptr_array[i] == element) {
            return i;
        }
    }
    return -1;
}

double max_abs(double* ptr_array, int n, double A) {
    double max_abs = -1.0;
    int found = 0;

    for (int i = 0; i < n; i++) {
        if (ptr_array[i] != A) {
            double abs_val = fabs(ptr_array[i]);
            if (!found || abs_val > max_abs) {
                max_abs = abs_val;
                found = 1;
            }
        }
    }

    if (found == 0) {
        printf("Ёлементы не найдены\n");
    }
    return max_abs;
}

double fa(double x) {
    return pow(x, 2) * M_PI * cos(M_PI * x);
}

int delete_negatives(double* ptr_arr, int size) {
    int write = 0;
    for (int i = 0; i < size; i++) {
        if (ptr_arr[i] >= 0) {
            ptr_arr[write] = ptr_arr[i];
            write++;
        }
    }
    return write;  // новое количество элементов
}



double* insert(double* ptr_arr, int* size) {

    int pos_count = 0;
    for (int i = 0; i < *size; i++) {
        if (ptr_arr[i] > 0.0) pos_count++;
    }

    int size_n = *size + pos_count;
    double* ptr_arr_n = realloc(ptr_arr,size_n * sizeof(double));

    int write_pos = 0;
    for (int i = 0; i < *size; i++) {
        ptr_arr_n[write_pos++] = ptr_arr[i];
        if (ptr_arr[i] > 0.0) {
            ptr_arr_n[write_pos++] = -999.0;
        }
    }


    *size = size_n;
    return ptr_arr_n;
}

double max_min_diff(double* ptr_array, int begin, int end,int n) {
    if (begin < 0 || end >= n || begin > end) {
        return -1.0; 
    }

    double min_val = ptr_array[begin];
    double max_val = ptr_array[begin];

    for (int i = begin + 1; i <= end; i++) {
        if (ptr_array[i] < min_val) {
            min_val = ptr_array[i];
        }
        if (ptr_array[i] > max_val) {
            max_val = ptr_array[i];
        }
    }

    return max_val - min_val;
}




