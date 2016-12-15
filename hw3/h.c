#include <stdio.h>
#include <math.h>

#define n 1

int main()
{
	// change array values to get new approximations
	double x[2];
	x[0] = 1.9;
	x[1] = 2.0;

	double fx[2];
	fx[0] = 14.323081535891006410566;
	fx[1] = 18.683097081886415935514;

	double fpx[2];
	fpx[0] = 11.747996543962477389300;
	fpx[1] = 15.398235652779238336052;

	double z[10], Q[10][10];

	int i, j;

	// cubic hermite
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

	// calculate approximation
	double val = 0.0;
	val = Q[0][0] + Q[1][1] * (1.97 - x[0]) +
					Q[2][2] * pow((1.97 - x[0]), 2) +
					Q[3][3] * pow((1.97 - x[0]), 2) * (1.97 - x[1]);

	for(i = 0; i < 4; i++)
	{
		printf("Q[%d][%d] = %22.14e\n", i, i, Q[i][i]);
	}

	printf("H3(1.55) approx = %.7f\n", val);

	return 0;
}
