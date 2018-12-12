#ifndef HOMEWORK6_WINE_H
#define HOMEWORK6_WINE_H

#include <valarray>

class Wine {

	using ArrayIntT = std::valarray<int>;
	using PairArrayT = std::pair<ArrayIntT, ArrayIntT>;

	static constexpr int currYear = 2018;

	std::string     name_;
	int             years_;
	PairArrayT      pair_;
	ArrayIntT       ages_;

public:
	Wine() = delete;
	Wine(const char* l, int y, const int yr[], const int bot[]);
	Wine(const char* l, int y);

	void         getBottles();
	const char*  label() const;
	size_t       sum() const;
	void         show() const;

};

#endif //HOMEWORK6_WINE_H
