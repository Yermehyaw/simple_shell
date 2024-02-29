#include "shell.h"

/**
 * len_str - Retyrns the length of a string minus the null byte
 * @str: String
 *
 * Return: String length (Success)
 */

int len_str(const char *str)
{
	int i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
		++i;
	return (i);
}
