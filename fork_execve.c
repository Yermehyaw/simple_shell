#include "shell.h"


/**
 * fork_execve - Fork and execute a command
 * @cmd_path: Alloc'ed memory. Path to command
 * @args: Command arguments
 * @mod: Command modifier, frees @cmd_path when set to 1, otherwise dosent
 *
 * Return: Always 0 (Success)
 */

int fork_execve(char *cmd_path, char **args, int mod)
{
	/*pid_t parent_pid;*/
	pid_t child_pid;
	int exit_code;

	/*parent_pid = getpid();*/
	child_pid = fork();
	if (child_pid < 0)
		return (1);
	if (child_pid == 0) /* In child process */
	{
		if (access(cmd_path, X_OK) == -1) /*if pid can exec program*/
			return (1);
		if (execve(cmd_path, args, NULL) == -1)
		{
			perror("Couldnt exec command\n");
			exit (1);
		}
	}
	if (child_pid > 0)
	{
		wait(&exit_code);
		if (mod == 1)
			free(cmd_path);
		return (0);
	}
	return (1);
}
