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

double Mn(double err0, double err1)
{
	return fabs(err1) / pow(fabs(err0), 1.618);
}

int main()
{
	int i = 2;

	double q0, q1, x0 = 0, x1 = 1, x, err[9], M[8];

	q0 = f(x0);
	q1 = f(x1);

	err[0] = error(x0);
	err[1] = error(x1);

	printf("%d\tx = %10.20e\terror = %10.20e\n", 0, x0, err[0]);
	printf("%d\tx = %10.20e\terror = %10.20e\n", 1, x1, err[1]);

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

		printf("%d\tx = %10.20e\terror = %10.20e\n", i, x, err[i]);
	}

	for(i = 1; i < 8; i++)
	{
		M[i - 1] = Mn(err[i], err[i+1]);
		printf("\tM%d = %10.20e\n", i, M[i - 1]);
	}

	return 0;
}
