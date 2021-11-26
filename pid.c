#include <stdio.h>
#include <unistd.h>
/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
	/* kind of like an integer */
	pid_t pidA;

	/* fork crea un PID hijo clon, a partir de ahora
	   las lineas de codigo se ejecutan dos veces:
	   - una con el PID original
	   - otra con el PID hijo */
	pidA = fork();

	/* entonces el printf se ejecuta dos veces,
	   - una vez con pidA original
	   - otra vez con pidA hijo */

	/* el PID del hijo siempre es 0, entonces para saber
	   si estas dentro del proceso hijo, chequea que PID == 0*/

	if (pidA == 0)
		printf("soy el proceso hijo, mi PID es : %u\n", pidA);
	else
		printf("soy el proceso padre, mi PID es : %u\n", pidA);
	return (0);
}
