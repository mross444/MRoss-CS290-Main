/*********************************************************************
** Program Filename: Q2.c
** Author:  Michael Ross
** Date:  7/8/17
** Description:  
** Input:  
** Output:  
*********************************************************************/

#include <stdio.h>

int foo(int* a, int* b, int c);

/**********************************************************************
								foo			
**********************************************************************/
int foo(int* a, int* b, int c) {
	*a = 2 * (*a);
	*b = (*b) / 2;
	//c = *a + *b;
	return c;
}

/**********************************************************************
								main			
**********************************************************************/
int main(void) {
	int x, y, z;
	x = 5;
	y = 6;
	z = 7;

	printf("x: ");
	printf("%d", x);
	printf("\ny: ");
	printf("%d", y);
	printf("\nz: ");
	printf("%d", z);

	printf("\n\nCalling foo...\n\n");
	foo(&x, &y, z);

	printf("x: ");
	printf("%d", x);
	printf("\ny: ");
	printf("%d", y);
	printf("\nz: ");
	printf("%d", z);

	printf("\n\n");


}