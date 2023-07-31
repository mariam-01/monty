#include "monty.h"
/**
 * _pall - prints the stack
 * @stack: pointer to the stack head
 * @counter: unused
 * Return: no return
 */
void _pall(stack_t **stack, unsigned int counter)
{
	stack_t *current = *stack;
	(void)counter;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * _push - add node to the stack
 * @stack: pointer to the stack head
 * @line_number: line number
 * Return: no return
 */
void _push(stack_t **stack, unsigned int line_number)
{
	int n, j = 0, flag = 0;
	char *arg = mon.arg;

	if (arg)
	{
		if (arg[0] == '-')
			j++;
		while (arg[j] != '\0')
		{
			if (arg[j] < '0' || arg[j] > '9')
				flag = 1;
			j++;
		}

		if (flag == 1)
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			fclose(mon.file);
			free(mon.content);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		fclose(mon.file);
		free(mon.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	n = atoi(arg);
	if (mon.lifi == 0)
		add_to_head(stack, n);
	else
		add_queue(stack, n);
}

/**
 * _pint - prints the top
 * @stack: pointer to the stack head
 * @line_number: line number
 * Return: no return
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(mon.file);
		free(mon.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

