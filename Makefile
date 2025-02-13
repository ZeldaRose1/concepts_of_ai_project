test: clean test.o Game.h Board.h
	g++ -o test test.o Game.o Board.o
	./test

debug: clean test.o Game.h Board.h
	g++ -o test test.o Game.o Board.o

test.o: test.cpp Game.o Board.h
	g++ -c -g test.cpp Game.h Board.h

Game.o: Game.cpp Game.h Board.h Board.cpp Board.o
	g++ -g -c Game.cpp

Board.o: Board.cpp Board.h
	g++ -g -c Board.cpp

clean:
	@if \
		[ -f test ]; \
		then \
		rm test; \
	fi
	
	@if \
		find . -name "*.o" | grep -q .;\
		then \
		rm *.o; \
	fi

	@if \
		find . -name "*.gch" | grep -q .;\
		then \
		rm *.gch; \
	fi

	