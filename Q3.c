/*********************************************************************
** Program Filename: Q3.c
** Author:  Michael Ross
** Date:  7/8/17
** Description:  
** Input:  
** Output:  
*********************************************************************/

#include <stdio.h>

void sort(int* numbers, int n);

/**********************************************************************
								sort			
**********************************************************************/
void sort(int* numbers, int n) {
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = numbers[i];
		j = i - 1;

		/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		while (j >= 0 && numbers[j] > key)
		{
			numbers[j + 1] = numbers[j];
			j = j - 1;
		}
		numbers[j + 1] = key;
	}
}


/**********************************************************************
								main			
**********************************************************************/
int main(void) {
	int n = 20;

	int *myNumbers = malloc(n * sizeof(int));

	int i;
	for (i = 0; i < n; i++) {
		myNumbers[i] = 1 + rand() % 99;
		printf("%d", myNumbers[i]);
		printf("\n");
	}

	printf("\n\nCalling sort...\n\n");
	sort(myNumbers, n);

	for (i = 0; i < n; i++) {
		printf("%d", myNumbers[i]);
		printf("\n");
	}


	free(myNumbers);
}