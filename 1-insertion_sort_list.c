#include "sort.h"
/**
 * swap_two - swap to doubly linked list elements
 * @a: left element
 * @b: right element
 * @list: all doubly linked list
 * Return: pointer to a element (actual)
 */
listint_t *swap_two(listint_t *a, listint_t *b, listint_t **list)
{
	if (a->prev)
		(a->prev)->next = b;
	else
		*list = b, b->prev = NULL;
	if ((b->next))
		(b->next)->prev = a;
	b->prev = a->prev;
	a->prev = b;
	a->next = b->next;
	b->next = a;
	return (a);
}
/**
 * insertion_sort_list - sorts list in ascending order
 * @list: a doubly linked list of integers to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *actual;
	listint_t *prev, *back;

	if (!list || !(*list) || !(*list)->next)
		return;

	actual = (*list)->next;
	while (actual)
	{
		prev = actual->prev;
		back = actual;
		while (back->prev && back->n < prev->n)
		{
			actual = swap_two(prev, back, list);
			print_list(*list);
			if (!back->prev)
				break;
			prev = back->prev;
		}
		actual = actual->next;
		prev = prev->next;
	}
}