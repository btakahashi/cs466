#include <stdio.h>
#include <math.h>

#define e 2.71828182845904523536
#define N 10

double y(double t)
{
  return t * t * (pow(e, t) - e);
}

double yprime(double t, double w)
{
	return (2 / t) * w + t * t * pow(e, t);
}

double dyprime(double t, double w)
{
	return -(2 / pow(t, 2)) * w + 2 / t * yprime(t, w) + 2 * t * pow(e, t) +
			pow(t, 2) * pow(e, t);
}

double d2yprime(double t, double w)
{
	return (4 / pow(t, 3)) * w - (4 / pow(t, 2)) * yprime(t , w) + pow(t, 2) * pow(e, t) +
		(2 / t) * dyprime(t , w) + 4 * pow(e, t) * t + 2 * pow(e, t);
}

double d3yprime(double t, double w)
{
	return (-12 / pow(t, 4)) * w + (12 / pow(t, 3)) * yprime(t , w) - (6 / pow(t, 2)) *
		dyprime(t , w) + (2 / t) * d2yprime(t , w) + pow(t, 2) * pow(e, t) +
		6 * pow(e, t) * t + 6 * pow(e, t);
}

double linInterp(double y1, double y2, double x1, double x2, double pt)
{
	double slope = (y2 - y1) / (x2 - x1);

	return slope * (pt - x1) + y1;
}

void euler()
{
	// for part a of question 1
	// used for euler's method
	double a = 1.0, b = 2.0, alpha = 0.0;
	double h, t[N + 1], w[N + 1];

	h = (b - a) / N;
	t[0] = a;
	w[0] = alpha;

	// used for "actual" values of y
	double yVal[N + 1];
	yVal[0] = y(t[0]);

	for(int i = 1; i <= N; i++)
	{
		// euler
		w[i] = w[i - 1] + h * yprime(t[i - 1], w[i - 1]);
		t[i] = a + i * h;

		// actual
		yVal[i] = y(t[i]);
	}

	for(int i = 0; i <= N; i++)
		printf("%d t = %.2f \t w = %.22e \t y = %.22e \t err = %.22e \n",
			i, t[i], w[i], yVal[i], fabs(yVal[i] - w[i]));

	// for part b of question 1
	double test[3] = {1.04, 1.55, 1.97};
	double yActual[3] = {y(test[0]), y(test[1]), y(test[2])};
	double est[3];

	est[0] = linInterp(w[0], w[1], t[0], t[1], test[0]);
	est[1] = linInterp(w[5], w[6], t[5], t[6], test[1]);
	est[2] = linInterp(w[9], w[10], t[9], t[10], test[2]);

	printf("\n");

	for(int i = 0; i < 3; i++)
		printf("%d t = %.2f \t est = %.22e \t y = %.22e \t err = %.22e\n",
			i, test[i], est[i], yActual[i], fabs(yActual[i] - est[i]));
}

void taylor2()
{
	// for part a of question 2
	// used for taylor's method
	double a = 1.0, b = 2.0, alpha = 0.0;
	double h, t[N + 1], w[N + 1];

	h = (b - a) / N;
	t[0] = a;
	w[0] = alpha;

	// used for "actual" values of y
	double yVal[N + 1];
	yVal[0] = y(t[0]);

	for(int i = 1; i <= N; i++)
	{
		// taylor
		w[i] = w[i - 1] + h * (yprime(t[i - 1], w[i - 1]) + h / 2 * dyprime(t[i - 1], w[i - 1]));
		t[i] = a + i * h;

		// actual
		yVal[i] = y(t[i]);
	}

	for(int i = 0; i <= N; i++)
		printf("%d t = %.2f \t w = %.22e \t y = %.22e \t err = %.22e \n",
			i, t[i], w[i], yVal[i], fabs(yVal[i] - w[i]));

	// for part b of question 2
	double test[3] = {1.04, 1.55, 1.97};
	double yActual[3] = {y(test[0]), y(test[1]), y(test[2])};
	double est[3];

	est[0] = linInterp(w[0], w[1], t[0], t[1], test[0]);
	est[1] = linInterp(w[5], w[6], t[5], t[6], test[1]);
	est[2] = linInterp(w[9], w[10], t[9], t[10], test[2]);

	printf("\n");

	for(int i = 0; i < 3; i++)
		printf("%d t = %.2f \t est = %.22e \t y = %.22e \t err = %.22e\n",
			i, test[i], est[i], yActual[i], fabs(yActual[i] - est[i]));
}

void taylor4()
{
	// for part c of question 2
	// used for taylor's method
	double a = 1.0, b = 2.0, alpha = 0.0;
	double h, t[N + 1], w[N + 1];

	h = (b - a) / N;
	t[0] = a;
	w[0] = alpha;

	// used for "actual" values of y
	double yVal[N + 1];
	yVal[0] = y(t[0]);

	for(int i = 1; i <= N; i++)
	{
		// taylor
		w[i] = w[i - 1] + h * (yprime(t[i - 1], w[i - 1]) + h / 2 * dyprime(t[i - 1], w[i - 1])
			+ pow(h, 2) / 6 * d2yprime(t[i - 1], w[i - 1]) + pow(h, 3) / 24 *
			d3yprime(t[i - 1], w[i - 1]));

		t[i] = a + i * h;

		// actual
		yVal[i] = y(t[i]);
	}

	for(int i = 0; i <= N; i++)
		printf("%d t = %.2f \t w = %.22e \t y = %.22e \t err = %.22e \n",
			i, t[i], w[i], yVal[i], fabs(yVal[i] - w[i]));
}

int main()
{
	euler();

	printf("\n");

	taylor2();

	printf("\n");

	taylor4();

  return 0;
}
