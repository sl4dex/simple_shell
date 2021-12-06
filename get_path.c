#include "main.h"
/**
 * get_path - gets path of user input
 * @list: tokenized list of user input
 * @env: array of strings with env variables
 */
void get_path(char **list, char **env)
{
	nodep *headEnv, *current;
	char *tok, *envValue, *aux;
	struct stat st;

	aux = strconcat("/", list[0]);
		printf("concatene %s\n", aux);
	list[0] = aux;
	envValue = _getenv("PATH=", env);
		printf("_getenv returned : %s\n", envValue);
	headEnv = tokenLinked(envValue, ":");
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
	int i;
	int match;
	char *envValue, *matchDup;
	nodep *head, *tmp;

	for (i = 0; env[i] != 0; i++)
	{
		match = _strncmp(env[i], name, 5);
		if (match == 0)
		{
			printf("_getenv - match!\n");
			matchDup = _strdup(env[i]);
			head = tokenLinked(matchDup, "=");
			if (head)
			{
				tmp = head->next;
				envValue = tmp->path;
				printf("ENVVALUE - %s\n", envValue);
				freezeLl(head);
				//free(matchDup);
				return (envValue);
			}
			free(matchDup);
		}
	}
	return (NULL);
}
