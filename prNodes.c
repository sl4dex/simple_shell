#include "main.h"

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
