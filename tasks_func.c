#include "monty.h"
/**
 * _pall - prints the stack
 * @head: stack head
 * @counter: no used
 * Return: no return
*/
void _pall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
 * _push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void _push(stack_t **head, unsigned int counter)
{
	int n, j = 0, flag = 0;

	if (mon.arg)
	{
		if (mon.arg[0] == '-')
			j++;
		for (; mon.arg[j] != '\0'; j++)
		{
			if (mon.arg[j] > 57 || mon.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(mon.file);
			free(mon.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(mon.file);
		free(mon.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(mon.arg);
	if (mon.lifi == 0)
		add_node(head, n);
	else
		add_queue(head, n);
}

/**
 * _pint - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void _pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(mon.file);
		free(mon.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * _swap - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void _swap(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(mon.file);
		free(mon.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->n;
	h->n = h->next->n;
	h->next->n = aux;
}

/**
 * _pop - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void _pop(stack_t **head, unsigned int counter)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(mon.file);
		free(mon.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}
/**
 * _add - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void _add(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(mon.file);
		free(mon.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->n + h->next->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}

/**
  *_nop- nothing
  *@head: stack head
  *@counter: line_number
  *Return: no return
 */
void _nop(stack_t **head, unsigned int counter)
{
	(void) counter;
	(void) head;
}










