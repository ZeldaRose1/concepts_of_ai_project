#include <iostream>
#include <cassert>
#include <math.h>
#include "Game.h"
using namespace std;


bool testBoardConstructor(){
    // This tests to ensure the board is initialized to all 0s
    Board b;
    try {
        for (short int i = 0; i < 22; i++) {
            assert (b.state[i] == 0);
        }
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
    for (int i = 0; i < 23; i++){
        b.state[i] = pow(-1, i);
    }

    // Initialize second board
    Board b2(b);

    // Run test
    try {
        for (short int i = 0; i < 22; i++) {
            assert (b.state[i] == b2.state[i]);
        }
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
        for (int i = 0; i < 23; i++) {
            assert(b.state[i] == 0);
        }
    } catch (const exception e) {
        cout << "Exception raised in testGameConstructor:\t" << e.what() << endl;
        return false;
    }
    return true;
}

bool testGameConstructorBoard() {
    // Tests if the default constructor for Game functions
    Board b;
    for (int i = 0; i < 23; i++)
        b[i] = pow(-1, i % 3);
    Game g(b);
    try {
        for (int i = 0; i < 23; i++) {
            assert(g.getBoard()[i] == b[i]);
        }
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
    b[b.a0] = 1;
    b[b.d0] = 1;
    b[b.g0] = 1;

    try {
        // Test the first row (all mills)
        assert (g.closeMill(b.a0, b));
        assert (g.closeMill(b.d0, b));
        assert (g.closeMill(b.g0, b));

        // Test all spaces that are not mills
        for (int i = 4; i < 23; i++)
            assert (!g.closeMill(i, b));

        // Un-mill the bottom row and retest. (Checks against non-homogenous row)
        b[b.d0] = -1;

        // Check mil has been undone
        assert (!g.closeMill(b.a0, b));
        assert (!g.closeMill(b.d0, b));
        assert (!g.closeMill(b.g0, b));

        // Reset board
        for (int i = 0; i < 23; i++)
            b[i] = 0;
        // Set a0, b1, c2
        b[b.a0] = 1;
        b[b.b1] = 1;
        b[b.c2] = 1;
        // Run tests
        for (int i = 0; i < 23; i++) {
            if (i == b.a0 || i == b.b1 || i == b.c2)
                assert (g.closeMill(i, b)); // Check real mils return true
            else
                assert (!g.closeMill(i, b));  // Check non-mils return false
        }
        
        // Reset board
        for (int i = 0; i < 23; i++)
            b[i] = 0;
        // Set pieces
        b[b.a0] = 1;
        b[b.a3] = 1;
        b[b.a6] = 1;
        // Run tests
        for (int i = 0; i < 23; i++) {
            if (i == b.a0 || i == b.a3 || i == b.a6)
                assert (g.closeMill(i, b)); // Check real mils return true
            else
                assert (!g.closeMill(i, b)); // Check non-mils return false
        }

        // Reset board
        for (int i = 0; i < 23; i++)
            b[i] = 0;
        // Set pieces
        b[b.g0] = 1;
        b[b.f1] = 1;
        b[b.e2] = 1;
        // Run tests
        for (int i = 0; i < 23; i++) {
            if (i == b.g0 || i == b.f1 || i == b.e2)
                assert (g.closeMill(i, b)); // Check real mils return true
            else
                assert (!g.closeMill(i, b)); // Check non-mils return false
        }

        // Reset board
        for (int i = 0; i < 23; i++)
            b[i] = 0;
        // Set pieces
        b[b.g0] = 1;
        b[b.g3] = 1;
        b[b.g6] = 1;
        // Run tests
        for (int i = 0; i < 23; i++) {
            if (i == b.g0 || i == b.g3 || i == b.g6)
                assert (g.closeMill(i, b)); // Check real mils return true
            else
                assert (!g.closeMill(i, b)); // Check non-mils return false
        }

        // Reset board
        for (int i = 0; i < 23; i++)
            b[i] = 0;
        // Set pieces
        b[b.a6] = 1;
        b[b.d6] = 1;
        b[b.g6] = 1;
        // Run tests
        for (int i = 0; i < 23; i++) {
            if (i == b.a6 || i == b.d6 || i == b.g6)
                assert (g.closeMill(i, b)); // Check real mils return true
            else
                assert (!g.closeMill(i, b)); // Check non-mils return false
        }

        // Reset board
        for (int i = 0; i < 23; i++)
            b[i] = 0;
        // Set pieces
        b[b.c4] = 1;
        b[b.b5] = 1;
        b[b.a6] = 1;
        // Run tests
        for (int i = 0; i < 23; i++) {
            if (i == b.a6 || i == b.b5 || i == b.c4)
                assert (g.closeMill(i, b)); // Check real mils return true
            else
                assert (!g.closeMill(i, b)); // Check non-mils return false
        }

        // Reset board
        for (int i = 0; i < 23; i++)
            b[i] = 0;
        // Set pieces
        b[b.e4] = 1;
        b[b.f5] = 1;
        b[b.g6] = 1;
        // Run tests
        for (int i = 0; i < 23; i++) {
            if (i == b.e4 || i == b.f5 || i == b.g6)
                assert (g.closeMill(i, b)); // Check real mils return true
            else
                assert (!g.closeMill(i, b)); // Check non-mils return false
        }

        // Reset board
        for (int i = 0; i < 23; i++)
            b[i] = 0;
        // Set pieces
        b[b.b1] = 1;
        b[b.d1] = 1;
        b[b.f1] = 1;
        // Run tests
        for (int i = 0; i < 23; i++) {
            if (i == b.b1 || i == b.d1 || i == b.f1)
                assert (g.closeMill(i, b)); // Check real mils return true
            else
                assert (!g.closeMill(i, b)); // Check non-mils return false
        }

        // Reset board
        for (int i = 0; i < 23; i++)
            b[i] = 0;
        // Set pieces
        b[b.f1] = 1;
        b[b.f3] = 1;
        b[b.f5] = 1;
        // Run tests
        for (int i = 0; i < 23; i++) {
            if (i == b.f1 || i == b.f3 || i == b.f5)
                assert (g.closeMill(i, b)); // Check real mils return true
            else
                assert (!g.closeMill(i, b)); // Check non-mils return false
        }

        // Reset board
        for (int i = 0; i < 23; i++)
            b[i] = 0;
        // Set pieces
        b[b.b5] = 1;
        b[b.d5] = 1;
        b[b.f5] = 1;
        // Run tests
        for (int i = 0; i < 23; i++) {
            if (i == b.b5 || i == b.d5 || i == b.f5)
                assert (g.closeMill(i, b)); // Check real mils return true
            else
                assert (!g.closeMill(i, b)); // Check non-mils return false
        }

        // Reset board
        for (int i = 0; i < 23; i++)
            b[i] = 0;
        // Set pieces
        b[b.a3] = 1;
        b[b.b3] = 1;
        b[b.c3] = 1;
        // Run tests
        for (int i = 0; i < 23; i++) {
            if (i == b.a3 || i == b.b3 || i == b.c3)
                assert (g.closeMill(i, b)); // Check real mils return true
            else
                assert (!g.closeMill(i, b)); // Check non-mils return false
        }

        // Reset board
        for (int i = 0; i < 23; i++)
            b[i] = 0;
        // Set pieces
        b[b.d4] = 1;
        b[b.d5] = 1;
        b[b.d6] = 1;
        // Run tests
        for (int i = 0; i < 23; i++) {
            if (i == b.d4 || i == b.d5 || i == b.d6)
                assert (g.closeMill(i, b)); // Check real mils return true
            else
                assert (!g.closeMill(i, b)); // Check non-mils return false
        }

        // Reset board
        for (int i = 0; i < 23; i++)
            b[i] = 0;
        // Set pieces
        b[b.e3] = 1;
        b[b.f3] = 1;
        b[b.g3] = 1;
        // Run tests
        for (int i = 0; i < 23; i++) {
            if (i == b.e3 || i == b.f3 || i == b.g3)
                assert (g.closeMill(i, b)); // Check real mils return true
            else
                assert (!g.closeMill(i, b)); // Check non-mils return false
        }

        // Reset board
        for (int i = 0; i < 23; i++)
            b[i] = 0;
        // Set pieces
        b[b.e3] = 1;
        b[b.f3] = 1;
        b[b.g3] = 1;
        // Run tests
        for (int i = 0; i < 23; i++) {
            if (i == b.e3 || i == b.f3 || i == b.g3)
                assert (g.closeMill(i, b)); // Check real mils return true
            else
                assert (!g.closeMill(i, b)); // Check non-mils return false
        }

        // Reset board
        for (int i = 0; i < 23; i++)
            b[i] = 0;
        // Set pieces
        b[b.c2] = 1;
        b[b.c3] = 1;
        b[b.c4] = 1;
        // Run tests
        for (int i = 0; i < 23; i++) {
            if (i == b.c2 || i == b.c3 || i == b.c4)
                assert (g.closeMill(i, b)); // Check real mils return true
            else
                assert (!g.closeMill(i, b)); // Check non-mils return false
        }

        // Reset board
        for (int i = 0; i < 23; i++)
            b[i] = 0;
        // Set pieces
        b[b.c4] = 1;
        b[b.d4] = 1;
        b[b.e4] = 1;
        // Run tests
        for (int i = 0; i < 23; i++) {
            if (i == b.c4 || i == b.d4 || i == b.e4)
                assert (g.closeMill(i, b)); // Check real mils return true
            else
                assert (!g.closeMill(i, b)); // Check non-mils return false
        }

        // Reset board
        for (int i = 0; i < 23; i++)
            b[i] = 0;
        // Set pieces
        b[b.e2] = 1;
        b[b.e3] = 1;
        b[b.e4] = 1;
        // Run tests
        for (int i = 0; i < 23; i++) {
            if (i == b.e2 || i == b.e3 || i == b.e4)
                assert (g.closeMill(i, b)); // Check real mils return true
            else
                assert (!g.closeMill(i, b)); // Check non-mils return false
        }
        
        // Force all spaces to be white
        for (int i = 0; i < 23; i++)
            b[i] = 1;
        // Run tests
        for (int i = 0; i < 23; i++)
            assert (g.closeMill(i, b));
        
        // Force all spaces to be black
        for (int i = 0; i < 23; i++)
            b[i] = -1;
        // Run tests
        for (int i = 0; i < 23; i++)
            assert (g.closeMill(i, b));

        // Reset board
        for (int i = 0; i < 23; i++) b[i] = 0;
        // Form mill
        b[b.a0] = 1;
        b[b.b1] = 1;
        b[b.c2] = 1;
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


    if (all_pass)
        cout << "All tests have passed!" << endl;
    else
        cout << "Tests have failed!" << endl;
    return 0;
}