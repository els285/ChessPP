#ifndef ChessGame
#define ChessGame

#include <string>
#include <iostream>
#include<vector>
#include <map>
#include <any>

#include "pieces.h"

using std::string;
using std::vector;
using std::map;


class Game{

    /*
    Game class is the overall class
    */

  public:
    map<string, std::any> white_pieces;
    map<string, std::any> black_pieces;

    // vector<Piece> white_pieces;
    // vector<Piece> black_pieces;

    Game(){
        std::cout << "Game started" << std::endl;
        initialise_pieces();
    }

    int initialise_pieces(){

        // White Pieces
        
        King WhiteKing("white",3,0);
        white_pieces["K"] = WhiteKing;
        Queen WhiteQueen("white",4,0);
        white_pieces["Q"] = WhiteQueen;
        Rook WhiteRookLeft("white",0,0), WhiteRookRight("white",7,0);
        white_pieces["R1"] = WhiteRookLeft; white_pieces["R2"] = WhiteRookRight;
        Bishop WhiteBishopLeft("white",2,0), WhiteBishopRight("white",5,0);
        white_pieces["B1"] = WhiteBishopLeft; white_pieces["B2"] = WhiteBishopRight;
        Knight WhiteKnightLeft("white",1,0), WhiteKnightRight("white",6,0);
        white_pieces["N1"] = WhiteKnightLeft; white_pieces["N2"] = WhiteKnightRight;

        for(int i=0; i<8;i++){
            Pawn pawn("white",i,1);
            string key = "P" + std::to_string(i);
            white_pieces[key] = pawn;
        }

        // Black Pieces
        King blackKing("black",3,7);
        black_pieces["K"] = blackKing;
        Queen blackQueen("black",4,7);
        black_pieces["Q"] = blackQueen;
        Rook BlackRookLeft("black",0,7), BlackRookRight("black",7,7);
        black_pieces["R1"] = BlackRookLeft; black_pieces["R2"] = BlackRookRight;
        Bishop BlackBishopLeft("black",2,7), BlackBishopRight("black",5,7);
        black_pieces["B1"] = BlackBishopLeft; black_pieces["B2"] = BlackBishopRight;
        Knight BlackKnightLeft("black",1,7), BlackKnightRight("black",6,7);
        black_pieces["N1"] = BlackKnightLeft; black_pieces["N2"] = BlackKnightRight;

        for(int i=0; i<8;i++){
            Pawn pawn("black",i,6);
            string key = "P" + std::to_string(i);
            black_pieces[key] = pawn;
        }

        return 0;
    }
};

#endif