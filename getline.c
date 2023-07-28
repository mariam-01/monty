#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

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
