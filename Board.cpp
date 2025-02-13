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


// For any position on the board, return a vector of adjacent spaces.
vector<unsigned short int> Board::neighbors(unsigned short int index) {
    // Returns vector of adjacent spaces
    switch (index) {
        case Board::a0:
            return vector<unsigned short int> {Board::d0, Board::b1, Board::a3};
            break;
        case Board::d0:
            return vector<unsigned short int> {Board::a0, Board::g0, Board::d1};
            break;
        case Board::g0:
            return vector<unsigned short int> {Board::d0, Board::f1, Board::g3};
            break;
        case Board::b1:
            return vector<unsigned short int> {Board::a0, Board::d1, Board::c2, Board::b3};
            break;
        case Board::d1:
            return vector<unsigned short int> {Board::d0, Board::b1, Board::f1};
            break;
        case Board::f1:
            return vector<unsigned short int> {Board::g0, Board::d1, Board::e2, Board::f3};
            break;
        case Board::c2:
            return vector<unsigned short int> {Board::b1, Board::e2, Board::c3};
            break;
        case Board::e2:
            return vector<unsigned short int> {Board::f1, Board::c2, Board::e3};
            break;
        case Board::a3:
            return vector<unsigned short int> {Board::a0, Board::b3, Board::a6};
            break;
        case Board::b3:
            return vector<unsigned short int> {Board::b1, Board::a3, Board::c3, Board::b5};
            break;
        case Board::c3:
            return vector<unsigned short int> {Board::c2, Board::b3, Board::c4};
            break;
        case Board::e3:
            return vector<unsigned short int> {Board::e2, Board::f3, Board::e4};
            break;
        case Board::f3:
            return vector<unsigned short int> {Board::f1, Board::e3, Board::g3, Board::f5};
            break;
        case Board::g3:
            return vector<unsigned short int> {Board::g0, Board::f3, Board::g6};
            break;
        case Board::c4:
            return vector<unsigned short int> {Board::c3, Board::d4, Board::b5};
            break;
        case Board::d4:
            return vector<unsigned short int> {Board::c4, Board::e4, Board::d5};
            break;
        case Board::e4:
            return vector<unsigned short int> {Board::e3, Board::d4, Board::f5};
            break;
        case Board::b5:
            return vector<unsigned short int> {Board::b3, Board::c4, Board::d5, Board::a6};
            break;
        case Board::d5:
            return vector<unsigned short int> {Board::d4, Board::b5, Board::f5, Board::d6};
            break;
        case Board::f5:
            return vector<unsigned short int> {Board::f3, Board::e4, Board::d5, Board::g6};
            break;
        case Board::a6:
            return vector<unsigned short int> {Board::a3, Board::b5, Board::d6};
            break;
        case Board::d6:
            return vector<unsigned short int> {Board::d5, Board::a6, Board::g6};
            break;
        case Board::g6:
            return vector<unsigned short int> {Board::g3, Board::f5, Board::d6};
            break;
        default:
            cout << "Error, improper location passed to neighbors." << endl;
            return vector<unsigned short int> {};
    }
}