#pragma once

class Robot {
public:
	enum Face {NORTH, EAST, SOUTH, WEST};

	Robot() {}

	int x() const { return mX; }
	void setX(int x) { mX = x; }

	int y() const { return mY; }
	void setY(int y) { mY = y; }

	Face face() const { return mFace; }
	void setFace(Face face) { mFace = face; }

	bool ready() const { return mX >= 0 && mY >= 0; }
private:
	int mX = -1;
	int mY = -1;
	Face mFace = NORTH;
};

