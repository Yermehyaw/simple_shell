#include "shell.h"


/**
 * cmd_concat - Will concatenate two strings and allocate memory to hold
 * the concatenated string
 * @str1: First string
 * @str2: Second string
 *
 * Return: Memory location of the alloc'ed string (Success)
 */

char *cmd_concat(char *str1, char *str2)
{
	int i, j, total_sz;
	char *ap_str;

	ap_str = NULL;
	if (str1 == NULL && str2 == NULL)
		return (NULL);
	total_sz = len_str(str1) + len_str(str2) + 2; /* +2 for mull bytes */
	if (str1 == NULL || str2 == NULL)
	{
		ap_str = malloc(total_sz);
		if (ap_str == NULL)
			return (NULL);
	}
	else
	{
		ap_str = realloc(str1, total_sz);
		if (ap_str == NULL)
			return (NULL);
	}
	for (i = 0; str1[i] != '\0'; ++i)
		ap_str[i] = str1[i];
	for (j = 0; str2[j] != '\0'; ++j)
	{
		ap_str[i] = str2[j];
		++i;
	}
	ap_str[i] = '\0';
	return (ap_str);
}
