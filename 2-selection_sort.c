#include "sort.h"
/**
 * selection_sort - This algorithm will first find the smallest
 * element in the array and swap it with the element in the first position,
 * then it will find the second smallest element and swap it with the element
 * in the second position, and it will keep on doing this until the entire
 * array is sorted.
 * @array: Array of data to be sorted
 * @size: Size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, index = 0;
	int tmp = 0;

	if (size < 2)
		return;
	while (i < size - 1)
	{
		index = i;
		tmp = array[i];
		j = i + 1;
		while (j < size)
		{
			if (array[j] < tmp)
				tmp = array[j], index = j;
			j++;
		}
		if (index != i)
		{
			array[index] = array[i];
			array[i] = tmp;
			print_array(array, size);
		}
		i++;
	}
}
