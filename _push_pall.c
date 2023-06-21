#include "mothy.h"

/**
 * _push - adds to the head of stack
 * @stack: head of stack
 * @l_count: is the counter of the lines
 */

void _push(stack_t **stack, unsigned int l_count)
{
	stack_t *new = malloc(sizeof(stack_t)), *tmp;

	if (new == NULL)
	{
		set_op_tok_error(malloc_error());
		return;
	}

	if (op_toks[1] == NULL || !is_valid_integer(op_toks[1]))
	{
		set_op_tok_error(no_int_error(l_count));
		free(new);
		return;
	}

	new->n = atoi(op_toks[1]);
	new->prev = NULL;



	if (*stack == NULL) /*Empty list*/
	{
		new->next = NULL;
		*stack = new;
	}
	else if (check_mode(*stack) == STACK) /*STACK mode insert at front*/
	{
		new->next = *stack;
		(*stack)->prev = new;
		*stack = new;
	}
	else
	{
		tmp = *stack;
		while (tmp->next != NULL)
			tmp = tmp->next;
		new->next = NULL;
		new->prev = tmp;
		tmp->next = new;
	}
}
