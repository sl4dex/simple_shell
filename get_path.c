#include "main.h"

/*int main ()
{
	get_path("ls");
	return (0);
}
*/
int get_path(char *word)
{
	nodep *headEnv1, *headEnv2, *current;
	char **list;
	char *tok;
	struct stat st;

	printf("get_path() - buscando ruta...  ");
	word = strconcat("/", word);
	printf("get_path() - concatenando: %s\n", word);
	/*returns PATH env variable value*/
	headEnv1 = _getenv("PATH=");
	prNodes(headEnv1);
	printf("linked1\n");
	/*creates linkedlist of PATH routes*/
	headEnv2 = tokenLinked2(headEnv1->path, ":");
	printf("linked2\n");
	prNodes(headEnv2);
	printf("-------------------------------\n");
	current = headEnv2;
	while (current)
	{
		tok = strconcat(current->path, word);
		if (stat(tok, &st) == 0)
		{
			printf("%s - existe arch\n", tok);
			/*ejecutarlo y liberar*/
			freezeLl(headEnv1);
			freezeLl(headEnv2);
			break;
		}
		else
		{
			printf("%s - NO existe arch\n", tok);
			current = current->next;
		}
	}
	freezeLl(headEnv1);
	freezeLl(headEnv2);
	return (0);
}
/**
 * _getenv - creates linked list of env variable name
 * @name: name of env variable
 * Return: head of linked list
 */
nodep *_getenv(const char *name)
{
	extern char **environ;
	int i;
	int match;
	nodep *head;

	for (i = 0; environ[i] != 0; i++)
	{
		match = strncmp(environ[i], name, 5);
		if (match == 0)
		{
			printf("match!\n");
			head = tokenLinked(environ[i], "=");
			if (head)
				return (head->next);
		}
	}
	printf("Error\n");
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
