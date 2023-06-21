#include "monty.h"

/**
 * monty_script - execute monty script bytecode
 * @op_script: file descriptorto open script
 *
 * Return: EXIT_SUCCESS on success or EXIT_FAILURE on fail
 */
int monty_script(FILE *op_script)
{
	stack_t *stack = NULL;
	char *line_input = NULL;
	size_t len = 0;
	unsigned int line_num = 0;
	int exit_stt = EXIT_SUCCESS;
	void (*opcode_fnc)(stack_t **, unsigned int);

	if (stack_initial(&stack) == EXIT_FAILURE)
		return EXIT_FAILURE;

	while (getline(&line_input, &len, op_script) != -1)
	{
		line_num++;
		opcode_tok = strtow(line_input, DELIMITER);
		if (opcode_tok == NULL)
		{
			if (is_delim(line_input , DELIMITER))
				continue;
			free_stack(&stack);
			return error_alloc();
		}
		else if (opcode_tok[0][0] == "#")
		{
			free_tok();
			continue;
		}
		opcode_fnc = get_opcode(opcode_tok[0]);
		if (opcode_fnc == NULL)
		{
			free_stack(&stack);
			exit_stt = unknown_err(op_toks[0], line_num);
			free_tok();
			break;
		}
		prev_len = tok_len();
		opcode_fnc(&stack, line_num);
		if (tok_len() != prev_len)
		{
			if (opcode_tok && opcode_tok[prev_len])
				exit_stt = atoi(opcode_tok[prev_len]);
			else
				exit_stt = EXIT_FAILURE;
			free_tok();
			break;
		}
		free_tok();
	}
	free_stack(&stack);
	if (line_input && line_input == 0)
	{
		free(line_input);
		return (error_alloc);
	}
	free(line_input);
	return (exit_stt);
}

/**
 */

