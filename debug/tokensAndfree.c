#include "main.h"
/**
 *tokenizer -
 * @command
 * @
 * @
 * Return: .
 */
char **tokenizer(char *command, char *separator, char **list)
{
	char *tkn;
	int i = 0;

	tkn = strtok(command, separator);
	if (!tkn)
	{
		printf("No hubo input\n");
		return(NULL);
	}
	else
	{
		printf("Tkn = %s\n", tkn);
		*(list + i) = tkn;
		i++;
	}
	while (tkn)
	{
		tkn = strtok(NULL, separator);
		printf("Tkn = %s\n", tkn);
		*(list + i) = tkn;
		i++;
	}
	return (list);
}

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
	nod = (nodep *)malloc(sizeof(nodep));
	if (!nod)
		printf("malloc de nodo fallo\n");
	nod->path = tok;
	nod->next = NULL;
	head = nod;
	while (tok)
	{
		tok = strtok(NULL, separator);
		if (tok)
		{
			newnod = (nodep *)malloc(sizeof(nodep));
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
/**
  * freezeLl - frees nodep format node's list
  * @pathLink: the linked list
  */
void freezeLl(nodep *head)
{
	nodep *tmp;

	while (head)
	{
		printf("free - soy %s\n", head->path);
		tmp = head;
		head = head->next;
		//printf("free - me movi al siguiente, soy %s\n", head->path);
		//free(tmp->path);
		free(tmp);
	}
	printf("free - saliendo\n");
}

/**
 * freezeBuff - frees input lines saved in getline
 * @str: the input obtained with getline
 */
void freezeBuff(char *str)
{
	free(str);
}
