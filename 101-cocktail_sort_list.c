#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @node_a: The first node to swap.
 * @node_b: The second node to swap.
 */
void swap_nodes(listint_t *node_a, listint_t *node_b)
{
	listint_t *prev_a = node_a->prev;
	listint_t *next_b = node_b->next;

	if (prev_a)
		prev_a->next = node_b;
	node_b->prev = prev_a;

	node_a->next = next_b;
	if (next_b)
		next_b->prev = node_a;

	node_b->next = node_a;
	node_a->prev = node_b;
}

/**
 * forward_pass - Performs a forward pass over the list.
 * @list: Pointer to the pointer of the first node of the list.
 * @current: Pointer to the current node.
 * Return: 1 if swapped, otherwise 0.
 */
int forward_pass(listint_t **list, listint_t **current)
{
	int swapped = 0;

	while ((*current)->next != NULL)
	{
		if ((*current)->n > (*current)->next->n)
		{
			swap_nodes(*current, (*current)->next);
			if ((*current)->prev == NULL)
				*list = *current; /* Update head of the list */
			print_list(*list);
			swapped = 1;
		}
		else
		{
			*current = (*current)->next;
		}
	}
	return (swapped);
}

/**
 * backward_pass - Performs a backward pass over the list.
 * @list: Pointer to the pointer of the first node of the list.
 * @current: Pointer to the current node.
 * Return: 1 if swapped, otherwise 0.
 */
int backward_pass(listint_t **list, listint_t **current)
{
	int swapped = 0;

	while (*current && (*current)->prev != NULL)
	{
		if ((*current)->n < (*current)->prev->n)
		{
			swap_nodes((*current)->prev, *current);
			if ((*current)->prev == NULL)
				*list = *current; /* Update head of the list */
			print_list(*list);
			swapped = 1;
		}
		else
		{
			*current = (*current)->prev;
		}
	}
	return (swapped);
}

/**
 * cocktail_sort_list - Sorts a doubly linked
 * list of integers in ascending order.
 * @list: Pointer to the pointer of the first node of the list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	int swapped;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swapped = 0;
		current = *list;

		/* Forward pass */
		swapped = forward_pass(list, &current);
		if (!swapped)
			break;

		/* Move to the last sorted node */
		swapped = 0;
		current = current->prev;

		/* Backward pass */
		swapped = backward_pass(list, &current);
	} while (swapped);
}
