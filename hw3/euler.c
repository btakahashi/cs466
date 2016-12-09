#include <stdio.h>
#include <math.h>

#define e 2.71828182845904523536

double y(double t)
{
  return t * t * (pow(e, t) - e);
}

double yprime(double t, double w)
{
	return (2 / t) * w + t * t *pow(e, t);
}

void euler()
{
	// used for euler's method
	double a = 1.0, b = 2.0, alpha = 0.0, N = 10.0;
	double h, t, w;

	h = (b - a) / N;
	t = a;
	w = alpha;

	// used for "actual" values of y
	double yVal = y(t);

	printf("t = %f \t w = %2.22e \t y = %2.22e \t err = %2.22e \n",
		t, w, yVal, fabs(yVal - w));

	for(int i = 1; i <= N; i++)
	{
		// euler
		w = w + h * yprime(t, w);
		t = a + i * h;

		// actual
		yVal = y(t);

		printf("t = %f \t w = %2.22e \t y = %2.22e \t err = %2.22e \n",
			t, w, yVal, fabs(yVal - w));
	}
}

double linInterp(double x1, double x2, double y1, double y2, double pt)
{
	double slope = (y2 - y1) / (x2 - x2);

	return slope * (pt - x1) + y1;
}

int main()
{
	euler();

  return 0;
}
