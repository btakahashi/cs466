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

	for(i = 0; i < 19; i++)
	{
		err[i] = errorLow(x);
		x = g(x);
	}

	for(i = 0; i < 9; i++)
	{
		printf("error%d: %10.20e\t error%d: %10.20e\n", i, err[i], i + 10, err[i + 10]);
	}
		printf("error%d: %10.20e\n", 9, err[9]);

	printf("\nFor x0 = 2:\n");

	x = 2;

	for(i = 0; i < 19; i++)
	{
		err[i] = errorHigh(x);
		x = g(x);
	}

	for(i = 0; i < 9; i++)
	{
		printf("error%d: %10.20e\t error%d: %10.20e\n", i, err[i], i + 10, err[i + 10]);
	}
		printf("error%d: %10.20e\n", 9, err[9]);

	return 0;
}
