#include "monty.h"
#include <stdio.h>

mon_t mon = {NULL, NULL, NULL, 0};

/**
 * main - Monty code interpreter
 * @argc: number of arguments
 * @argv: Monty file location
 * Return: 0 on success, otherwise EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
    FILE *mfile;
    char *line = NULL;
    size_t len = 0;
    ssize_t read_len = 1;
    stack_t *stack = NULL;
    unsigned int line_number = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return EXIT_FAILURE;
    }

    mfile = fopen(argv[1], "r");
    if (!mfile)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    while (read_len > 0)
    {
        line = NULL;
        read_len = _getline(&line, &len, mfile);
        mon.content = line;
        line_number++;

        if (read_len > 0)
        {
            execute(line, &stack, line_number, mfile);
        }

        free(line);
    }

    free_stack(stack);
    fclose(mfile);
    return 0;
}
