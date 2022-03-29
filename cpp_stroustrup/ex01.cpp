#include <iostream>
#include <string>

int	main(void)
{
	std::string str;

	std::cout << "Please, enter your name\n";
	std::getline(std::cin, str);
	std::cout << "Hello, " << str << "!\n";

	return (0);
}

/*
int	main(void)
{
	std::string str;

	std::cout << "Enter your name\n";

	std::cin >> str;

	std::cout << "Hello, " << str << "!\n";

	return (0);
}
*/
