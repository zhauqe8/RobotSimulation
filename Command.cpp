#include "Command.hpp"
#include "Robot.hpp"
#include "Serialisation.hpp"

#include <vector>

template<>
PlaceCommand Serialisation<PlaceCommand>::deserialise(const std::string& str)
{
	std::vector<std::string> tokens;
	split(str, ' ', std::back_inserter(tokens));
	if (tokens.size() == 2) {
		std::vector<std::string> args;
		split(tokens[1], ',', std::back_inserter(args));
		if (args.size() == 3) {
			auto face = Serialisation<Robot::Face>::deserialise(args[2]);
			return PlaceCommand(std::stoi(args[0]), std::stoi(args[1]), face);
		}
	} 

	throw std::invalid_argument("Failed to create PLACE command from string: "+str);
}

Command makeCommand(const std::string& str)
{
	if (str.find("PLACE") == 0 || str.find("place") == 0) {
		return Serialisation<PlaceCommand>::deserialise(str);
	} else if (str.find("MOVE") == 0 || str.find("move") == 0) {
		return MoveCommand();
	} else if (str.find("LEFT") == 0 || str.find("left") == 0) {
		return LeftCommand();
	} else if (str.find("RIGHT") == 0 || str.find("right") == 0) {
		return RightCommand();
	} else if (str.find("REPORT") == 0 || str.find("report") == 0) {
		return ReportCommand();
	}

	throw std::invalid_argument("Failed to create command from string: "+str);
}

