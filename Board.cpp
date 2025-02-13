#include "Board.h"
#include <iostream>

using namespace std;

Board::Board(){
    // Initialize the board's state
    for (short int i = 0; i < 23; i++){
        state[i] = 0;
    }
}

Board::Board(const Board& b) {
    // Copy constructor
    for (short int i = 0; i < 23; i++){
        state[i] = b.state[i];
    }
}


short int& Board::operator[](const unsigned short int i) {
    return state[i];
}