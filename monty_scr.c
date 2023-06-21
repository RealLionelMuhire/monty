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
			if (is_line(line_input , DELIMITER))
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
 * is_line - checks if a line contains delimiter
 * @line_inputL pointer to line
 * @delimiter: delim characters
 *
 * Return: 1 if there is delimiter, else 0
 */
int is_line(char *line_input, char *delimiter)
{
	int a, b;

	for (a = 0; line_input[a]; a++)
	{
		for (b = 0; delimiter[b]; b++)
		{
			if (line_input[a] == delimiter[b])
				break;
		}
		if (delimiter[b] == '\0')
			return (0);
	}
	return (1);
}

/**
 * get_opcode - opcode functions
 * @opcode: opcodes
 *
 * Return: pointer to functions
 */
void (*get_opcode(char *opcode))(stack_t**, unsigned int)
{
	instruction_t opcode_fnc[] = {
		{"push", _push}
		{"pall", _pall}
		{NULL, NULL}
	};
	int a;

	for (a = 0; opcode_fnc[a].opcode; a++)
	{
		if (strcmp(opcode, opcode_fnc[a].opcode) == 0)
			return (opcode_fnc[a].f);
	}
	return (NULL);
}

/**
 * tok_len - length of tokens
 *
 * Return: length of the tokens
 */
unsigned int tok_len(void)
{
	unsigned int token_len = 0;

	while (opcode_tok[token_len])
		token_len++;
	return (token_len);
}
