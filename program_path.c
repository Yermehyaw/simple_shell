#include "shell.h"

/**
 * program_path - This program will check for a program in PATH and execute it
 * (Frees all memory allocated in it except @buf when successful or not)
 * @buf: Line of input from getline(). A string.
 * @env: Environ variables
 *
 * Return: 0 (Success)
 */

int program_path(char *buf, char **env)
{
	char **temp_env, **args, *found_path;

	/* Allocating and initializing */
	temp_env = alloc_arr_str2(env, len_arr(env) * sizeof(char *));/*editb*/
	if (temp_env == NULL) /* Could not allocate memory */
		return (80);
	args = alloc_arr_str(buf, word_no(buf) * sizeof(char *));
	if (args == NULL) /* Single command, no space delimiter */
	{
		args = malloc(2 * sizeof(char *));
		if (args == NULL)
			return (81);
		args[0] = buf;
		args[1] = NULL;
	}
	/* Find the command in PATH */
	found_path = get_dir(args, temp_env);
	if (found_path == NULL)
	{
		free_all(args, temp_env, NULL);
		return (82);
	}
	/* Execute the path/dir  where command is found */
	program_path_exec(found_path, args);
	free_all(args, temp_env, NULL);
	return (0);
}



/**
 * alloc_arr_str2 - Allocate memory for an array of strings and initialize
 * tokens from another arr of  string delim by white space
 * @buf: array of strings
 * @size: Lenght of array
 *
 * Return: Memory location of the array (Success)
 */

char **alloc_arr_str2(char **buf, int size)
{
	int i;
	char **arr_str;

	arr_str = malloc((size + 1) * sizeof(char *));
	/**
	 * The added values to the alloc is not neccessary but prevemts an
	 * unsual edge case e.g if any of the string is "" and maybe more
	 */
	if (arr_str == NULL)
		return (NULL);
	i = 0;
	while (buf[i])
	{
		arr_str[i] = malloc((len_str(buf[i]) + 1) * sizeof(char));
		if (arr_str == NULL)
		{
			free_arr_str(arr_str);
			return (NULL);
		}
		cpy_str(arr_str[i], buf[i]);
		++i;
	}
	arr_str[i] = NULL;
	return (arr_str);
}

/**
 * program_path_exec - Concatenates two strings and to form a command path
 * which it executes
 * @found_path: The path where thr command was found
 * @args: The name of command and its arguments
 *
 */

void program_path_exec(char *found_path, char **args)
{
	int success;
	char *command_path;

	command_path = cmd_concat(found_path, args[0]);
	/* Memory is alloc'ed for command_path in cmd_concat */
	if (command_path == NULL)
		return;
	success = fork_execve(command_path, args, 1);
	if (success != 0) /* fork_exec() not successful */
		free(command_path);
}
