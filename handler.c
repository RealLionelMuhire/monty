#include "monty.h"

/**
 * error_usage - prints messages for error usage
 * Return: always EXIT_FAILURE
 */

int error_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * error_open - prints error for opened file or file name
 * Return: always EXIT_FAILURE
 */

int error_open(void)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}
