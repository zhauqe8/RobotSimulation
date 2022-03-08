#include "Command.hpp"
#include "Robot.hpp"
#include "Serialisation.hpp"
#include "Simulator.hpp"
#include "TableTop.hpp"

#include <fstream>
#include <vector>

template<typename Iter>
void read(std::istream& stream, Iter out)
{
	using namespace std;
	string line;
	while (std::getline(stream, line)) {
		try {
			auto trimmed = trim(line, [](char ch) { return std::isspace(ch); });
			if (trimmed.empty()) continue;

			auto command = makeCommand(trimmed);
			*out = command;
			++out;
		} catch (std::invalid_argument exp) {
			std::cerr << "Skipped invalid command: " << line << std::endl;
		}
	}
}

void readAndExecute(std::istream& stream, Simulator& simulator)
{
	using namespace std;
	string line;
	while (std::getline(stream, line)) {
		try {
			auto trimmed = trim(line, [](char ch) { return std::isspace(ch); });
			if (trimmed.empty()) continue;

			auto command = makeCommand(trimmed);
			command.execute(simulator);
		} catch (std::invalid_argument exp) {
			std::cerr << "Skipped invalid command: " << line << std::endl;
		}
	}
}

int main(int argc, char* argv[])
{
	Simulator simulator;

	if (argc == 2) {
		std::ifstream stream(argv[1]);
		std::vector<Command> commands;
		read(stream, std::back_inserter(commands));
		for (auto& c: commands) {
			c.execute(simulator);
		}
		return 0;
	} else if (argc == 1) {
		readAndExecute(std::cin, simulator);
	}
	return 0;
}
