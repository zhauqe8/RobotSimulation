#include "Command.hpp"
#include "Robot.hpp"
#include "Serialisation.hpp"
#include "Simulator.hpp"
#include "TableTop.hpp"

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void assertSerialisation()
{
	vector<string> output;
	split("ab 1 $2 ,", ' ', back_inserter(output));
	assert(4 == output.size());
	assert("ab" == output[0]);
	assert("1" == output[1]);
	assert("$2" == output[2]);
	assert("," == output[3]);

	output.clear();
	split("ab 1 $2 , ", ',', back_inserter(output));
	assert(2 == output.size());
	assert("ab 1 $2 " == output[0]);
	assert(" " == output[1]);

	output.clear();
	auto output1 = trim(" abc ", [](char ch){return isspace(ch);});
	assert("abc" == output1);
}

int main()
{
	assertSerialisation();
	std::cout << "Passed" << std::endl;
}
