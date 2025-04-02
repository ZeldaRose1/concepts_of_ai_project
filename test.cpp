#include <iostream>
#include <fstream> // Needed for io testing
#include <cassert>
#include <stdio.h> // For deleting files
#include <math.h>
#include "Game.h"
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

bool testGameConstructor() {
    // Tests if the default constructor for Game functions
    Game g;
    Board b = g.getBoard();
    try {
        assert(b.white == 0);
        assert(b.black == 0);
        assert(b.whiteCount == 0);
        assert(b.blackCount == 0);
    } catch (const exception e) {
        cout << "Exception raised in testGameConstructor:\t" << e.what() << endl;
        return false;
    }
    return true;
}

bool testGameConstructorBoard() {
    // Tests if the default constructor for Game functions
    Board b;
    b.updateBoard(b.a0, 1);
    b.updateBoard(b.d0, 1);
    b.updateBoard(b.g0, 1);

    b.updateBoard(b.a6, -1);
    b.updateBoard(b.d6, -1);
    b.updateBoard(b.g6, -1);
    
    Game g(b);
    try {
        assert(g.getBoard().white == 7);
        assert(g.getBoard().black == 7340032);
    } catch (const exception e) {
        cout << "Exception raised in testGameConstructorBoard:\t" << e.what() << endl;
        return false;
    }
    
    return true;
}


bool testCloseMill() {
    // Test function for Game::closeMill()
    Game g;
    Board b;

    // Test for false on all empty spaces
    for (int i = 0; i < 23; i++)
        assert (!g.closeMill(i, b));
    
    // Form mill on bottom row
    b.updateBoard(b.a0, 1);
    b.updateBoard(b.d0, 1);
    b.updateBoard(b.g0, 1);

    try {
        // Test the first row (all mills)
        assert (g.closeMill(b.a0, b));
        assert (g.closeMill(b.d0, b));
        assert (g.closeMill(b.g0, b));

        // Test all spaces that are not mills
        for (int i = 4; i < 23; i++)
            assert (!g.closeMill(i, b));

        // Un-mill the bottom row and retest. (Checks against non-homogenous row)
        b.updateBoard(b.d0,  -1);

        // Check mil has been undone
        assert (!g.closeMill(b.a0, b));
        assert (!g.closeMill(b.d0, b));
        assert (!g.closeMill(b.g0, b));

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
                assert (g.closeMill(i, b)); // Check real mils return true
            else
                assert (!g.closeMill(i, b));  // Check non-mils return false
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
                assert (g.closeMill(i, b)); // Check real mils return true
            else
                assert (!g.closeMill(i, b)); // Check non-mils return false
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
                assert (g.closeMill(i, b)); // Check real mils return true
            else
                assert (!g.closeMill(i, b)); // Check non-mils return false
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
                assert (g.closeMill(i, b)); // Check real mils return true
            else
                assert (!g.closeMill(i, b)); // Check non-mils return false
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
                assert (g.closeMill(i, b)); // Check real mils return true
            else
                assert (!g.closeMill(i, b)); // Check non-mils return false
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
                assert (g.closeMill(i, b)); // Check real mils return true
            else
                assert (!g.closeMill(i, b)); // Check non-mils return false
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
                assert (g.closeMill(i, b)); // Check real mils return true
            else
                assert (!g.closeMill(i, b)); // Check non-mils return false
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
                assert (g.closeMill(i, b)); // Check real mils return true
            else
                assert (!g.closeMill(i, b)); // Check non-mils return false
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
                assert (g.closeMill(i, b)); // Check real mils return true
            else
                assert (!g.closeMill(i, b)); // Check non-mils return false
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
                assert (g.closeMill(i, b)); // Check real mils return true
            else
                assert (!g.closeMill(i, b)); // Check non-mils return false
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
                assert (g.closeMill(i, b)); // Check real mils return true
            else
                assert (!g.closeMill(i, b)); // Check non-mils return false
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
                assert (g.closeMill(i, b)); // Check real mils return true
            else
                assert (!g.closeMill(i, b)); // Check non-mils return false
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
                assert (g.closeMill(i, b)); // Check real mils return true
            else
                assert (!g.closeMill(i, b)); // Check non-mils return false
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
                assert (g.closeMill(i, b)); // Check real mils return true
            else
                assert (!g.closeMill(i, b)); // Check non-mils return false
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
                assert (g.closeMill(i, b)); // Check real mils return true
            else
                assert (!g.closeMill(i, b)); // Check non-mils return false
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
                assert (g.closeMill(i, b)); // Check real mils return true
            else
                assert (!g.closeMill(i, b)); // Check non-mils return false
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
                assert (g.closeMill(i, b)); // Check real mils return true
            else
                assert (!g.closeMill(i, b)); // Check non-mils return false
        }
        
        // Force all spaces to be white
        for (int i = 0; i < 23; i++)
            b.updateBoard(i, 1);
        // Run tests
        for (int i = 0; i < 23; i++)
            assert (g.closeMill(i, b));
        
        // Force all spaces to be black
        for (int i = 0; i < 23; i++)
            b.updateBoard(i, -1);
        // Run tests
        for (int i = 0; i < 23; i++)
            assert (g.closeMill(i, b));

        // Reset board
        for (int i = 0; i < 23; i++) b.updateBoard(i, 0);
        // Form mill
        b.updateBoard(b.a0, 1);
        b.updateBoard(b.b1, 1);
        b.updateBoard(b.c2, 1);
        for (int i = 0; i < 23; i++) {
            if (i == b.a0 || i == b.b1 || i == b.c2) {
                assert (g.closeMill(i, b));
            } else {
                assert (!g.closeMill(i, b));
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
    Game g;
    Board b1;
    vector<Board> l;

    // Setup three black pieces on the board
    b1.updateBoard(b1.g6, -1);
    b1.updateBoard(b1.a6, -1);
    b1.updateBoard(b1.g0, -1);
    b1.updateBoard(b1.a0, -1);
    g.generateRemove(b1, l);

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
        g.generateRemove(b1, l);

        // Start asserts for mixed case
        assert(l.size() == 2);
        assert(l[0].black == pow(2, 22) + pow(2, 21) + pow(2, 20) + pow(2, 2));
        assert(l[1].black == pow(2, 22) + pow(2, 21) + pow(2, 20) + pow(2, 0));

        /* Validate behavior when only mill exists (case 3) */
        l.clear();
        // Form mill across row 0
        b1.black += pow(2, 1);
        g.generateRemove(b1, l);

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
    /* Validates behavior of Game::generateHopping */
    Game g;
    Board b;
    b.white = 1; // Single tile on a0

    // Start testing block
    try {
        /* Tests all branches of code except for the generateRemove() call */
        // Run code; should have 22 different options in the list
        vector<Board> l = g.generateHopping(b);
        assert(l.size() == 22);

        // Check that the tiles hop in the order we expected
        for (int i = 0; i < 22; i++) {
            assert(l[i][i + 1] == 1);
        }

        /* Test for generateRemove() functionality */
        l.clear();
        // Set board to have only three pieces for white outside of a mill
        b.white = pow(2, b.a6) + pow(2, b.a3) + pow(2, b.g0);
        // Set board to be have one empty space, and the rest be black
        b.black = pow(2, b.g6) + pow(2, b.d6) + pow(2, b.f5) + pow(2, b.d5) + pow(2, b.b5) + pow(2, b.e4) + 
            pow(2, b.d4) + pow(2, b.c4) + pow(2, b.g3) + pow(2, b.f3) + pow(2, b.e3) + pow(2, b.c3) + pow(2, b.b3) + 
            pow(2, b.e2) + pow(2, b.c2) + pow(2, b.f1) + pow(2, b.d1) + pow(2, b.b1) + pow(2, b.d0);
        // Note the empty space is a0
        l = g.generateHopping(b);
        /*
            Generate Hopping should start by moving g0 to a0 and then remove each black piece
            that is not part of a mill. Since we cannot remove a piece if there are non-milled
            pieces, this will reduce the number of entries in the list.

            d0 is the only black piece that isn't in a mill. So we only append one option to the
            list for the first tile

            The other two options will only move white's a3 and a6 to a0 and leave black alone.
            We can test these simple cases directly
        */
        // Verify correct number of moves
        assert(l.size() == 3);
        // Check the first moves output where we remove a piece from black.
        assert(l[0].white == pow(2, b.a6) + pow(2, b.a3) + pow(2, b.a0));
        assert(l[0].black == pow(2, b.g6) + pow(2, b.d6) + pow(2, b.f5) + pow(2, b.d5) + pow(2, b.b5) + pow(2, b.e4) + 
            pow(2, b.d4) + pow(2, b.c4) + pow(2, b.g3) + pow(2, b.f3) + pow(2, b.e3) + pow(2, b.c3) + pow(2, b.b3) + 
            pow(2, b.e2) + pow(2, b.c2) + pow(2, b.f1) + pow(2, b.d1) + pow(2, b.b1));
        // Check the second move. No black pieces removed
        assert(l[1].white == pow(2, b.a6) + pow(2, b.a0) + pow(2, b.g0));
        assert(l[1].black == pow(2, b.g6) + pow(2, b.d6) + pow(2, b.f5) + pow(2, b.d5) + pow(2, b.b5) + pow(2, b.e4) + 
            pow(2, b.d4) + pow(2, b.c4) + pow(2, b.g3) + pow(2, b.f3) + pow(2, b.e3) + pow(2, b.c3) + pow(2, b.b3) + 
            pow(2, b.e2) + pow(2, b.c2) + pow(2, b.f1) + pow(2, b.d1) + pow(2, b.b1) + pow(2, b.d0));
        // Check the third move. No black pieces removed
        assert(l[2].white == pow(2, b.a0) + pow(2, b.a3) + pow(2, b.g0));
        assert(l[2].black == pow(2, b.g6) + pow(2, b.d6) + pow(2, b.f5) + pow(2, b.d5) + pow(2, b.b5) + pow(2, b.e4) + 
            pow(2, b.d4) + pow(2, b.c4) + pow(2, b.g3) + pow(2, b.f3) + pow(2, b.e3) + pow(2, b.c3) + pow(2, b.b3) + 
            pow(2, b.e2) + pow(2, b.c2) + pow(2, b.f1) + pow(2, b.d1) + pow(2, b.b1) + pow(2, b.d0));
    } catch (const exception e) {
        cout << "Exception raised in testGenerateHopping:\t" << e.what() << endl;
        return false;
    }

    return true;
}

bool testGenerateAdd() {
    /* Validate performance of generate add */
    // Initialize variables
    Game g;
    Board b;
    vector<Board> l;

    // Start tests
    try {
        /*
            Test setup has two white pieces in row 0 and one black piece.
            The first move generated will run the generateRemove function
            The rest will be simple adds. This should cover all branches
            of the generateAdd() function.

            generateRemove() will only add one element to the list so we
            The rest of the code will generate moves for the other 20
            open spaces for a total of 21 boards in the list.
        */
        l.clear();
        b.white = pow(2, b.a0) + pow(2, b.d0);
        b.black = pow(2, b.a3);
        l = g.generateAdd(b);
        assert(l.size() == 20);
    } catch (const exception e) {
        cout << "Exception raised in testGenerateAdd:\t" << e.what() << endl;
        return false;
    }
    
    return true;
}

bool testGenerateMove() {
    /* Validates performance of midgame Game::generateMove() function */
    // Initialize variables
    Game g;
    Board b;
    vector<Board> l;
    
    // Start testing
    try{
        /*
            Setting up a board to test for all posibilities of the code
            White has a0, d0, and g3 while black has a3.
            
            This means that a0 will have one move,
            d0 will have two moves,
            and g3 will have 3 moves, one of which will be a mill
            and remove black's a3 tile.

            In total we can expect 6 outcomes from this test.
        */
        b.white = pow(2, b.a0) + pow(2, b.d0) + pow(2, b.g3);
        b.black = pow(2, b.a3);
        l = g.generateMove(b);
        // Begin checks
        assert(l.size() == 6);
        
        // Check first entry
        assert(l[0].white == pow(2, b.b1) + pow(2, b.d0) + pow(2, b.g3));
        assert(l[0].black == pow(2, b.a3));
        // Check second entry
        assert(l[1].white == pow(2, b.a0) + pow(2, b.g0) + pow(2, b.g3));
        assert(l[1].black == pow(2, b.a3));
        // Check third entry
        assert(l[2].white == pow(2, b.a0) + pow(2, b.d1) + pow(2, b.g3));
        assert(l[2].black == pow(2, b.a3));
        // Check fourth entry
        assert(l[3].white == pow(2, b.a0) + pow(2, b.d0) + pow(2, b.g0));
        assert(l[3].black == 0);
        // Check fifth entry
        assert(l[4].white == pow(2, b.a0) + pow(2, b.d0) + pow(2, b.f3));
        assert(l[4].black == pow(2, b.a3));
        // Check sixth and final entry
        assert(l[5].white == pow(2, b.a0) + pow(2, b.d0) + pow(2, b.g6));
        assert(l[5].black == pow(2, b.a3));

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
        assert (atoi(content.c_str()) == 0);

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

    // Populate board with pattern of WB-
    for (int i = 0; i < 23; i++) {
        if (i % 3 == 0)
            o << '1';
        else if (i % 3 == 1)
            o << '-' << '1';
        else
            o << '0';
    }
    o << "\n0\n1" << endl;
    // Close file to allow resources
    o.close();

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
    } catch (const exception e) { // Fail block
        cout << "Exception raised in testReadBoard:\t" << e.what() << endl;
        success = false;
    }
    
    // Clean file
    try {remove("test_read123456789.txt");}
    catch (const exception e) {
        success = false;
    }

    return success;

}


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
    if (!testGameConstructor()) {
        all_pass = false;
        cout << "testGameConstructor failed" << endl;
    }
    if (!testGameConstructorBoard()) {
        all_pass = false;
        cout << "testGameConstructorBoard failed" << endl;
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

    if (all_pass)
        cout << "All tests have passed!" << endl;
    else
        cout << "Tests have failed!" << endl;
    return 0;
}