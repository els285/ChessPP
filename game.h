#ifndef ChessGame
#define ChessGame

#include <string>
#include <iostream>
#include<vector>
#include "pieces.h"

using std::string;
using std::vector;


class Game{

    /*
    Game class is the overall class
    */

  public:
    vector<Piece> white_pieces;
    vector<Piece> black_pieces;

    Game(){
        std::cout << "Game started" << std::endl;
        initialise_pieces();
    }

    int initialise_pieces(){
        
        King WhiteKing("white",3,0);
        King BlackKing("black",3,7);
        Queen WhiteQueen("white",4,0);
        Queen BlackQueen("black",4,7);
        white_pieces.push_back(WhiteKing);
        black_pieces.push_back(BlackKing);        
        white_pieces.push_back(WhiteQueen);
        black_pieces.push_back(BlackQueen);
        return 0;
    }
};

#endif