/*
 * implementation of the binary search function on an ascending array
 * retun 0, if element num is not found in the array a.
 * return 1, if element num is found in th array a.
 * ind -- index to put the number num in array.
*/

int	binary_search(int *a, int length, int num, int* ind)
{	
	int	begin;
	int	end;
	int	middle;

	if (length <= 0 || num < a[0])
	{
		*ind = 0;
		return (length > 0 && num == a[0]);
	}
	else if (num > a[length - 1])
	{
		*ind = length;
		return (0);
	}
	else
	{
		begin = 0;
		end = length - 1;
		while (end - begin > 1)
		{
			middle = (end + begin) / 2;
			if (num < a[middle])
			{
				end = middle;
			}
			else if (num > a[middle])
			{
				begin = middle;
			}
			else
			{
				*ind = middle;
				return (1);
			}
		}
		*ind = end;
		return (num == a[end]);
	}
}
