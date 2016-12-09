#include <stdio.h>

#define n 1

int main()
{
	double x[2];
	x[0] = 8.3;
	x[1] = 8.6;

	double fx[2];
	fx[0] = 17.56492;
	fx[1] = 18.50515;

	double fpx[2];
	fpx[0] = 3.116256;
	fpx[1] = 3.151762;

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

	for(i = 0; i < 4; i++)
	{
		printf("Q[%d][%d] = %22.14e\n", i, i, Q[i][i]);
	}

	return 0;
}
