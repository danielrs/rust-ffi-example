// sort.c

#include "sort.h"

void* get_pointer(void* arr, int i, size_t item_size) {
    return arr + i * item_size / sizeof(char);
}

void swap(void* arr, int i, int j, size_t item_size) {
    char* p = get_pointer(arr, i, item_size);
    char* q = get_pointer(arr, j, item_size);
    char temp;

    // Swaps values byte-by-byte.
    for (int i = 0; i < item_size; ++i) {
        temp = p[i];
        p[i] = q[i];
        q[i] = temp;
    }
}

void quicksort(void* arr, int begin, int end, size_t item_size, CMP cmp) {
    if (begin >= end - 1) return;

    // Partition the array.
    void* pivot = get_pointer(arr, begin, item_size);
    int left = begin + 1;
    int right = end - 1;

    while(left < right) {
        if (cmp(get_pointer(arr, left, item_size), pivot) <= 0) {
            ++left;
        }
        else if (cmp(get_pointer(arr, right, item_size), pivot) > 0) {
            --right;
        }
        else {
            swap(arr, left, right, item_size);
        }
    }
    if (cmp(get_pointer(arr, left, item_size), pivot) < 0) {
        swap(arr, begin, left, item_size);
    }
    else {
        swap(arr, begin, left - 1, item_size);
    }

    // Recursively sort the array.
    quicksort(arr, begin, left, item_size, cmp);
    quicksort(arr, left, end, item_size, cmp);
}

/* #include <stdio.h> */

/* int compare(const void* a, const void* pivot) { */
/*     return (*(int*)a) - (*(int*)pivot); */
/* } */

/* int main() { */
/*     int arr[] = {-10, 5, 2, 10, -10}; */
/*     int len = sizeof(arr) / sizeof(int); */

/*     quicksort(arr, 0, len, sizeof(int), compare); */

/* 	for (int i = 0; i < len; ++i) { */
/*         printf("%d, ", arr[i]); */
/*     } */
/*     printf("\n"); */
/* } */
