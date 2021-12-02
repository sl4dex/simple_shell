#include "main.h"

int chkBuiltin(char **list, char **env)
{
	int pid, status, i;

	printf("entre a builtin\n");
	if (strcmp(list[0], "env") == 0)
	{
		printf("ejecutando...\n");
		for (i = 0; env[i]; i++)
			printf("%s\n", env[i]);
	}
	else if (0)
	{
		pid = fork();
		if (!pid)
		{
		}
		else
			wait(&status);
	}
	return(0);
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
