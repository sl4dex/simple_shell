#include "main.h"

int get_path(char **list)
{
	nodep *headEnv, *current;
	char *tok, *envValue, *aux;
	struct stat st;

	printf("get_path() - buscando ruta...   ");
	/* malloc with strconcat*/
	aux = strconcat("/", list[0]);
	list[0] = aux;
	printf("get_path() - concatene: %s\n", list[0]);
	envValue = _getenv("PATH=");
	printf("getenv returned: %s\n", envValue);
	headEnv = tokenLinked(envValue, ":");
	printf("linkeando valores\n");
	prNodes(headEnv);
	printf("-------------------------------\n");
	current = headEnv;
	while (current)
	{
		/* malloc with strconcat*/
		tok = strconcat(current->path, list[0]);
		if (stat(tok, &st) == 0)
		{
			printf("get_path - %s : existe arch, cambiando comando por ruta\n", tok);
			list[0] = tok;
			printf("ruta appended en lista: %s\n", list[0]);
			execution(list);
			free(tok);
			break;
		}
		else
		{
			printf("get_path - %s : NO existe arch\n", tok);
			current = current->next;
		}
		free(tok);
	}
	printf("get_path - no encontre nada\n");
	free(aux);
	freezeLl(headEnv);
	return (0);
}
/**
 * _getenv - creates linked list of env variable name
 * @name: name of env variable
 * Return: head of linked list
 */
char *_getenv(const char *name)
{
	extern char **environ;
	int i;
	int match;
	char *envValue, *matchDup;
	nodep *head, *tmp;

	for (i = 0; environ[i] != 0; i++)
	{
		match = strncmp(environ[i], name, 5);
		if (match == 0)
		{
			printf("match!\n");
				/*malloc*/
			matchDup = strdup(environ[i]);
			head = tokenLinked(matchDup, "=");
			if (head)
			{
				tmp = head->next;
				envValue = tmp->path;
				freezeLl(head);
				free(matchDup);
				return (envValue);
			}
			free(matchDup);
		}
	}
	printf("_getenv no hizo match\n");
	return (NULL);
}
/**
 * *_strcat - concatenates two strings.
 * @dest: string destination
 * @src: string to be concatendatd
 *
 * Return: concatenated string
 */
char *_strcat(char *dest, char *src)
{
	int pos, pos2;

	/*averigua el size de dest */
	for (pos = 0; dest[pos] != 0; pos++)
	{
	}
	/* recorre el string a copiar */
	for (pos2 = 0; src[pos2] != 0; pos2++)
	{
		/* desde el final de dest, agrega src */
		*(dest + pos + pos2) = *(src + pos2);
	}
	/* agrega el null al final del nuevo string */
	*(dest + pos + pos2) = 0;
	return (dest);
}
