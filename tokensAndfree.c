#include "main.h"
/**
 * tokenizer - tokenizes string, creating an array of strings
 * @command: string to be tokenized
 * @separator: indicated delimiter
 * @list: array of strings that will contain the tokens
 *
 * Return: tokenized array of strings
 */
char **tokenizer(char *command, char *separator, char **list)
{
	char *tkn;
	int i = 0;

	tkn = strtok(command, separator);
	if (!tkn)
		return (NULL);
	list[i] = tkn;
	printf("tkn[%d], : %s  ", i, tkn);
	i++;
	while (tkn)
	{
		tkn = strtok(NULL, separator);
		list[i] = tkn;
		printf("tkn[%d], : %s  ", i, tkn);
		i++;
	}
	putchar(10);
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
		exit(96);
	printf("node - %s\n", tok);
	nod->path = tok;
	nod->next = NULL;
	head = nod;
	while (tok)
	{
		tok = strtok(NULL, separator);
		if (tok)
		{
			printf("node - %s\n", tok);
			newnod = (nodep *)malloc(sizeof(nodep));
			if (!newnod)
				exit(96);
			nod->next = newnod;
			newnod->path = tok;
			newnod->next = NULL;
			nod = newnod;
		}
	}
	return (head);
}
/**
 * prNodes - prints nodes in current list
 * @h: head of linked list
 * Return: number of elements in linked list
 */
size_t prNodes(const nodep *h)
{
	int elem = 0;

	if (h)
	{
		elem++;
		/*TROUBLE! !!!!!!!!!!!!!!!!!*/
		printf("%s\n", h->path);
		if (h->next)
			elem += prNodes(h->next);
	}
	return (elem);
}
/**
  * freezeLl - frees nodep format linked list
  * @head: head of the linked list
  */
void freezeLl(nodep *head)
{
	nodep *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

/**
 * freezeBuff - frees input lines saved in getline
 * @str: the input obtained with getline
 */
void freezeBuff(char *str)
{
	free(str);
}
