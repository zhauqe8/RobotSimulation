#include "Serialisation.hpp"
#include "Simulator.hpp"

#include<sstream>

void Simulator::place(int x, int y, Robot::Face face)
{
	if (x >= 0 && x <= TableTop::XExtent &&
		y >= 0 && y <= TableTop::YExtent) {
		mRobot.setX(x);
		mRobot.setY(y);
		mRobot.setFace(face);
	}
}

void Simulator::left()
{
	if (!mRobot.ready()) return;

	Robot::Face newFace = mRobot.face();
	switch(mRobot.face()) {
	case Robot::NORTH:
		newFace = Robot::WEST;
		break;
	case Robot::SOUTH:
		newFace = Robot::EAST;
		break;
	case Robot::EAST:
		newFace = Robot::NORTH;
		break;
	case Robot::WEST:
		newFace = Robot::SOUTH;
		break;
	}
	mRobot.setFace(newFace);
}

void Simulator::right()
{
	if (!mRobot.ready()) return;

	Robot::Face newFace = mRobot.face();
	switch(mRobot.face()) {
	case Robot::NORTH:
		newFace = Robot::EAST;
		break;
	case Robot::SOUTH:
		newFace = Robot::WEST;
		break;
	case Robot::EAST:
		newFace = Robot::SOUTH;
		break;
	case Robot::WEST:
		newFace = Robot::NORTH;
		break;
	}
	mRobot.setFace(newFace);
}

void Simulator::move()
{
	if (!mRobot.ready()) return;

	switch(mRobot.face()) {
	case Robot::NORTH:
		if (mRobot.y() < mTableTop.YExtent) mRobot.setY(mRobot.y()+1);
		break;
	case Robot::SOUTH:
		if (mRobot.y() > 0) mRobot.setY(mRobot.y()-1);
		break;
	case Robot::EAST:
		if (mRobot.x() < mTableTop.XExtent) mRobot.setX(mRobot.x()+1);
		break;
	case Robot::WEST:
		if (mRobot.x() > 0) mRobot.setX(mRobot.x()-1);
		break;
	}
}

std::string Simulator::report()
{
	std::stringstream ss;
	ss << mRobot.x() << "," << mRobot.y() << "," << Serialisation<Robot::Face>::serialise(mRobot.face());
	return ss.str();
}
