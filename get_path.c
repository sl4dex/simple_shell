#include "main.h"

/*int main ()
{
	get_path("ls");
	return (0);
}
*/
int get_path(char **list)
{
	nodep *headEnv, *current;
	char *tok, *envValue;
	struct stat st;

	printf("get_path() - buscando ruta...   ");
	list[0] = strconcat("/", list[0]);
	printf("get_path() - concatenando: %s\n", list[0]);
	/*returns PATH env variable value*/
	envValue = _getenv("PATH=");
	printf("getenv returned: %s\n", envValue);
	/*creates linkedlist of PATH routes*/
	headEnv = tokenLinked(envValue, ":");
	printf("linkeando valores\n");
	prNodes(headEnv);
	printf("-------------------------------\n");
	current = headEnv;
	while (current)
	{
		tok = strconcat(current->path, list[0]);
		if (stat(tok, &st) == 0)
		{
			printf("get_path - %s : existe arch, cambiando comando por ruta\n", tok);
			/*!!!!!!!!! free?? */
			list[0] = tok;
			printf("ruta appended en lista: %s\n", list[0]);
			/*ejecutarlo*/
			execution(list);
			free(tok);
			break;
		}
		else
		{
			printf("get_path - %s : NO existe arch\n", tok);
			current = current->next;
		}
	}
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
	char *envValue;
	nodep *head, *tmp;

	for (i = 0; environ[i] != 0; i++)
	{
		char *matchDup;

		match = strncmp(environ[i], name, 5);
		if (match == 0)
		{
			printf("match!\n");
			matchDup = strdup(environ[i]);
			head = tokenLinked(matchDup, "=");
			if (head)
			{
				tmp = head->next;
				envValue = tmp->path;
				freezeLl(head);
				//free(matchDup);
				return (envValue);
			}
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
