#pragma once

#include "Robot.hpp"
#include "TableTop.hpp"

#include<string>

class Simulator {
public:
	Simulator() = default;

	void place(int x, int y, Robot::Face face);
	void left();
	void right();
	void move();
	std::string report();

private:
	Robot mRobot;
	TableTop mTableTop;
};
