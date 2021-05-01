run: compile
	./UnsortedList

compile: UnsortedList.cpp Student.cpp UnsortedListDriver.cpp
	g++ -Wall -std=c++11 -pedantic-errors -o UnsortedList UnsortedList.cpp Student.cpp UnsortedListDriver.cpp

clean:
	rm UnsortedList
