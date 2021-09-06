static void	swap(int *a, int *b);

void	bubble_sort(int *array, int size)
{
	int	inverse;
	int	j;

	inverse = 1;
	while (inverse)
	{
		j = 0;
		inverse = 0;
		while (j < size - 1)
		{
			if (array[j] > array[j + 1])
			{
				swap(array + j, array + j + 1);
				inverse = 1;
			}
			++j;
		}
	}	
}

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
