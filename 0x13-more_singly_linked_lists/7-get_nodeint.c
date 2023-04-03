#include "lists.h"

/**
 * get_nodeint_at_index - this fuction Locates a given node of
 *                        a listint_t linked list.
 * @head: this is  A pointer to the head of the listint_t list.
 * @index: it that it indices start at 0.
 *
 * Return: If the node does not exist - kindly give back NULL.
 *         Otherwise - the located node.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int node;

	for (node = 0; node < index; node++)
	{
		if (head == NULL)
			return (NULL);

		head = head->next;
	}

	return (head);
}
