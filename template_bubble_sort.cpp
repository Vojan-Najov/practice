template <class T>
void mysort(T *a, int size)
{
	for(int start = 0; ; ++start)
	{
		bool done = true;
		for (int i = size - 2; i >= start; --i)
		{
			if (a[i + 1] < a[i])
			{
				T tmp = a[i + 1];
				a[i + 1] = a[i];
				a[i] = tmp;
				done = false;
			}
		}
		if (done)
			break;
	}
}

/* using

#include <iostream>

int main()
{
	int a[5] = {9, 1, 4, 3, 5};

	for (int i = 0; i < 5; ++i)
		std::cout << a[i] << ' ';
	std::cout << '\n';
	mysort<int>(a, 5);
	for (int i = 0; i < 5; ++i)
		std::cout << a[i] << ' ';
	std::cout << '\n';
	mysort<int>(a, 5);
	for (int i = 0; i < 5; ++i)
		std::cout << a[i] << ' ';
	std::cout << '\n';

	return 0;
}
end */
