#include <stdio.h>
#include <math.h>

double f(double x)
{
	return x * x - 2;
}

double df(double x)
{
	return 2 * x;
}

double d2f(double x)
{
	return 2.0;
}

double h(double x)
{
	return x - ((f(x) * df(x)) / ((df(x) * df(x)) - (f(x) * d2f(x))));
}

double error(double x)
{
	return x - sqrt(2);
}

int main()
{
	double x = 1, err[9];

	int i;

	err[0] = error(x);
	printf("%d\tx = %10.20e\terror = %10.20e\n", 0, x, err[0]);

	for(i = 1; i < 9; i++)
	{
		x = h(x);

		err[i] = error(x);

		printf("%d\tx = %10.20e\terror = %10.20e\n", i, x, err[i]);
	}

	return 0;
}
