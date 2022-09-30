.PHONY: all
all: hello ut

hello: src/HelloWorld.cpp
	g++ src/HelloWorld.cpp -o bin/HelloWorld

ut: test/ut_main.cpp
	g++ -std=c++11 -Wfatal-errors test/ut_main.cpp -o bin/ut_all -lgtest -lpthread

.PHONY: clean
clean:
	rm -f bin/*