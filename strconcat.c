#include "main.h"
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
