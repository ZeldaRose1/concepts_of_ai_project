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


bool testUpdateBoard() {
    // Tests the updateBoard function
    Board b;
    try {
        // Test 1.1: gamePhase==0 blank to white
        b.updateBoard(b.a0, 1);
        assert(b.white == pow(2, b.a0));
        assert(b.black == 0);
        assert(b.whiteCount == 1);
        assert(b.blackCount == 0);
        assert(b.gamePhase == 0);

        // Test 1.2: gamePhase==0 blank to black
        b.updateBoard(b.d0, -1);
        assert(b.black == pow(2, b.d0));
        assert(b.white == pow(2, b.a0));
        assert(b.whiteCount == 1);
        assert(b.blackCount == 1);
        assert(b.gamePhase == 0);

        // Test 1.3: gamePhase==0 white to blank
        b.updateBoard(b.a0, 0);
        assert(b.white == 0);
        assert(b.black == pow(2, b.d0));
        assert(b.whiteCount == 0);
        assert(b.blackCount == 1);
        assert(b.gamePhase == 0);
        
        // Test 1.4: gamePhase==0 black to blank
        b.updateBoard(b.d0, 0);
        assert(b.white == 0);
        assert(b.black == 0);
        assert(b.whiteCount == 0);
        assert(b.blackCount == 0);
        assert(b.gamePhase == 0);

        // Test 1.5: gamePhase==0 white to black
        b.white = pow(2, b.a0);
        b.black = pow(2, b.d0);
        b.whiteCount = 1;
        b.blackCount = 1;
        b.updateBoard(b.a0, -1);
        assert(b.white == 0);
        assert(b.black == pow(2, b.d0) + pow(2, b.a0));
        assert(b.whiteCount == 0);
        assert(b.blackCount == 2);
        assert(b.gamePhase == 0);
        
        // Test 1.6: gamePhase==0 black to white
        b.updateBoard(b.d0, 1);
        assert(b.white == pow(2, b.d0));
        assert(b.black == pow(2, b.a0));
        assert(b.whiteCount == 1);
        assert(b.blackCount == 1);
        assert(b.gamePhase == 0);

        // Test 2.1: gamePhase moves to phase 1; blank to white
        Board b2;
        b2.whiteCount = 6;
        b2.blackCount = 6;
        b2.gamePhase = 0;
        b2.updateBoard(b.a0, 1); // Should swap phase 0 - 1
        // assert(b2.gamePhase == 1);
        assert(b2.whiteCount == 7);
        assert(b2.blackCount == 6);

        // Test 2.2: gamePhase moves to phase 1; blank to black
        b2.whiteCount = 6;
        b2.blackCount = 6;
        b2.gamePhase = 0;
        b2.updateBoard(b.a0, -1); // Should swap phase 0 - 1
        // assert(b2.gamePhase == 1);

        // Test 2.3: gamePhase moves to phase 1; white to blank
        b2.white = pow(2, b2.a3);
        b2.whiteCount = 6;
        b2.blackCount = 6;
        b2.gamePhase = 0;
        b2.updateBoard(b2.a3, 0); // Should swap phase 0 - 1
        // assert(b2.gamePhase == 1);
        assert(b2.white == 0);

        // Test 2.4: gamePhase moves to phase 1; black to blank
        b2.black = pow(2, b2.a3);
        b2.whiteCount = 6;
        b2.blackCount = 6;
        b2.gamePhase = 0;
        b2.updateBoard(b2.a3, 0); // Should swap phase 0 - 1
        // assert(b2.gamePhase == 1);
        assert(b2.black == 0);

        // Test 2.5: gamePhase moves to phase 1; white to black
        b2.white = pow(2, b2.a3);
        b2.black = 0;
        b2.whiteCount = 6;
        b2.blackCount = 6;
        b2.gamePhase = 0;
        b2.updateBoard(b2.a3, -1); // Should swap phase 0 - 1
        // assert(b2.gamePhase == 1);
        assert(b2.white == 0);
        assert(b2.black == pow(2, b2.a3));

        // Test 2.6: gamePhase moves to phase 1; black to white
        b2.white = 0;
        b2.black = pow(2, b2.a3);
        b2.whiteCount = 6;
        b2.blackCount = 6;
        b2.gamePhase = 0;
        b2.updateBoard(b2.a3, 1); // Should swap phase 0 - 1
        // assert(b2.gamePhase == 1);
        assert(b2.black == 0);
        assert(b2.white == pow(2, b2.a3));

        // Test 3.1: gamePhase moves to phase 2; white to blank
        Board b3;
        b3.white = pow(2, b3.a0);
        b3.whiteCount = 4;
        b3.blackCount = 6;
        b3.gamePhase = 1;
        b3.updateBoard(b3.a0, 0); // Should swap phase 1 - 2
        // assert(b3.gamePhase == 2);
        assert(b3.white == 0);
        assert(b3.whiteCount == 3);
        assert(b3.blackCount == 6);

        // Test 3.2: gamePhase moves to phase 2; black to blank
        b3.white = 0;
        b3.black = pow(2, b3.a0);
        b3.whiteCount = 6;
        b3.blackCount = 4;
        b3.gamePhase = 1;
        b3.updateBoard(b3.a0, 0); // Should swap phase 1 - 2
        // assert(b3.gamePhase == 2);
        assert(b3.black == 0);
        assert(b3.blackCount == 3);
        assert(b3.whiteCount == 6);

        // Test 3.3: gamePhase moves to phase 2; white to black
        b3.white = pow(2, b3.a0);
        b3.black = 0;
        b3.whiteCount = 4;
        b3.blackCount = 6;
        b3.gamePhase = 1;
        b3.updateBoard(b3.a0, -1); // Should swap phase 1 - 2
        // assert(b3.gamePhase == 2);
        assert(b3.white == 0);
        assert(b3.black == pow(2, b3.a0));
        assert(b3.blackCount == 7);
        assert(b3.whiteCount == 3);

        // Test 3.4: gamePhase moves to phase 2; black to white
        b3.white = 0;
        b3.black = pow(2, b3.a0);
        b3.whiteCount = 6;
        b3.blackCount = 4;
        b3.gamePhase = 1;
        b3.updateBoard(b3.a0, 1); // Should swap phase 1 - 2
        // assert(b3.gamePhase == 2);
        assert(b3.black == 0);
        assert(b3.white == pow(2, b3.a0));
        assert(b3.whiteCount == 7);
        assert(b3.blackCount == 3);
        

    } catch (const exception e){
        cout << "Exception raised in testUpdateBoard:\t" << e.what() << endl;
        return false;
    }
    return true;
}


bool testGenerateRemove() {
    /* 
        Validates behavior of GenerateRemove function.
        Validates:
            - Correct number of solutions
            - Correctness of each solution
            - Correctness of gamePhase, whiteTurn, and depth
    */


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


        // Test gamePhase swapping
            // Game phase 0 to 1
        Board b2;
        b2.updateBoard(b2.a0, 1);
        b2.updateBoard(b2.a3, 1);
        b2.updateBoard(b2.a6, 1);
        b2.updateBoard(b2.g0, -1);
        b2.updateBoard(b2.g3, -1);
        b2.updateBoard(b2.g6, -1);
        b2.gamePhase = 0;
        b2.whiteTurn = true;
        b2.depth = 17;
        l.clear();
        b2.generateRemove(b2, l);
        for (int i = 0; i < l.size(); i++) {
            assert(l[i].gamePhase == 1);
            assert(l[i].whiteTurn == false);
            assert(l[i].depth == 18);
        }

        // Test gamePhase swapping
            // Game phase 1 to 2
        Board b3;
        b3.updateBoard(b3.a0, 1);
        b3.updateBoard(b3.a3, 1);
        b3.updateBoard(b3.a6, 1);
        b3.updateBoard(b3.b1, 1);
        b3.updateBoard(b3.g0, -1);
        b3.updateBoard(b3.g3, -1);
        b3.updateBoard(b3.g6, -1);
        b3.updateBoard(b3.f5, -1);
        b3.gamePhase = 1;
        b3.whiteTurn = true;
        b3.depth = 20;
        l.clear();
        b3.generateRemove(b3, l);
        for (int i = 0; i < l.size(); i++) {
            assert(l[i].gamePhase == 2);
            assert(l[i].whiteTurn == false);
            assert(l[i].depth == 21);
        }

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
        b.depth = 30;
        l = b.generateHopping(b);
        
        // Should generate (23-3)*3 = 60 possible hops (each white piece can go to any empty spot)
        assert(l.size() == 51);
        
        // Verify all moves hopped from a0
        for (int i = 0; i < 17; i++) {
            assert(l[i].white == pow(2, i + 3) + pow(2, b.d0) + pow(2, b.g0));
            assert(l[i].black == pow(2, b.a6) + pow(2, b.d6) + pow(2, b.g6));
            assert(l[i].whiteTurn == false);  // Turn should flip
            assert(l[i].depth == 31);
        } // Verify all moves hopped from d0
        for (int i = 0; i < 17; i++) {
            assert(l[i + 17].white == pow(2, b.a0) + pow(2, i + 3) + pow(2, b.g0));
            assert(l[i + 17].black == pow(2, b.a6) + pow(2, b.d6) + pow(2, b.g6));
            assert(l[i + 17].whiteTurn == false);  // Turn should flip
            assert(l[i + 17].depth == 31);
        } // Verify all moves hopped from g0
        for (int i = 0; i < 17; i++) {
            assert(l[i + 34].white == pow(2, b.a0) + pow(2, b.d0) + pow(2, i + 3));
            assert(l[i + 34].black == pow(2, b.a6) + pow(2, b.d6) + pow(2, b.g6));
            assert(l[i + 34].whiteTurn == false);  // Turn should flip
            assert(l[i + 34].depth == 31);
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


        
        // // Test 3: Black's turn, no mill formation
        // l.clear();
        // // Moving white tile from a0 to b5 for ease of indexing
        // b.updateBoard(b.a0, 0);
        // b.updateBoard(b.b5, 1);
        // b.whiteTurn = false;
        // l = b.generateHopping(b);

        // assert(l.size() == 51);
        // // Verify all moves hopped from a0
        // for (int i = 0; i < 17; i++) {
        //     assert(l[i].white == pow(2, b.b5) + pow(2, b.d5) + pow(2, b.f5));
        //     assert(l[i].black == pow(2, i) + pow(2, b.d6) + pow(2, b.g6));
        //     assert(l[i].whiteTurn == true);  // Turn should flip
        // } // Verify all moves hopped from d0
        // for (int i = 0; i < 17; i++) {
        //     assert(l[i + 17].white == pow(2, b.b5) + pow(2, b.d5) + pow(2, b.f5));
        //     assert(l[i + 17].black == pow(2, b.a6) + pow(2, i) + pow(2, b.g6));
        //     assert(l[i + 17].whiteTurn == true);  // Turn should flip
        // } // Verify all moves hopped from g0
        // for (int i = 0; i < 17; i++) {
        //     assert(l[i + 34].white == pow(2, b.b5) + pow(2, b.d5) + pow(2, b.f5));
        //     assert(l[i + 34].black == pow(2, b.a6) + pow(2, b.d6) + pow(2, i));
        //     assert(l[i + 34].whiteTurn == true);  // Turn should flip
        // }
        
        // // Test 4: Black's turn with mill formation
        // l.clear();
        // // Moving black tile from a6 to a0 to force only one mill
        // b.updateBoard(b.a6, 0);
        // b.updateBoard(b.a0, -1);
        // b.whiteTurn = false;
        // l = b.generateHopping(b);

        // assert(l.size() == 53);

        // for (int i = 0; i < 16; i++) {
        //     assert(l[i].white == pow(2, b.b5) + pow(2, b.d5) + pow(2, b.f5));
        //     assert(l[i].black == pow(2, i + 1) + pow(2, b.d6) + pow(2, b.g6));
        //     assert(l[i].whiteTurn == true);  // Turn should flip
        // }
        
        // // Verify the removed pieces
        // assert(l[16].white == pow(2, b.d5) + pow(2, b.f5));
        // assert(l[16].black == pow(2, b.a6) + pow(2, b.d6) + pow(2, b.g6));
        // assert(l[16].whiteTurn == true);
        // assert(l[17].white == pow(2, b.b5) + pow(2, b.f5));
        // assert(l[17].black == pow(2, b.a6) + pow(2, b.d6) + pow(2, b.g6));
        // assert(l[17].whiteTurn == true);  // Turn should flip
        // assert(l[18].white == pow(2, b.b5) + pow(2, b.d5));
        // assert(l[18].black == pow(2, b.a6) + pow(2, b.d6) + pow(2, b.g6));
        // assert(l[18].whiteTurn == true);  // Turn should flip

        // // Verify hopping d6
        // for (int i = 0; i < 16; i++) {
        //     assert(l[i + 19].white == pow(2, b.b5) + pow(2, b.d5) + pow(2, b.f5));
        //     assert(l[i + 19].black == pow(2, b.a0) + pow(2, i + 1) + pow(2, b.g6));
        //     assert(l[i + 19].whiteTurn == true);  // Turn should flip
        // }

        // // Last hop of d6 to a6
        // assert(l[35].white == pow(2, b.b5) + pow(2, b.d5) + pow(2, b.f5));
        // assert(l[35].black == pow(2, b.a0) + pow(2, b.a6) + pow(2, b.g6));
        // assert(l[35].whiteTurn == true);  // Turn should flip

        // // Verify hopping g6
        // for (int i = 0; i < 16; i++) {
        //     assert(l[i + 36].white == pow(2, b.b5) + pow(2, b.d5) + pow(2, b.f5));
        //     assert(l[i + 36].black == pow(2, b.a0) + pow(2, b.d6) + pow(2, i + 1));
        //     assert(l[i + 36].whiteTurn == true);  // Turn should flip
        // }

        // // Final hop of g6 to a6
        // assert(l[52].white == pow(2, b.b5) + pow(2, b.d5) + pow(2, b.f5));
        // assert(l[52].black == pow(2, b.a0) + pow(2, b.d6) + pow(2, b.a6));
        // assert(l[52].whiteTurn == true);  // Turn should flip
        
    } catch (const exception& e) {
        cout << "Exception raised in testGenerateHopping:\t" << e.what() << endl;
        return false;
    }
    
    return true;
}


bool testGenerateAdd() {
    /*
        Validate performance of generate add
        Validates:
            - Correct number of solutions
            - Correctness of each solution
            - Correctness of gamePhase, whiteTurn, and depth
            - Correctness of white and black pieces
    */
    Board b;
    vector<Board> l;

    // Start tests
    try {
        // Test 1: White's turn, no mil
            // Nested test; validate gamePhase at depth 0 and depth increment is correct
        l.clear();
        b.white = 0;
        b.black = 0;
        b.depth = 0;
        b.whiteTurn = true;
        l = b.generateAdd(b);
        assert(l.size() == 23);
        for (int i = 0; i < 23; i++){
            assert(l[i].white == pow(2, i));
            assert(l[i].black == 0);
            assert(l[i].whiteTurn == false);
            assert(l[i].gamePhase == 0);
            assert(l[i].depth == 1);
        }

        // Test 2: White's turn, with option for mill
        l.clear();
        b.white = pow(2, b.a0) + pow(2, b.d0); // Move to g0 will provide mill for white
        b.black = pow(2, b.b1);
        b.whiteTurn = true;
        b.depth = 17;
        l = b.generateAdd(b);
        
        // Should generate 20 adds, one of which will be a mil.
        // The mil will remove one piece, but will not generate multiple options.
        assert(l.size() == 20);
        // Check the first entry (the mill)
        assert(l[0].white == pow(2, b.g0) + pow(2, b.d0) + pow(2, b.a0));
        assert(l[0].black == 0);
        assert(l[0].whiteTurn == false);
        assert(l[0].gamePhase == 1);
        assert(l[0].depth == 18);
        
        // Check remaining entries
        for (int i = 1; i < 20; i++) {
            assert(l[i].white == pow(2, b.a0) + pow(2, b.d0) + pow(2, i + 3));
            assert(l[i].black == pow(2, b.b1));
            assert(l[i].whiteTurn == false);
            assert(l[i].gamePhase == 1);
            assert(l[i].depth == 18);
        }
        
        // // Test 3: black turn no mill
        // l.clear();
        // b.white = pow(2, 0);
        // b.black = 0;
        // b.whiteTurn = false;
        // l = b.generateAdd(b);
        // assert(l.size() == 22);
        // for (int i = 0; i < 22; i++){
        //     assert(l[i].white == 1);
        //     assert(l[i].black == pow(2, i + 1));
        //     assert(l[i].whiteTurn == true);
        // }

        // // Test 4: Black turn with mil
        // l.clear();
        // b.white = pow(2, b.g6) + pow(2, b.d6) + pow(2, b.a6);
        // b.black = pow(2, b.a0) + pow(2, b.d0); // Black's move to g0 will form a mill
        // b.whiteTurn = false;
        // l = b.generateAdd(b);
        
        // // Should generate 18 additions since 5 / 23 are filled
        // // 1 of the moves will be a mill and generate three removals
        // // This should total 20 moves if I'm thinking correctly
        // // The mil will remove one piece, but will not generate multiple options.
        // assert(l.size() == 20);
        
        // // Check removals (from single mill)
        // for (int i = 0; i < 3; i++) {
        //     assert(l[i].white == pow(2, b.g6) + pow(2, b.d6) + pow(2, b.a6) - pow(2, 22 - (2 - i)));
        //     assert(l[i].black == pow(2, b.g0) + pow(2, b.d0) + pow(2, b.a0));
        //     assert(l[i].whiteTurn == true);
        // }
        // // Check non-mill entries
        // for (int i = 3; i < 20; i++) {
        //     assert(l[i].white == pow(2, b.a6) + pow(2, b.d6) + pow(2, b.g6));
        //     assert(l[i].black == pow(2, b.a0) + pow(2, b.d0) + pow(2, i));
        //     assert(l[i].whiteTurn == true);
        // }

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

        // // Test 3: Black No mils
        // // b.updateBoard(b.d6, 0);
        // l.clear();
        // b.whiteTurn = false;
        // l = b.generateMove(b);

        // assert(l.size() == 7);
        
        // // Move b1 - c2
        // assert(l[0].white == pow(2, b.a0) + pow(2, b.d1) + pow(2, b.g0));
        // assert(l[0].black == pow(2, b.c2) + pow(2, b.d6) + pow(2, b.f1));
        // assert(l[0].whiteTurn == true);
        
        // // Move b1 - b3
        // assert(l[1].white == pow(2, b.a0) + pow(2, b.d1) + pow(2, b.g0));
        // assert(l[1].black == pow(2, b.b3) + pow(2, b.d6) + pow(2, b.f1));
        // assert(l[1].whiteTurn == true);

        // // Move f1 - e2
        // assert(l[2].white == pow(2, b.a0) + pow(2, b.d1) + pow(2, b.g0));
        // assert(l[2].black == pow(2, b.b1) + pow(2, b.d6) + pow(2, b.e2));
        // assert(l[2].whiteTurn == true);

        // // Move f1 - f3
        // assert(l[3].white == pow(2, b.a0) + pow(2, b.d1) + pow(2, b.g0));
        // assert(l[3].black == pow(2, b.b1) + pow(2, b.d6) + pow(2, b.f3));
        // assert(l[3].whiteTurn == true);

        // // Move d6 - d5
        // assert(l[4].white == pow(2, b.a0) + pow(2, b.d1) + pow(2, b.g0));
        // assert(l[4].black == pow(2, b.b1) + pow(2, b.d5) + pow(2, b.f1));
        // assert(l[4].whiteTurn == true);

        // // Move d6 - a6
        // assert(l[5].white == pow(2, b.a0) + pow(2, b.d1) + pow(2, b.g0));
        // assert(l[5].black == pow(2, b.b1) + pow(2, b.a6) + pow(2, b.f1));
        // assert(l[5].whiteTurn == true);
        // // Move d6 - g6
        // assert(l[6].white == pow(2, b.a0) + pow(2, b.d1) + pow(2, b.g0));
        // assert(l[6].black == pow(2, b.b1) + pow(2, b.g6) + pow(2, b.f1));
        // assert(l[6].whiteTurn == true);

        // // Test 4: Black with mill
        
        // // Move black pieces to prepare for mill in top row.
        // b.updateBoard(b.a6, -1);
        // b.updateBoard(b.g3, -1);
        // b.updateBoard(b.b1, 0);
        // b.updateBoard(b.f1, 0);

        // // Move white pieces to be reduce number of black moves
        // b.updateBoard(b.a0, 0);
        // b.updateBoard(b.d1, 0);
        // b.updateBoard(b.g0, 0);
        // b.updateBoard(b.a3, 1);
        // b.updateBoard(b.d5, 1);
        // b.updateBoard(b.b5, 1);
        // b.depth = 20;
        
        // // Clear board and regenerate moves
        // l.clear();
        // l = b.generateMove(b);

        // // Move g3 - g0
        // assert(l[0].white == pow(2, b.a3) + pow(2, b.b5) + pow(2, b.d5));
        // assert(l[0].black == pow(2, b.a6) + pow(2, b.d6) + pow(2, b.g0));
        // assert(l[0].whiteTurn == true);
        // assert(l[0].depth == 21);

        // // Move g3 - f3
        // assert(l[1].white == pow(2, b.a3) + pow(2, b.b5) + pow(2, b.d5));
        // assert(l[1].black == pow(2, b.a6) + pow(2, b.d6) + pow(2, b.f3));
        // assert(l[1].whiteTurn == true);
        // assert(l[1].depth == 21);

        // // Move g3 - g6; Remove a3
        // assert(l[2].white == pow(2, b.b5) + pow(2, b.d5));
        // assert(l[2].black == pow(2, b.a6) + pow(2, b.d6) + pow(2, b.g6));
        // assert(l[2].whiteTurn == true);
        // assert(l[2].depth == 21);

        // // Move g3 - g6; Remove b5
        // assert(l[3].white == pow(2, b.a3) + pow(2, b.d5));
        // assert(l[3].black == pow(2, b.a6) + pow(2, b.d6) + pow(2, b.g6));
        // assert(l[3].whiteTurn == true);
        // assert(l[3].depth == 21);

        // // Move g3 - g6; Remove d5
        // assert(l[4].white == pow(2, b.a3) + pow(2, b.b5));
        // assert(l[4].black == pow(2, b.a6) + pow(2, b.d6) + pow(2, b.g6));
        // assert(l[4].whiteTurn == true);
        // assert(l[5].depth == 21);

        // // Move d6 - g6
        // assert(l[5].white == pow(2, b.a3) + pow(2, b.b5) + pow(2, b.d5));
        // assert(l[5].black == pow(2, b.a6) + pow(2, b.g6) + pow(2, b.g3));
        // assert(l[5].whiteTurn == true);
        // assert(l[5].depth == 21);

        // Test depth and gamePhase changing
        l.clear();
        b.white = pow(2, b.d0) + pow(2, b.g0) + pow(2, b.b1);
        b.black = pow(2, b.g6) + pow(2, b.d6) + pow(2, b.a6) + pow(2, b.f5);
        b.whiteCount = 4; // Would normally already be gamePhase 2, but we use it here for testing
        b.blackCount = 4;
        b.gamePhase = 1;
        b.whiteTurn = true;
        b.depth = 20;
        l = b.generateMove(b);
        assert(l.size() == 8);
        for (int i = 0; i < 7; i++) {
            if (i != 4){
                assert(l[i].whiteCount == 4);
                assert(l[i].blackCount == 4);
                assert(l[i].gamePhase == 1);
                assert(l[i].depth == 21);
            }
            else {
                assert(l[i].whiteCount == 4);
                assert(l[i].blackCount == 3);
                assert(l[i].gamePhase == 2);
                assert(l[i].depth == 21);
            }
        }

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
    b1.gamePhase = 1; // Leave checking behavior of gamePhase updates to other tests
    
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

        // Check turn
        getline(i, content);
        // assert (atoi(content.c_str()) == 23);
        
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
    ofstream o3;
    o3.open("test_read123456789_3.txt");
    o3 << "xxxWWWBBBxxxxxxxxxxxxxx\n1\n0\n6";

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
    o3.close();

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
        
        // Read Board with letter values
        Board b3("test_read123456789_3.txt");
        for (int i = 0; i < 23; i++) {
            if (i >= 3 && i < 6)
                assert (b3[i] == 1);
            else if (i >= 6 && i < 9)
                assert (b3[i] == -1);
            else
                assert (b3[i] == 0);
        }
        assert(b3.whiteTurn == 1);
        assert(b3.gamePhase == 0);
        assert(b3.depth == 6);

    } catch (const exception e) { // Fail block
        cout << "Exception raised in testReadBoard:\t" << e.what() << endl;
        success = false;
    }
    
    // Clean file
    try {remove("test_read123456789.txt");remove("test_read123456789_2.txt");remove("test_read123456789_3.txt");}
    catch (const exception e) {
        success = false;
    }

    return success;

}


bool testStaticEstimate() {
    // Validate performance of Board::staticEstimate() function
    
    try {
        // Test 1: Game phase 0
        Board b;
        b.updateBoard(b.a0, 1);
        b.updateBoard(b.d0, 1);
        b.updateBoard(b.g0, 1);
        b.updateBoard(b.a6, -1);
        b.updateBoard(b.b1, -1);
        b.whiteTurn = true;
        assert (b.staticEstimate() == 1);
        b.updateBoard(b.g3, -1);
        b.updateBoard(b.f5, -1);
        assert (b.staticEstimate() == -1);

        // Test 2: Game phase 1
        b.white = 0;
        b.whiteCount = 0;
        b.black = 0;
        b.blackCount = 0;
        b.updateBoard(b.a0, 1);
        b.updateBoard(b.d0, 1);
        b.updateBoard(b.g0, 1);
        b.updateBoard(b.b1, 1);
        b.updateBoard(b.a6, -1);
        b.updateBoard(b.d1, -1);
        b.updateBoard(b.g3, -1);
        b.updateBoard(b.c3, -1);
        b.gamePhase = 1;
        b.whiteTurn = true;
        assert (b.staticEstimate() == -9);
        b.whiteTurn = false;
        assert (b.staticEstimate() == 4);

        // Test 3 Final moves
        b.white = 0;
        b.whiteCount = 0;
        b.black = 0;
        b.blackCount = 0;
        b.updateBoard(b.a0, 1);
        b.updateBoard(b.d0, 1);
        b.updateBoard(b.g0, 1);
        b.updateBoard(b.b1, -1);
        b.updateBoard(b.a6, -1);
        b.gamePhase = 2;
        assert (b.staticEstimate() == 10000);
        b.updateBoard(b.g0, -1);
        assert (b.staticEstimate() == -10000);

        // Test 4: No moves remaining
        b.white = 0;
        b.whiteCount = 0;
        b.black = 0;
        b.blackCount = 0;
        b.updateBoard(b.a0, 1);
        b.updateBoard(b.d0, 1);
        b.updateBoard(b.g0, 1);
        b.updateBoard(b.d1, 1);
        b.updateBoard(b.b1, -1);
        b.updateBoard(b.f1, -1);
        b.updateBoard(b.g3, -1);
        b.updateBoard(b.a3, -1);
        b.whiteTurn = true;
        b.gamePhase = 1;
        assert (b.staticEstimate() == -10000);
        b.white = 0;
        b.whiteCount = 0;
        b.black = 0;
        b.blackCount = 0;
        b.updateBoard(b.a0, -1);
        b.updateBoard(b.d0, -1);
        b.updateBoard(b.g0, -1);
        b.updateBoard(b.d1, -1);
        b.updateBoard(b.b1, 1);
        b.updateBoard(b.f1, 1);
        b.updateBoard(b.g3, 1);
        b.updateBoard(b.a3, 1);
        b.whiteTurn = false;
        b.gamePhase = 1;
        assert (b.staticEstimate() == 10000);


        return true;
    } catch (...) {
        cout << "A test case for staticEstimate failed!" << endl;
        return false;
    }
}


bool testStaticEstimateImproved() {
    // Validate performance of Board::staticEstimate() function
    float result, compare = 0;

    try {
        // Test 1: Game phase 0
        Board b;
        b.updateBoard(b.a0, 1);
        b.updateBoard(b.d0, 1);
        b.updateBoard(b.g0, 1);
        b.updateBoard(b.a6, -1);
        b.updateBoard(b.b1, -1);
        b.whiteTurn = true;
        result = (floor(b.staticEstimateImproved() * 100) / 100);
        compare = (floor(((1) + (9 / 5.) - (7 / 5.)) * 100) / 100);
        assert (result == compare);
        b.updateBoard(b.g3, -1);
        b.updateBoard(b.f5, -1);
        result = (floor(b.staticEstimateImproved() * 100) / 100);
        compare = (floor(((-1) + (9 / 5.) - (14 / 5.)) * 100) / 100);
        assert (result == compare);

        // Test 2: Game phase 1
        b.white = 0;
        b.whiteCount = 0;
        b.black = 0;
        b.blackCount = 0;
        b.updateBoard(b.a0, 1);
        b.updateBoard(b.d0, 1);
        b.updateBoard(b.g0, 1);
        b.updateBoard(b.b1, 1);
        b.updateBoard(b.a6, -1);
        b.updateBoard(b.d1, -1);
        b.updateBoard(b.g3, -1);
        b.updateBoard(b.c3, -1);
        b.gamePhase = 1;
        b.whiteTurn = true;
        result = b.staticEstimateImproved();
        compare = (1000 / 5.) - 9;
        assert (round((result - compare) * 10) == 0);
        b.whiteTurn = false;
        result = b.staticEstimateImproved();
        compare = (1000 / 5.) + 4;
        assert (round((result - compare) * 10) == 0);
        

        // Test 3 Final moves
        b.white = 0;
        b.whiteCount = 0;
        b.black = 0;
        b.blackCount = 0;
        b.updateBoard(b.a0, 1);
        b.updateBoard(b.d0, 1);
        b.updateBoard(b.g0, 1);
        b.updateBoard(b.b1, -1);
        b.updateBoard(b.a6, -1);
        b.gamePhase = 2;
        result = b.staticEstimateImproved();
        assert (b.staticEstimateImproved() == 10000);
        b.updateBoard(b.g0, -1);
        result = b.staticEstimateImproved();
        assert (b.staticEstimateImproved() == -10000);

        // Test 4: No moves remaining
        b.white = 0;
        b.whiteCount = 0;
        b.black = 0;
        b.blackCount = 0;
        b.updateBoard(b.a0, 1);
        b.updateBoard(b.d0, 1);
        b.updateBoard(b.g0, 1);
        b.updateBoard(b.d1, 1);
        b.updateBoard(b.b1, -1);
        b.updateBoard(b.f1, -1);
        b.updateBoard(b.g3, -1);
        b.updateBoard(b.a3, -1);
        b.whiteTurn = true;
        b.gamePhase = 1;
        assert (b.staticEstimateImproved() == -10000);
        b.white = 0;
        b.whiteCount = 0;
        b.black = 0;
        b.blackCount = 0;
        b.updateBoard(b.a0, -1);
        b.updateBoard(b.d0, -1);
        b.updateBoard(b.g0, -1);
        b.updateBoard(b.d1, -1);
        b.updateBoard(b.b1, 1);
        b.updateBoard(b.f1, 1);
        b.updateBoard(b.g3, 1);
        b.updateBoard(b.a3, 1);
        b.whiteTurn = false;
        b.gamePhase = 1;
        assert (b.staticEstimateImproved() == 10000);


        return true;
    } catch (...) {
        cout << "A test case for staticEstimate failed!" << endl;
        return false;
    }
}


bool testMinMax() {
    // Test case for minMax function
    try {
        // Test 1.1: gamePhase==0; whiteTurn==true; even number search depth
        Board b1;
        b1.white = 0;
        b1.black = 0;
        b1.whiteCount = 0;
        b1.blackCount = 0;
        b1.whiteTurn = 1; // White's turn
        b1.gamePhase = 0; // Adding Phase
        b1.depth = 0;

        int leaf_count = 0;
        int heuristic = b1.minMax(b1, 0, 2, leaf_count);
        cout << "heuristic: " << heuristic << endl;

        // Expected heuristic: white and black are even, so heuristic = (1 - 1) = 0
        assert(heuristic == 0);
        assert(leaf_count == 506); // Ensure leaf nodes were evaluated
        leaf_count = 0;

        // Test 1.2: gamePhase==0; whiteTurn==true; 0 search depth
        heuristic = b1.minMax(b1, 1, 1, leaf_count);
        assert(heuristic == 0);
        assert(leaf_count == 1);
        leaf_count = 0;
        
        // Test 1.2: gamePhase==0; whiteTurn==true; odd number search depth
        heuristic = b1.minMax(b1, 0, 1, leaf_count);
        cout << "heuristic: " << heuristic << endl;

        // Expected heuristic: white has the only piece on the board so heuristic = 1
        assert(heuristic == 1);
        assert(leaf_count == 23); // Ensure leaf nodes were evaluated
        leaf_count = 0;

        // Test 2.0: base case no depth, midgame
        // Update board for next test
        Board b2;
        b2.white = pow(2, b2.a0) + pow(2, b2.d0) + pow(2, b2.g0) + pow(2, b2.b1); // Fill bottom row with white
        b2.black = pow(2, b2.a6) + pow(2, b2.d6) + pow(2, b2.g6) + pow(2, b2.f5); // Fill top row with white
        b2.whiteCount = 4;
        b2.blackCount = 4;
        b2.whiteTurn = 1;
        b2.depth = 20;
        b2.gamePhase = 1;

        // Pull value from minMax function
        heuristic = b2.minMax(b2, 0, 0, leaf_count);
        assert(heuristic == -7); // Black has seven moves
        assert(leaf_count == 1);
        assert(b2.gamePhase == 1); // Ensure game phase is not changed
        leaf_count = 0;

        // Test 2.1: Midgame, white turn, odd depth
        // This test takes the minimum of the first layer
        b2.L.clear();
        heuristic = b2.minMax(b2, 0, 1, leaf_count);
        assert(heuristic == 6); //
        assert(leaf_count == 7);
        leaf_count = 0;

        // Test 2.2: Midgame, white turn, even depth
        b2.L.clear();
        heuristic = b2.minMax(b2, 0, 2, leaf_count);
        assert(heuristic == -7); //
        assert(leaf_count == 47);
        leaf_count = 0;

        return true;
    } catch (...) {
        cout << "testMinMax failed" << endl;
        return false;
    }
}


// bool testMinMaxImproved() {
//     // TODO: Update test cases for improved heuristic

//     // Test case for minMax function
//     try {
//         // Test 1.1: gamePhase==0; whiteTurn==true; even number search depth
//         Board b1;
//         b1.white = 0;
//         b1.black = 0;
//         b1.whiteCount = 0;
//         b1.blackCount = 0;
//         b1.whiteTurn = 1; // White's turn
//         b1.gamePhase = 0; // Adding Phase
//         b1.depth = 0;

//         int leaf_count = 0;
//         int heuristic = b1.minMax(b1, 0, 2, leaf_count);
//         cout << "heuristic: " << heuristic << endl;

//         // Expected heuristic: white and black are even, so heuristic = (1 - 1) = 0
//         assert(heuristic == 0);
//         assert(leaf_count == 506); // Ensure leaf nodes were evaluated
//         leaf_count = 0;

//         // Test 1.2: gamePhase==0; whiteTurn==true; 0 search depth
//         heuristic = b1.minMax(b1, 1, 1, leaf_count);
//         assert(heuristic == 0);
//         assert(leaf_count == 1);
//         leaf_count = 0;
        
//         // Test 1.2: gamePhase==0; whiteTurn==true; odd number search depth
//         heuristic = b1.minMax(b1, 0, 1, leaf_count);
//         cout << "heuristic: " << heuristic << endl;

//         // Expected heuristic: white has the only piece on the board so heuristic = 1
//         assert(heuristic == 1);
//         assert(leaf_count == 23); // Ensure leaf nodes were evaluated
//         leaf_count = 0;

//         // Test 2.0: base case no depth, midgame
//         // Update board for next test
//         Board b2;
//         b2.white = pow(2, b2.a0) + pow(2, b2.d0) + pow(2, b2.g0) + pow(2, b2.b1); // Fill bottom row with white
//         b2.black = pow(2, b2.a6) + pow(2, b2.d6) + pow(2, b2.g6) + pow(2, b2.f5); // Fill top row with white
//         b2.whiteCount = 4;
//         b2.blackCount = 4;
//         b2.whiteTurn = 1;
//         b2.depth = 20;
//         b2.gamePhase = 1;

//         // Pull value from minMax function
//         heuristic = b2.minMax(b2, 0, 0, leaf_count);
//         assert(heuristic == -7); // Black has seven moves
//         assert(leaf_count == 1);
//         assert(b2.gamePhase == 1); // Ensure game phase is not changed
//         leaf_count = 0;

//         // Test 2.1: Midgame, white turn, odd depth
//         // This test takes the minimum of the first layer
//         b2.L.clear();
//         heuristic = b2.minMax(b2, 0, 1, leaf_count);
//         assert(heuristic == 6); //
//         assert(leaf_count == 7);
//         leaf_count = 0;

//         // Test 2.2: Midgame, white turn, even depth
//         b2.L.clear();
//         heuristic = b2.minMax(b2, 0, 2, leaf_count);
//         assert(heuristic == -7); //
//         assert(leaf_count == 47);
//         leaf_count = 0;

//         return true;
//     } catch (...) {
//         cout << "testMinMax failed" << endl;
//         return false;
//     }
// }


bool testABmM() {
    /*
        Validate performance of Board::ABmM() function
    */
    int alpha = -10005;
    int beta = 10005;

    // Test case for Alpha - Beta minMax function
    try {
        // Test 1.1: gamePhase==0; whiteTurn==true; even number search depth
        Board b1;
        b1.white = 0;
        b1.black = 0;
        b1.whiteCount = 0;
        b1.blackCount = 0;
        b1.whiteTurn = 1; // White's turn
        b1.gamePhase = 0; // Adding Phase
        b1.depth = 0;

        int leaf_count = 0;
        int heuristic = b1.ABmM(b1, 0, 2, leaf_count, alpha, beta);
        cout << "heuristic: " << heuristic << endl;

        // Expected heuristic: white and black are even, so heuristic = (1 - 1) = 0
        // TODO: update heuristic check AND leaf count
        assert(heuristic == 0);
        assert(leaf_count == 44); // Ensure leaf nodes were evaluated
        // Reset parameters
        leaf_count = 0;

        // Test 1.2: gamePhase==0; whiteTurn==true; 0 search depth
        heuristic = b1.ABmM(b1, 1, 1, leaf_count, alpha, beta);
        assert(heuristic == 0);
        assert(leaf_count == 1);
        // Reset parameters
        leaf_count = 0;
        
        // Test 1.3: gamePhase==0; whiteTurn==true; odd number search depth
        heuristic = b1.ABmM(b1, 0, 1, leaf_count, alpha, beta);

        // Expected heuristic: white has the only piece on the board so heuristic = 1
        assert(heuristic == 1);
        assert(leaf_count == 23); // Ensure leaf nodes were evaluated
        // Reset parameters
        leaf_count = 0;

        // Test 2.0: Contrived case for ABmM
        Board b2;
        b2.white = 0;
        b2.black = 0;
        b2.whiteCount = 0;
        b2.blackCount = 0;
        b2.whiteTurn = 0; // Black's turn (it's the minMax function)
        b2.gamePhase = 0; // Adding Phase
        b2.depth = 0;

        // Make three nodes for level 1
        Board b2_0, b2_1, b2_2;

        // Make 9 nodes at level 2 (3 ^ level)
        Board b2_0_0, b2_0_1, b2_0_2;
        Board b2_1_0, b2_1_1, b2_1_2;
        Board b2_2_0, b2_2_1, b2_2_2;

        // Make 27 nodes at level 3 (3 ^ level)
        Board b2_0_0_0, b2_0_0_1, b2_0_0_2;
        Board b2_0_1_0, b2_0_1_1, b2_0_1_2;
        Board b2_0_2_0, b2_0_2_1, b2_0_2_2;

        Board b2_1_0_0, b2_1_0_1, b2_1_0_2;
        Board b2_1_1_0, b2_1_1_1, b2_1_1_2;
        Board b2_1_2_0, b2_1_2_1, b2_1_2_2;

        Board b2_2_0_0, b2_2_0_1, b2_2_0_2;
        Board b2_2_1_0, b2_2_1_1, b2_2_1_2;
        Board b2_2_2_0, b2_2_2_1, b2_2_2_2;


        b2_0_0.whiteCount = 3;
        b2_0_1.whiteCount = 12;
        b2_0_2.whiteCount = 8;

        b2_1_0.whiteCount = 2;
        b2_1_1.whiteCount = 4;
        b2_1_2.whiteCount = 6;

        b2_2_0.whiteCount = 14;
        b2_2_1.whiteCount = 5;
        b2_2_2.whiteCount = 2;

        b2_0_0_0.whiteCount = 12;
        b2_0_0_1.whiteCount = 15;
        b2_0_0_2.whiteCount = 4;
        b2_0_1_0.whiteCount = 2;
        b2_0_1_1.whiteCount = 9;
        b2_0_1_2.whiteCount = 6;
        b2_0_2_0.whiteCount = 15;
        b2_0_2_1.whiteCount = 6;
        b2_0_2_2.whiteCount = 4;

        b2_1_0_0.whiteCount = 8;
        b2_1_0_1.whiteCount = 7;
        b2_1_0_2.whiteCount = 4;
        b2_1_1_0.whiteCount = 1;
        b2_1_1_1.whiteCount = 14;
        b2_1_1_2.whiteCount = 4;
        b2_1_2_0.whiteCount = 6;
        b2_1_2_1.whiteCount = 15;
        b2_1_2_2.whiteCount = 10;

        b2_2_0_0.whiteCount = 15;
        b2_2_0_1.whiteCount = 6;
        b2_2_0_2.whiteCount = 14;
        b2_2_1_0.whiteCount = 3;
        b2_2_1_1.whiteCount = 8;
        b2_2_1_2.whiteCount = 9;
        b2_2_2_0.whiteCount = 13;
        b2_2_2_1.whiteCount = 1;
        b2_2_2_2.whiteCount = 2;

        // Organize trees
        b2.L.push_back(b2_0);
        b2.L.push_back(b2_1);
        b2.L.push_back(b2_2);
        
        b2.L[0].L.push_back(b2_0_0);
        b2.L[0].L.push_back(b2_0_1);
        b2.L[0].L.push_back(b2_0_2);

        b2.L[1].L.push_back(b2_1_0);
        b2.L[1].L.push_back(b2_1_1);
        b2.L[1].L.push_back(b2_1_2);

        b2.L[2].L.push_back(b2_2_0);
        b2.L[2].L.push_back(b2_2_1);
        b2.L[2].L.push_back(b2_2_2);

        // Level 3: branch 1
        b2.L[0].L[0].L.push_back(b2_0_0_0);
        b2.L[0].L[0].L.push_back(b2_0_0_1);
        b2.L[0].L[0].L.push_back(b2_0_0_2);

        b2.L[0].L[1].L.push_back(b2_0_1_0);
        b2.L[0].L[1].L.push_back(b2_0_1_1);
        b2.L[0].L[1].L.push_back(b2_0_1_2);

        b2.L[0].L[2].L.push_back(b2_0_2_0);
        b2.L[0].L[2].L.push_back(b2_0_2_1);
        b2.L[0].L[2].L.push_back(b2_0_2_2);

        // Level 3: branch 2
        b2.L[1].L[0].L.push_back(b2_1_0_0);
        b2.L[1].L[0].L.push_back(b2_1_0_1);
        b2.L[1].L[0].L.push_back(b2_1_0_2);
       
        b2.L[1].L[1].L.push_back(b2_1_1_0);
        b2.L[1].L[1].L.push_back(b2_1_1_1);
        b2.L[1].L[1].L.push_back(b2_1_1_2);
       
        b2.L[1].L[2].L.push_back(b2_1_2_0);
        b2.L[1].L[2].L.push_back(b2_1_2_1);
        b2.L[1].L[2].L.push_back(b2_1_2_2);

        // Level 3: branch 3
        b2.L[2].L[0].L.push_back(b2_2_0_0);
        b2.L[2].L[0].L.push_back(b2_2_0_1);
        b2.L[2].L[0].L.push_back(b2_2_0_2);
        b2.L[2].L[1].L.push_back(b2_2_1_0);
        b2.L[2].L[1].L.push_back(b2_2_1_1);
        b2.L[2].L[1].L.push_back(b2_2_1_2);
        b2.L[2].L[2].L.push_back(b2_2_2_0);
        b2.L[2].L[2].L.push_back(b2_2_2_1);
        b2.L[2].L[2].L.push_back(b2_2_2_2);
        
        // Evaluate heuristic
        heuristic = b2.ABmM(b2, 0, 2, leaf_count, alpha, beta);
        assert(heuristic == 6);
        assert(leaf_count == 7);
        leaf_count = 0;

        // Test level 3
        heuristic = b2.ABmM(b2, 0, 3, leaf_count, alpha, beta);
        assert(heuristic == 4);
        assert(leaf_count == 13);

        return true;
    } catch (...) {
        cout << "testMinMax failed" << endl;
        return false;
    }
}

bool testABMm() {
    /*
        Validate performance of Board::ABMm() function
    */
    int alpha = -10005;
    int beta = 10005;

    // Test case for Alpha - Beta maxMin function
    try {
        // Test 1.1: gamePhase==0; whiteTurn==true; even number search depth
        Board b1;
        b1.white = 0;
        b1.black = 0;
        b1.whiteCount = 0;
        b1.blackCount = 0;
        b1.whiteTurn = 1; // White's turn
        b1.gamePhase = 0; // Adding Phase
        b1.depth = 0;

        int leaf_count = 0;
        int heuristic = b1.ABMm(b1, 0, 2, leaf_count, alpha, beta);
        cout << "heuristic: " << heuristic << endl;

        // Expected heuristic: white and black are even, so heuristic = (1 - 1) = 0
        // TODO: update heuristic check AND leaf count
        assert(heuristic == 0);
        assert(leaf_count == 44); // Ensure leaf nodes were evaluated
        // Reset parameters
        leaf_count = 0;

        // Test 1.2: gamePhase==0; whiteTurn==true; 0 search depth
        heuristic = b1.ABMm(b1, 1, 1, leaf_count, alpha, beta);
        assert(heuristic == 0);
        assert(leaf_count == 1);
        // Reset parameters
        leaf_count = 0;
        
        // Test 1.3: gamePhase==0; whiteTurn==true; odd number search depth
        heuristic = b1.ABMm(b1, 0, 1, leaf_count, alpha, beta);

        // Expected heuristic: white has the only piece on the board so heuristic = 1
        assert(heuristic == 1);
        assert(leaf_count == 23); // Ensure leaf nodes were evaluated
        // Reset parameters
        leaf_count = 0;

        // Test 2.0: Contrived case for ABmM
        Board b2;
        b2.white = 0;
        b2.black = 0;
        b2.whiteCount = 0;
        b2.blackCount = 0;
        b2.whiteTurn = 1; // Black's turn (it's the minMax function)
        b2.gamePhase = 0; // Adding Phase
        b2.depth = 0;

        // Make three nodes for level 1
        Board b2_0, b2_1, b2_2;

        // Make 9 nodes at level 2 (3 ^ level)
        Board b2_0_0, b2_0_1, b2_0_2;
        Board b2_1_0, b2_1_1, b2_1_2;
        Board b2_2_0, b2_2_1, b2_2_2;

        // Make 27 nodes at level 3 (3 ^ level)
        Board b2_0_0_0, b2_0_0_1, b2_0_0_2;
        Board b2_0_1_0, b2_0_1_1, b2_0_1_2;
        Board b2_0_2_0, b2_0_2_1, b2_0_2_2;

        Board b2_1_0_0, b2_1_0_1, b2_1_0_2;
        Board b2_1_1_0, b2_1_1_1, b2_1_1_2;
        Board b2_1_2_0, b2_1_2_1, b2_1_2_2;

        Board b2_2_0_0, b2_2_0_1, b2_2_0_2;
        Board b2_2_1_0, b2_2_1_1, b2_2_1_2;
        Board b2_2_2_0, b2_2_2_1, b2_2_2_2;


        b2_0_0.whiteCount = 3;
        b2_0_1.whiteCount = 12;
        b2_0_2.whiteCount = 8;

        b2_1_0.whiteCount = 2;
        b2_1_1.whiteCount = 4;
        b2_1_2.whiteCount = 6;

        b2_2_0.whiteCount = 14;
        b2_2_1.whiteCount = 5;
        b2_2_2.whiteCount = 2;

        b2_0_0_0.whiteCount = 12;
        b2_0_0_1.whiteCount = 15;
        b2_0_0_2.whiteCount = 4;
        b2_0_1_0.whiteCount = 2;
        b2_0_1_1.whiteCount = 9;
        b2_0_1_2.whiteCount = 6;
        b2_0_2_0.whiteCount = 15;
        b2_0_2_1.whiteCount = 6;
        b2_0_2_2.whiteCount = 4;

        b2_1_0_0.whiteCount = 8;
        b2_1_0_1.whiteCount = 7;
        b2_1_0_2.whiteCount = 4;
        b2_1_1_0.whiteCount = 1;
        b2_1_1_1.whiteCount = 14;
        b2_1_1_2.whiteCount = 4;
        b2_1_2_0.whiteCount = 6;
        b2_1_2_1.whiteCount = 15;
        b2_1_2_2.whiteCount = 10;

        b2_2_0_0.whiteCount = 15;
        b2_2_0_1.whiteCount = 6;
        b2_2_0_2.whiteCount = 14;
        b2_2_1_0.whiteCount = 3;
        b2_2_1_1.whiteCount = 8;
        b2_2_1_2.whiteCount = 9;
        b2_2_2_0.whiteCount = 13;
        b2_2_2_1.whiteCount = 1;
        b2_2_2_2.whiteCount = 2;

        // Organize trees
        b2.L.push_back(b2_0);
        b2.L.push_back(b2_1);
        b2.L.push_back(b2_2);
        
        b2.L[0].L.push_back(b2_0_0);
        b2.L[0].L.push_back(b2_0_1);
        b2.L[0].L.push_back(b2_0_2);

        b2.L[1].L.push_back(b2_1_0);
        b2.L[1].L.push_back(b2_1_1);
        b2.L[1].L.push_back(b2_1_2);

        b2.L[2].L.push_back(b2_2_0);
        b2.L[2].L.push_back(b2_2_1);
        b2.L[2].L.push_back(b2_2_2);

        // Level 3: branch 1
        b2.L[0].L[0].L.push_back(b2_0_0_0);
        b2.L[0].L[0].L.push_back(b2_0_0_1);
        b2.L[0].L[0].L.push_back(b2_0_0_2);

        b2.L[0].L[1].L.push_back(b2_0_1_0);
        b2.L[0].L[1].L.push_back(b2_0_1_1);
        b2.L[0].L[1].L.push_back(b2_0_1_2);

        b2.L[0].L[2].L.push_back(b2_0_2_0);
        b2.L[0].L[2].L.push_back(b2_0_2_1);
        b2.L[0].L[2].L.push_back(b2_0_2_2);

        // Level 3: branch 2
        b2.L[1].L[0].L.push_back(b2_1_0_0);
        b2.L[1].L[0].L.push_back(b2_1_0_1);
        b2.L[1].L[0].L.push_back(b2_1_0_2);
       
        b2.L[1].L[1].L.push_back(b2_1_1_0);
        b2.L[1].L[1].L.push_back(b2_1_1_1);
        b2.L[1].L[1].L.push_back(b2_1_1_2);
       
        b2.L[1].L[2].L.push_back(b2_1_2_0);
        b2.L[1].L[2].L.push_back(b2_1_2_1);
        b2.L[1].L[2].L.push_back(b2_1_2_2);

        // Level 3: branch 3
        b2.L[2].L[0].L.push_back(b2_2_0_0);
        b2.L[2].L[0].L.push_back(b2_2_0_1);
        b2.L[2].L[0].L.push_back(b2_2_0_2);
        b2.L[2].L[1].L.push_back(b2_2_1_0);
        b2.L[2].L[1].L.push_back(b2_2_1_1);
        b2.L[2].L[1].L.push_back(b2_2_1_2);
        b2.L[2].L[2].L.push_back(b2_2_2_0);
        b2.L[2].L[2].L.push_back(b2_2_2_1);
        b2.L[2].L[2].L.push_back(b2_2_2_2);
        
        // Evaluate heuristic
        heuristic = b2.ABMm(b2, 0, 2, leaf_count, alpha, beta);
        assert(heuristic == 3);
        assert(leaf_count == 7);
        leaf_count = 0;

        // Test level 3
        heuristic = b2.ABMm(b2, 0, 3, leaf_count, alpha, beta);
        assert(heuristic == 9);
        assert(leaf_count == 16);

        return true;
    } catch (...) {
        cout << "testMinMax failed" << endl;
        return false;
    }
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

    if (!testCloseMill()) {
        all_pass = false;
        cout << "testCloseMill failed" << endl;
    }

    if (!testNeighbors()) {
        all_pass = false;
        cout << "testNeighbors failed" << endl;
    }

    if (!testUpdateBoard()) {
        all_pass = false;
        cout << "testUpdateBoard failed" << endl;
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

    if (!testStaticEstimate()) {
        all_pass = false;
        cout << "testStaticEstmate failed" << endl;
    }

    if (!testMinMax()) {
        all_pass = false;
        cout << "testMinMax failed" << endl;
    }

    if (!testABmM()) {
        all_pass = false;
        cout << "testABmM failed" << endl;
    }

    if (!testABMm()) {
        all_pass = false;
        cout << "testABMm failed" << endl;
    }

    if (!testStaticEstimateImproved()) {
        all_pass = false;
        cout << "testStaticEstimateImproved failed" << endl;
    }

    // if (!testMinMaxImproved()) {
    //     all_pass = false;
    //     cout << "testMinMaxImproved failed" << endl;
    // }


    if (all_pass)
        cout << "All tests have passed!" << endl;
    else
        cout << "Tests have failed!" << endl;
    return 0;
}