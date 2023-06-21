#include "monty.h"

/**
 * free_stack - frees memory allocated on stack
 * @stack: double pointer to stack
 */
void free_stack(stack_t **stack)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	*stack = NULL;
}

/**
 * stack_initial - initializes the stack
 * @stack: double pointer to the stack
 *
 * Return: EXIT_SUCCESS always
 */
int stack_initial(stack_t **stack)
{
	*stack = NULL;
	return (EXIT_SUCCESS);
}
