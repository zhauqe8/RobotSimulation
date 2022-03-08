#include "Robot.hpp"
#include "Serialisation.hpp"

template<>
Robot::Face Serialisation<Robot::Face>::deserialise(const std::string& str)
{
	if (str == "NORTH" || str == "north") {
		return Robot::NORTH;
	} else if (str == "EAST" || str == "east") {
		return Robot::EAST;
	} else if (str == "SOUTH" || str == "south") {
		return Robot::SOUTH;
	} else if (str == "WEST" || str == "west") {
		return Robot::WEST;
	}
		
	throw std::invalid_argument("Failed to create face from string: "+str);
}

template<>
std::string Serialisation<Robot::Face>::serialise(const Robot::Face& face)
{
	switch(face) {
	case Robot::NORTH:
		return "NORTH";
	case Robot::SOUTH:
		return "SOUTH";
	case Robot::EAST:
		return "EAST";
	case Robot::WEST:
		return "WEST";
	}

	throw std::invalid_argument("Failed to convert face to string.");
}


