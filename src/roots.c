#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "roots.h"

void roots(int a, int b, int c, int *amount, double *x1, double *x2)
{
	if (a == 0) {
		fprintf(stderr, "First coefficient must be positive!\n");
		return;
	}

	double discriminant;
	discriminant = (b * b) - (4 * a * c);

	if (discriminant < 0) {
		*amount = 0;
	} else if (discriminant == 0) {
		*x1 = - b / (2 * a);
		*amount = 1;
	} else if (discriminant > 0) {
		*x1 = (- b + sqrt(discriminant)) / (2 * a);
		*x2 = (- b - sqrt(discriminant)) / (2 * a);
		*amount = 2;
	}
}