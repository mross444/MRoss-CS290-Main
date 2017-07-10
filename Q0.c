/*********************************************************************
** Program Filename: Q0.c
** Author:  Michael Ross
** Date:  7/8/17
** Description:  
** Input:  
** Output:  
*********************************************************************/
#include <stdio.h>

void fooA(int* iptr);



/**********************************************************************
								fooA			
**********************************************************************/
void fooA(int* iptr) {
	printf("Value pointed to be xptr: ");
	printf("%i", iptr);
	printf("\n");
	printf("Address of xptr: ");
	printf("%x", &iptr);
	printf("\n");
}


/**********************************************************************
								main			
**********************************************************************/
int main(void)
{
	int x = 4;
	int* xptr;
	xptr = x;
	printf("Address of x (hexadecimal): ");
	printf("%x", &x);
	printf("\n");

	fooA(xptr);
}