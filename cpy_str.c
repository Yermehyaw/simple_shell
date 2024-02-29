#include "shell.h"

/**
 * cpy_str - Copies the chars of a string into another. Including the '\0'
 * @dest: Pasting location
 * @src: Copied string
 *
 * Return: No of bytes Copied (Success)
 */

int cpy_str(char *dest, char *src)
{
	int i;

	if (src == NULL)
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (i);
}
