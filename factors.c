#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>

void factor(char *s, unsigned int line_num);
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
			line_count++;
			factor(s, line_count);
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
 ** @s: string
 ** @line_num: line number in the file
 ** Return: Nothing
 **/
void factor(char *s, unsigned int line_num)
{
	long long int p, q, n;
	long long int i = 2;

	n = atoi(s);
	while (i <= n / 2)
	{
		if (n % i == 0)
		{
			q = i;
			p = n / q;
			printf("%lld=%lld*%lld\n", n, p, q);
			break;
		}
		i++;
	}
}
