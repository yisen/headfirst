all: Strategy Observer

Strategy: Strategy.o
	g++ -O0 -g3 -o Strategy Strategy.o

Strategy.o: Strategy.cpp
	g++ -O0 -g3 -c Strategy.cpp

Observer: Observer.o
	g++ -O0 -g3 -o Observer Observer.o

Observer.o: Observer.cpp
	g++ -O0 -g3 -c Observer.cpp

clean:
	@rm *.o Strategy Observer -f
