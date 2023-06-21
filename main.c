#include "monty.h"

/**
 * main - entry point for monty interpreter
 * @argc: counter of arguments
 * @argv: array of arguments
 *
 * Return: success or error
 */
int main(int argc, char **argv)
{
	FILe *op_script;
	int exit_stt;

	if (argc != 2)
		return (error_usage());

	op_script = fopen(argv[1], "r");
	if (op_script == NULL)
		return (error_open(argv[1]));

	exit = monty_script(op_script);

	fclose(op_script);
	return (exit_stt);
}
