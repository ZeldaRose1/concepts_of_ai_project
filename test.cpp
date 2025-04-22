#include <iostream>
#include <fstream> // Needed for io testing
#include <cassert>
#include <stdio.h> // For deleting files
#include <math.h>
#include "Board.h"
using namespace std;


bool testBoardConstructor(){
    // This tests to ensure the board is initialized to all 0s
    Board b;
    try {
        assert(b.white == 0);
        assert(b.black == 0);
        assert(b.whiteCount == 0);
        assert(b.blackCount == 0);
    }
    catch (const exception e) {
        cout << "Exception raised in testBoardConstructor:\t" << e.what() << endl;
        return false;
    }
    return true;
}

bool testBoardCopyConstructor(){
    // This tests generates random data to fill the board with to 
    // check that the copy constructor functions as planned.
    Board b;
    b.updateBoard(b.e4, 1);
    b.updateBoard(b.f5, 1);
    b.updateBoard(b.g6, 1);

    b.updateBoard(b.a0, -1);
    b.updateBoard(b.a3, -1);
    b.updateBoard(b.a6, -1);

    // Initialize second board
    Board b2(b);

    // Run test
    try {
        assert(b2.white == 4784128);
        assert(b2.black == 1048833);
        assert(b2.whiteCount == 3);
        assert(b2.blackCount == 3);
    }
    catch (const exception e) {
        cout << "Exception raised in testBoardConstructor:\t" << e.what() << endl;
        return false;
    }
    return true;
}


bool testCloseMill() {
    // Test function for Game::closeMill()
    // Game g;
    Board b;

    // Test for false on all empty spaces
    for (int i = 0; i < 23; i++)
        assert (!b.closeMill(i, b));
    
    // Form mill on bottom row
    b.updateBoard(b.a0, 1);
    b.updateBoard(b.d0, 1);
    b.updateBoard(b.g0, 1);

    try {
        // Test the first row (all mills)
        assert (b.closeMill(b.a0, b));
        assert (b.closeMill(b.d0, b));
        assert (b.closeMill(b.g0, b));

        // Test all spaces that are not mills
        for (int i = 4; i < 23; i++)
            assert (!b.closeMill(i, b));

        // Un-mill the bottom row and retest. (Checks against non-homogenous row)
        b.updateBoard(b.d0,  -1);

        // Check mil has been undone
        assert (!b.closeMill(b.a0, b));
        assert (!b.closeMill(b.d0, b));
        assert (!b.closeMill(b.g0, b));

        // Reset board
        for (int i = 0; i < 23; i++)
            b.updateBoard(i, 0);
        // Set a0, b1, c2
        b.updateBoard(b.a0, 1);
        b.updateBoard(b.b1, 1);
        b.updateBoard(b.c2, 1);
        // Run tests
        for (int i = 0; i < 23; i++) {
            if (i == b.a0 || i == b.b1 || i == b.c2)
                assert (b.closeMill(i, b)); // Check real mils return true
            else
                assert (!b.closeMill(i, b));  // Check non-mils return false
        }
        
        // Reset board
        for (int i = 0; i < 23; i++)
            b.updateBoard(i, 0);
        // Set pieces
        b.updateBoard(b.a0, 1);
        b.updateBoard(b.a3, 1);
        b.updateBoard(b.a6, 1);
        // Run tests
        for (int i = 0; i < 23; i++) {
            if (i == b.a0 || i == b.a3 || i == b.a6)
                assert (b.closeMill(i, b)); // Check real mils return true
            else
                assert (!b.closeMill(i, b)); // Check non-mils return false
        }

        // Reset board
        for (int i = 0; i < 23; i++)
            b.updateBoard(i, 0);
        // Set pieces
        b.updateBoard(b.g0, 1);
        b.updateBoard(b.f1, 1);
        b.updateBoard(b.e2, 1);
        // Run tests
        for (int i = 0; i < 23; i++) {
            if (i == b.g0 || i == b.f1 || i == b.e2)
                assert (b.closeMill(i, b)); // Check real mils return true
            else
                assert (!b.closeMill(i, b)); // Check non-mils return false
        }

        // Reset board
        for (int i = 0; i < 23; i++)
            b.updateBoard(i, 0);
        // Set pieces
        b.updateBoard(b.g0, 1);
        b.updateBoard(b.g3, 1);
        b.updateBoard(b.g6, 1);
        // Run tests
        for (int i = 0; i < 23; i++) {
            if (i == b.g0 || i == b.g3 || i == b.g6)
                assert (b.closeMill(i, b)); // Check real mils return true
            else
                assert (!b.closeMill(i, b)); // Check non-mils return false
        }

        // Reset board
        for (int i = 0; i < 23; i++)
            b.updateBoard(i, 0);
        // Set pieces
        b.updateBoard(b.a6, 1);
        b.updateBoard(b.d6, 1);
        b.updateBoard(b.g6, 1);
        // Run tests
        for (int i = 0; i < 23; i++) {
            if (i == b.a6 || i == b.d6 || i == b.g6)
                assert (b.closeMill(i, b)); // Check real mils return true
            else
                assert (!b.closeMill(i, b)); // Check non-mils return false
        }

        // Reset board
        for (int i = 0; i < 23; i++)
            b.updateBoard(i, 0);
        // Set pieces
        b.updateBoard(b.c4, 1);
        b.updateBoard(b.b5, 1);
        b.updateBoard(b.a6, 1);
        // Run tests
        for (int i = 0; i < 23; i++) {
            if (i == b.a6 || i == b.b5 || i == b.c4)
                assert (b.closeMill(i, b)); // Check real mils return true
            else
                assert (!b.closeMill(i, b)); // Check non-mils return false
        }

        // Reset board
        for (int i = 0; i < 23; i++)
            b.updateBoard(i, 0);
        // Set pieces
        b.updateBoard(b.e4, 1);
        b.updateBoard(b.f5, 1);
        b.updateBoard(b.g6, 1);
        // Run tests
        for (int i = 0; i < 23; i++) {
            if (i == b.e4 || i == b.f5 || i == b.g6)
                assert (b.closeMill(i, b)); // Check real mils return true
            else
                assert (!b.closeMill(i, b)); // Check non-mils return false
        }

        // Reset board
        for (int i = 0; i < 23; i++)
            b.updateBoard(i, 0);
        // Set pieces
        b.updateBoard(b.b1, 1);
        b.updateBoard(b.d1, 1);
        b.updateBoard(b.f1, 1);
        // Run tests
        for (int i = 0; i < 23; i++) {
            if (i == b.b1 || i == b.d1 || i == b.f1)
                assert (b.closeMill(i, b)); // Check real mils return true
            else
                assert (!b.closeMill(i, b)); // Check non-mils return false
        }

        // Reset board
        for (int i = 0; i < 23; i++)
            b.updateBoard(i, 0);
        // Set pieces
        b.updateBoard(b.f1, 1);
        b.updateBoard(b.f3, 1);
        b.updateBoard(b.f5, 1);
        // Run tests
        for (int i = 0; i < 23; i++) {
            if (i == b.f1 || i == b.f3 || i == b.f5)
                assert (b.closeMill(i, b)); // Check real mils return true
            else
                assert (!b.closeMill(i, b)); // Check non-mils return false
        }

        // Reset board
        for (int i = 0; i < 23; i++)
            b.updateBoard(i, 0);
        // Set pieces
        b.updateBoard(b.b5, 1);
        b.updateBoard(b.d5, 1);
        b.updateBoard(b.f5, 1);
        // Run tests
        for (int i = 0; i < 23; i++) {
            if (i == b.b5 || i == b.d5 || i == b.f5)
                assert (b.closeMill(i, b)); // Check real mils return true
            else
                assert (!b.closeMill(i, b)); // Check non-mils return false
        }

        // Reset board
        for (int i = 0; i < 23; i++)
            b.updateBoard(i, 0);
        // Set pieces
        b.updateBoard(b.a3, 1);
        b.updateBoard(b.b3, 1);
        b.updateBoard(b.c3, 1);
        // Run tests
        for (int i = 0; i < 23; i++) {
            if (i == b.a3 || i == b.b3 || i == b.c3)
                assert (b.closeMill(i, b)); // Check real mils return true
            else
                assert (!b.closeMill(i, b)); // Check non-mils return false
        }

        // Reset board
        for (int i = 0; i < 23; i++)
            b.updateBoard(i, 0);
        // Set pieces
        b.updateBoard(b.d4, 1);
        b.updateBoard(b.d5, 1);
        b.updateBoard(b.d6, 1);
        // Run tests
        for (int i = 0; i < 23; i++) {
            if (i == b.d4 || i == b.d5 || i == b.d6)
                assert (b.closeMill(i, b)); // Check real mils return true
            else
                assert (!b.closeMill(i, b)); // Check non-mils return false
        }

        // Reset board
        for (int i = 0; i < 23; i++)
            b.updateBoard(i, 0);
        // Set pieces
        b.updateBoard(b.e3, 1);
        b.updateBoard(b.f3, 1);
        b.updateBoard(b.g3, 1);
        // Run tests
        for (int i = 0; i < 23; i++) {
            if (i == b.e3 || i == b.f3 || i == b.g3)
                assert (b.closeMill(i, b)); // Check real mils return true
            else
                assert (!b.closeMill(i, b)); // Check non-mils return false
        }

        // Reset board
        for (int i = 0; i < 23; i++)
            b.updateBoard(i, 0);
        // Set pieces
        b.updateBoard(b.e3, 1);
        b.updateBoard(b.f3, 1);
        b.updateBoard(b.g3, 1);
        // Run tests
        for (int i = 0; i < 23; i++) {
            if (i == b.e3 || i == b.f3 || i == b.g3)
                assert (b.closeMill(i, b)); // Check real mils return true
            else
                assert (!b.closeMill(i, b)); // Check non-mils return false
        }

        // Reset board
        for (int i = 0; i < 23; i++)
            b.updateBoard(i, 0);
        // Set pieces
        b.updateBoard(b.c2, 1);
        b.updateBoard(b.c3, 1);
        b.updateBoard(b.c4, 1);
        // Run tests
        for (int i = 0; i < 23; i++) {
            if (i == b.c2 || i == b.c3 || i == b.c4)
                assert (b.closeMill(i, b)); // Check real mils return true
            else
                assert (!b.closeMill(i, b)); // Check non-mils return false
        }

        // Reset board
        for (int i = 0; i < 23; i++)
            b.updateBoard(i, 0);
        // Set pieces
        b.updateBoard(b.c4, 1);
        b.updateBoard(b.d4, 1);
        b.updateBoard(b.e4, 1);
        // Run tests
        for (int i = 0; i < 23; i++) {
            if (i == b.c4 || i == b.d4 || i == b.e4)
                assert (b.closeMill(i, b)); // Check real mils return true
            else
                assert (!b.closeMill(i, b)); // Check non-mils return false
        }

        // Reset board
        for (int i = 0; i < 23; i++)
            b.updateBoard(i, 0);
        // Set pieces
        b.updateBoard(b.e2, 1);
        b.updateBoard(b.e3, 1);
        b.updateBoard(b.e4, 1);
        // Run tests
        for (int i = 0; i < 23; i++) {
            if (i == b.e2 || i == b.e3 || i == b.e4)
                assert (b.closeMill(i, b)); // Check real mils return true
            else
                assert (!b.closeMill(i, b)); // Check non-mils return false
        }
        
        // Force all spaces to be white
        for (int i = 0; i < 23; i++)
            b.updateBoard(i, 1);
        // Run tests
        for (int i = 0; i < 23; i++)
            assert (b.closeMill(i, b));
        
        // Force all spaces to be black
        for (int i = 0; i < 23; i++)
            b.updateBoard(i, -1);
        // Run tests
        for (int i = 0; i < 23; i++)
            assert (b.closeMill(i, b));

        // Reset board
        for (int i = 0; i < 23; i++) b.updateBoard(i, 0);
        // Form mill
        b.updateBoard(b.a0, 1);
        b.updateBoard(b.b1, 1);
        b.updateBoard(b.c2, 1);
        for (int i = 0; i < 23; i++) {
            if (i == b.a0 || i == b.b1 || i == b.c2) {
                assert (b.closeMill(i, b));
            } else {
                assert (!b.closeMill(i, b));
            }
        }
        
        
    } catch (const exception e){
        cout << "Exception raised in testCloseMill:\t" << e.what() << endl;
        return false;
    }

    return true;
}

bool testNeighbors() {
    // Checks that all the values hard coded into Board's
    // neighbor function return the proper vector
    
    // Variable initialization
    Board b;
    vector<unsigned short int> v;
    
    // Tests begin
    try {
        // Test 1
        v = b.neighbors(b.a0);
        assert(v[0] == b.d0 && v[1] == b.b1 && v[2] == b.a3);

        // Test 2
        v = b.neighbors(b.d0);
        assert(v[0] == b.a0 && v[1] == b.g0 && v[2] == b.d1);

        // Test 3
        v = b.neighbors(b.g0);
        assert(v[0] == b.d0 && v[1] == b.f1 && v[2] == b.g3);

        // Test 4
        v = b.neighbors(b.b1);
        assert(v[0] == b.a0 && v[1] == b.d1 && v[2] == b.c2 && v[3] == b.b3);

        // Test 5
        v = b.neighbors(b.d1);
        assert(v[0] == b.d0 && v[1] == b.b1 && v[2] == b.f1);

        // Test 6
        v = b.neighbors(b.f1);
        assert(v[0] == b.g0 && v[1] == b.d1 && v[2] == b.e2 && v[3] == b.f3);

        // Test 7
        v = b.neighbors(b.c2);
        assert(v[0] == b.b1 && v[1] == b.e2 && v[2] == b.c3);

        // Test 8
        v = b.neighbors(b.e2);
        assert(v[0] == b.f1 && v[1] == b.c2 && v[2] == b.e3);

        // Test 9
        v = b.neighbors(b.a3);
        assert(v[0] == b.a0 && v[1] == b.b3 && v[2] == b.a6);

        // Test 10
        v = b.neighbors(b.b3);
        assert(v[0] == b.b1 && v[1] == b.a3 && v[2] == b.c3 && v[3] == b.b5);

        // Test 11
        v = b.neighbors(b.c3);
        assert(v[0] == b.c2 && v[1] == b.b3 && v[2] == b.c4);

        // Test 12
        v = b.neighbors(b.e3);
        assert(v[0] == b.e2 && v[1] == b.f3 && v[2] == b.e4);

        // Test 13
        v = b.neighbors(b.f3);
        assert(v[0] == b.f1 && v[1] == b.e3 && v[2] == b.g3 && v[3] == b.f5);

        // Test 14
        v = b.neighbors(b.g3);
        assert(v[0] == b.g0 && v[1] == b.f3 && v[2] == b.g6);
        
        // Test 15
        v = b.neighbors(b.c4);
        assert(v[0] == b.c3 && v[1] == b.d4 && v[2] == b.b5);

        // Test 16
        v = b.neighbors(b.d4);
        assert(v[0] == b.c4 && v[1] == b.e4 && v[2] == b.d5);

        // Test 17
        v = b.neighbors(b.e4);
        assert(v[0] == b.e3 && v[1] == b.d4 && v[2] == b.f5);

        // Test 18
        v = b.neighbors(b.b5);
        assert(v[0] == b.b3 && v[1] == b.c4 && v[2] == b.d5 && v[3] == b.a6);
        
        // Test 19
        v = b.neighbors(b.d5);
        assert(v[0] == b.d4 && v[1] == b.b5 && v[2] == b.f5 && v[3] == b.d6);

        // Test 20
        v = b.neighbors(b.f5);
        assert(v[0] == b.f3 && v[1] == b.e4 && v[2] == b.d5 && v[3] == b.g6);

        // Test 21
        v = b.neighbors(b.a6);
        assert(v[0] == b.a3 && v[1] == b.b5 && v[2] == b.d6);

        // Test 22
        v = b.neighbors(b.d6);
        assert(v[0] == b.d5 && v[1] == b.a6 && v[2] == b.g6);

        // Test 23
        v = b.neighbors(b.g6);
        assert(v[0] == b.g3 && v[1] == b.f5 && v[2] == b.d6);

    } catch (const exception e){
        cout << "Exception raised in testNeighbors:\t" << e.what() << endl;
        return false;
    }

    return true;
    
}


bool testGenerateRemove() {
    /* Validates behavior of GenerateRemove function. */
    // Declare Variables
    // Game g;
    Board b1;
    vector<Board> l;

    // TODO: Add test cases for when there are no
    // non-mil black pieces to remove, but l is non-empty

    // Setup three black pieces on the board
    b1.updateBoard(b1.g6, -1);
    b1.updateBoard(b1.a6, -1);
    b1.updateBoard(b1.g0, -1);
    b1.updateBoard(b1.a0, -1);
    b1.generateRemove(b1, l);

    // Assert blocks
    try {
        /* Check behavior with no mills (case 1) */
        // Should have four solutions.
        assert(l.size() == 4);
        assert(l[0].black == pow(2, 22) + pow(2, 20) + pow(2, 2));
        assert(l[1].black == pow(2, 22) + pow(2, 20) + pow(2, 0));
        assert(l[2].black == pow(2, 22) + pow(2, 2) + pow(2, 0));
        assert(l[3].black == pow(2, 20) + pow(2, 2) + pow(2, 0));

        /* Validate behavior when a mill exists (mixed case 2) */
        l.clear();
        // Form mill across row 6
        b1.black += pow(2, 21);
        b1.generateRemove(b1, l);

        // Start asserts for mixed case
        assert(l.size() == 2);
        assert(l[0].black == pow(2, 22) + pow(2, 21) + pow(2, 20) + pow(2, 2));
        assert(l[1].black == pow(2, 22) + pow(2, 21) + pow(2, 20) + pow(2, 0));

        /* Validate behavior when only mill exists (case 3) */
        l.clear();
        // Form mill across row 0
        b1.black += pow(2, 1);
        b1.generateRemove(b1, l);

        // Start asserts for mixed case
        assert(l.size() == 6);
        assert(l[0].black == pow(2, 22) + pow(2, 21) + pow(2, 20) + pow(2, 2) + pow(2, 1));
        assert(l[1].black == pow(2, 22) + pow(2, 21) + pow(2, 20) + pow(2, 2) + pow(2, 0));
        assert(l[2].black == pow(2, 22) + pow(2, 21) + pow(2, 20) + pow(2, 1) + pow(2, 0));
        assert(l[3].black == pow(2, 22) + pow(2, 21) + pow(2, 2) + pow(2, 1) + pow(2, 0));
        assert(l[4].black == pow(2, 22) + pow(2, 20) + pow(2, 2) + pow(2, 1) + pow(2, 0));
        assert(l[5].black == pow(2, 21) + pow(2, 20) + pow(2, 2) + pow(2, 1) + pow(2, 0));

    } catch (const exception e){
        cout << "Exception raised in testGenerateRemove:\t" << e.what() << endl;
        return false;
    }

    return true;
}


bool testGenerateHopping() {
    /* Validates performance of endgame Board::generateHopping() function */
    Board b;
    vector<Board> l;

    try {
        /*
            We need to test four main scenarios:
            1. White's turn with no mill formation
            2. White's turn with mill formation (triggering remove)
            3. Black's turn with no mill formation
            4. Black's turn with mill formation
        */

        // Test 1: White's turn, no mill formation
        // Setup: 3 white pieces with no possible mills, 3 black pieces
        l.clear();
        b.updateBoard(b.a0, 1);
        b.updateBoard(b.d0, 1);
        b.updateBoard(b.g0, 1);
        b.updateBoard(b.a6, -1);
        b.updateBoard(b.d6, -1);
        b.updateBoard(b.g6, -1);
        b.whiteTurn = true;
        l = b.generateHopping(b);
        
        // Should generate (23-3)*3 = 60 possible hops (each white piece can go to any empty spot)
        assert(l.size() == 51);
        
        // Verify all moves hopped from a0
        for (int i = 0; i < 17; i++) {
            assert(l[i].white == pow(2, i + 3) + pow(2, b.d0) + pow(2, b.g0));
            assert(l[i].black == pow(2, b.a6) + pow(2, b.d6) + pow(2, b.g6));
            assert(l[i].whiteTurn == false);  // Turn should flip
        } // Verify all moves hopped from d0
        for (int i = 0; i < 17; i++) {
            assert(l[i + 17].white == pow(2, b.a0) + pow(2, i + 3) + pow(2, b.g0));
            assert(l[i + 17].black == pow(2, b.a6) + pow(2, b.d6) + pow(2, b.g6));
            assert(l[i + 17].whiteTurn == false);  // Turn should flip
        } // Verify all moves hopped from g0
        for (int i = 0; i < 17; i++) {
            assert(l[i + 34].white == pow(2, b.a0) + pow(2, b.d0) + pow(2, i + 3));
            assert(l[i + 34].black == pow(2, b.a6) + pow(2, b.d6) + pow(2, b.g6));
            assert(l[i + 34].whiteTurn == false);  // Turn should flip
        }

        
        // Test 2: White's turn with mill formation
        // a0 can form a mil only at b5
        l.clear();
        b.updateBoard(b.d0, 0);
        b.updateBoard(b.g0, 0);
        b.updateBoard(b.d5, 1);
        b.updateBoard(b.f5, 1);
        b.whiteTurn = true;
        l = b.generateHopping(b);

        // Should have (23 - 6) = 17 open spaces
        // Three pieces to move gives (23 - 6) * 3 = 51 steps
        // Only one move on white will form a mill, but this will add a board
        // for each of 3 removed pieces for a total of 53 boards
        assert(l.size() == 53);

        for (int i = 0; i < 16; i++) {
            assert(l[i].white == pow(2, i + 1) + pow(2, b.d5) + pow(2, b.f5));
            assert(l[i].black == pow(2, b.a6) + pow(2, b.d6) + pow(2, b.g6));
            assert(l[i].whiteTurn == false);  // Turn should flip
        }
        
        // Verify the removed pieces
        assert(l[16].white == pow(2, b.b5) + pow(2, b.d5) + pow(2, b.f5));
        assert(l[16].black == pow(2, b.d6) + pow(2, b.g6));
        assert(l[16].whiteTurn == false);
        assert(l[17].white == pow(2, b.b5) + pow(2, b.d5) + pow(2, b.f5));
        assert(l[17].black == pow(2, b.a6) + pow(2, b.g6));
        assert(l[17].whiteTurn == false);  // Turn should flip
        assert(l[18].white == pow(2, b.b5) + pow(2, b.d5) + pow(2, b.f5));
        assert(l[18].black == pow(2, b.a6) + pow(2, b.d6));
        assert(l[18].whiteTurn == false);  // Turn should flip

        // Verify hopping d5
        for (int i = 0; i < 17; i++) {
            assert(l[i + 19].white == pow(2, b.a0) + pow(2, i + 1) + pow(2, b.f5));
            assert(l[i + 19].black == pow(2, b.a6) + pow(2, b.d6) + pow(2, b.g6));
            assert(l[i + 19].whiteTurn == false);  // Turn should flip
        }

        // Verify hopping f5
        for (int i = 0; i < 17; i++) {
            assert(l[i + 36].white == pow(2, b.a0) + pow(2, b.d5) + pow(2, i + 1));
            assert(l[i + 36].black == pow(2, b.a6) + pow(2, b.d6) + pow(2, b.g6));
            assert(l[i + 36].whiteTurn == false);  // Turn should flip
        }


        
        // Test 3: Black's turn, no mill formation
        l.clear();
        // Moving white tile from a0 to b5 for ease of indexing
        b.updateBoard(b.a0, 0);
        b.updateBoard(b.b5, 1);
        b.whiteTurn = false;
        l = b.generateHopping(b);

        assert(l.size() == 51);
        // Verify all moves hopped from a0
        for (int i = 0; i < 17; i++) {
            assert(l[i].white == pow(2, b.b5) + pow(2, b.d5) + pow(2, b.f5));
            assert(l[i].black == pow(2, i) + pow(2, b.d6) + pow(2, b.g6));
            assert(l[i].whiteTurn == true);  // Turn should flip
        } // Verify all moves hopped from d0
        for (int i = 0; i < 17; i++) {
            assert(l[i + 17].white == pow(2, b.b5) + pow(2, b.d5) + pow(2, b.f5));
            assert(l[i + 17].black == pow(2, b.a6) + pow(2, i) + pow(2, b.g6));
            assert(l[i + 17].whiteTurn == true);  // Turn should flip
        } // Verify all moves hopped from g0
        for (int i = 0; i < 17; i++) {
            assert(l[i + 34].white == pow(2, b.b5) + pow(2, b.d5) + pow(2, b.f5));
            assert(l[i + 34].black == pow(2, b.a6) + pow(2, b.d6) + pow(2, i));
            assert(l[i + 34].whiteTurn == true);  // Turn should flip
        }
        
        // Test 4: Black's turn with mill formation
        l.clear();
        // Moving black tile from a6 to a0 to force only one mill
        b.updateBoard(b.a6, 0);
        b.updateBoard(b.a0, -1);
        b.whiteTurn = false;
        l = b.generateHopping(b);

        cout << "Test 4 Starting Board: \t\t";
        b.printBoard();
        cout << "\n\n" << endl;

        for (int i = 0; i < l.size(); i++){
            cout << "Board " << i << ":\t\t";
            l[i].printBoard();
            cout << endl;
        }

        assert(l.size() == 53);

        for (int i = 0; i < 16; i++) {
            assert(l[i].white == pow(2, b.b5) + pow(2, b.d5) + pow(2, b.f5));
            assert(l[i].black == pow(2, i + 1) + pow(2, b.d6) + pow(2, b.g6));
            assert(l[i].whiteTurn == true);  // Turn should flip
        }
        
        // Verify the removed pieces
        assert(l[16].white == pow(2, b.d5) + pow(2, b.f5));
        assert(l[16].black == pow(2, b.a6) + pow(2, b.d6) + pow(2, b.g6));
        assert(l[16].whiteTurn == true);
        assert(l[17].white == pow(2, b.b5) + pow(2, b.f5));
        assert(l[17].black == pow(2, b.a6) + pow(2, b.d6) + pow(2, b.g6));
        assert(l[17].whiteTurn == true);  // Turn should flip
        assert(l[18].white == pow(2, b.b5) + pow(2, b.d5));
        assert(l[18].black == pow(2, b.a6) + pow(2, b.d6) + pow(2, b.g6));
        assert(l[18].whiteTurn == true);  // Turn should flip

        // Verify hopping d6
        for (int i = 0; i < 16; i++) {
            assert(l[i + 19].white == pow(2, b.b5) + pow(2, b.d5) + pow(2, b.f5));
            assert(l[i + 19].black == pow(2, b.a0) + pow(2, i + 1) + pow(2, b.g6));
            assert(l[i + 19].whiteTurn == true);  // Turn should flip
        }

        // Last hop of d6 to a6
        assert(l[35].white == pow(2, b.b5) + pow(2, b.d5) + pow(2, b.f5));
        assert(l[35].black == pow(2, b.a0) + pow(2, b.a6) + pow(2, b.g6));
        assert(l[35].whiteTurn == true);  // Turn should flip

        // Verify hopping g6
        for (int i = 0; i < 16; i++) {
            assert(l[i + 36].white == pow(2, b.b5) + pow(2, b.d5) + pow(2, b.f5));
            assert(l[i + 36].black == pow(2, b.a0) + pow(2, b.d6) + pow(2, i + 1));
            assert(l[i + 36].whiteTurn == true);  // Turn should flip
        }

        // Final hop of g6 to a6
        assert(l[52].white == pow(2, b.b5) + pow(2, b.d5) + pow(2, b.f5));
        assert(l[52].black == pow(2, b.a0) + pow(2, b.d6) + pow(2, b.a6));
        assert(l[52].whiteTurn == true);  // Turn should flip
        
    } catch (const exception& e) {
        cout << "Exception raised in testGenerateHopping:\t" << e.what() << endl;
        return false;
    }
    
    return true;
}

bool testGenerateAdd() {
    /* Validate performance of generate add */
    Board b;
    vector<Board> l;

    // Start tests
    try {
        // Test 1: White's turn, no mil
        l.clear();
        b.white = 0;
        b.black = 0;
        b.whiteTurn = true;
        l = b.generateAdd(b);
        assert(l.size() == 23);
        for (int i = 0; i < 23; i++){
            assert(l[i].white == pow(2, i));
            assert(l[i].black == 0);
            assert(l[i].whiteTurn == false);
        }

        // Test 2: White's turn, with option for mill
        l.clear();
        b.white = pow(2, b.a0) + pow(2, b.d0); // Move to g0 will provide mill for white
        b.black = pow(2, b.b1);
        b.whiteTurn = true;
        l = b.generateAdd(b);
        
        // Should generate 20 adds, one of which will be a mil.
        // The mil will remove one piece, but will not generate multiple options.
        assert(l.size() == 20);
        // Check the first entry (the mill)
        assert(l[0].white == pow(2, b.g0) + pow(2, b.d0) + pow(2, b.a0));
        assert(l[0].black == 0);
        assert(l[0].whiteTurn == false);
        
        // Check remaining entries
        for (int i = 1; i < 20; i++) {
            assert(l[i].white == pow(2, b.a0) + pow(2, b.d0) + pow(2, i + 3));
            assert(l[i].black == pow(2, b.b1));
            assert(l[i].whiteTurn == false);
        }
        
        // Test 3: black turn no mill
        l.clear();
        b.white = pow(2, 0);
        b.black = 0;
        b.whiteTurn = false;
        l = b.generateAdd(b);
        assert(l.size() == 22);
        for (int i = 0; i < 22; i++){
            assert(l[i].white == 1);
            assert(l[i].black == pow(2, i + 1));
            assert(l[i].whiteTurn == true);
        }

        // Test 4: Black turn with mil
        l.clear();
        b.white = pow(2, b.g6) + pow(2, b.d6) + pow(2, b.a6);
        b.black = pow(2, b.a0) + pow(2, b.d0); // Black's move to g0 will form a mill
        b.whiteTurn = false;
        l = b.generateAdd(b);
        
        // Should generate 18 additions since 5 / 23 are filled
        // 1 of the moves will be a mill and generate three removals
        // This should total 20 moves if I'm thinking correctly
        // The mil will remove one piece, but will not generate multiple options.
        assert(l.size() == 20);
        
        // Check removals (from single mill)
        for (int i = 0; i < 3; i++) {
            assert(l[i].white == pow(2, b.g6) + pow(2, b.d6) + pow(2, b.a6) - pow(2, 22 - (2 - i)));
            assert(l[i].black == pow(2, b.g0) + pow(2, b.d0) + pow(2, b.a0));
            assert(l[i].whiteTurn == true);
        }
        // Check non-mill entries
        for (int i = 3; i < 20; i++) {
            assert(l[i].white == pow(2, b.a6) + pow(2, b.d6) + pow(2, b.g6));
            assert(l[i].black == pow(2, b.a0) + pow(2, b.d0) + pow(2, i));
            assert(l[i].whiteTurn == true);
        }

    } catch (const exception& e) {
        cout << "Exception raised in testGenerateAdd:\t" << e.what() << endl;
        return false;
    }
    
    return true;
}

bool testGenerateMove() {
    /* Validates performance of midgame Game::generateMove() function */
    // Initialize variables
    Board b;
    vector<Board> l;
    
    // Start testing
    try{
        /*
            We have four cases to try based on if it's white's turn and if
            we trigger a mill. We will test these one at a time.
        */

        // Test 1: White's turn, no mill
        // Setup: White piece at a0 that can move to d0 (connected neighbors)
        l.clear();
        b.updateBoard(b.a0, 1);
        b.updateBoard(b.d0, 1);
        b.updateBoard(b.g0, 1);
        b.updateBoard(b.b1, -1);
        b.updateBoard(b.d1, -1);
        b.updateBoard(b.f1, -1);
        b.whiteTurn = true;
        l = b.generateMove(b);
        
        // Should generate a move from a0 - a3 and a move from g0 - g3
        assert(l.size() == 2);
        assert(l[0].white == pow(2, b.d0) + pow(2, b.g0) + pow(2, b.a3));
        assert(l[0].black == pow(2, b.b1) + pow(2, b.d1) + pow(2, b.f1));
        assert(l[0].whiteTurn == false);
        assert(l[1].white == pow(2, b.a0) + pow(2, b.d0) + pow(2, b.g3));
        assert(l[1].black == pow(2, b.b1) + pow(2, b.d1) + pow(2, b.f1));
        assert(l[1].whiteTurn == false);

        // Test 2: White's turn, with mill
        // Setup: White piece at a0 that can move to d0 (connected neighbors)
        l.clear();
        // b.updateBoard(b.a0, 1);
        b.updateBoard(b.d0, 0); // Reset from first test
        b.updateBoard(b.d1, 1);
        // b.updateBoard(b.g0, 1);
        b.updateBoard(b.b1, -1);
        b.updateBoard(b.d6, -1);
        b.updateBoard(b.f1, -1);
        l = b.generateMove(b);

        // Assert section
        assert(l.size() == 7);
        // Move a0 - d0
        assert(l[0].white == pow(2, b.d1) + pow(2, b.g0) + pow(2, b.d0));
        assert(l[0].black == pow(2, b.b1) + pow(2, b.d6) + pow(2, b.f1));
        assert(l[0].whiteTurn == false);

        // Move a0 - a3
        assert(l[1].white == pow(2, b.d1) + pow(2, b.g0) + pow(2, b.a3));
        assert(l[1].black == pow(2, b.b1) + pow(2, b.d6) + pow(2, b.f1));
        assert(l[1].whiteTurn == false);
        
        // Move g0 - d0
        assert(l[2].white == pow(2, b.a0) + pow(2, b.d0) + pow(2, b.d1));
        assert(l[2].black == pow(2, b.b1) + pow(2, b.d6) + pow(2, b.f1));
        assert(l[2].whiteTurn == false);

        // Move g0 - g3
        assert(l[3].white == pow(2, b.a0) + pow(2, b.d1) + pow(2, b.g3));
        assert(l[3].black == pow(2, b.b1) + pow(2, b.d6) + pow(2, b.f1));
        assert(l[3].whiteTurn == false);

        // Move d1 - d0; Remove b1
        assert(l[4].white == pow(2, b.a0) + pow(2, b.d0) + pow(2, b.g0));
        assert(l[4].black == pow(2, b.d6) + pow(2, b.f1));
        assert(l[4].whiteTurn == false);

        // Move d1 - d0; Remove f1
        assert(l[5].white == pow(2, b.a0) + pow(2, b.d0) + pow(2, b.g0));
        assert(l[5].black == pow(2, b.b1) + pow(2, b.d6));
        assert(l[5].whiteTurn == false);

        // Move d1 - d0; Remove b6
        assert(l[6].white == pow(2, b.a0) + pow(2, b.d0) + pow(2, b.g0));
        assert(l[6].black == pow(2, b.b1) + pow(2, b.f1));
        assert(l[6].whiteTurn == false);

        // Test 3: Black No mils
        // b.updateBoard(b.d6, 0);
        l.clear();
        b.whiteTurn = false;
        l = b.generateMove(b);

        assert(l.size() == 7);
        
        // Move b1 - c2
        assert(l[0].white == pow(2, b.a0) + pow(2, b.d1) + pow(2, b.g0));
        assert(l[0].black == pow(2, b.c2) + pow(2, b.d6) + pow(2, b.f1));
        assert(l[0].whiteTurn == true);
        
        // Move b1 - b3
        assert(l[1].white == pow(2, b.a0) + pow(2, b.d1) + pow(2, b.g0));
        assert(l[1].black == pow(2, b.b3) + pow(2, b.d6) + pow(2, b.f1));
        assert(l[1].whiteTurn == true);

        // Move f1 - e2
        assert(l[2].white == pow(2, b.a0) + pow(2, b.d1) + pow(2, b.g0));
        assert(l[2].black == pow(2, b.b1) + pow(2, b.d6) + pow(2, b.e2));
        assert(l[2].whiteTurn == true);

        // Move f1 - f3
        assert(l[3].white == pow(2, b.a0) + pow(2, b.d1) + pow(2, b.g0));
        assert(l[3].black == pow(2, b.b1) + pow(2, b.d6) + pow(2, b.f3));
        assert(l[3].whiteTurn == true);

        // Move d6 - d5
        assert(l[4].white == pow(2, b.a0) + pow(2, b.d1) + pow(2, b.g0));
        assert(l[4].black == pow(2, b.b1) + pow(2, b.d5) + pow(2, b.f1));
        assert(l[4].whiteTurn == true);

        // Move d6 - a6
        assert(l[5].white == pow(2, b.a0) + pow(2, b.d1) + pow(2, b.g0));
        assert(l[5].black == pow(2, b.b1) + pow(2, b.a6) + pow(2, b.f1));
        assert(l[5].whiteTurn == true);
        // Move d6 - g6
        assert(l[6].white == pow(2, b.a0) + pow(2, b.d1) + pow(2, b.g0));
        assert(l[6].black == pow(2, b.b1) + pow(2, b.g6) + pow(2, b.f1));
        assert(l[6].whiteTurn == true);

        // Test 4: Black with mill
        
        // Move black pieces to prepare for mill in top row.
        b.updateBoard(b.a6, -1);
        b.updateBoard(b.g3, -1);
        b.updateBoard(b.b1, 0);
        b.updateBoard(b.f1, 0);

        // Move white pieces to be reduce number of black moves
        b.updateBoard(b.a0, 0);
        b.updateBoard(b.d1, 0);
        b.updateBoard(b.g0, 0);
        b.updateBoard(b.a3, 1);
        b.updateBoard(b.d5, 1);
        b.updateBoard(b.b5, 1);
        
        // Clear board and regenerate moves
        l.clear();
        l = b.generateMove(b);

        // Move g3 - g0
        assert(l[0].white == pow(2, b.a3) + pow(2, b.b5) + pow(2, b.d5));
        assert(l[0].black == pow(2, b.a6) + pow(2, b.d6) + pow(2, b.g0));
        assert(l[0].whiteTurn == true);

        // Move g3 - f3
        assert(l[1].white == pow(2, b.a3) + pow(2, b.b5) + pow(2, b.d5));
        assert(l[1].black == pow(2, b.a6) + pow(2, b.d6) + pow(2, b.f3));
        assert(l[1].whiteTurn == true);

        // Move g3 - g6; Remove a3
        assert(l[2].white == pow(2, b.b5) + pow(2, b.d5));
        assert(l[2].black == pow(2, b.a6) + pow(2, b.d6) + pow(2, b.g6));
        assert(l[2].whiteTurn == true);

        // Move g3 - g6; Remove b5
        assert(l[3].white == pow(2, b.a3) + pow(2, b.d5));
        assert(l[3].black == pow(2, b.a6) + pow(2, b.d6) + pow(2, b.g6));
        assert(l[3].whiteTurn == true);

        // Move g3 - g6; Remove d5
        assert(l[4].white == pow(2, b.a3) + pow(2, b.b5));
        assert(l[4].black == pow(2, b.a6) + pow(2, b.d6) + pow(2, b.g6));
        assert(l[4].whiteTurn == true);

        // Move d6 - g6
        assert(l[5].white == pow(2, b.a3) + pow(2, b.b5) + pow(2, b.d5));
        assert(l[5].black == pow(2, b.a6) + pow(2, b.g6) + pow(2, b.g3));
        assert(l[5].whiteTurn == true);

    } catch (const exception e) {
        cout << "Exception raised in testGenerateMove:\t" << e.what() << endl;
        return false;
    }
    
    return true;
}

bool testSwapColors() {
    /* Validate behavior of Board::swapColors() */
    // Setup initial board
    Board b;
    // White pieces
    b.updateBoard(b.a0, 1);
    b.updateBoard(b.d0, 1);
    b.updateBoard(b.g3, 1);
    b.updateBoard(b.b5, 1);
    b.updateBoard(b.g6, 1);
    // Black pieces
    b.updateBoard(b.a3, -1);
    b.updateBoard(b.c2, -1);
    b.updateBoard(b.e4, -1);
    b.updateBoard(b.f5, -1);

    try {
        // Swap colors
        b.swapColors();
        // Validate appropriate swap
        assert(b.black == pow(2, b.a0) + pow(2, b.d0) + pow(2, b.g3) + pow(2, b.b5) + pow(2, b.g6));
        assert(b.white == pow(2, b.a3) + pow(2, b.c2) + pow(2, b.e4) + pow(2, b.f5));
        assert(b.whiteCount == 4);
        assert(b.blackCount == 5);

        // Swap colors
        b.swapColors();
        // Validate appropriate swap
        assert(b.white == pow(2, b.a0) + pow(2, b.d0) + pow(2, b.g3) + pow(2, b.b5) + pow(2, b.g6));
        assert(b.black == pow(2, b.a3) + pow(2, b.c2) + pow(2, b.e4) + pow(2, b.f5));
        assert(b.whiteCount == 5);
        assert(b.blackCount == 4);
    } catch (const exception e) {
        cout << "Exception raised in testSwapColors:\t" << e.what() << endl;
        return false;
    }
    return true;
}

bool testSetCounts() {
    /* Validate behavior of Board::swapColors() */
    // Setup initial board
    Board b;
    b.white = pow(2, b.a0) + pow(2, b.d0) + pow(2, b.g3) + pow(2, b.b5);
    b.black = pow(2, b.a3) + pow(2, b.c2) + pow(2, b.e4) + pow(2, b.f5);

    try {
        // Swap colors
        b.setCounts();
        // Validate appropriate swap
        assert(b.whiteCount == 4);
        assert(b.blackCount == 4);

        // Change counts and recheck
        b.white += pow(2, b.b3) + pow(2, b.d5);
        b.black += pow(2, b.c3);
        b.setCounts();
        assert(b.whiteCount == 6);
        assert(b.blackCount == 5);
        
    } catch (const exception e) {
        cout << "Exception raised in testSetCounts:\t" << e.what() << endl;
        return false;
    }
    return true;
}

bool testWriteBoard() {
    // Tests writeBoard function
    // Note that the updateBoard function does not update turn
    // The check for matching whiteTurn is moot, but proves the value 
    // is printed to .txt file.
    
    bool success = true;

    // Setup Board
    Board b1;
    for (int i = 0; i < 23; i++) {
        b1.updateBoard(i, pow(-1, i));
    }
    
    // Test phase begin
    try {
        // Write board
        b1.writeBoard("test_write123456789.txt");

        // Test board can write with "test" as argument without writing
        for (int i = 0; i < 20; i++)
            assert(b1.writeBoard("test") == 1);

        // Initialize in stream and start reading board
        ifstream i;
        i.open("test_write123456789.txt");
        
        // Initialize string to hold file contents
        string content;
        // Load line 1 to string
        getline(i, content);
        
        int offset = 0;
        for (int i = 0; i < 23; i++) {
            if (pow(-1, i) == -1)
                offset += 1;
            assert (content[i + offset] == '1');
        }

        // Check turn
        getline(i, content);
        assert (atoi(content.c_str()) == 1);

        // Check gamePhase
        getline(i, content);
        assert (atoi(content.c_str()) == 1);
        
    } catch (const exception e) { // Fail block
        cout << "Exception raised in testWriteBoard:\t" << e.what() << endl;
        success = false;
    }
    
    // Clean file
    try {remove("test_write123456789.txt");}
    catch (const exception e) {
        success = false;
    }

    return success;
}

bool testReadBoard() {
    // Validate performance of Board::readBoard() function

    // Setup
    bool success = true;
    ofstream o;
    o.open("test_read123456789.txt");
    ofstream o2;
    o2.open("test_read123456789_2.txt");
    o2 << "101-10-100000000000000000\n1\n0";

    // Populate board with pattern of WB-
    for (int i = 0; i < 23; i++) {
        if (i % 3 == 0)
            o << '1';
        else if (i % 3 == 1)
            o << "-1";
        else
            o << '0';
    }
    o << "\n0\n1" << endl;
    // Close file to allow resources
    o.close();
    o2.close();

    // Start assertions
    try {
        // Run function
        Board b("test_read123456789.txt");
        for (int i = 0; i < 23; i++) {
            if (i % 3 == 0)
                assert (b[i] == 1);
            else if (i % 3 == 1)
                assert (b[i] == -1);
            else
                assert (b[i] == 0);
        }
        assert(b.whiteTurn == 0);
        assert(b.gamePhase == 1);
        Board b2("test_read123456789_2.txt");
        assert(b2[0] == 1);
        assert(b2[1] == 0);
        assert(b2[2] == 1);
        assert(b2[3] == -1);
        assert(b2[4] == 0);
        assert(b2[5] == -1);
        for (int i = 6; i < 23; i++)
            assert(b2[i] == 0);

    } catch (const exception e) { // Fail block
        cout << "Exception raised in testReadBoard:\t" << e.what() << endl;
        success = false;
    }
    
    // Clean file
    try {remove("test_read123456789.txt");remove("test_read123456789_2.txt");}
    catch (const exception e) {
        success = false;
    }

    return success;

}




// bool testStaticEstimate() {
//     // Validate performance of Board::staticEstimate() function
    
//     // // Setup invalid case
//     // Board invalid;
//     // invalid.whiteTurn = false;
//     // try {
//     //     invalid.staticEstimate();
//     //     assert(false); // Should not reach this point
//     // } catch (const exception& e) {
//     //     // Expected exception for invalid game phase
//     //     assert(string(e.what()) == "Board started with black and this should not happen!");
//     // }
    
//     try {
//         // Test Case 1: Opening phase (gamePhase == 0)
//         Board b1;
//         b1.whiteCount = 4;
//         b1.blackCount = 2;
//         b1.gamePhase = 0; // Opening phase
//         assert(b1.staticEstimate() == 2); // Expected heuristic: 4 - 2 = 2

//         Board b1_1;
//         b1_1.whiteCount = 2;
//         b1_1.blackCount = 4;
//         b1_1.gamePhase = 0; // Opening phase
//         assert(b1_1.staticEstimate() == -2); // Expected heuristic: 2 - 4 = -2

//         // Test Case 2: Midgame phase (gamePhase == 1) with black victory condition
//         Board b2;
//         b2.whiteCount = 2; // White has 2 pieces
//         b2.blackCount = 4; // Black has 4 pieces
//         b2.gamePhase = 1; // Midgame phase
//         assert(b2.staticEstimate() == -10000); // Expected heuristic: black wins

//         // Test Case 3: Midgame phase (gamePhase == 1) with white victory condition
//         Board b3;
//         b3.whiteCount = 4; // White has 4 pieces
//         b3.blackCount = 2; // Black has 2 pieces
//         b3.gamePhase = 1; // Midgame phase
//         assert(b3.staticEstimate() == 10000); // Expected heuristic: white wins

//         // Test Case 4: Midgame phase (gamePhase == 1) with no moves for black
//         Board b4;
//         b4.whiteCount = 4;
//         b4.blackCount = 4;
//         b4.gamePhase = 1; // Midgame phase
//         b4.L.clear(); // No moves available
//         assert(b4.staticEstimate() == 10000); // Expected heuristic: black can't move, white wins

//         // Test Case 5: Midgame phase (gamePhase > 0) with no moves for white
//         Board b5;
//         b5.whiteCount = 4;
//         b5.blackCount = 4;
//         b5.gamePhase = 1; // Midgame phase
//         b5.L.clear(); // No moves available
//         b5.whiteTurn = 0; // Black's turn
//         assert(b5.staticEstimate() == -10000); // Expected heuristic: white can't move, black wins

//         // Test Case 6: Midgame phase (gamePhase > 0) with in-progress game
//         Board b6;
//         b6.whiteCount = 5;
//         b6.blackCount = 4;
//         b6.gamePhase = 1; // Midgame phase
//         b6.L = b6.generateNextLevel(b6); // Generate moves
//         int expectedHeuristic = 1000 * (5 - 4) - b6.L.size(); // Heuristic formula
//         assert(b6.staticEstimate() == expectedHeuristic);

//         cout << "All test cases for staticEstimate passed!" << endl;
//         return true;
//     } catch (...) {
//         cout << "A test case for staticEstimate failed!" << endl;
//         return false;
//     }
// }

// bool testMinMax() {
    // Under construction

//     // Test case for minMax function
//     try {
//         // Test 1: White's turn, even depth
//         Board b1;
//         b1.white = (1 << 0) + (1 << 1); // White pieces at positions 0 and 1
//         b1.black = (1 << 2) + (1 << 3);           // Black piece at position 2
//         b1.whiteCount = 2;
//         b1.blackCount = 2;
//         b1.whiteTurn = 1; // White's turn
//         b1.gamePhase = 1; // Midgame phase

//         int leaf_count = 0;
//         int heuristic = b1.minMax(b1, 0, 1, leaf_count);
//         cout << "heuristic: " << heuristic << endl;

//         // Expected heuristic: white has more pieces, so heuristic = 1000 * (2 - 1) = 1000
//         assert(heuristic == 0);
//         assert(leaf_count > 1); // Ensure leaf nodes were evaluated

//         // Test 2: Black's turn, odd depth
//         // Board b2;
//         // b2.white = (1 << 0);           // White piece at position 0
//         // b2.black = (1 << 1) + (1 << 2); // Black pieces at positions 1 and 2
//         // b2.whiteCount = 1;
//         // b2.blackCount = 2;
//         // b2.whiteTurn = 0; // Black's turn
//         // b2.gamePhase = 1; // Midgame phase

//         // leaf_count = 0;
//         // heuristic = b2.minMax(b2, 0, 3, leaf_count);

//         // // Expected heuristic: black has more pieces, so heuristic = 1000 * (1 - 2) = -1000
//         // assert(heuristic == -1000);
//         // assert(leaf_count > 0); // Ensure leaf nodes were evaluated

//         return true;
//     } catch (...) {
//         cout << "testMinMax failed" << endl;
//         return false;
//     }
// }


int main() {
    // Initialize boolean for tracking test failures
    bool all_pass = true;

    // Run test for default Board constructor
    if (!testBoardConstructor()) {
        all_pass = false;
        cout << "testBoardConstructor failed" << endl;
    }
    if (!testBoardCopyConstructor()) {
        all_pass = false;
        cout << "testBoardCopyConstructor failed" << endl;
    }

    if (!testCloseMill()) {
        all_pass = false;
        cout << "testCloseMill failed" << endl;
    }

    if (!testNeighbors()) {
        all_pass = false;
        cout << "testNeighbors failed" << endl;
    }

    if (!testGenerateRemove()) {
        all_pass = false;
        cout << "testGenerateRemove failed" << endl;
    }

    if (!testGenerateHopping()) {
        all_pass = false;
        cout << "testGenerateHopping failed" << endl;
    }
    
    if (!testGenerateAdd()) {
        all_pass = false;
        cout << "testGenerateAdd failed" << endl;
    }

    if (!testGenerateMove()) {
        all_pass = false;
        cout << "testGenerateMove failed" << endl;
    }

    if (!testSwapColors()) {
        all_pass = false;
        cout << "testSwapColors failed" << endl;
    }

    if (!testSetCounts()) {
        all_pass = false;
        cout << "testSetCounts failed" << endl;
    }
    
    if (!testWriteBoard()) {
        all_pass = false;
        cout << "testWriteBoard failed" << endl;
    }

    if (!testReadBoard()) {
        all_pass = false;
        cout << "testReadBoard failed" << endl;
    }

    // if (!testStaticEstimate()) {
    //     all_pass = false;
    //     cout << "testMinMax failed" << endl;
    // }

    // if (!testMinMax()) {
    //     all_pass = false;
    //     cout << "testMinMax failed" << endl;
    // }

    if (all_pass)
        cout << "All tests have passed!" << endl;
    else
        cout << "Tests have failed!" << endl;
    return 0;
}