#include "monty.h"
/**
 * custom_getline - Read a line from a file stream.
 * @lineptr: Pointer to the buffer where the line will be stored.
 * @n: Pointer to the size of the buffer.
 * @stream: The input file stream.
 *
 * Return: The number of characters read (excluding null terminator) or -1 on error or end-of-file.
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t buffer_size = 0;
	size_t current_pos = 0;
	int current_char;
    char *new_lineptr;

    if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);

	while ((current_char = fgetc(stream)) != EOF)
	{
		if (current_pos >= buffer_size - 1)
		{
			buffer_size += 128;
			new_lineptr = realloc(*lineptr, buffer_size);
			if (new_lineptr == NULL)
				return (-1);
			*lineptr = new_lineptr;
			*n = buffer_size;
		}

		(*lineptr)[current_pos++] = (char)current_char;

		if (current_char == '\n')
			break;
	}

	if (current_pos == 0 && current_char == EOF)
		return (-1);

	(*lineptr)[current_pos] = '\0';

	return (current_pos);
}
