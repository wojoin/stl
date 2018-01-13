main:main.o stl_function.h
	g++ -std=c++11 main.cpp -o main
main.o:main.cpp
	g++ -c main.cpp
clean:
	-rm -f *.o *.exe
