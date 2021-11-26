#include "main.h"

int main(void)
{
	int i;
	char frase[] = "baila tu cuerpo alegria macarena";
	char **toks = tokenizer(frase);
	
	for (i = 0; i < 7; i++)
	{
		printf("tkn[%d] = %s\n", i, toks[i]);
	}
	return (0);
}
