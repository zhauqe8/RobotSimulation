# RobotSimulation

How to build
============

The code repository includes a **Makefile** which contains simulator (**RobotSimulation**) and unit test (**UnitTests**) targets.

>git clone https://github.com/zhauqe8/RobotSimulation.git  
>cd RobotSimulation/build  
>make

How to run 
==========

Simulator
---------
The simulator accepts input commands both from **stdin** and text file.
Run the executable without any argument to feed the commands from **stdin**, otherwise
pass the input file as first argument.

Unit tests
----------
Unit tests are build into the **UnitTests** executable. It does not take any argument
and prints **Passed** if all tests pass.

Integration tests
-----------------
Integration tests are written in Python in **IntegrationTests.py** script.
It expects input commands in a **.input** extension file and their corresponding exptected output
in the same named text file but with **.output** extension. The test data must reside in **TestData** directory
and the script must be run from **build** directory.

>cd build; python ../IntegrationTests.py
