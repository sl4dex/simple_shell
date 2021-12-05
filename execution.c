#include "main.h"
/**
 * chkBuiltin - checks if input is a builtin
 * @list: array of strings with the input
 * @env: the current environment
 * Return: 1 if input is a builtin, 0 otherwise
 */
int chkBuiltin(char **list, char **env, char *buffer)
{
	int pid, status, i;

	printf("entre a builtin\n");
	if (_strcmp(list[0], "env") == 0 && list[1] == NULL)
	{
		printf("ejecutando...\n");
		for (i = 0; env[i]; i++)
			printf("%s\n", env[i]);
		return (1);
	}
	else if (_strcmp(list[0], "exit") == 0 && list[1] == NULL)
	{
			freezeBuff(buffer);
			free(list);
			exitpls();
	}
	return(0);
}
/**
 * chkPath - checks if input already has a path
 * @list:
 *
 * Return: 1 if input already has a path, 0 otherwise
 */
int chkPath(char **list)
{
		printf("chequeando ruta\n");
		if ((strncmp(list[0], "/", 1) == 0) ||
			(strncmp(list[0], ".", 1) == 0))
		{
			printf("tiene ruta\n");
			execution(list);
			return (1);
		}
		else
		{
			printf("no tiene ruta?\n");
			return (0);
		}
}
/**
 * execution -
 * @list:
 */
void execution(char **list)
{
	int status, pd;

	pd = fork();
	if (pd == 0)
	{
		if (execve(list[0], list, NULL) == -1)
			perror("Error");
	}
	wait(&status);
}
/**
 * exitpls -
 * @
 */
void exitpls(void)
{
	/*
	   free...
	*/
	exit(98);
}
/**
 * _strcmp - compares ASCII numeric value of two strings.
 * @s1: first string
 * @s2: second string
 *
 * Return: ASCII numeric difference between s1 and s2
 */
int _strcmp(char *s1, char *s2)
{
	int pos, result;

	for (pos = 0; s1[pos] != 0; pos++)
	{
		if (s1[pos] == s2[pos])
			result = 0;
		else
		{
			result = s1[pos] - s2[pos];
			break;
		}
	}
	return (result);
}
