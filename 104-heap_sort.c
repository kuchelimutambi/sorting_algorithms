#include <stdio.h>
#include "sort.h"

/**
 * sift_down - Performs the sift-down operation in the Heap sort algorithm
 * @array: The array to be sorted
 * @start: The start index of the heap
 * @end: The end index of the heap
 * @size: The size of the array
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
    size_t root = start;
    size_t child;

    while ((child = 2 * root + 1) <= end) {
        if (child + 1 <= end && array[child] < array[child + 1])
            child++;

        if (array[root] < array[child]) {
            int temp = array[root];
            array[root] = array[child];
            array[child] = temp;
            print_array(array, size);
            root = child;
        } else {
            return;
        }
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order using the Heap sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
    if (array == NULL || size <= 1)
        return;

    /* Build max heap */
    for (int i = size / 2 - 1; i >= 0; i--)
        sift_down(array, i, size - 1, size);

    /* Heap sort */
    for (int i = size - 1; i > 0; i--) {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        print_array(array, size);
        sift_down(array, 0, i - 1, size);
    }
}
