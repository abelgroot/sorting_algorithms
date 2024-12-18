#include "sort.h"

/**
* insertion_sort_list - a function to sort a duobly linked list of integers
* using insertion sort
* @list: a pointer to the head of a doubly linked list
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	current = (*list)->next;
	while (current != NULL)
	{
		temp = current;
		current = current->next;

		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			temp->prev->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = temp->prev;
			temp->next = temp->prev;
			temp->prev = temp->next->prev;
			if (temp->prev != NULL)
				temp->prev->next = temp;
			else
				(*list) = temp;
			temp->next->prev = temp;
			print_list(*list);
		}
	}
}
