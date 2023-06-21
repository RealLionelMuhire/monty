#include "monty.h"

/**
 * error_pop - prints pop error mesage
 * @l_count: line counter
 *
 * Return: always EXIT_FAILURE
 */
int error_pop(unsigned int l_count)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", l_count);
	return (EXIT_FAILURE);
}

/**
 * error_pint - prints pint error message
 * @l_count: line counter
 *
 * Return: always EXIT_FAILURE
 */
int error_pint(unsigned int l_count)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", l_count);
	return (EXIT_FAILURE);
}

/**
 * stack_error - prints error for stack or queue of smaller than 2 nodes
 * @l_count: line counter
 * @op: operation
 *
 * Return: always EXIT_FAILURE
 */
int stack_error(unsigned int l_count, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", l_count, op);
	return (EXIT_FAILURE);
}
