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
	return (2 / t) * w + t * t *pow(e, t);
}

double linInterp(double x1, double x2, double y1, double y2, double pt)
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
		printf("t = %f \t w = %2.22e \t y = %2.22e \t err = %2.22e \n",
			t[i], w[i], yVal[i], fabs(yVal[i] - w[i]));

	// for part b of question 1
	double test[3] = {1.04, 1.55, 1.97};
	//double yActual[3] = {y(test[0]), y(test[1]), y(test[2])};
	double est[3];

	est[0] = linInterp(w[0], w[1], t[0], t[1], test[0]);
	est[1] = linInterp(w[5], w[6], t[5], t[6], test[1]);
	est[2] = linInterp(w[9], w[10], t[9], t[10], test[2]);

	for(int i = 0; i < 3; i++)
		printf("@t = %f estimate = %2.22e\n", test[i], est[i]);
}

int main()
{
	euler();

  return 0;
}
