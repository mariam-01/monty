#include "monty.h"
/**
 * _swap - swaps the top two elements of the stack.
 * @stack: pointer to the stack head
 * @line_number: line number
 * Return: no return
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		fclose(mon.file);
		free(mon.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = first->next;

	temp = first->n;
	first->n = second->n;
	second->n = temp;
}

/**
 * _pop - removes the top element from the stack.
 * @stack: pointer to the stack head
 * @line_number: line number
 * Return: no return
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		fclose(mon.file);
		free(mon.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}

/**
 * _add - adds the top two elements of the stack.
 * @stack: pointer to the stack head
 * @line_number: line number
 * Return: no return
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		fclose(mon.file);
		free(mon.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = first->next;
	sum = first->n + second->n;
	second->n = sum;

	*stack = second;
	free(first);
}

/**
 * _nop - does nothing
 * @stack: pointer to the stack head
 * @line_number: line number
 * Return: no return
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	/* This function does nothing */
}

