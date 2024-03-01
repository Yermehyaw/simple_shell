#include "shell.h"

void print_arr_str(char **); /* For debugging */

/**
 * path_exec - Will execute a path and its arguments in a string passed to it
 * @buf: A string
 *
 * Return: 0 (Success)
 */

int path_exec(char *buf)
{
	char **args;

	/* Tokenize string using a dynmically alloced array using " " delim*/
	args = alloc_arr_str(buf, word_no(buf) * sizeof(char *));
	if (args == NULL)/* Only the path no delim*/
		args[0] = buf;
	print_arr_str(args);
	printf("Control reached here\n");
	fork_execve(args[0], args, 0);
	free_arr_str(args);
	return (0);
}
