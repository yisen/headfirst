all: Strategy Observer Decorator

Strategy: Strategy.o
	g++ -O0 -g3 -o Strategy Strategy.o

Strategy.o: Strategy.cpp
	g++ -O0 -g3 -c Strategy.cpp

Observer: Observer.o
	g++ -O0 -g3 -o Observer Observer.o

Observer.o: Observer.cpp
	g++ -O0 -g3 -c Observer.cpp

Decorator: Decorator.o
	g++ -O0 -g3 -o Decorator Decorator.o

Decorator.o: Decorator.cpp
	g++ -O0 -g3 -c Decorator.cpp

clean:
	@rm *.o Strategy Observer -f
