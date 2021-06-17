#include <assert.h>

void	normalization(double x, int *sign, int *exp, double *mant);

void	normalization(double x, int *sign, int *exp, double *mant)
{
	int 	s;
	int 	e;
	double	m;

	s = 1;
	e = 0;
	m = x;
	if (x < 0)
	{
		s = -1;
		m = -x;
	}
	while (m >= 2)
	{
		m /= 2.;
		++e;
		// x == s * m * 2^e;
	}
	assert(m < 2.);
	while (m < 1.)
	{
		m *= 2;
		--e;
		// x == s * m * 2^e;
	}
	assert(m < 2. && m >= 1.);
	*sign = s;
	*exp = e;
	*mant = m;
}
