#include "sort.h"
/**
 * insertion_sort_list - a function to sort a doubly linked list of integers
 * using insertion sort
 * @list: a pointer to the head of a doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp, *bigger;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}
	current = (*list)->next;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			bigger = temp->prev;
			if (bigger->prev != NULL)
				bigger->prev->next = temp;
			else
				(*list) = temp;
			if (temp->next != NULL)
				temp->next->prev = bigger;
			temp->prev = bigger->prev;
			bigger->next = temp->next;
			temp->next = bigger;
			bigger->prev = temp;
			print_list(*list);
		}
		print_list(*list);
	}
}
