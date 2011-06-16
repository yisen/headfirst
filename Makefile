all: Strategy

Strategy: Strategy.o
	g++ -O0 -g3 -o Strategy Strategy.o

Strategy.o: Strategy.cpp
	g++ -O0 -g3 -c Strategy.cpp

clean:
	@rm *.o Strategy -f
