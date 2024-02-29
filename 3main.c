#include "shell.h"

/**
 * main - Shell Entry point. Controls the shell execution process
 * @ac: Arg count
 * @av: Arg vector
 * @env: Environ variables
 *
 * Return: Always 0 (Success)
 */

int main(int ac, char **av, char **env)
{
	int shell_ret;

	shell_ret = 1;
	while (shell_ret != 0)
	{
		shell_ret = shell(ac, av, env);
	}
	return (0);
}
