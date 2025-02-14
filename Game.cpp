#include "Game.h"
#include <iostream>

using namespace std;

Game::Game() {
    // Default constructor for a game
    Board b;
    board = b;
}

Game::Game(Board b) {
    // Constructor for pre-existing board
    board = b;
}

Board& Game::getBoard() {
    return board;
}

void Game::setBoard(Board b) {
    board = b;
}

// Check for mill at given position in given board
bool Game::closeMill(short int i, Board& b){
    // Tests position for a mill after tile has been placed
    // Pull value at i
    short int val = b[i];

    // Verify location has tile already
    if (val == 0) {
        // Position empty, no mil
        return false;
    }

    // Start switch for mil
    switch (i) {
        case 0: // This is a0
            if (
                (b[b.d0] == val && b[b.g0] == val) ||
                (b[b.b1] == val && b[b.c2] == val) ||
                (b[b.a3] == val && b[b.a6] == val)
            ) return true;
            else return false;
            break;
        case 1: // This is d0
            if (
                (b[b.a0] == val && b[b.g0] == val)
            ) return true;
            else return false;
            break;
        case 2: // g0
            if (
                (b[b.a0] == val && b[b.d0] == val) ||
                (b[b.f1] == val && b[b.e2] == val) ||
                (b[b.g3] == val && b[b.g6] == val)
            ) return true;
            else return false;
            break;
        case 3: // b1
            if (
                (b[b.d1] == val && b[b.f1] == val) ||
                (b[b.b3] == val && b[b.b5] == val) ||
                (b[b.a0] == val && b[b.c2] == val)
            ) return true;
            else return false;
            break;
        case 4: // d1
            if (
                (b[b.b1] == val && b[b.f1] == val)
            ) return true;
            else return false;
            break;
        case 5: // f1
            if (
                (b[b.g0] == val && b[b.e2] == val) ||
                (b[b.b1] == val && b[b.d1] == val) ||
                (b[b.f3] == val && b[b.f5] == val)
            ) return true;
            else return false;
            break;
        case 6: // c2
            if (
                (b[b.a0] == val && b[b.b1] == val) ||
                (b[b.c3] == val && b[b.c4] == val)
            ) return true;
            else return false;
            break;
        case 7: // e2
            if (
                (b[b.g0] == val && b[b.f1] == val) ||
                (b[b.e3] == val && b[b.e4] == val)
            ) return true;
            else return false;
            break;
        case 8: // a3
            if (
                (b[b.b3] == val && b[b.c3] == val) ||
                (b[b.a0] == val && b[b.a6] == val)
            ) return true;
            else return false;
            break;
        case 9: // b3
            if (
                (b[b.a3] == val && b[b.c3] == val) ||
                (b[b.b1] == val && b[b.b5] == val)
            ) return true;
            else return false;
            break;
        case 10: // c3
            if (
                (b[b.a3] == val && b[b.b3] == val) ||
                (b[b.c2] == val && b[b.c4] == val)
            ) return true;
            else return false;
            break;
        case 11: // e3
            if (
                (b[b.e2] == val && b[b.e4] == val) ||
                (b[b.f3] == val && b[b.g3] == val)
            ) return true;
            else return false;
            break;
        case 12: // f3
            if (
                (b[b.e3] == val && b[b.g3] == val) ||
                (b[b.f1] == val && b[b.f5] == val)
            ) return true;
            else return false;
            break;
        case 13: // g3
            if (
                (b[b.g0] == val && b[b.g6] == val) ||
                (b[b.e3] == val && b[b.f3] == val)
            ) return true;
            else return false;
            break;
        case 14: // c4
            if (
                (b[b.b5] == val && b[b.a6] == val) ||
                (b[b.d4] == val && b[b.e4] == val) ||
                (b[b.c2] == val && b[b.c3] == val)
            ) return true;
            else return false;
            break;
        case 15: // d4
            if (
                (b[b.c4] == val && b[b.e4] == val) ||
                (b[b.d5] == val && b[b.d5] == val)
            ) return true;
            else return false;
            break;
        case 16: // e4
            if (
                (b[b.e2] == val && b[b.e3] == val) ||
                (b[b.c4] == val && b[b.d4] == val) ||
                (b[b.f5] == val && b[b.g6] == val)
            ) return true;
            else return false;
            break;
        case 17: // b5
            if (
                (b[b.c4] == val && b[b.a6] == val) ||
                (b[b.d5] == val && b[b.f5] == val) ||
                (b[b.b1] == val && b[b.b3] == val)
            ) return true;
            else return false;
            break;
        case 18: // d5
            if (
                (b[b.d4] == val && b[b.d6] == val) ||
                (b[b.b5] == val && b[b.f5] == val)
            ) return true;
            else return false;
            break;
        case 19: // f5
            if (
                (b[b.b5] == val && b[b.d5] == val) ||
                (b[b.f1] == val && b[b.f3] == val) ||
                (b[b.e4] == val && b[b.g6] == val)
            ) return true;
            else return false;
            break;
        case 20: // a6
            if (
                (b[b.a0] == val && b[b.a3] == val) ||
                (b[b.c4] == val && b[b.b5] == val) ||
                (b[b.d6] == val && b[b.g6] == val)
            ) return true;
            else return false;
            break;
        case 21: // d6
            if (
                (b[b.d4] == val && b[b.d5] == val) ||
                (b[b.a6] == val && b[b.g6] == val)
            ) return true;
            else return false;
            break;
        case 22: // g6
            if (
                (b[b.g0] == val && b[b.g3] == val) ||
                (b[b.e4] == val && b[b.f5] == val) ||
                (b[b.a6] == val && b[b.d6] == val)
            ) return true;
            else return false;
            break;
        default:
            return false;
    }
}


void Game::generateRemove(Board& b, vector<Board>& l) {
    // Generate a list of all possible black removals and insert into list l
    for (int i = 0; i < 23; i++) {
        if (b[i] == -1) {
            if (!closeMill(i, b)) {
                Board b2(b);
                b2.updateBoard(i, 0);
                l.push_back(b2);
            }
        }
    }
    // If we have any values in the list, we are done.
    if (l.size() > 0)
        return;
    
    // If we cannot remove an unprotected piece, we remove a piece with a mil.
    for (int i = 0; i < 23; i++) {
        if (b[i] == -1) {
            Board b2(b);
            b2.updateBoard(i, 0);
            l.push_back(b2);
        }
    }
}