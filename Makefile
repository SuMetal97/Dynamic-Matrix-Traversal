matrix: matrix.o
	g++ -std=c++17 matrix.o -o matrix

Main.o: matrix.cpp
	g++ -std=c++17 -c matrix.cpp

clean:
	rm *.o matrix
