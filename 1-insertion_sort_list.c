#include "sort.h"

/**
 * insertion_sort_list - sorts an array of ints using bubble sort in ascending order
 * @list: linked-list of integers
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *cur, *cur2, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	cur = *list;
	while (cur)
	{
		cur2 = cur->next;
		while (cur->prev && cur->prev->n > cur->n)
		{
			cur->prev->next = cur->next;
			if (cur->next != NULL)
				cur->next->prev = cur->prev;
			temp = cur->prev;
			cur->prev = cur->prev->prev;
			cur->next = temp;
			cur->next->prev = cur;
			if (cur->prev != NULL)
				cur->prev->next = cur;
			else
				*list = cur;
			print_list(*list);
		}
		cur = cur2;
	}
}
