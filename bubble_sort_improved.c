#include <stddef.h>

static void	swap(int *a, int *b);

void	bubble_sort_improved(int *array, size_t size)
{
	int	inverse;
	size_t	j;
	size_t	k;

	if (size < 2)
		return ;
	inverse = 1;
	k = 0;
	while (inverse)
	{
		inverse = 0;
		j = 0;
		while (j < size - k - 1)
		{
			if (array[j] > array[j + 1])
			{
				swap(array + j, array + j + 1);
				inverse = 0;
			}
			++j;
		}
		++k;
	}	
}

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
