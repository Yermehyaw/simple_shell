#include "shell.h"


/**
 * free_all - Frees all array of strings passed to it
 * @arr1: An array of strings
 *
 * Description: Ensure it is used for an array of strings that has been
 * previously alloocated and not freed, as theur is no way to check for failure
 * since it return void.
 * The last argument passed to free_all() MUST be NULL
 */

void free_all(char **arr1, ...)
{
	int i;
	char **arr;
	va_list ap;

	if (arr1 == NULL)
		return;
	va_start(ap, arr1);
	free_arr_str(arr1);
	arr = va_arg(ap, char **);
	while (arr != NULL) /*Function call must be terminated by a NULL param*/
	{
		while (arr[i])
		{
			free(arr[i]);
			++i;
		}
		free(arr);
		arr = va_arg(ap, char **);
	}
	free(arr);
	va_end(ap);
}
