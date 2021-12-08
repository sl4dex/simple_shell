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
	i++;
	while (tkn)
	{
		tkn = strtok(NULL, separator);
		list[i] = tkn;
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
		exit(96);
	nod->path = tok;
	nod->next = NULL;
	head = nod;
	while (tok)
	{
		tok = strtok(NULL, separator);
		if (tok)
		{
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
