#include "main.h"
/**
 * get_path - gets path of user input
 * @list: tokenized list of user input
 * @env: array of strings with env variables
 */
void get_path(char **list, char **env)
{
	nodep *headEnv, *current;
	char *tok, *envValue, *dupenv, *aux;
	struct stat st;

	aux = strconcat("/", list[0]);
		printf("concatene %s\n", aux);
	list[0] = aux;
	envValue = _getenv("PATH=", env);
	dupenv = _strdup(envValue);
	printf("_getenv returned : %s\n", envValue);
	headEnv = tokenLinked(dupenv, ":");
	prNodes(headEnv);
	current = headEnv;
	while (current)
	{
		tok = strconcat(current->path, list[0]);
		printf("concatene %s\n", tok);
		if (stat(tok, &st) == 0)
		{
			printf("existe %s\n", tok);
			list[0] = tok;
			execution(list);
			free(tok);
			break;
		}
		else
			current = current->next;
		free(tok);
	}
	free(dupenv);
	free(aux);
	freezeLl(headEnv);
}
/**
 * _getenv - creates linked list of env variable name
 * @name: name of env variable
 * @env: array of strings with env variables
 * Return: head of linked list
 */
char *_getenv(char *name, char **env)
{
	int i, match;

	/* only works with PATH env variable */
	for (i = 0; env[i] != 0; i++)
	{
		/* _strlen(PATH=) == 5 (0 to 4) */
		match = _strncmp(env[i], name, 5);
		if (match == 0)
		{
			printf("_getenv - match! %s\n", env[i] + 5);
			return (env[i] + 5);
		}
	}
	return (NULL);
}
