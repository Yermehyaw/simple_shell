#include "shell.h"


/**
 * print_arr_str - Will print an array of strings
 * @arr_str: Array of strings
 */


void print_arr_str(char **arr_str)
{
	int i;

	if (arr_str == NULL)
		printf("The array is NULL\n");
	i = 0;
	while (arr_str[i])
	{
		printf("%s\n", arr_str[i]);
		++i;
	}
}
