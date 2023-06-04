#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>

long long int factor(long long int n);
/**
 ** main - entry point
 ** @argc: number of arguments
 ** @argv: array of argc
 ** Return: success on exit, exit failure otherwise
 **/
int main(int argc, char **argv)
{
	char s[500];
	size_t line_count = 0;
	FILE *fp;
	long long int n, p, q;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: factor file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp != NULL)
	{
		while (fgets(s, sizeof(s), fp) != NULL)
		{
			n = atoll(s);
			q = factor(n);
			p = n / q;
			printf("%lld=%lld*%lld\n", n, p, q);
		}
		fclose(fp);
	}
	else
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		fclose(fp);
		exit(EXIT_FAILURE);
	}

	return (0);
}

/**
 ** factor - factorises a number
 ** @n: number to be factored
 ** Return: returns factor
 **/
long long int factor(long long int n)
{
	long long int i = 11;

	if (n % 2)
		return (2);
	if (n % 3)
		return (3);
	if (n % 5)
		return (5);
	if (n % 7)
		return (7);
	while (i <= n / 2)
	{
		if (n % i == 0)
			break;
		i += 2;
		if (n % i == 0)
			break;
		i += 4;
		if (n % i == 0)
			break;
		i += 2;
		if (n % i == 0)
			break;
		i += 2;
	}
	return (i);
}
