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

/**
 * error_alloc - prints allocation error
 * Return: always EXIT_FAILURE
 */
int error_alloc(void)
{
	fprintf(stderr, "Error: allocation failed\n");
	return (EXIT_FAILURE);
}

/**
 * unknown_err - prints unknown error 
 * Return: always EXIT_FAILURE
 */
int unknown_err(char *op, unsigned int line_num)
{
	fprintf(stderr, "Error: Unknown opcode %s\n", op, line_num);
	return (EXIT_FAILURE);
}
