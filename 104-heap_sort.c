#include "sort.h"
/**
 * heap_sort - sorts an array in ascending order using the Heap sort algorithm
 * @array: array to be sorted
 * @size: size of the array to be sorted
 * Return: is void
 */
void heap_sort(int *array, size_t size)
{
	int temp, i;

	for (i = size / 2 - 1 ; i >= 0 ; i--)
	{
		heapify(array, i, size, size);
	}

	i = size - 1;
	while (i > 0)
	{
		temp = array[i];
		array[i] = array[0];
		array[0] = temp;
		print_array(array, size);
		heapify(array, 0, i, size);
		i--;
	}
}

/**
 * heapify - puts the array into the heap
 * @array: array to be sorted
 * @min: element farthest to the left
 * @max: element farthest to the right
 * @size: size of the array
 * Return: is void
 */
void heapify(int *array, int min, int max, size_t size)
{
	int root, temp, right, left;

	root = min;
	left = 2 * root + 1;
	right = 2 * root + 2;

	if (left < max && array[left] > array[root])
	{
		root = left;
	}

	if (right < max && array[right] > array[root])
	{
		root = right;
	}

	if (min != root)
	{
		temp = array[root];
		array[root] = array[min];
		array[min] = temp;
		print_array(array, size);
		heapify(array, root, max, size);
	}
}
