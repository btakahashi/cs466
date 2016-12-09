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

int main()
{
	double x = 1, err[9];
	int i;

	err[0] = error(x);
	printf("n\t\t\t\tx\t\t\t\t\t\terror\n\n");
	printf("%d\t%10.20e\t%10.20e\n", 0, x, err[0]);

	for(i = 1; i < 9; i++)
	{
		x = g(x);

		err[i] = error(x);

		printf("%d\t%10.20e\t%10.20e\n", i, x, err[i]);
	}

	return 0;
}
