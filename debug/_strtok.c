#include "main.h"
#include <stdlib.h>


/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter
 *
 * @str: string to copy
 *
 * Return: *dup to the duplicate string or NULL if it fails
 */
char *_strdup(char *str)
{
	unsigned int a;
	char *dup;

	if (!str)
		return (NULL);
	for (a = 0; str[a]; a++)
		;
	dup = malloc(a + 1);
	if (!dup)
		return (NULL);
	for (a = 0; str[a]; a++)
		dup[a] = str[a];
	dup[a] = 0;
	return (dup);
}

/**
 * _strtok - returns a tokenized list
 *
 * @str: string to tokenize
 * @separator: token's delimiter
 *
 * Return: a token list or NULL if it fails
 */

char **_strtok(char *str, char separator)
{
	char *tokList[1024], **tokListReturn, auxTok[1024];
	int exit = 0, i = 0, j = 0, k = 0, y = 0, tokLen = 0;

	for (i = 0; exit == 0; i++)
	{
		if (str[i] != separator)
			tokLen++;
		if (str[i] == separator)
			if (tokLen != 0)
			{
				j = i - tokLen;
				for (y = 0; y < tokLen; y++, j++)
					auxTok[y] = str[j];
				tokList[k] = _strdup(auxTok);
				freezer(auxTok);
				tokLen = 0, k++;
			}

		if (!str[i + 1])
		{
			j = (i + 1) - tokLen;

			for (y = 0; y < tokLen; y++, j++)
				auxTok[y] = str[j];
			tokList[k] = _strdup(auxTok);
			freezer(auxTok);
			tokList[k + 1] = 0;
			exit++;
		}
	}
	tokListReturn = tokList;
	return (tokListReturn);
}

/**
 * freezer - sets to null the pointer positions
 *
 * @str: string to set
 *
 * Return: 0 in success -1 if it fails
 */

int freezer(char *str)
{
	int i;

	if (!str)
		return (-1);
	for (i = 0; str[i]; i++)
	{
		str[i] = 0;
	}
	return (0);
}
