#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p, s)\
	if (!(p = malloc(s)))\
	{\
		fprintf(stderr, "Insufficient memory");\
		exit(EXIT_FAILURE);\
	}

void version_1();
void version_2();
void version_3();

int main(int argc, char **argv)
{
	version_1();
	version_2();
	version_3();
	return 0;
}

void version_1()
{
	int i, *pi;
	float f, *pf;
	pi = (int *) malloc(sizeof(int));
	pf = (float *) malloc(sizeof(float));
	*pi = 1024;
	*pf = 3.14;
	printf("an integer = %d, a float = %f\n", *pi, *pf);
	free(pi);
	free(pf);
}

void version_2()
{
	int i, *pi;
	float f, *pf;
	if(!(pi = malloc(sizeof(int))) || !(pf = malloc(sizeof(float))))
	{
		fprintf(stderr, "Insufficient memory");
		exit(EXIT_FAILURE);
	}
	*pi = 1024;
	*pf = 3.14;
	printf("an integer = %d, a float = %f\n", *pi, *pf);
	free(pi);
	free(pf);
}

void version_3()
{
	int i, *pi;
	float f, *pf;
	MALLOC(pi, sizeof(int));
	MALLOC(pf, sizeof(float));
	*pi = 1024;
	*pf = 3.14;
	printf("an integer = %d, a float = %f\n", *pi, *pf);
	free(pi);
	free(pf);
}
