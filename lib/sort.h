// sort.h
#include <stdlib.h>

/**
 * Type alias for a comparator function.
 * Whose first parameter is the current item to be compared.
 * And the second parameter is the pivot to compare against.
 * @returns and integer. A value <= 0 place the item on the left of the pivot,
 * any other value place the item on the right of the pivot.
 */
typedef int(*CMP)(const void*, const void*);

/**
 * Returns a pointer to the specified index in the array.
 * @param arr the array.
 * @param i the index to get the pointer to.
 * @param item_size the size in bytes of each item.
 * @returns a pointer to the given index.
 */
void* get_pointer(void* arr, int i, size_t item_size);

/**
 * Swaps the values in the given indices.
 * @param arr the array.
 * @param i the first index.
 * @param j the second index.
 * @param item_size the size in bytes of each item.
 */
void swap(void* arr, int i, int j, size_t item_size);

/**
 * Sorts the array pointed at by the void pointer.
 * @param arr the array to be sorted.
 * @param start the start index of the array.
 * @param end the end index (exclusive) of the array.
 * @param item_size the size in bytes of each item.
 * @param cmp the comparator function to use during sorting.
 */
void quicksort(void* arr, int start, int end, size_t item_size, CMP cmp);
