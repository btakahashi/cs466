#include <stdio.h>

#define n 2

int main()
{
	double x[3];
	x[0] = -0.5;
	x[1] = -0.25;
	x[2] = 0.0;

	double fx[3];
	fx[0] = -0.0247500;
	fx[1] = 0.3349375;
	fx[2] = 1.1010000;

	double fpx[3];
	fpx[0] = 0.7510000;
	fpx[1] = 2.1890000;
	fpx[2] = 4.0020000;

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
