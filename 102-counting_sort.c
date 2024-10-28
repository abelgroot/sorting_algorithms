#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * counting_sort - Sorts an array of integers using Counting sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int max;
	int *count = NULL;
	size_t i;

	if (size < 2)
		return;
	max = array[0];
	/* Find the max value in the array */
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	/* Allocate memory for the count array */
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
		return;

	/* Initialize the count array with zeros */
	for (i = 0; i <= (size_t)max; i++)
		count[i] = 0;
	/* Populate the count array with frequencies */
	for (i = 0; i < size; i++)
		count[array[i]]++;

	/* Accumulate counts */
	for (i = 1; i <= (size_t)max; i++)
		count[i] += count[i - 1];

	/* Print the accumulated count array */
	print_array(count, max + 1);
	counting_sort_helper(array, size, count);
	free(count);
}

/**
 * counting_sort_helper - Helper function to complete the counting sort process
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 * @count: Pointer to the counting array with accumulated counts
 * Return: void
 */
void counting_sort_helper(int *array, size_t size, int *count)
{
	int *output = NULL;
	size_t i;

	/* Allocate memory for the output array */
	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;

	/* Build the output array based on counts */
	for (i = size; i-- > 0;)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	/* Copy sorted elements back to the original array */
	for (i = 0; i < size; i++)
		array[i] = output[i];

	/* Print the final sorted array */
	print_array(array, size);
	free(output);
}
