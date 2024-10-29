#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * swap - Swap two elements in an array and print the array.
 * @array: The array where elements are to be swapped.
 * @i: The index of the first element to swap.
 * @j: The index of the second element to swap.
 * @size: The size of the array.
 */
void swap(int *array, size_t i, size_t j, size_t size)
{
	int temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
	print_array(array, size);
}

/**
 * sift_down - Ensure the heap property is maintained in the array.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @start: The starting index of the subtree.
 * @end: The last index of the heap.
 */
void sift_down(int *array, size_t size, size_t start, size_t end)
{
	size_t root = start;
	size_t child;

	while ((child = root * 2 + 1) <= end)
	{
		if (child + 1 <= end && array[child] < array[child + 1])
			child++;
		if (array[root] < array[child])
		{
			swap(array, root, child, size);
			root = child;
		}
		else
			return;
	}
}

/**
 * heapify - Build a heap from the array.
 * @array: The array to be heapified.
 * @size: The size of the array.
 */
void heapify(int *array, size_t size)
{
	ssize_t start = (size / 2) - 1;

	while (start >= 0)
	{
		sift_down(array, size, start, size - 1);
		start--;
	}
}

/**
 * heap_sort - Sort an array of integers in ascending order using heap sort.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	size_t end;

	if (!array || size < 2)
		return;

	heapify(array, size);

	for (end = size - 1; end > 0; end--)
	{
		swap(array, 0, end, size);
		sift_down(array, size, 0, end - 1);
	}
}
