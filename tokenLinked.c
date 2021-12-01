#include "main.h"

nodep *tokenLinked(char *string, char *separator)
{
	char *tok;
	nodep *head, *nod, *newnod;
	tok = strtok(string, separator);
	if (!tok)
		return (NULL);
	else
	{
		nod = malloc(sizeof(nodep));
		nod->path = tok;
		nod->next = NULL;
		head = nod;
	}
	while (tok)
	{
		tok = strtok(NULL, separator);
		if (tok)
		{
			newnod = malloc(sizeof(nodep));
			nod->next = newnod;
			newnod->path = tok;
			newnod->next = NULL;
			nod = newnod;
		}
	}
	return (head);
}
