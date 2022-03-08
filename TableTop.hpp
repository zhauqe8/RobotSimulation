#pragma once

template<int X, int Y>
class Table{
public:
	static constexpr int XExtent = X;
	static constexpr int YExtent = Y;
};

using TableTop = Table<5,5>;

