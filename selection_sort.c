#include <stddef.h>

static void	swap(int *a, int *b);

void	selection_sort(int *array, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	min;

	i = 0;
	while (i < size - 1)
	{
		min = i;
		j = i + 1;
		while (j < size)
		{
			if (array[j] < array[min])
				min = j;
			++j;
		}
		if (min != i)
			swap(array + i, array + min);
		++i;
	} 
}

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
