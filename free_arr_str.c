#include "shell.h"


/**
 * free_arr_str - Free an array of strings previously alloc'ed
 * @arr_str: Alloc'ed array of strings
 *
 * Description: Ensure it is used for an array of strings that has been
 * previously alloocated and not freed, as theur is no way to check for failure
 * since it return void
 */

void free_arr_str(char **arr_str)
{
	int i;

	if (arr_str == NULL)
		return;
	i = 0;
	while (arr_str[i])
	{
		free(arr_str[i]);
		++i;
	}
	free(arr_str);
}
