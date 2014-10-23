#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_SIZE 101
#define SWAP(x, y ,t) ((t) = (x), (x) = (y), (y) = (t))
#define COMPARE(x,y) (((x) < (y)) ? -1:((x) == (y)) ? 0:1)
/* compare x and y, return -1 for less than, 0 for equal 1 for greater */


void sort(int [], int);
void print_list(int [], int);
int binarysearch(int [], int, int, int);


int main(int argv, char **argc)
{
	int i, n, search_num;
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

	//sort
	sort(list, n);
	print_list(list, n);

	//binary search
	printf("Enter the search number: ");
	scanf("%d", &search_num);
	printf("%d index is %d.\n", search_num, binarysearch(list, search_num, 0, n-1));
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

int binarysearch(int list[], int search_num, int left_index, int right_index)
{
	int middle_index;
	if(left_index <= right_index)
	{
		middle_index = (left_index + right_index) / 2;
		switch(COMPARE(list[middle_index], search_num))
		{
			case -1: return binarysearch(list, search_num, middle_index+1, right_index);
 			case  0: return middle_index;
			case  1: return binarysearch(list, search_num, left_index, middle_index-1);
		}
	}
	return -1;
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

