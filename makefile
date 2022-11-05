.PHONY: all std
all: hello std

hello: src/HelloWorld.cpp
	g++ -std=c++14 src/Triangle.cpp src/Circle.cpp src/MathVector.cpp src/Polygon.cpp src/HelloWorld.cpp -o bin/HelloWorld

std:
	g++ -std=c++14 -Wfatal-errors src/Circle.cpp src/Polygon.cpp src/MathVector.cpp src/Triangle.cpp test/ut_main.cpp -o bin/ut_all -lgtest -lpthread

.PHONY: clean
clean:
	rm bin/*
