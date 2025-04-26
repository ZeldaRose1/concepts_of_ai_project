minimax: Board.o MiniMaxOpening.cpp Board.cpp
	g++ -g -o minimax Board.o MiniMaxOpening.cpp

minimaxgame: Board.o MiniMaxGame.cpp Board.cpp
	g++ -g -o minimaxgame Board.o MiniMaxGame.cpp

test: clean test.o Board.h
	g++ -o test test.o Board.o
	./test

debug: clean test.o  Board.h
	g++ -o test test.o Board.o

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
		[ -f minimax ]; \
		then \
		rm minimax; \
	fi

	@if \
		[ -f minimaxgame ]; \
		then \
		rm minimaxgame; \
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

	@if \
		[ -f "CoAI_group30_rose_zelda_semester_project.zip" ]; \
		then \
		rm CoAI_group30_rose_zelda_semester_project.zip; \
	fi

zip:
	zip CoAI_group30_rose_zelda_semester_project.zip *.o *.h *.cpp Makefile README.md