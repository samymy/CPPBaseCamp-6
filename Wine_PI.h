#ifndef HOMEWORK6_WINE_PI_H
#define HOMEWORK6_WINE_PI_H

#include <valarray>

class Wine: std::string, std::valarray<int>, std::pair<std::valarray<int>, std::valarray<int>> {

	using ArrayIntT = std::valarray<int>;
	using PairArrayT = std::pair<ArrayIntT, ArrayIntT>;

	static constexpr int currYear = 2018;

	int             years_;

public:
	Wine() = delete;
	Wine(const char* l, int y, const int yr[], const int bot[]);
	Wine(const char* l, int y);

	void         getBottles();
	const char*  label() const;
	size_t       sum() const;
	void         show() const;

};

#endif //HOMEWORK6_WINE_PI_H
