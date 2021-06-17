#include <stdio.h>
#define	TRUE 1

int	main(void)
{
	float			f;
	double			d;
	int				*p, *p1;
	int				s, e, mf, res;
	int				md[2];
	unsigned int	mask;

	while (TRUE)
	{
		printf("\nInput a real number:\n");
		res = scanf("%lf", &d);
		if (res <= 0)
			break ;
		f = (float) d;

		/* FLOAT____________________________________*/
		printf("Float representation:\n");
		p = (int*) &f;

		printf("Hex: %08X\n", *p);
		
		s = ((*p >> 31) & 1);
		e = ((*p >> 23) & 0xFF);
		mf = (*p & 0x7FFFFF);
		
		printf("s = %d,  e = %d,\nm = ", s, e);
		mask = 0x400000;
		while (mask != 0)
		{
			if ((mask & mf) != 0)
				printf("1");
			else
				printf("0");
			mask >>= 1;
		}
		printf("\n");

		/* DOUBLE__________________________________*/
		printf("\nDouble penetration:\n");
		p = (int *) &d;							/* Lower word */
		p1 = p + 1;								/* Upper word */

		printf("Hex: %08x %08X\n", *p1, *p);

		s = ((*p1 >> 31) & 1);
		e = ((*p1 >> 20) & 0x7ff);				/* 11 bits */
		md[0] = (*p1 & 0xfffff);				/* 20 lower bits */
		md[1] = *p;								/* 32 lower bits */
		
		printf("s = %d,  e = %d,\nm = ", s, e);
		mask = 0x80000;
		while (mask != 0)
		{
			if ((mask & md[0]) != 0)
				printf("1");
			else
				printf("0");
			mask >>= 1;
		}
		mask = 0x80000000;
		while (mask != 0)
		{
			if ((mask &md[1]) != 0)
				printf("1");
			else
				printf("0");
			mask >>= 1;
		}
		printf("\n");
	}
	return (0);
}
