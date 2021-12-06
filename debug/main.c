#include "main.h"

int main()
{
	int len;
	nodep *head;
	char PATH[100] = "PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin";
	head = tokenLinked(PATH, "=");
	len = prNodes(head);
	printf("nodos: %d\n", len);
	printf("------------------------\n");
	head = head->next;
	head = tokenLinked(head->path, ":");
	len = prNodes(head);
	printf("nodos: %d\n", len);
	return(0);
}
