#include "monty.h"

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
		set_op_token_error(malloc_error());
		return;
	}

	if (opcode_tok[1] == NULL || !is_valid_integer(opcode_tok[1]))
	{
		set_op_token_error(none_err_int(l_count));
		free(new);
		return;
	}

	new->n = atoi(opcode_tok[1]);
	new->prev = NULL;



	if (*stack == NULL) /*Empty list*/
	{
		new->next = NULL;
		*stack = new;
	}
	else if (check_md(*stack) == STACK) /*STACK mode insert at front*/
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

/**
 * _pall - print all elements in the stack and queue
 * @l_count: is the line counter
 * @stack: head of linked list of stacks
 */

void _pall(stack_t **stack, unsigned int l_count)
{
	stack_t *curr = (*stack)->next;

	while (curr)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
	(void)l_count;
}

/**
 * _pint - prints the top value of stack
 * @stack: head of linked list
 * @l_count: line counter
 */
void _pint(stack_t **stack, unsigned int l_count)
{
	if ((*stack)->next == NULL)
	{
		set_op_token_error(error_pint(l_count));
		return;
	}
	printf("%d\n", (*stack)->next->n);
}

/**
 * _pop - removes the top element
 * @stack: head of linked lists
 * @l_count:  line counter
 */
void _pop(stack_t **stack, unsigned int l_count)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		set_op_tok_error(error_pop(l_count));
		return;
	}
	next = (*stack)->next->next;
	free((*stack)->next);

	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}

/**
 * _swap - swaps two top value of the stack
 * @stack: head of the linked list
 * @l_count: line counter
 */
void _swap(stack_t **stack, unsigned int l_count)
{
	stack_t *curr;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_token_error(stack_error(l_count, "swap"));
		return;
	}

	curr = (*stack)->next;
	(*stack)->next = curr->next;
	(*stack)->prev = curr;

	if (curr->next)
		curr->next->prev = (*stack);
	curr->next = (*stack);
	curr->prev = NULL;
	(*stack) = curr;
}
