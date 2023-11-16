/* to be able to use printf */
#include <stdio.h>

/* to be able to use timing functionality i.e. clock()*/
#include <time.h>

long double factorial(int number); /* function prototype */
long double euler_number(long double number); /* function prototype */

/* function main begins program execution */
int main(void)
{
	/* start the clock */
	clock_t begin = clock();

	int i; /* counter */

	/* program introduction */
	printf("This program calculates the Euler number for 50 terms showing each step\n\n");

	/* loop 50 times; during each iteration call the euler_number function and display result */
	for (i = 0; i <= 50; i++) {
		printf("The euler number for %d terms is %.20Lf\n", i, euler_number(i));
	}

	/* end the clock*/
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	/* print the result */
	printf("\nThe time elapsed is %f\n", time_spent);

	return 0;
} /* end main */

/* recursive definition of function factorial */
long double factorial(int number)
{
	/* base case */
	if (number <= 1) {
		return 1;
	}
	else { /* recursive step */
		return (number * factorial(number - 1));
	}
} /* end function factorial */


/* recursive definition of function euler_number */
long double euler_number(long double number)
{
	/* base case */
	if (number == 0)
	{
		return 1;
	}

	/* recursive step */
	else
	{
		return (1.0 / factorial(number) + euler_number(number - 1));
	}
} /* end function euler_number */