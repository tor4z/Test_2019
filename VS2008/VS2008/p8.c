#include <stdio.h>
#include <math.h>

double sqr(int a)
{
	return (double)(a * a);
}

int p8()
{
	int x0, y0, z0, x1, y1, z1;
	double PI = acos(-1);
	double r, v;
	while(scanf("%d %d %d %d %d %d", &x0, &y0, &z0, &x1, &y1, &z1) == 6)
	{
		r = sqrt(sqr(x0-x1) + sqr(y0-y1) + sqr(z0-z1));
		v = (4 * PI * pow(r, 3))/3;
		printf("%.3f %.3f", r, v);
	}
	return 0;
}