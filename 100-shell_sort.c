#include "sort.h"

/**
* shell_sort - Sorts an array of integers in ascending order
* using the Shell sort algorithm with Knuth sequence
* @array: Pointer to the array of integers
* @size: Number of elements in the array
*/
void shell_sort(int *array, size_t size)
{
	size_t interval = 1, i, j;
	int temp;

	/**
	 * Edge case: If the array is empty or
	 * has only one element, nothing to sort
	*/
	if (array == NULL || size < 2)
		return;

	/* Step 1: Calculate the initial interval using Knuth's sequence */
	while (interval < size / 3)
		interval = interval * 3 + 1;

	/* Step 2: Sort with decreasing intervals */
	while (interval >= 1)
	{
		/* Perform insertion sort with the current interval */
		for (i = interval; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
			{
				array[j] = array[j - interval];
			}
			array[j] = temp;
		}

		/* Print the array after each interval decrease */
		print_array(array, size);
		interval = (interval - 1) / 3;  /* Reduce interval */
	}
}
