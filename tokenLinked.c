#include "main.h"
/**
 * tokenLinked - tokenizes a string, each token is the string element of a node
 * @string: string to be tokenized
 * @separator: delimiter string to tokenize
 * Return: head of linked list
 */
nodep *tokenLinked(char *string, char *separator)
{
	char *tok;
	nodep *head, *nod, *newnod;

	tok = strtok(string, separator);
	if (!tok)
		return (NULL);
	nod = malloc(sizeof(nodep));
	nod->path = tok;
	nod->next = NULL;
	head = nod;
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
/**
 * prNodes - 
 * @h:
 * Return: .
 */
size_t prNodes(const nodep *h)
{
	int elem = 0;

	if (h)
	{
		elem++;
		printf("%s\n", h->path);
		if (h->next)
			elem += prNodes(h->next);
	}
	return (elem);
}
