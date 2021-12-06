#include "main.h"
/**
 * main - very simple shell c:
 * @argc: num of arguments
 * @argv: array of strings, each string is an argument
 * @env: array of strings, each string is an env variable
 * Return: Always 0
 */
int main(int argc, char **argv, char **env)
{
	char *buffer, **list;
	size_t bufsize = 1024;
	ssize_t chars;
	int status, success;
	pid_t pd;

	buffer = malloc(bufsize);
	list = malloc(1024 * sizeof(char *));
	if (!buffer)
		return (-1);
	while (1)
	{
		success = 0;
		printf("  -> ");
		chars = getline(&buffer, &bufsize, stdin);
		if (chars == 1)
			continue;
		buffer[chars - 1] = 0;
		list = tokenizer(buffer, " ", list);
		success = chkBuiltin(list, env, buffer);
		if (success == 1)
			continue;
		success = chkPath(list);
		if (success == 1)
			continue;
		get_path(list, env);
	}
	freezeBuff(buffer);
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
