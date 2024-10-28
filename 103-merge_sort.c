#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
* merge - Merges two sorted subarrays of `array` into a single sorted subarray
* @array: The array to sort
* @temp: Temporary array for merging
* @left: Starting index of the left subarray
* @mid: Ending index of the left subarray and start of right subarray
* @right: Ending index of the right subarray
*/
void merge(int *array, int *temp, int left, int mid, int right)
{
	int i = left, j = mid + 1, k = left, x;

	printf("Merging...\n[left]: ");
	for (x = left; x <= mid; x++)
		printf("%d%s", array[x], x < mid ? ", " : "");
	printf("\n[right]: ");
	for (x = mid + 1; x <= right; x++)
		printf("%d%s", array[x], x < right ? ", " : "");
	printf("\n");

	/* Merge two halves into temp array */
	while (i <= mid && j <= right)
	{
		if (array[i] <= array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}

	/* Copy remaining elements from the left half */
	while (i <= mid)
		temp[k++] = array[i++];

	/* Copy remaining elements from the right half */
	while (j <= right)
		temp[k++] = array[j++];

	/* Copy sorted elements back to original array */
	for (i = left; i <= right; i++)
		array[i] = temp[i];

	printf("[Done]: ");
	for (x = left; x <= right; x++)
		printf("%d%s", array[x], x < right ? ", " : "");
	printf("\n");
}

/**
* merge_sort_recursive - Recursively sorts and merges subarrays
* @array: The array to sort
* @temp: Temporary array for merging
* @left: The starting index of the array segment
* @right: The ending index of the array segment
*/
void merge_sort_recursive(int *array, int *temp, int left, int right)
{
	int mid;

	if (left >= right)
		return;

	mid = left + (right - left) / 2;

	/* Sort left half */
	merge_sort_recursive(array, temp, left, mid);

	/* Sort right half */
	merge_sort_recursive(array, temp, mid + 1, right);

	/* Merge sorted halves */
	merge(array, temp, left, mid, right);
}

/**
* merge_sort - Sorts an array of integers in ascending order
* using the top-down Merge Sort algorithm
* @array: The array to sort
* @size: The size of the array
*/
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (size < 2)
		return;

	/* Allocate temporary array for merging */
	temp = malloc(size * sizeof(int));

	if (!temp)
		return;

	/* Start recursive merge sort */
	merge_sort_recursive(array, temp, 0, size - 1);

	/* Free temporary array */
	free(temp);
}
