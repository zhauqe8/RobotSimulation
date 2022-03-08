#pragma once

#include "Simulator.hpp"

#include <iostream>
#include <memory>
#include <string>

class PlaceCommand {
public:

	PlaceCommand(int x, int y, Robot::Face face)
		: mX(x), mY(y), mFace(face)
	{}

	void execute(Simulator& simulator)
	{
		simulator.place(mX, mY, mFace);
	}

private:
	int mX = -1;
	int mY = -1;
	Robot::Face mFace = Robot::NORTH;
};

class MoveCommand {
public:
	MoveCommand() = default;

	void execute(Simulator& simulator)
	{
		simulator.move();
	}
};

class LeftCommand {
public:
	LeftCommand() = default;

	void execute(Simulator& simulator)
	{
		simulator.left();
	}
};

class RightCommand {
public:
	RightCommand() = default;

	void execute(Simulator& simulator)
	{
		simulator.right();
	}
};

class ReportCommand {
public:
	ReportCommand() = default;

	void execute(Simulator& simulator)
	{
		auto str = simulator.report();
		std::cout << str << std::endl;
	}
};

class Command {
public:
	template<typename T>
	Command(const T& t) : mImpl{new CommandModel<T>(t)} {}
	Command(Command&&) = default;
	Command& operator=(Command&&) = default;
	Command(const Command& other) { mImpl = other.mImpl->clone(); }
	Command& operator=(const Command& other)
	{ 
		mImpl = other.mImpl->clone();
		return *this;
	}

	void execute(Simulator& simulator) { mImpl->execute(simulator); }

private:
	struct CommandConcept {
		virtual ~CommandConcept() {}
		virtual std::unique_ptr<CommandConcept> clone() const = 0;
		virtual void execute(Simulator& simulator) = 0;
	};

	template<typename T>
	struct CommandModel : public CommandConcept {
		CommandModel(T&& value) : mObj{std::forward<T>(value)} {}
		CommandModel(const T& value) : mObj{value} {}
		std::unique_ptr<CommandConcept> clone() const override
		{ return std::make_unique<CommandModel>(*this); }

		void execute(Simulator& simulator)
		{
			mObj.execute(simulator);
		}
		
		T mObj;
	};

	std::unique_ptr<CommandConcept> mImpl;
};

Command makeCommand(const std::string& str);

