#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_SIZE 101
#define SWAP(x, y ,t) ((t) = (x), (x) = (y), (y) = (t))

void sort(int [], int);
void print_list(int [], int);

int main(int argv, char **argc)
{
	int i, n;
	int list[MAX_SIZE];

	printf("Enter the number of numbers to generate: ");
	scanf("%d", &n);
	if( n < 1 || n > MAX_SIZE) 
	{
		fprintf(stderr, "Improper value of n\n");
		exit(EXIT_FAILURE);
	}
	for (i=0; i < n; i++)
	{
		list[i] = rand() % 1000;
		printf("%d ", list[i]);
	}
	printf("\n");
	sort(list, n);
	print_list(list, n);
	return 0;
}

void sort(int list[], int n)
{
	int i, j, min, temp;
	for (i=0; i < n-1; i++)
	{
		min = i;
		for(j=i+1; j < n; j++)
		{
			if(list[j] < list[min])
				min = j;
		}
		SWAP(list[i], list[min], temp);
	}
}
 
void print_list(int list[], int n)
{
	int i;
	for (i=0; i < n; i++)
	{
		printf("%d ", list[i]);
	}
	printf("\n");
}

