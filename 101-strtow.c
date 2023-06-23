#include "monty.h"
/**
 * count_tokens - Counts the number of tokens in a string.
 * @str: The string to count tokens from.
 * @delim: The delimiter character.
 *
 * Return: The number of tokens.
 */
static int count_tokens(const char *str, char *delim)
{
	int count = 0;
	int i = 0;
	int len = strlen(str);

	while (i < len)
	{
		while (str[i] && str[i] == *delim)
			i++;

		if (str[i] != '\0')
			count++;

		while (str[i] && str[i] != *delim)
			i++;
	}

	return (count);
}

/**
 * strtow - Splits a string into an array of tokens.
 * @str: The string to split.
 * @delim: The delimiter character.
 *
 * Return: The array of tokens, or NULL on failure.
 */
char **strtow(const char *str, char *delim)
{
	char **tokens;
	
	int i = 0;
	int token_len = 0;
	int token_index = 0;
	int str_len = strlen(str), num_tokens;

	if (str == NULL || str[0] == '\0')
		return (NULL);

	num_tokens = count_tokens(str, delim);
	tokens = malloc((num_tokens + 1) * sizeof(char *));
	if (tokens == NULL)
		return (NULL);


	while (i <= str_len)
	{
		if (str[i] && str[i] != *delim)
		{
			token_len++;
		}
		else if (token_len > 0)
		{
			tokens[token_index] = malloc((token_len + 1) * sizeof(char));
			if (tokens[token_index] == NULL)
			{
				while (token_index > 0)
					free(tokens[--token_index]);
				free(tokens);
				return (NULL);
			}

			strncpy(tokens[token_index], str + i - token_len, token_len);
			tokens[token_index][token_len] = '\0';
			token_len = 0;
			token_index++;
		}

		i++;
	}

	tokens[token_index] = NULL;
	return (tokens);
}
