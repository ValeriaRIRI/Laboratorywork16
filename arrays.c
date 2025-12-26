#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "array.h"  
#define MIN 10.0
#define MAX 50.0

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
        printf("Элементы не найдены\n");
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

double* generate_array(int* size) {
    *size = MIN + (rand() / (double)RAND_MAX) * (MAX - MIN);
    double* arr = (double*)malloc(*size * sizeof(double));
    for (int i = 0; i < *size; i++) {
        arr[i] = -50.0 + (100.0 * rand() / RAND_MAX);  
    }
    return arr;
}

double* create_arr_d(double* arr_a, double* arr_b, double* arr_c, int size_a, int size_b, int size_c, int* size_d) {
    int neg = 0;
    for (int i = 0; i < size_a; i++) if (arr_a[i] < 0) neg++;
    *size_d = neg + size_b + (size_c / 5 + (size_c % 5 != 0));
    double* d = malloc(*size_d * sizeof(double));
    int k = 0;

    for (int i = size_a - 1; i >= 0; i--) if (arr_a[i] < 0) d[k++] = arr_a[i];
    for (int i = 0; i < size_b; i++) d[k++] = arr_b[i];
    for (int i = 0; i < size_c; i += 5) d[k++] = arr_c[i];

    return d;
}

void sort_bubble(double* ptr_array, int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (ptr_array[j] > ptr_array[j + 1]) {
                double temp = ptr_array[j];     
                ptr_array[j] = ptr_array[j + 1];
                ptr_array[j + 1] = temp;
            }
        }
    }
}


void sort_select(double* ptr_array, int n) {
    int i, j, imax;
    for (i = 0; i < n - 1; i++) {
        imax = i;
        for (j = i + 1; j < n; j++) {
            if (ptr_array[j] > ptr_array[imax]) {
                imax = j;
            }
        }
        if (imax != i) {
            double temp = ptr_array[i];      
            ptr_array[i] = ptr_array[imax];
            ptr_array[imax] = temp;
        }
    }
}


void sort_insert(double* ptr_array, int n) {
    int i, j;
    double temp;  
    for (i = 1; i < n; i++) {  
        temp = ptr_array[i];
        j = i;
        while (j > 0 && ptr_array[j - 1] > temp) {
            ptr_array[j] = ptr_array[j - 1];
            j--;
        }
        ptr_array[j] = temp;
    }
}

void sort_cocktail(double* arr, int size) {
    int swapped;
    int left = 0;
    int right = size - 1;

    do {
        swapped = 0;

        
        for (int i = left; i < right; i++) {
            if (arr[i] > arr[i + 1]) {
                double temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
                right--;  
            }
        }

        
        for (int i = right - 1; i >= left; i--) {
            if (arr[i] > arr[i + 1]) {
                double temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
                left++;   
            }
        }
    } while (swapped && left < right);
}





