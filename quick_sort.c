#include <stddef.h>

static void	swap(int *a, int *b);

static void	partition(int *array, size_t size, size_t *idx_mid);

void	quick_sort(int *array, size_t size)
{
	size_t	begin;
	size_t	k;
	size_t	idx_mid;
	size_t	left;
	size_t	right;

	if (size < 2)
		return ;
	else if (size == 2)
	{
		if (array[0] > array[1])
			swap(array, array + 1);
		return ;
	}
	begin = 0;
	k = size;
	while (k > 1)
	{
		idx_mid = k / 2;
		partition(array + begin, k, &idx_mid);
		left = idx_mid;
		right = k - 1 - left;
		if (left <= right)
		{
			quick_sort(array + begin, left);
			begin += left + 1;
			k -= left + 1;
		}
		else 
		{
			quick_sort(array + begin + idx_mid + 1, right);
			k -= right + 1;
		}
	}
}

static void	partition(int *array, size_t size, size_t *idx_mid)
{
	size_t	i;
	size_t	j;
	int	changed;
	int	mid;

	if (*idx_mid != 0)
		swap(array, array + *idx_mid);
	mid = array[0];
	i = 0;
	j = size;
	while (j - i > 1)
	{
		changed = 0;
		if (array[i + 1] <=  mid)
		{
			++i;
			changed = 1;
		}
		if (j - i > 1 && array[j - 1] >= mid)
		{
			--j;
			changed = 1;
		}
		if (!changed)
		{
			++i;
			--j;
			swap(array + i, array + j);
		}
	}	
	if (i > 0)
		swap(array, array + i);
	*idx_mid = i;
}

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
