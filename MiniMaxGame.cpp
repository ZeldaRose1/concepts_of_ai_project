#include "Board.h"
#include <iostream>

/*
This file will act as a driver to control minimax search

Arg1 is the input .txt file
Arg2 is the output file
Arg3 is the depth of the search

The input file must be three lines with the following format:
    First line: board positions with 1's representing white pieces,
        -1's representing black pieces, and 0's representing empty
    Second line: Single int with a 1 for white's turn and 0 for black's
    Third line: Single int with a 0 for opening phase, 1 for midgame,
        and 2 for endgame
*/

// Please note, this is an exact copy of the MiniMaxOpening.cpp file


int main (int argc, char *argv[]) {
    // Verify the proper number of arguments.
    if (argc != 4){
        cout << "ERROR: Must supply input file name, output file name, and the depth of the search." << endl;
        return 1;
    }

    // Load board from file
    cout << argv[1] << endl;
    Board b(argv[1]);
    int cur_iter = 0;
    cout << argv[3] << endl;
    int max_depth = atoi(argv[3]);
    int leaf_count = 0;


    // Loop through the iterations
    Board output = b.miniMaxSearch(b, max_depth, leaf_count);

    cout << "Input Position:  ";
    for (int i = 0; i < 23; i++){
        if (b[i] == -1)
            cout << 'B';
        else if (b[i] == 1)
            cout << 'W';
        else if (b[i] == 0)
            cout << 'x';
        else
            cout << ' ';
    }
        
        
    
    cout << "\nOutput Position:  ";
    for (int i = 0; i < 23; i++){
        if (output[i] == -1)
            cout << 'B';
        else if (output[i] == 1)
            cout << 'W';
        else if (output[i] == 0)
            cout << 'x';
        else
            cout << ' ';
    }

    output.writeBoard(argv[2]);

    cout << "\nPositions evaluated by static estimation:";
    cout << leaf_count << endl;

    cout << "MINIMAX estimate: " << output.heuristic << endl;
    cout << "output.staticEstimate(): " << output.staticEstimate() << endl;

    return 0;
}