#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
# define TRUE 1 

int main(void)
{
	int n;
	
	srand(time(NULL));
	while (TRUE)
	{
		n = rand();
		printf("%d\n", n);
		sleep(1);
	}

	return (0);
}
