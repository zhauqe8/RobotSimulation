src=..

all: RobotSimulation UnitTests

RobotSimulation: $(src)/main.cpp
	g++ -std=c++14 \
		$(src)/Command.cpp \
		$(src)/main.cpp \
		$(src)/Robot.cpp \
		$(src)/Simulator.cpp \
		-o RobotSimulation

UnitTests: $(src)/UnitTests.cpp
	g++ -std=c++14 \
		$(src)/Command.cpp \
		$(src)/Robot.cpp \
		$(src)/Simulator.cpp \
		$(src)/UnitTests.cpp \
		-g -o UnitTests 
