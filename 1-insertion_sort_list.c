#include "sort.h"

/**
 * insertion_sort_list - Sort a doubly linked list of
 * integers
 * @list: Pointer to the head of the doubly linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	temp = NULL;

	while (current != NULL)
	{
		temp = current;

		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			/* Swap the nodes */
			temp->prev->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = temp->prev;
			temp->next = temp->prev;
			temp->prev = temp->prev->prev;
			temp->next->prev = temp;

			/* Update the head of the list if needed */
			if (temp->prev == NULL)
				*list = temp;
			else
				temp->prev->next = temp;

			/* Print the list after swapping */
			print_list(*list);
		}
		current = current->next;
	}
}
