#include "main.h"
#define UNUSED __attribute__((__unused__))
/**
 * main - very simple shell c:
 * @argc: num of arguments
 * @argv: array of strings, each string is an argument
 * @env: array of strings, each string is an env variable
 * Return: Always 0
 */
int main(UNUSED int argc, char **argv, char **env)
{
	char *buffer, **list;
	size_t bufsize = 1024;
	ssize_t chars;
	int success;

	buffer = malloc(bufsize);
	list = malloc(1024 * sizeof(char *));
	if (!buffer)
		return (-1);
	signal(SIGINT, SIG_IGN);
	while (1)
	{
		success = 0;
		if (isatty(1) == 1)
		write(1, "  -> ", 5);
		chars = getline(&buffer, &bufsize, stdin);
		if (chars == 1)
		continue;
		if (chars == -1)
		break;
		buffer[chars - 1] = 0;
		list = tokenizer(buffer, "\n \t", list);
		success = chkBuiltin(list, env, buffer);
		if (success == 1)
		continue;
		success = chkPath(list);
		if (success == 1)
		continue;
		get_path(list, argv, env);
		if (isatty(1) == 0)
		break;
	}
	free(buffer);
	free(list);
	return (0);
}
/**
 * strconcat - concatenates two strings.
 * @s1: first string
 * @s2: second string
 *
 * Return: pointer to concatenated string
 */
char *strconcat(char *s1, char *s2)
{
	int size1, size2, i, j;
	char *ptr;

	if (s1 == NULL && s2 == NULL)
	{
		ptr = malloc(0 * sizeof(char));
		return (ptr);
	}
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	for (size1 = 0; s1[size1] != 0; size1++)
	{
	}
	for (size2 = 0; s2[size2] != 0; size2++)
	{
	}

	ptr = malloc(size1 - 1 + size2 * sizeof(char) + 2);
	if (!ptr)
		return (NULL);
	for (i = 0; i < size1; i++)
		ptr[i] = s1[i];
	for (j = 0; j <= size2; j++, i++)
		ptr[i] = s2[j];
	return (ptr);
}
/**
 * _strlen - returns the length of a string.
 * @s: pointer to string (array of chars)
 *
 * Return: String size
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
	}
	return (i);
}
/**
 * _strdup - points to a space in heap containg the string parameter
 * @str: string to be duped
 *
 * Return: pointer to memory space in heap
 */
char *_strdup(char *str)
{
	char *ptr;
	int size, j;

	if (str == NULL)
		return (NULL);
	for (size = 0; str[size] != 0; size++)
	{
	}
	size++;
	ptr = (char *) malloc(size * sizeof(char));
	if (!ptr)
		return (NULL);
	for (j = 0; j <= size; j++)
		ptr[j] = str[j];
	return (ptr);
}
/**
 * _strncmp - compares at most the first n bytes of s1 and s2
 * @s1: first string to be compared
 * @s2: second string to be compared
 * @n: number of bytes to compare
 *
 * Return: ascii numeric difference of first occurance, 0 if equal
 */
int _strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i;
	int sum;

	if (!n)
		return (0);
	for (i = 0; s1[i] != 0 && s2 != 0 && i < n; i++)
	{
		sum = s1[i] - s2[i];
		if (sum != 0)
			return (sum);
	}
	return (0);
}
