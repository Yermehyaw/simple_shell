#include "shell.h"

/**
 * shell - The simple shell
 * @ac: Arg coint
 * @av: Arg vector
 * @env: Environ variables
 *
 * Description: Similar to sh shell. This shell is capable of the basic tasks
 * expected of any shell
 * check_string() checks for / and newline
 * cmd_checker() check for inbuilt command
 * program_path() checks if its a program in PATH
 * If neither, commnd mot found error printed and loop restarted
 *
 * Return: Always 0 (Success)
 */

int shell(int ac, char **av, char **env)
{
	char *input_line;
	size_t line_len;
	int line, wrt, check, found, prg_exit;

	(void)ac, (void)av, (void)wrt, (void)found;
	input_line = NULL; /*cant be NULL if realloc'ed in cust getline*/
	line_len = 0;
	while (1)
	{
		wrt = write(STDOUT_FILENO, "($)", 4);
		line = getline(&input_line, &line_len, stdin);
		signal(SIGINT, SIG_IGN);
		if ((int)line == -1) /*Test for EOF */
		{
			free(input_line); /* or call cmd_exit() ? */
			exit(0);/*Not sure if to return back or exit to OS*/
		}
		/* Pass to cmd_sep() first to check for ';', '$$' etc in str */
		check = check_string(input_line, env);
		if (check == 0 || check == 50) /* Special char found */
		{/* 50 is an arbitrary return value for '\n' */
			free(input_line);
			return (91);
		}
		/*found = cmd_checker(input_line, env);*/
		/*if (found == 0)*/ /* Inbuilt command found */
		/*{*/
		/*free(input_line);*/
		/*return (92);*/
		/*}*/
		prg_exit = program_path(input_line, env);
		if (prg_exit == 0)
		{
			free(input_line);
			return (93);
		}
		free(input_line);
		return (95);
	}
	return (0);
}
