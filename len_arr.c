#include "shell.h"

/**
 * len_arr - Returns the length of an array of strings
 * @arr: Array of strings
 *
 * Return: Arrray length (Success)
 */

int len_arr(char **arr)
{
	int i, j, count;

	if (arr == NULL)
		return (0);
	i = j = count = 0;
	while (arr[i] != NULL)
	{
		while (arr[i][j] != '\0')
			++j;
		j = 0;
		++i;
		++count;
	}
	return (count);
}
