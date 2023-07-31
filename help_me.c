#include "monty.h"



#define INITIAL_BUFFER_SIZE 64

int _getline(char **lineptr, size_t *n, FILE *stream) {
    size_t bufferSize = *n;
    char *buffer = *lineptr;
    int currentChar;
    size_t i = 0;

    if (lineptr == NULL || n == NULL || stream == NULL) {
        return -1; /* Invalid input parameters */
    }

    if (buffer == NULL) {
        bufferSize = INITIAL_BUFFER_SIZE;
        buffer = (char *)malloc(bufferSize);
        if (buffer == NULL) {
            return -1; /* Memory allocation failed */
        }
    }

    while ((currentChar = fgetc(stream)) != EOF) {
	char *newBuffer;
        if (i >= bufferSize - 1) { /* Leave space for the null-terminator */
            bufferSize *= 2;
            newBuffer = (char *)realloc(buffer, bufferSize);
            if (newBuffer == NULL) {
                free(buffer);
                return -1; /* Memory reallocation failed */
            }
            buffer = newBuffer;
        }

        buffer[i++] = currentChar;

        if (currentChar == '\n') {
            break;
        }
    }

    buffer[i] = '\0'; /* Null-terminate the string */

    *lineptr = buffer;
    *n = bufferSize;

    if (i == 0 && currentChar == EOF) {
        return -1; /* No characters read (end-of-file) */
    }

    return i; /* Return the number of characters read (excluding null-terminator) */
}

/**
 * add_to_head - add node to the head of the stack
 * @stack: pointer to the head of the stack
 * @value: new_value to be added
 * Return: no return
 */
void add_to_head(stack_t **stack, int value)
{
    stack_t *new_node, *current;

    current = *stack;
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        printf("Error\n");
        exit(EXIT_FAILURE);
    }

    if (current)
        current->prev = new_node;

    new_node->n = value;
    new_node->next = current;
    new_node->prev = NULL;
    *stack = new_node;
}


/**
 * free_stack - frees a doubly linked list
 * @stack: head of the stack
 */
void free_stack(stack_t *stack)
{
	stack_t *current, *next_node;

	current = stack;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
}




/**
 * execute - executes the opcode
 * @content: line content
 * @stack: head of the stack
 * @line_number: line number in the file
 * @file: pointer to the monty file
 * Return: 0 on success, 1 if the opcode is not found
 */
int execute(char *content, stack_t **stack, unsigned int line_number, FILE *file)
{
instruction_t opst[] = {
				{"push", _push}, {"pall", _pall}, {"pint", _pint},
				{"pop", _pop},
				{"swap", _swap},
				{NULL, NULL}
				};
unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	mon.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			opst[i].f(stack, line_number);
			return (0);
		}
		i++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, op);
	fclose(file);
	free(content);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}

/**
 * add_queue - add node to the tail stack
 * @head: pointer to the head of the stack
 * @n: new_value
 * Return: no return
 */
void add_queue(stack_t **head, int n)
{
	stack_t *new_node, *last_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
	}
	else
	{
		last_node = *head;
		while (last_node->next)
			last_node = last_node->next;

		last_node->next = new_node;
		new_node->prev = last_node;
	}
}


