#include "lists.h"

/**
 * pop_listint - This one works to Deletes the head node of 
 * 	a listint_t list.
 * @head: it is a pointer to the address of the
 *        head of the fuction  listint_t list.
 *
 * Return: If the linked list is empty - please return 0.
 *         Otherwise - The head node's data (n).
 */
int pop_listint(listint_t **head)
{
	listint_t *tmp;
	int ret;

	if (*head == NULL)
		return (0);

	tmp = *head;
	ret = (*head)->n;
	*head = (*head)->next;

	free(tmp);

	return (ret);
}
