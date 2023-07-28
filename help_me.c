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
 * add_node - add node to the head stack
 * @head: head of the stack
 * @n: new_value
 * Return: no return
*/
void add_node(stack_t **head, int n)
{

	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (aux)
		aux->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}

/**
* execute - executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @content: line content
* Return: no return
*/
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
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
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}


/**
* free_stack - frees a doubly linked list
* @head: head of the stack
*/
void free_stack(stack_t *head)
{
	stack_t *aux;

	aux = head;
	while (head)
	{
		aux = head->next;
		free(head);
		head = aux;
	}
}

/**
 * add_queue - add node to the tail stack
 * @n: new_value
 * @head: head of the stack
 * Return: no return
*/
void add_queue(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}


