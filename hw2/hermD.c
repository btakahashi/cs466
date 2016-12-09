#include <stdio.h>

#define n 3

int main()
{
	double x[4];
	x[0] = -1.0;
	x[1] = -0.5;
	x[2] = 0.0;
	x[3] = 0.5;

	double fx[4];
	fx[0] = 0.86199480;
	fx[1] = 0.95802009;
	fx[2] = 1.0986123;
	fx[3] = 1.2943767;

	double fpx[4];
	fpx[0] = 0.15536240;
	fpx[1] = 0.23269654;
	fpx[2] = 0.33333333;
	fpx[3] = 0.45186776;

	double z[10], Q[10][10];

	int i, j;

	for(i = 0; i <= n; i++)
	{
		z[2 * i] = x[i];
		z[2 * i + 1] = x[i];
		Q[2 * i][0] = fx[i];
		Q[2 * i + 1][0] = fx[i];
		Q[2 * i + 1][1] = fpx[i];
		if(i != 0)
		{
			Q[2 * i][1] = (Q[2 * i][0] - Q[2 * i - 1][0]) / (z[2 * i] - z[2 * i - 1]);
		}
	}

	for(i = 2; i <= 2 * n + 1; i++)
	{
		for(j = 2; j <= i; j++)
		{
			Q[i][j] = (Q[i][j - 1] - Q[i - 1][j - 1]) / (z[i] - z[i - j]);
		}
	}

	for(i = 0; i <= 2 * n + 1; i++)
	{
		printf("Q[%d][%d] = %22.14e\n", i, i, Q[i][i]);
	}

	return 0;
}
