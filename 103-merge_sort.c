#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge - merges 2 sub arrays of arr[]
 * @array: array to be sorted
 * @sub: sub array for sorted elements
 * @size: size of the array to be sorted
 */

void merge(int *array, int *sub, size_t size)
{

	size_t temp = size / 2, i = 0, j = 0, k;

	if (size < 2)
		return;

	merge(array, sub, temp);
	merge(array + temp, sub + temp, size - temp);

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array, temp);
	printf("[right]: ");
	print_array(array + temp, size - temp);
	for (k = 0; k < size; k++)
		if (j >= size - temp || (i < temp && array[i] < (array + temp)[j]))
		{
			sub[k] = array[i];
			i++;
		}
		else
		{
			sub[k] = (array + temp)[j];
			j++;
		}
	for (k = 0; k < size; k++)
		array[k] = sub[k];
	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge_sort - initiate merge sort
 * @array: array to be sorted
 * @size: size of the array to be sorted
 */

void merge_sort(int *array, size_t size)
{
	int *temp;

	if (!array || size < 2)
		return;

	temp = malloc(sizeof(*temp) * size);
	if (!temp)
		return;

	merge(array, temp, size);
	free(temp);
}
