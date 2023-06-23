#include "monty.h"


/**
 * get_integer - Converts an integer to a string representation.
 * @num: The number to convert.
 *
 * Return: A character pointer to the newly created string. NULL otherwise.
 */

char *get_integer(int num)
{
	unsigned int temp;
	int length = 0;
	long num_long = 0;
	char *ret;

	temp = absolute_value(num);
	length = calculate_numbase_length(temp, 10);

	if (num < 0 || num_long < 0)
		length++; /* negative sign */

	ret = malloc(length + 1); /* create new string */
	if (!ret)
		return (NULL);

	fill_numbase_buffer(temp, 10, ret, length);
	if (num < 0 || num_long < 0)
		ret[0] = '-';

	return (ret);
}

/**
 * fill_numbase_buffer - Fills a buffer with correct numbers up to base 36.
 * @num: The number to convert to a string given the base.
 * @base: The base of the number used in conversion (works up to base 36).
 * @buffer: The buffer to fill with the result of conversion.
 * @buffer_size: The size of the buffer in bytes.
 *
 * Return: Always void.
 */
void fill_numbase_buffer(unsigned int num, unsigned int base,
		char *buffer, int buffer_size)
{
	int rem, i = buffer_size - 1;

	buffer[buffer_size] = '\0';
	while (i >= 0)
	{
		rem = num % base;
		if (rem > 9)
			buffer[i] = rem + 87; /* 10 will be 'a', 11 = 'b', ... */
		else
			buffer[i] = rem + '0';
		num /= base;
		i--;
	}
}



/**
 * free_tok - frees the tokens of op_arr str
 */

void free_tok(void)
{
	unsigned int i = 0;

	if (opcode_tok == NULL)
		return;

	while (opcode_tok[i])
	{
		free(opcode_tok[i]);
		i++;
	}

	free(opcode_tok);
}

/**
 * set_op_token_error - Sets the last element of op_tokens to be an error code.
 * @error_code: Integer to store as a string in op_tokens.
 */
void set_op_token_error(int error_code)
{
	int tokens_len = 0, i = 0;
	char *exit_str = NULL;
	char **new_tokens = NULL;

	tokens_len = token_array_length();
	new_tokens = malloc(sizeof(char *) * (tokens_len + 2));
	if (!opcode_tok)
	{
		malloc_error();
		return;
	}
	while (i < tokens_len)
	{
		new_tokens[i] = opcode_tok[i];
		i++;
	}
	exit_str = get_integer(error_code);
	if (!exit_str)
	{
		free(new_tokens);
		malloc_error();
		return;
	}
	new_tokens[i++] = exit_str;
	new_tokens[i] = NULL;
	free(opcode_tok);
	opcode_tok = new_tokens;
}
