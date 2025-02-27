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
        
        // Helper functions
        bool closeMill(short int, Board& b); // Input board location; returns T/F if move completes a mill
        
        
        // Setters and Getters for convenience
        void setBoard(Board);
        Board& getBoard();
        
        // Major functions
        void generateRemove(Board&, vector<Board>&);
        vector<Board> generateHopping(Board&);
        vector<Board> generateAdd(Board&);
        vector<Board> generateMove(Board&);

        /* Functions that still need to be implemented */
        // vector<Board> GenerateMovesOpening(Board&); // No pseudocode given // Static estimation for opening
        // vector<Board> generateMovesMidgameEndgame(Board&); // Only basic logic given
};