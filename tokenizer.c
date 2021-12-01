#include "main.h"

/**
 * tokenizer - gets string from shell.c and separates each word into an array
 *		element.
 * @string: string to tokenize
 *
 * Return: array of tokens
 */
char **tokenizer(char string[], char *separator)
{
	int i;
	char **tokens;
	
	//creates string array in heap to make a succesful return
	tokens = malloc(sizeof(char *) * 1024);
	for (i = 0; i < 1024; i++)
		tokens[i] = malloc(sizeof(char) * 255);
	i = 0;
	tokens[i] = strtok(string, separator);
	if (!tokens[i])
	{
		printf("Error\n");
		return (NULL);
	}
	while (tokens[i])
	{
		i++;
		tokens[i] = strtok(NULL, separator);
	}
	return (tokens);
}
