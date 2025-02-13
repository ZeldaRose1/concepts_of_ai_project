#include <vector>
#include <iostream>
#include "Board.h"

using namespace std;

class Game {
    private:
        // Board variable to store current state of the game
        Board board;
        
    public:
        // Constructors
        Game();
        Game(Board);
        
        // Necessary functions
        bool closeMill(short int, const Board& b); // Input board location; returns T/F if move completes a mill
        
        
        // Setters and Getters for convenience
        void setBoard(Board);
        Board& getBoard();

        // vector<short int> generateAdd();
        // vector<short int> generateMove();
        // vector<short int> generateHopping();
};