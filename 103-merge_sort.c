#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merges two subarrays of array[] in sorted order.
 * @array: The main array containing both subarrays.
 * @left: Pointer to the left subarray.
 * @right: Pointer to the right subarray.
 * @left_size: Size of the left subarray.
 * @right_size: Size of the right subarray.
 */
void merge(int *array, int *left, int *right,
					 size_t left_size, size_t right_size)
{
	size_t i = 0, j = 0, k = 0;

	printf("Merging...\n[left]: ");
	for (i = 0; i < left_size; i++)
		printf("%d%s", left[i], (i < left_size - 1) ? ", " : "\n");

	printf("[right]: ");
	for (i = 0; i < right_size; i++)
		printf("%d%s", right[i], (i < right_size - 1) ? ", " : "\n");

	i = 0;
	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}

	while (i < left_size)
		array[k++] = left[i++];
	while (j < right_size)
		array[k++] = right[j++];

	printf("[Done]: ");
	for (i = 0; i < left_size + right_size; i++)
		printf("%d%s", array[i], (i < left_size + right_size - 1) ? ", " : "\n");
}

/**
 * merge_sort_recursive - Recursively splits and merges an array.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_sort_recursive(int *array, size_t size)
{
	size_t i, mid;
	int *left, *right;

	if (size < 2)
		return;

	mid = size / 2;
	left = malloc(mid * sizeof(int));
	right = malloc((size - mid) * sizeof(int));

	if (!left || !right)
		return;

	for (i = 0; i < mid; i++)
		left[i] = array[i];
	for (i = mid; i < size; i++)
		right[i - mid] = array[i];

	merge_sort_recursive(left, mid);
	merge_sort_recursive(right, size - mid);
	merge(array, left, right, mid, size - mid);

	free(left);
	free(right);
}

/**
 * merge_sort - Top-level merge sort function.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	merge_sort_recursive(array, size);
}
