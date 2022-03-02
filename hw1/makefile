.PHONY: dirs clean

all: dirs ut_all

ut_all: test/ut_circle.h test/ut_main.cpp test/ut_rectangle.h test/ut_triangle.h test/ut_two_dimensional_vector.h
	g++ -std=c++11 test/ut_main.cpp -o bin/ut_all -lgtest -lpthread
dirs:
	mkdir -p bin
	mkdir -p obj
clean:
	rm -f bin/*