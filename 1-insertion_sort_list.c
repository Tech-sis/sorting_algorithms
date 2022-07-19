#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * @list: pointer to the head of the list
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next, *temp;

	if (list == NULL || *list == NULL)
		return;
	current = *list;
	while (current->next != NULL)
	{
		next = current->next;
		if (current->n > next->n)
		{
			temp = next->next;
			next->next = next->next->prev;
			next->prev = current;
			current->next = next->next;
			current->prev = next;
			next->next = temp;
			if (next->next != NULL)
				next->next->prev = next;
			*list = current;
		}
		current = current->next;
		print_list(*list);
	}
}
