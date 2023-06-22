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




