minimaxopeningimproved: Board.o MiniMaxOpeningImproved.cpp Board.cpp
	g++ -g -o minimaxopeningimproved Board.o MiniMaxOpeningImproved.cpp

minimaxgameimproved: Board.o MiniMaxGameImproved.cpp Board.cpp
	g++ -g -o minimaxgameimproved Board.o MiniMaxGameImproved.cpp

abgameblack: Board.o ABGameBlack.cpp Board.cpp
	g++ -g -o abgameblack Board.o ABGameBlack.cpp

abopeningblack: Board.o ABOpeningBlack.cpp Board.cpp
	g++ -g -o abopeningblack Board.o ABOpeningBlack.cpp

minimaxopeningblack: Board.o MiniMaxOpeningBlack.cpp Board.cpp
	g++ -g -o minimaxopeningblack Board.o MiniMaxOpeningBlack.cpp

minimaxgameblack: Board.o MiniMaxGameBlack.cpp Board.cpp
	g++ -g -o minimaxgameblack Board.o MiniMaxGameBlack.cpp

abgame: Board.o ABGame.cpp Board.cpp
	g++ -g -o abgame Board.o ABGame.cpp

abopening: Board.o ABOpening.cpp Board.cpp
	g++ -g -o abopening Board.o ABOpening.cpp

minimaxopening: Board.o MiniMaxOpening.cpp Board.cpp
	g++ -g -o minimaxopening Board.o MiniMaxOpening.cpp

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
		[ -f abopeningblack ]; \
		then \
		rm abopeningblack; \
	fi

	@if \
		[ -f abgameblack ]; \
		then \
		rm abgameblack; \
	fi
	
	@if \
		[ -f minimaxopeningimproved ]; \
		then \
		rm minimaxopeningimproved; \
	fi

	@if \
		[ -f minimaxgameimproved ]; \
		then \
		rm minimaxgameimproved; \
	fi

	@if \
		[ -f minimaxopeningblack ]; \
		then \
		rm minimaxopeningblack; \
	fi

	@if \
		[ -f minimaxgameblack ]; \
		then \
		rm minimaxgameblack; \
	fi
	
	@if \
		[ -f abopening ]; \
		then \
		rm abopening; \
	fi

	@if \
		[ -f abgame ]; \
		then \
		rm abgame; \
	fi
	
	@if \
		[ -f minimaxopening ]; \
		then \
		rm minimaxopening; \
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
	zip CoAI_group30_rose_zelda_semester_project.zip *.h *.cpp Makefile README.md ../rose-zelda_project_report.pdf