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

/**
 * check_md - checks the mode of the stack_t
 * @stack: head of the linked list
 *
 * Return: STACK in staxk mode, QUEUE in queue mode, otherwise 2
 */
int check_md(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}

/**
 * none_err_int - prints invalid push error
 * @l_count: line counter
 *
 * Return: always EXIT_FAILURE
 */
int none_err_int(unsigned int l_count)
{
	fprintf(stderr, "L%u: usage: push integer\n", l_count);
	return (EXIT_FAILURE);
}
