#include <stdio.h>
#include <stdlib.h>

void swap(char *x, char *y);
void perm(char [], int, int);

int main(int argv, char **argc)
{
	int temp;
	char list[] = "abcd";
	perm(list, 0, 3);
	printf("\n");
	return 0;
}

void swap(char *x, char *y)
{
	char temp = *x;
	*x = *y;
	*y = temp;
}

void perm(char list[], int i, int n)
{
	int j;
	if (i == n)
	{
		for(j = 0; j <= n; j++)
			printf("%c", list[j]);
		printf("   ");
	}
	else
	{
		for(j = i; j <= n; j++)
		{
			swap(&list[i], &list[j]);
			perm(list, i+1, n);
			swap(&list[i], &list[j]);
		}			
	}
}
