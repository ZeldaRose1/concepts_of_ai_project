#include <vector>
#include <iostream>

using namespace std;

class Board {
    public: // This is such a small class, probably don't need private
        // class variables
        unsigned long int white;
        unsigned long int black;
        unsigned short int whiteCount;
        unsigned short int blackCount;
        bool whiteTurn;
        vector<Board> L;

        // Index values for readability
        const static unsigned short int a0 = 0;
        const static unsigned short int d0 = 1;
        const static unsigned short int g0 = 2;
        
        const static unsigned short int b1 = 3;
        const static unsigned short int d1 = 4;
        const static unsigned short int f1 = 5;
        
        const static unsigned short int c2 = 6;
        const static unsigned short int e2 = 7;
        
        const static unsigned short int a3 = 8;
        const static unsigned short int b3 = 9;
        const static unsigned short int c3 = 10;
        const static unsigned short int e3 = 11;
        const static unsigned short int f3 = 12;
        const static unsigned short int g3 = 13;
        
        const static unsigned short int c4 = 14;
        const static unsigned short int d4 = 15;
        const static unsigned short int e4 = 16;
        
        const static unsigned short int b5 = 17;
        const static unsigned short int d5 = 18;
        const static unsigned short int f5 = 19;
        
        const static unsigned short int a6 = 20;
        const static unsigned short int d6 = 21;
        const static unsigned short int g6 = 22;
        
        // Begin class methods
        // Class constructors
        Board();
        Board(const Board&); // Copy constructor
        Board(const char*); // Constructor from file path
    
        // Class operators
        // Read index operator
        short int operator[](int); // Overload [] operator to read value
        void updateBoard(short int, short int); // index, (+1, 0, or -1) for val


        // Helper functions
        vector<unsigned short int> neighbors(unsigned short int); // Returns vector of neighbors
        void swapColors(); // Changes white and black
        void setCounts(); // Updates the counts for white and black pieces
        int writeBoard(string); // Saves status of current board to a .txt file
    };
    