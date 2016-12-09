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

double g(double x)
{
	return x - f(x) / df(x);
}

double error(double x)
{
	return x - sqrt(2);
}

double Mn(double en, double en_1)
{
	return en_1 / (en * en);
}

int main()
{
	double x = 1, err[9], M[5];
	int i;

	err[0] = error(x);
	printf("%d\tx = %10.20e\terror = %10.20e\n", 0, x, err[0]);

	for(i = 1; i < 9; i++)
	{
		x = g(x);

		err[i] = error(x);

		printf("%d\tx = %10.20e\terror = %10.20e\n", i, x, err[i]);
	}

	for(i = 1; i < 5; i++)
	{
		M[i - 1] = Mn(err[i], err[i + 1]);

		printf("\tM%d = %10.20e\n", i, M[i - 1]);
	}

	return 0;
}
