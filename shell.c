#include "main.h"
/**
 * main - very simple shell c:
 *
 * Return:
 */
int main(int argc, char **argv, char **env)
{
	char *buffer, **list;
	size_t bufsize = 1024;
	ssize_t chars;
	int status, success;
	pid_t pd;

	buffer = malloc(bufsize);
	list = malloc(1024 * sizeof(char *));
	if (!buffer)
		return(-1);
	while (1)
	{
		success = 0;
		printf("  -> ");
		chars = getline(&buffer, &bufsize, stdin);
		if (chars == 1)
			continue;
		buffer[chars - 1] = 0;
		printf("--*-----*------*-----*---\nel input fue: %s\n", buffer);
		list = tokenizer(buffer, " ", list);
		/*checkear si es builtin, o si tiene ruta, o si hay que buscarla*/
		success = chkBuiltin(list, env, buffer);
		if (success == 1)
			continue;
		printf("no es builtin.\n");
		success = chkPath(list);
		if (success == 1)
			continue;
		printf("no hay path predefinido.\n");
		get_path(list);
	}
	freezeBuff(buffer);
	free(list);
	printf("chau c:\n");
	return 0;
}
/**
 * str_concat - concatenates two strings.
 * @s1: first string
 * @s2: second string
 *
 * Return: pointer to concatenated string
 */
char *strconcat(char *s1, char *s2)
{
	int size1, size2, i, j;
	char *ptr;

	if (s1 == NULL && s2 == NULL)
	{
		ptr = malloc(0 * sizeof(char));
		return (ptr);
	}
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	for (size1 = 0; s1[size1] != 0; size1++)
	{
	}
	for (size2 = 0; s2[size2] != 0; size2++)
	{
	}

	ptr = malloc(size1 - 1 + size2 * sizeof(char) + 2);
	if (!ptr)
		return (NULL);
	for (i = 0; i < size1; i++)
		ptr[i] = s1[i];
	for (j = 0; j <= size2; j++, i++)
		ptr[i] = s2[j];
	return (ptr);
}
