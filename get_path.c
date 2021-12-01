#include "main.h"

int main ()
{
	get_path("/ls");
	return (0);
}

int get_path(char *word)
{
	nodep *headEnv, *current;
	char **list;
	char *tok;
	struct stat st;
	
	/*returns PATH env variable value*/
	headEnv = _getenv("PATH");
	/*creates linkedlist of PATH routes*/
	headEnv = tokenLinked(headEnv->path, ":");
	prNodes(headEnv);
	printf("-------------------------------\n");
	current = headEnv;
	while (current)
	{
		tok = strconcat(current->path, word);
		if (stat(tok, &st) == 0)
		{
			printf("%s - existe arch\n", tok);
			break;
		}
		else
		{
			printf("%s - NO existe arch\n", tok);
			current = current->next;
		}
	}
	return (0);
}

nodep *_getenv(const char *name)
{
	extern char **environ;
	int i;
	char *match;
	nodep *head;

	for (i = 0; environ[i] != 0; i++)
	{
		match = strstr(environ[i], name);
		if (match)
		{
			head = tokenLinked(match, "=");
			if (head)
				return (head->next);
		}
	}
	printf("Error\n");
	return (NULL);
}
