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

int error_open(char *filename)
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
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * unknown_err - prints unknown error
 * @op: operation
 * @line_num: line count
 * Return: always EXIT_FAILURE
 */
int unknown_err(char *op, unsigned int line_num)
{
	fprintf(stderr, "Error: Unknown instruction %s\n", op, line_num);
	return (EXIT_FAILURE);
}


/**
 * opcode_tok_err - Sets last element of op_toks to be an error code.
 * @err_code: Integer to store as a string in op_toks.
 */
void opcode_tok_err(int err_code)
{
	int len = 0, i = 0;
	char *exit_str = NULL;
	char **new_toks = NULL;

	len = tok_len();
	new_toks = malloc(sizeof(char *) * (len + 2));
	if (!new_toks)
	{
		error_alloc();
		return;
	}

	for (i = 0; i < len; i++)
		new_toks[i] = op_toks[i];

	exit_str = get_integer(err_code);
	if (!exit_str)
	{
		free(new_toks);
		error_alloc();
		return;
	}
	new_toks[i++] = exit_str;
	new_toks[i] = NULL;
	free(op_toks);
	op_toks = new_toks;
}
