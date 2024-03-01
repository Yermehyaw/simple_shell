#include "shell.h"


/**
 * check_string - Check for the presence of a special char in a string
 * @input_line: Line of input(from getlibe())
 * @env: Environ variables
 *
 * Return:O (Success)
 */

int check_string(char *input_line, char **env)
{
	int i;
	char *buf, *temp_buf;

	(void)env;
	if (input_line[0] == '\n') /* Cam be moved to cmd_sep() later on */
		return (50);
	buf = malloc(len_str(input_line) + 1);
	if (buf == NULL) /* Failed to alloc memory */
		return (68);
	cpy_str(buf, input_line);
	temp_buf = strtok(buf, " ");
	if (temp_buf == NULL) /* Probably a string without a space delim */
		temp_buf = buf;
	for (i = 0; temp_buf[i] != '\0'; ++i)
	{
		if (temp_buf[i] == '/')
		{
			printf("path_exec will be called in the %dth char\n",
			       i);
			path_exec(input_line);
			free(buf);
			return (0); /*The presence of / indicates a cmd path */
		}
	}
	/* '/' was not found */
	free(buf);
	return (69);
}
