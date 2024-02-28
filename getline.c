#include "shell.h"

#define BUFFER_SIZE 256

/**
 * map_fd - return symbolic constant for a fd
 * @value: integer value for fd
 *
 * Return: symbolic constant or -1 for failure
 */

int map_fd(int value)
{
	if (value == 0)
		return (STDIN_FILENO);
	else if (value == 1)
		return (STDOUT_FILENO);
	else if (value == 2)
		return (STDERR_FILENO);
	write(1, "\nwrong fd\n", 11);
	exit(-1);
}

/**
 * mem_alloc - default memory allocate
 * @buffer: pointer to the buffer
 * @buffer_size: bytes for the buffer size.
 *
 * Return: 0 success -1 failed
 */

ssize_t mem_alloc(char **buffer, size_t *buffer_size)
{
	*buffer_size = BUFFER_SIZE;
	*buffer = malloc(*buffer_size);

	if (*buffer == NULL)
	{
		write(1, "\nmalloc failed\n", 16);
		return (-1);
	}
	return (0);
}

/**
 * mem_realloc - resize memory if buffer is filled
 * @buffer: pointer to buffer holding read chars
 * @buffersize: bytes for the buffer
 *
 * Return: 0 success, -1 fails
 */

ssize_t mem_realloc(char **buffer, size_t *buffersize)
{
	*buffersize *= 2; /* dynamically double buffersize */
	char *temp_ptr = realloc(*buffer, *buffersize);

	if (temp_ptr == NULL)
	{
		write(1, "\nmem_realloc failed\n", 21);
		return (-1);
	}
	*buffer = temp_ptr;
	return (0);
}

/**
 * _getline - get a line from a file stream
 * @lineptr: pointer to buffer for read chars
 * @n: pointer to bytes for buffer
 * @fd: file descriptor
 *
 * Return: bytes read or -1 failed or EOF
 */

ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	ssize_t bytesRead = 0;
	size_t count = 0;
	char c;

	if (lineptr == NULL || n == NULL)
		return (-1); /* Invalid arguments */

	/* Allocate buffer if it's NULL or smaller than the default */
	if (*lineptr == NULL || *n < BUFFER_SIZE)
	{
		if (mem_alloc(lineptr, n) == -1)
			return (-1);
	}
	int sc = map_fd(fd); /* get symbolic constant for given fd */
	/* Read characters until newline or end of file */
	while (read(sc, &c, 1) == 1 && c != '\n' && c != EOF)
	{
		(*lineptr)[count++] = c;
		bytesRead++;
		/* Resize the buffer if buffer size is exceeded */
		if (count >= *n - 1)
		{
			if (mem_realloc(lineptr, n) == -1)
				return (-1);
		}
	}
	if (c == EOF) 
		return (EOF);
	if (bytesRead == 0) return (-1); /* No characters read and reached end
					    of file */
	/* Null-terminate the string */
	(*lineptr)[bytesRead] = '\0';
	return (bytesRead);
}
