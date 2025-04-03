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


vector<Board> Game::generateHopping(Board& b) {
    /* Generates a list of Board positions during the endgame */
    // Initialize variables
    vector<Board> l;

    // Start outer loop
    for (int i = 0; i < 23; i++) { // Loop checks all owned pieces
        // Skip unowned tiles
        if (b[i] == 1) {
            for (int j = 0; j < 23; j++) { // Check all pieces that aren't the current tile
                // Check for empty spaces
                if (b[j] == 0) {
                    // Make copy of the board to be pushed to the list
                    Board b2(b);
                    
                    // Update the board with the new move
                    b2.updateBoard(i, 0);
                    b2.updateBoard(j, 1);
                    
                    // If we can create a mill
                    if (closeMill(j, b2))
                        // Add all possible removals to list
                        generateRemove(b2, l);
                    else
                        // Otherwise, just push back the current board
                        l.push_back(b2);
                }
            }
        }
    }
    return l;
}


vector<Board> Game::generateAdd(Board& b) {
    /*
        This function will add a tile to the board.
        White is assumed to be the player in this case.
    */

    // Initializations
    vector<Board> l;

    // Loop over each position on the board
    for (int i = 0; i < 23; i++) {
        // Check if the position is empty
        if (b[i] == 0) {
            // Copy board to a new variable
            Board b_copy(b);
            // Set the empty location to white
            b_copy.updateBoard(i, 1);
            // Check for a mill
            if (closeMill(i, b_copy))
                // Add all possible removals to the list
                generateRemove(b_copy, l);
            else
                // Save board to the list
                l.push_back(b_copy);
        }
    }

    return l;
}

vector<Board> Game::generateMove(Board& b) {
    /*
        Midgame function. Moves pieces around the board when there
        are more than three white pieces on the board.
        Assumes white is moving
    */
    // Initialize variables
    vector<Board> l;
    vector<unsigned short int> n;

    // Loop over all moves on the board
    for(int i = 0; i < 23; i++) {
        // Check if tile is placed at location i
        if (b[i] == 1) {
            // Assign list of neighbors for position i
            n = b.neighbors(i);
            // Loop over list of neighbors
            for (int j = 0; j < n.size(); j++) {
                // Check value of Board at every neighboring position
                if (b[ n[j] ] == 0) {
                    // Copy board to temporary variable
                    Board b_copy(b);
                    // Move piece
                    b_copy.updateBoard(i, 0);
                    b_copy.updateBoard(n[j], 1);
                    // Check for mills
                    if (closeMill(n[j], b_copy))
                        generateRemove(b_copy, l);
                    else // If there are no pieces to remove push the board as is
                        l.push_back(b_copy);
                }
            }
        }
    }

    return l;
}

