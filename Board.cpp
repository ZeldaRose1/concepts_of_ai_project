#include "Board.h"
#include <iostream>
#include <cmath>

using namespace std;

Board::Board(){
    // Initialize the board's state
    white = 0;
    black = 0;
}

Board::Board(const Board& b) {
    // Copy constructor
    white = b.white;
    black = b.black;
}

// Write index operator
void Board::updateBoard(short int i, short int val) {
    // This function assumes white is changing the value
    // Check preconditions
    
    // Declare variables
    unsigned long int w;
    unsigned long int b;

    // Validate val
    if (val != 1 && val != -1 && val != 0)
        throw std::invalid_argument("Board can only hold 1, 0, or -1");
    // Validate index
    if (i < 0 || i >= 23)
        throw std::invalid_argument("Index must be between 0 and 22");
    
    // Save value of position i into two variables
    if (i == 0) {
        w = white % 2;
        b = black % 2;
    } else {
        w = (white / static_cast<unsigned long int>(pow(2, i))) % 2;
        b = (black / static_cast<unsigned long int>(pow(2, i))) % 2;
    }

    // Check for consistency
    if (w == 1 && b == 1)
        throw std::domain_error("White and black occupy same space.");
    else if (val == 1) { // Set space to white
        if (b == 1)
            black -= static_cast<unsigned long int>(pow(2, i));
        if (w == 1)
            return; // Value already matches
        else{
            white += static_cast<unsigned long int>(pow(2, i));
        }

    } else if (val == -1) { // Set space to black
        if (w == 1)
            white -= static_cast<unsigned long int>(pow(2, i));
        if (b == 1)
            return; // Value already matches
        else
            black += static_cast<unsigned long int>(pow(2, i)); // Update black

    } else if (val == 0) { // Set space to empty   
        if (w == 1)
            white -= static_cast<unsigned long int>(pow(2, i));
        if (b == 1)
            black -= static_cast<unsigned long int>(pow(2, i));
    }
    return;
}


// Read index operator
short int Board::operator[](const unsigned short int i){
    // Checks both white and black before returning state
    // Validate index
    if (i < 0 || i >= 23)
        throw std::invalid_argument("Index must be between 0 and 22");

    unsigned long int w;
    unsigned long int b;

    // Check value at position i for white and black
    if (i == 0) {
        w = white % 2;
        b = black % 2;
    } else {
        w = (white / static_cast<unsigned long int>(pow(2, i))) % 2;
        b = (black / static_cast<unsigned long int>(pow(2, i))) % 2;
    }

    if (w == 1 && b == 1)
        throw std::domain_error("Same position assigned to white and black");
    else if (w == 1 && b == 0)
        return 1;
    else if (w == 0 && b == 1)
        return -1;
    else
        return 0;
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