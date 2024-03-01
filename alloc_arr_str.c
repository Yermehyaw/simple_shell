#include "shell.h"

/**
 * alloc_arr_str - Allocate memory for an array of strings amd initialize
 * tokens from a string delim by white space
 * @buf: String
 * @size: Length of string
 *
 * Return: Memory location of the array (Success)
 */

char **alloc_arr_str(char *buf, int size)
{
	int i;
	char **arr_str, *tmp_str, *tmp_buf;

	arr_str = NULL;
	tmp_buf = malloc((len_str(buf) + 1) * sizeof(char));
	if (tmp_buf == NULL)
		return (NULL);
	cpy_str(tmp_buf, buf);
	arr_str = malloc(size);
	if (arr_str == NULL)
	{
		free(tmp_buf);
		return (NULL);
	}
	tmp_str = strtok(tmp_buf, " ");
	if (tmp_str == NULL) /* No whitespace demim, single command? */
	{
		free(tmp_buf);
		free(arr_str);
		return (NULL);
	}
	for (i = 0; tmp_str; ++i)
	{
		arr_str[i] = malloc(len_str(tmp_str) + 1);/*Put sizeof yrself*/
		cpy_str(arr_str[i], tmp_str);
		tmp_str = strtok(NULL, " ");
	}
	arr_str[i] = NULL;
	free(tmp_buf);
	return (arr_str); /* Used for args */
}
