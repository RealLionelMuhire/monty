#include "monty.h"

/**
 * absolute_value - Calculates the absolute value of an integer.
 * @i: The integer to get the absolute value of.
 *
 * Return: The unsigned integer absolute value of i.
 */
unsigned int absolute_value(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}


/**
 * calculate_numbase_length - Calculates the length
 * ------------------of buffer needed for an unsigned int.
 * @num: The number to get the length needed for.
 * @base: The base of the number representation used by the buffer.
 *
 * Return: The length of buffer needed (excluding null byte).
 */
int calculate_numbase_length(unsigned int num, unsigned int base)
{
	int len = 1; /* All numbers contain at least one digit */

	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}
