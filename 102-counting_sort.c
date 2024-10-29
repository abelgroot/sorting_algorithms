#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

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

    if (!array || !count)
        return;

    /* Allocate memory for the output array */
    output = malloc(sizeof(int) * size);
    if (output == NULL)
        return;

    /* Build the output array based on counts */
    for (i = size - 1; i < size; i--)  /* Use underflow to break loop */
    {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    /* Copy sorted elements back to the original array */
    for (i = 0; i < size; i++)
        array[i] = output[i];

    free(output);
}

/**
 * counting_sort - Sorts an array of integers using Counting sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
    int max = 0, *count = NULL;
    size_t i;

    /* Input validation */
    if (!array || size < 2)
        return;

    /* Find the max value and check for negative numbers */
    max = array[0];
    for (i = 0; i < size; i++)
    {
        if (array[i] < 0)
            return;
        if (array[i] > max)
            max = array[i];
    }

    /* Allocate and check memory for count array */
    count = calloc((max + 1), sizeof(int));
    if (!count)
        return;

    /* Count occurrences of each element */
    for (i = 0; i < size; i++)
        count[array[i]]++;

    /* Calculate cumulative count */
    for (i = 1; i <= (size_t)max; i++)
        count[i] += count[i - 1];

    /* Print count array and perform sorting */
    print_array(count, max + 1);
    counting_sort_helper(array, size, count);

    free(count);
}