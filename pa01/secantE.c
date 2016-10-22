#include <stdio.h>
#include <math.h>

double f(double x)
{
	return (x * x) - 2;
}

double error(double x)
{
	return x - sqrt(2);
}

int main()
{
	int i = 2;

	double q0, q1, x0 = 0, x1 = 1, x, err[9];

	q0 = f(x0);
	q1 = f(x1);

	err[0] = error(x0);
	err[1] = error(x1);
	printf("n\t\t\t\tx\t\t\t\t\t\terror\n\n");
	printf("%d\t%10.20e\t%10.20e\n", 0, x0, err[0]);
	printf("%d\t%10.20e\t%10.20e\n", 1, x1, err[1]);

	for(i = 2; i < 9; i++)
	{
		// compute xi
		x = x1 - q1 * (x1 - x0) / (q1 - q0);
		
		// update values
		x0 = x1;
		q0 = q1;
		x1 = x;
		q1 = f(x);

		// calculate error
		err[i] = error(x);

		printf("%d\t%10.20e\t%10.20e\n", i, x, err[i]);
	}
	return 0;
}
