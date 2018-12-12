#include "Wine.h"

#include <iostream>
#include <iomanip>

Wine::Wine(const char* l, int y, const int* yr, const int* bot):
	name_(l),
	years_(y),
	pair_({ ArrayIntT(yr, y), ArrayIntT(bot, y) }),
	ages_(y)
{
	for (int cnt = 0; cnt < years_; ++cnt)
		ages_[cnt] = currYear - pair_.first[cnt];
}

Wine::Wine(const char* l, int y):
	name_(l),
	years_(y),
	pair_({ { y }, { y } }),
	ages_(y)
{}

void    Wine::getBottles() {

	std::cout << "Enter entries using format \'<year> <number>\'" << std::endl;

	for (int cnt = 0; cnt < years_; ++cnt) {

		std::cout << cnt + 1 << ":\t";
		std::cin >> pair_.first[cnt];
		std::cin >> pair_.second[cnt];
		ages_[cnt] = currYear - pair_.first[cnt];
	}
}

const char* Wine::label() const {

	return name_.c_str();
}

size_t  Wine::sum() const {

	size_t  init = 0;

	return std::accumulate(std::begin(pair_.second), std::end(pair_.second), init);
}

void Wine::show() const {

	if (!name_.empty())
		std::cout << "~~~~~" << name_ << "~~~~~" << std::endl;

	std::cout << "|";
	std::cout << std::setw(10) << "year" << "|";
	std::cout << std::setw(10) << "age" << "|";
	std::cout << std::setw(10) << "number";
	std::cout << "|" << std::endl;

	for (int cnt = 0; cnt < years_; ++cnt) {

		std::cout << "|";
		std::cout << std::setw(10) << pair_.first[cnt] << "|";
		std::cout << std::setw(10) << ages_[cnt] << "|";
		std::cout << std::setw(10) << pair_.second[cnt];
		std::cout << "|" << std::endl;
	}
}
