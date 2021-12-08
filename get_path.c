#include "main.h"
/**
 * get_path - gets path of user input
 * @list: tokenized list of user input
 * @argv: list of arguments in main function
 * @env: array of strings with env variables
 */
void get_path(char **list, char **argv, char **env)
{
	nodep *headEnv, *current;
	char *tok, *envValue, *dupenv, *aux;
	struct stat st;
	int found = 0;

	/* concatenates / to the command */
	aux = strconcat("/", list[0]);
	list[0] = aux;
	/* gets PATH env variable (the value before "=") */
	envValue = _getenv("PATH=", env);
	dupenv = _strdup(envValue);
	/*tokenizes PATH env value, creating a linked list with each path*/
	headEnv = tokenLinked(dupenv, ":");
	current = headEnv;
	/* while node exists*/
	while (current)
	{
		/* adds "/command" to each path */
		tok = strconcat(current->path, list[0]);
		/* if the file in that path exists */
		if (stat(tok, &st) == 0)
		{
			found = 1;
			list[0] = tok;
			execution(list, argv);
			free(tok);
			break;
		}
		else
			current = current->next;
		free(tok);
	}
	if (found == 0)
		perror(argv[0]);
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
			return (env[i] + 5);
		}
	}
	return (NULL);
}
