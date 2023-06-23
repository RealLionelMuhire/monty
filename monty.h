#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdbool.h>

#define DELIMITER " \n\t\a\b"
#define STACK 0
#define QUEUE 1

extern char **opcode_tok;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
extern char **op_toks;

/** error handler*/
int error_usage(void);
int error_open(char *filename);
int error_alloc(void);
int unknown_err(char *op, unsigned int line_num);
int error_pop(unsigned int l_count);
int error_pint(unsigned int l_count);
int stack_error(unsigned int l_count, char *op);
void opcode_tok_err(int err_code);
int malloc_error(void);

/** monty script interpreter*/
int monty_script(FILE *op_script);
int is_line(char *line_input, char *delimiter);
void (*get_opcode(char *opcode))(stack_t**, unsigned int);
unsigned int tok_len(void);

/** stack handler*/
void free_stack(stack_t **stack);
int stack_initial(stack_t **stack);
int check_md(stack_t *stack);
int none_err_int(unsigned int l_count);

/** opcodes*/
void _push(stack_t **stack, unsigned int l_count);
void _pall(stack_t **stack, unsigned int l_count);
void _pint(stack_t **stack, unsigned int l_count);
void _pop(stack_t **stack, unsigned int l_count);
void _swap(stack_t **stack, unsigned int l_count);


/*tools and tools2*/
char *get_integer(int num);
void fill_numbase_buffer(unsigned int num,
		unsigned int base, char *buffer, int buffer_size);
unsigned int absolute_value(int i);
void free_tok(void);
int calculate_numbase_length(unsigned int num, unsigned int base);
void set_op_token_error(int error_code);
bool is_integer(const char *str);


/*strtow*/
char **strtow(const char *str, char *delim);
/*getline*/
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);


#endif
