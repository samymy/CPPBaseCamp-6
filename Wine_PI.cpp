#include "Wine_PI.h"

#include <iostream>
#include <iomanip>

Wine::Wine(const char* l, int y, const int* yr, const int* bot):
		std::string(l),
		years_(y),
		PairArrayT({ ArrayIntT(yr, y), ArrayIntT(bot, y) }),
		ArrayIntT(y)
{
	for (int cnt = 0; cnt < years_; ++cnt)
		ArrayIntT::operator[](cnt) = currYear - PairArrayT::first[cnt];
}

Wine::Wine(const char* l, int y):
		std::string(l),
		years_(y),
		PairArrayT({ { y }, { y } }),
		ArrayIntT(y)
{}

void    Wine::getBottles() {

	std::cout << "Enter entries using format \'<year> <number>\'" << std::endl;

	for (int cnt = 0; cnt < years_; ++cnt) {

		std::cout << cnt + 1 << ":\t";
		std::cin >> PairArrayT::first[cnt];
		std::cin >> PairArrayT::second[cnt];
		ArrayIntT::operator[](cnt) = currYear - PairArrayT::first[cnt];
	}
}

const char* Wine::label() const {

	return std::string::c_str();
}

size_t  Wine::sum() const {

	size_t  init = 0;

	return std::accumulate(std::begin(PairArrayT::second), std::end(PairArrayT::second), init);
}

void Wine::show() const {

	if (!std::string::empty())
		std::cout << "~~~~~" << std::string::c_str() << "~~~~~" << std::endl;

	std::cout << "|";
	std::cout << std::setw(10) << "year" << "|";
	std::cout << std::setw(10) << "age" << "|";
	std::cout << std::setw(10) << "number";
	std::cout << "|" << std::endl;

	for (int cnt = 0; cnt < years_; ++cnt) {

		std::cout << "|";
		std::cout << std::setw(10) << PairArrayT::first[cnt] << "|";
		std::cout << std::setw(10) << ArrayIntT::operator[](cnt) << "|";
		std::cout << std::setw(10) << PairArrayT::second[cnt];
		std::cout << "|" << std::endl;
	}
}
