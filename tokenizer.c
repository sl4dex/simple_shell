#include "main.h"

/**
 * tokenizer - gets string from shell.c and separates each word into an array
 *		element.
 * @string: string to tokenize
 *
 * Return: array of tokens
 */
char **tokenizer(char string[])
{
	int i;
	//char str[1024] = "con mi kelly slate tamo bien";
	char **tokens;
	
	//creates string array in heap to make a succesful return
	tokens = malloc(sizeof(char *) * 1024);
	i = 0;
	tokens[i] = strtok(string, " ");
	if (!tokens[i])
	{
		printf("Error\n");
		return (NULL);
	}
	while (tokens[i])
	{
		i++;
		tokens[i] = strtok(NULL, " ");
		if (!tokens[i])
			break;
	}
	return (tokens);
}
