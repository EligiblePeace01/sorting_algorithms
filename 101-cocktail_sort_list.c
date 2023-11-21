#include "sort.h"

size_t listint_len(listint_t *h);

/**
 * cocktail_sort_list - sorts a doubly linked list
 * of integers in ascending order using the Cocktail shaker
 * sort algorithm
 * @list: doubly linked list of integers
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *f = NULL;
	listint_t *b = NULL;
	listint_t *aux = NULL;
	size_t n, i;

	if (list == NULL || *list == NULL)
		return;

	n = listint_len(*list);

	if (n < 2)
		return;

	b = *list;
	for (i = 0; i < n; i++)
	{
		for (f = b->next; f->next != NULL; f = f->next)
		{
			if (f->prev->n > f->n)
			{
				if (f->prev->prev != NULL)
					f->prev->prev->next = f;
				else
					*list = f;

				if (f->next != NULL)
					f->next->prev = f->prev;

				aux = f->prev->prev;

				f->prev->next = f->next;
				f->prev->prev = f;

				f->next = f->prev;
				f->prev = aux;

				print_list(*list);
				f = f->next;
			}
		}
		for (b = f; b->prev != NULL;)
		{
			if (b->prev->n > b->n)
			{
				if (b->prev->prev != NULL)
					b->prev->prev->next = b;
				else
					*list = b;

				if (b->next != NULL)
					b->next->prev = b->prev;

				aux = b->prev->prev;

				b->prev->next = b->next;
				b->prev->prev = b;

				b->next = b->prev;
				b->prev = aux;

				print_list(*list);
			}
			else
				b = b->prev;
		}
	}
}

/**
 *  listint_len - number of elements in a linked listint_t list.
 * @h: header of listint_t
 * Return: the number of nodes
 */
size_t listint_len(listint_t *h)
{
	size_t len_list;

	for (len_list = 0; h != NULL; len_list++)
		h = h->next;
	return (len_list);
}
