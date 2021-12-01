#include "main.h"

/*int main()
{
	char *str = _getenv("PATH");
	if (str)
		printf("Returned: %s\n", str);
	return (0);
}*/
nodep *_getenv(const char *name)
{
	extern char **environ;
	int i;
	char *match;
	nodep head;

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
