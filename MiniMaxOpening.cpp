#include "Board.h"
#include <iostream>

/*
This file will act as a driver to control minimax search

Arg1 is the input file
Arg2 is the output file
Arg3 is the depth of the search
*/


int main (int argc, char *argv[]) {
    // Verify the proper number of arguments.
    if (argc != 4){
        cout << "ERROR: Must supply input file name, output file name, and the depth of the search." << endl;
        return 1;
    }

    Board b;
    b.updateBoard(0, 1);
    b.updateBoard(1, 1);
    b.updateBoard(2, 1);

    b.updateBoard(20, -1);
    b.updateBoard(21, -1);
    b.updateBoard(22, -1);

    b.writeBoard(argv[3]);
    

    return 0;
}