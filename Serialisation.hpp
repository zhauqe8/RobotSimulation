#pragma once

#include <stdexcept>
#include <string>
#include <sstream>
#include <algorithm>

template<typename Iter>
void split(const std::string& str, char delim, Iter out)
{
	std::istringstream ss(str);

	std::string token;
	while (std::getline(ss, token, delim)) {
		*out = token;
		++out;
	}
}

template<typename Filter>
std::string trim(const std::string& str, Filter filter)
{
	auto start = std::find_if_not(str.begin(), str.end(), filter);
	auto end = std::find_if_not(str.rbegin(), str.rend(), filter).base();
	return end <= start ? std::string() : std::string(start, end);
}

template<typename Type>
struct Serialisation {
	static std::string serialise(const Type& obj);
	static Type deserialise(const std::string& str);
};

