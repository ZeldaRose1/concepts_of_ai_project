#include "Board.h"
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

Board::Board(){
    // Initialize the board's state
    white = 0;
    black = 0;
    whiteCount = 0;
    blackCount = 0;
    whiteTurn = 1;
    gamePhase = 0;
    heuristic = 0;
}

Board::Board(const Board& b) {
    // Copy constructor
    white = b.white;
    black = b.black;
    whiteCount = b.whiteCount;
    blackCount = b.blackCount;
    whiteTurn = b.whiteTurn;
    gamePhase = b.gamePhase;
    heuristic = b.heuristic;
}

Board::Board(const char* in_path) {
    // Read a board in from a file.

    // Initialize and open file
    ifstream in;
    in.open(in_path);
    string content;
    (getline(in, content));
    int offset = 0;
    for (int i = 0; i < 23; i++) {
        if (content[i + offset] == '-'){
            offset += 1;
            updateBoard(i, -1);
        } else if (content[i + offset] == '0') {
            updateBoard(i, 0);
        } else
            updateBoard(i, 1);
    }
    
    // Read turn line
    getline(in, content);
    whiteTurn = atoi(content.c_str());

    // Read game phase
    getline(in, content);
    gamePhase = atoi(content.c_str());

    // Default heuristic to be calculated later
    heuristic = 0;
    
    // Close in file
    in.close();
}

// Write index operator
void Board::updateBoard(short int i, short int val) {
    /*
        This function assumes white is changing the value
        i is the index
        val is 1, -1, or 0 to change index to white, black, or empty respectively
    */
    
    // Declare variables
    unsigned long int w;
    unsigned long int b;
    
    // Check preconditions
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
        if (b == 1) {
            black -= static_cast<unsigned long int>(pow(2, i));
            blackCount--;
            // whiteTurn = whiteTurn == 1 ? 0 : 1; // Toggle whiteTurn
            // Check for transition to end game phase
            if (gamePhase == 1 & blackCount <= 3)
                gamePhase = 2;
        } if (w == 1)
            return; // Value already matches
        else{
            white += static_cast<unsigned long int>(pow(2, i));
            whiteCount++; // Increment white count
            // whiteTurn = whiteTurn == 1 ? 0 : 1; // Toggle whiteTurn
            // Update game phase
            if (whiteCount == 9 & blackCount == 9 & gamePhase == 0)
                gamePhase = 1;
        }

    } else if (val == -1) { // Set space to black
        if (w == 1){
            white -= static_cast<unsigned long int>(pow(2, i));
            whiteCount--;
            // whiteTurn = whiteTurn == 1 ? 0 : 1; // Toggle whiteTurn
            // Check for transition to end game phase
            if (gamePhase == 1 & whiteCount <= 3)
                gamePhase = 2;
        } if (b == 1)
            return; // Value already matches
        else {
            black += static_cast<unsigned long int>(pow(2, i)); // Update black
            blackCount++;
            // whiteTurn = whiteTurn == 1 ? 0 : 1; // Toggle whiteTurn
            // Update game phase
            if (whiteCount == 9 & blackCount == 9 & gamePhase == 0)
                gamePhase = 1;
        }

    } else if (val == 0) { // Set space to empty   
        if (w == 1){
            white -= static_cast<unsigned long int>(pow(2, i));
            whiteCount--;
            // whiteTurn = whiteTurn == 1 ? 0 : 1; // Toggle whiteTurn
            // Check for transition to end game phase
            if (gamePhase == 1 & whiteCount <= 3)
                gamePhase = 2;
        } if (b == 1) {
            black -= static_cast<unsigned long int>(pow(2, i));
            blackCount--;
            // whiteTurn = whiteTurn == 1 ? 0 : 1; // Toggle whiteTurn
            // Check for transition to end game phase
            if (gamePhase == 1 & blackCount <= 3)
                gamePhase = 2;
        }
    }
    return;
}


// Read index operator
short int Board::operator[](int i){
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


void Board::swapColors() {
    /* Swap board positions for white and black. */
    
    // Board value swap
    unsigned long int temp = white;
    white = black;
    black = temp;
    
    // Count swap
    unsigned long int tempCount = whiteCount;
    whiteCount = blackCount;
    blackCount = tempCount;
    
    // Toggle turn variable
    whiteTurn == 1 ? 0 : 1;

    return;
}

void Board::setCounts() {
    /* Updates the count of white pieces in a given board */
    // Reset counts
    whiteCount = 0;
    blackCount = 0;
    
    // Loop over spots in the board and count pieces
    for (int i = 0; i < 23; i++) {
        if (operator[](i) == 1)
            whiteCount++;
        else if (operator[](i) == -1)
            blackCount++;
    }
    return;
}

int Board::writeBoard(string out_path){
    // Write board to a text file
    
    // Initialize out stream
    ofstream out;
    // Open file
    out.open(out_path);
    if (out.is_open()){
        // Write file
        for (int i = 0; i < 23; i++) {
            out << operator[](i);
        }
        // Write new turn and gamePhase
        out << "\n" << whiteTurn << "\n" << gamePhase << endl;
        return 1;
    } else {
        cout << "Error in Board::writeBoard; Could not open file." << endl;
        return 0;
    }

}

bool Board::closeMill(short int i, Board& b){
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

void Board::generateRemove(Board& b, vector<Board>& l) {
    // Generate a list of all possible black removals and insert into list l
    for (int i = 0; i < 23; i++) {
        if (b[i] == -1) {
            if (!closeMill(i, b)) {
                Board b2(b);
                b2.updateBoard(i, 0);
                b2.whiteTurn == 1 ? 0 : 1;
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
            b2.whiteTurn == 1 ? 0 : 1;
            l.push_back(b2);
        }
    }
}

vector<Board> Board::generateHopping(Board& b) {
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
                    else{
                        // Otherwise, just push back the current board
                        b2.whiteTurn == 1 ? 0 : 1;
                        l.push_back(b2);
                    }
                }
            }
        }
    }
    return l;
}

vector<Board> Board::generateAdd(Board& b) {
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
            else {
                // Save board to the list
                b_copy.whiteTurn == 1 ? 0 : 1;
                l.push_back(b_copy);
            }
        }
    }

    return l;
}

vector<Board> Board::generateMove(Board& b) {
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
                    else {  // If there are no pieces to remove push the board as is
                        b_copy.whiteTurn == 1 ? 0 : 1;
                        l.push_back(b_copy);
                    }
                }
            }
        }
    }

    return l;
}

vector<Board> Board::generateNextLevel(Board& b) {
    // Checks game phase and turn to fill a board's vector
    
    if (b.whiteTurn == 0)
        b.swapColors();
    
    if (b.gamePhase == 0)
        return generateAdd(b);
    else if (b.gamePhase == 2 & b.whiteCount <= 3)
        return generateHopping(b);
    else
        return generateMove(b);
}

int Board::staticEstimate() {
    // Calculates a heuristic after checking game phase
    
    if (gamePhase == 0){
        // Heuristic for opening
        heuristic = whiteCount - blackCount;
        return heuristic;

    } else if (gamePhase > 0) {
        // Heuristic calculations for post opening
        if (blackCount <= 2){
            // Next move is victory for white (max)
            heuristic = 10000;
            return heuristic;

        } else if (whiteCount <= 2) {
            // Next move is black victory
            heuristic = -10000;
            return heuristic;

        } else {

            if (L.size() == 0){
                L = generateNextLevel(*this);
                // Black can't move so white wins
                heuristic = 10000;
                return heuristic;

            } else {
                // Final heuristic for in-progress game
                heuristic = 1000 * (whiteCount - blackCount) - L.size();
                return heuristic;
            }
        }
    }
    return heuristic;
}


/*
int Board::minMax(Board& b) {

}
*/
