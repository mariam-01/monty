#include "monty.h"

/* Global variable for the stack */
stack_t *global_stack = NULL;

/**
 * push - Pushes an element onto the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number in the Monty byte code file.
 */
void push(stack_t **stack, unsigned int line_number)
{
    /* Implement the push opcode functionality here */
    /* You need to extract the integer argument from the byte code file */

    /* Example error handling when there is no argument or it's not an integer */
    if (/* Argument is not an integer */)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    /* Create a new node and push it onto the stack */
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    /* Initialize the new node */
    new_node->n = /* Integer value */;
    new_node->prev = NULL;
    new_node->next = *stack;

    /* Update the previous node's 'prev' pointer if applicable */
    if (*stack != NULL)
        (*stack)->prev = new_node;

    /* Update the stack pointer to the new head */
    *stack = new_node;
}

/**
 * pall - Prints all the values on the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number in the Monty byte code file.
 */
void pall(stack_t **stack, unsigned int line_number)
{
    /* Implement the pall opcode functionality here */
    /* Traverse the stack and print its elements */
    stack_t *current = *stack;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
