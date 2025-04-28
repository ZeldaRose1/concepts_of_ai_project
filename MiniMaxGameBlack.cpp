#include "Board.h"
#include <iostream>

/*
This file will act as a driver to control minimax search
This is a copy of the MiniMaxGame program, but it forces
the board to start on black's turn.

Arg1 is the input .txt file
Arg2 is the output file
Arg3 is the depth of the search

The input file must be three lines with the following format:
    First line: board positions with 1's representing white pieces,
        -1's representing black pieces, and 0's representing empty
    Second line: Single int with a 1 for white's turn and 0 for black's
    Third line: Single int with a 0 for opening phase, 1 for midgame,
        and 2 for endgame
    Fourth line: Single int with the number of turns played
*/


int main (int argc, char *argv[]) {
    // Verify the proper number of arguments.
    if (argc != 4){
        cout << "ERROR: Must supply input file name, output file name, and the depth of the search." << endl;
        return 1;
    }

    // Load board from file
    cout << argv[1] << endl;
    Board b(argv[1]);
    b.whiteTurn = false;  // Force black turn
    int cur_iter = 0;
    cout << argv[3] << endl;
    int max_depth = atoi(argv[3]);
    int leaf_count = 0;


    // Loop through the iterations
    Board output = b.miniMaxSearch(b, max_depth, leaf_count);

    cout << "Input Position:  ";
    b.printBoard();
        
        
    
    cout << "\nOutput Position:  ";
    output.printBoard();

    output.writeBoard(argv[2]);

    cout << "\nPositions evaluated by static estimation:";
    cout << leaf_count << endl;

    cout << "MINIMAX estimate: " << output.heuristic << endl;

    return 0;
}