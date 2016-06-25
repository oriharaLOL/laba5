#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "roots.h"

int main(int argc, char *argv[])
{
	if (argc < 4) {
		fprintf(stderr, "Please, enter your coefficients!\n");
		exit(EXIT_FAILURE);
	}

	int a, b, c;
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	c = atoi(argv[3]);

	double x1, x2;
	int amount;
	roots(a, b, c, &amount, &x1, &x2);

	if (amount == 0) {
		printf("This equation has noo roots\n");
	} else if (amount == 1) {
		printf("There is only one root:\n%f\n", x1);
	} else if (amount == 2) {
		printf("There are two roots:\nx1 = %f\tx2 = %f\n", x1, x2);
	}

	return EXIT_SUCCESS;
}