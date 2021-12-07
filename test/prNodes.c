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

