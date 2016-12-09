#include <stdio.h>
#include <math.h>

double f(double x)
{
	return 2 * cos(5 * x) + 2 * cos (4 * x) + 6 * cos(3 * x) + 4 * cos(2 * x) + 10 * cos(x) + 3;
}

double df(double x)
{
	return -10 * sin(5 * x) - 8 * sin(4 * x) - 18 * sin(3 * x) - 8 * sin(2 * x) - 10 * sin(x);
}

double d2f(double x)
{
	return -50 * cos(5 * x) - 32 * cos(4 * x) - 54 * cos(3 * x) - 16 * cos(2 * x) - 10 * cos(x);
}

double g(double x)
{
	return x - f(x) / df(x);
}

double h(double x)
{
	return x - ((f(x) * df(x)) / ((df(x) * df(x)) - (f(x) * d2f(x))));
}

double errorLow(double x)
{
	return x - M_PI / 3;
}

double errorHigh(double x)
{
	return x - 2 * M_PI / 3;
}

int main()
{
	double x = 1, err[19];
	int i;

	printf("For x0 = 1:\n");

	err[0] = errorLow(x);
	printf("%d\tx = %10.20e\terror = %10.20e\n", 0, x, err[0]);

	for(i = 1; i < 19; i++)
	{
		x = h(x);

		err[i] = errorLow(x);

		printf("%d\tx = %10.20e\terror = %10.20e\n", i, x, err[i]);
	}

	printf("\nFor x0 = 2:\n");

	x = 2;
	err[0] = errorHigh(x);
	printf("%d\tx = %10.20e\terror = %10.20e\n", 0, x, err[0]);

	for(i = 1; i < 19; i++)
	{
		x = h(x);

		err[i] = errorHigh(x);

		printf("%d\tx = %10.20e\terror = %10.20e\n", i, x, err[i]);
	}

	return 0;
}
