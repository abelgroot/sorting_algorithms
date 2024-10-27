#include "sort.h"

/**
* selection_sort - Sorts an array of integers in ascending order
* using the Selection sort algorithm.
* @array: Pointer to the array of integers to be sorted.
* @size: Number of elements in the array.
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;

		/* Find the index of the minimum element in the unsorted part */
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
			min_idx = j;
		}

		/* Swap if a new minimum element is found */
		if (min_idx != i)
		{
			temp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = temp;

			/* Print the array after each swap */
			print_array(array, size);
		}
	}
}
