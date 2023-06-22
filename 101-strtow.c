#include "monty.h"
/**
 * strtow - Splits a string into an array of words.
 * @str: The input string.
 *
 * Return: A pointer to an array of strings (words). NULL on failure or if str is empty.
 */
char **strtow(char *str)
{

	int i, j, k, word_count = 0;
	char **words = (NULL);


	if (str == NULL || *str == '\0')
		return (NULL);

	
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
			word_count++;
	}

	if (word_count == 0)
		return (NULL);

	words = malloc(sizeof(char *) * (word_count + 1));
	if (words == NULL)
		return (NULL);

	for (i = 0, j = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ')
		{
			k = 0;
			while (str[i + k] != ' ' && str[i + k] != '\0')
				k++;

			words[j] = malloc(sizeof(char) * (k + 1));
			if (words[j] == NULL)
			{
				for (j--; j >= 0; j--)
					free(words[j]);
				free(words);
				return (NULL);
			}

			for (k = 0; str[i] != ' ' && str[i] != '\0'; i++, k++)
				words[j][k] = str[i];
			words[j][k] = '\0';
			j++;
		}
	}

	words[j] = NULL;
	return (words);
}
