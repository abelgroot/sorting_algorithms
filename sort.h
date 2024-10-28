#ifndef	SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
/**
* struct listint_s - Doubly linked list node
*
* @n: Integer stored in the node
* @prev: Pointer to the previous element of the list
* @next: Pointer to the next element of the list
*/
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/** bubble selection and quick sort */
void bubble_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void quick_sort(int *array, size_t size);


/**helper funstion */
int partition(int *array, int low, int high, size_t size);
void quick_sort_helper(int *array, int low, int high, size_t size);

/** shell sort with */
void shell_sort(int *array, size_t size);

/** Merge Sort */
void merge_sort(int *array, size_t size);
void merge(int *array, int *left, int *right, size_t left_size, size_t right_size);

#endif /* SORT_H */
