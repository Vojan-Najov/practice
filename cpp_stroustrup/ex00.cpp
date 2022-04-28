#include <iostream>

int	main(void)
{
	const float	factor = 2.54;
	float x, in, cm;
	char ch;

	std::cout << "Enter the length: ";
	
	std::cin >> x;
	std::cin >> ch;

	switch (ch) {
		case 'i':
			in = x;
			cm = x * factor;
			break ;
		case 'c':
			in = x / factor;
			cm = x;
			break ;
		default:
			in = cm = 0.;
			break ;
	}
	
	std::cout << in << " inches = " << cm << " centimetres\n";
}
