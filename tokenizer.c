#include "main.h"

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
