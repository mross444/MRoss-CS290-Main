/*********************************************************************
** Program Filename: Q0.c
** Author:  Michael Ross
** Date:  7/8/17
** Description:  
** Input:  
** Output:  
*********************************************************************/
#include <stdio.h>
#include <assert.h>

struct student {
	int id;
	int score;
};

struct student* allocate();
void generate(struct student* students);
void output(struct student* students);
void summary(struct student* students);
void deallocate(struct student* stud);

/**********************************************************************
							 allocate
	Allocates memory for ten students and returns the pointer			
**********************************************************************/
struct student* allocate() {
	struct student *s = malloc(10 * sizeof(struct student));
	assert(s != 0);
	return s;
}


/**********************************************************************
							 generate
	Generates random IDs and scores for each of the ten students and
	stores them in the array of students.  Uses rand() to generate
	random numbers.  IDs are unique and between 1 and 10 (both 
	inclusive) and score is between 0 and 100 (both inclusive).			
**********************************************************************/
void generate(struct student* students) {
	int i;			/* counter */
	int j;
	int tempVal;
	int checkVal;	/* checks for ID uniqueness */
	int matchFound;

	for (i = 0; i < 10; i++) {

		//id setting
		do {
			matchFound = 0;
			tempVal = 1 + rand() % 10;
			for (j = 0; j < i; j++) {
				if (tempVal == students[j].id) {
					matchFound = 1;
				}
			}
		} while(matchFound == 1);

		students[i].id = tempVal;

		//set score
		students[i].score = 1 + rand() % 99;
	}
}

/**********************************************************************
							  output
	Prints the ids and scores of all the students (unsorted).		
**********************************************************************/
void output(struct student* students) {
	int i;

	for (i = 0; i < 10; i++) {
		printf("ID: ");
		printf("%d", students[i].id);
		printf("   Score: ");
		printf("%d", students[i].score);
		printf("\n");
	}

	printf("\n");
}

/**********************************************************************
							  summary
	Prints the minimum score, maximum score, and average score of the
	ten students.		
**********************************************************************/
void summary(struct student* students) {
	printf("------------------------------\n");
	printf("           SUMMARY            \n");
	printf("------------------------------\n");

	int min, max, sum, i;

	//start min and max off as the first value
	min = students[0].score;
	max = students[0].score;
	sum = 0;

	for (i = 0; i < 10; i++) {
		if (students[i].score < min) {
			min = students[i].score;
		}

		if (students[i].score > max) {
			max = students[i].score;
		}

		sum += students[i].score;
	}

	printf("MIN SCORE: ");
	printf("%d", min);
	printf("\nMAX SCORE: ");
	printf("%d", max);
	printf("\nAVG SCORE: ");
	printf("%d", sum/10);
	printf("\n\n");
}

/**********************************************************************
							 deallocate
	Frees the memory allocated to students.  Checks that students is 
	not NULL (NULL == 0) before attemtping to free it.		
**********************************************************************/
void deallocate(struct student* stud) {
	free(stud);
}




/**********************************************************************
								main			
**********************************************************************/
int main(void)
{
	struct student *st = 0;

	st = allocate();
	generate(st);
	output(st);
	summary(st);
	free(st);

}