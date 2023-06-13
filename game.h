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

/*
User-defined template for a particular type of map which uses string and then
generic object
*/
template<typename T>
using MyMap = std::map<string, T>;

class Game{

    /*
    Game class is the overall class
    */

  public:
    MyMap<Piece> white_pieces;
    MyMap<Piece> black_pieces;

    enum pos_stat {white, black, empty};
    map<vector<int> , pos_stat> Positions;


    Game(){
        std::cout << "Game started" << std::endl;
        initialise_pieces();
    }

    int initialise_pieces(){

        // White Pieces
        Piece WhiteKing(PieceType::KING,Colour::WHITE,3,0);
        white_pieces["K"] = WhiteKing;
        Piece WhiteQueen(PieceType::QUEEN,Colour::WHITE,4,0);
        white_pieces["Q"] = WhiteQueen;
        Piece WhiteRookLeft(PieceType::ROOK,Colour::WHITE,0,0), WhiteRookRight(PieceType::ROOK,Colour::WHITE,7,0);
        white_pieces["R1"] = WhiteRookLeft; white_pieces["R2"] = WhiteRookRight;
        Piece WhiteBishopLeft(PieceType::BISHOP,Colour::WHITE,2,0), WhiteBishopRight(PieceType::BISHOP,Colour::WHITE,5,0);
        white_pieces["B1"] = WhiteBishopLeft; white_pieces["B2"] = WhiteBishopRight;
        Piece WhiteKnightLeft(PieceType::KNIGHT,Colour::WHITE,1,0), WhiteKnightRight(PieceType::KNIGHT,Colour::WHITE,6,0);
        white_pieces["N1"] = WhiteKnightLeft; white_pieces["N2"] = WhiteKnightRight;

        for(int i=0; i<8;i++){
            Piece pawn(PieceType::PAWN,Colour::WHITE,i,1);
            string key = "P" + std::to_string(i);
            white_pieces[key] = pawn;
        }

        // Black Pieces
        Piece blackKing(PieceType::KING,Colour::BLACK,3,7);
        black_pieces["K"] = blackKing;
        Piece blackQueen(PieceType::QUEEN,Colour::BLACK,4,7);
        black_pieces["Q"] = blackQueen;
        Piece blackRookLeft(PieceType::ROOK,Colour::BLACK,0,7), blackRookRight(PieceType::ROOK,Colour::BLACK,7,7);
        black_pieces["R1"] = blackRookLeft; black_pieces["R2"] = blackRookRight;
        Piece blackBishopLeft(PieceType::BISHOP,Colour::BLACK,2,7), blackBishopRight(PieceType::BISHOP,Colour::BLACK,5,7);
        black_pieces["B1"] = blackBishopLeft; black_pieces["B2"] = blackBishopRight;
        Piece blackKnightLeft(PieceType::KNIGHT,Colour::BLACK,1,7), blackKnightRight(PieceType::KNIGHT,Colour::BLACK,6,7);
        black_pieces["N1"] = blackKnightLeft; black_pieces["N2"] = blackKnightRight;

        for(int i=0; i<8;i++){
            Piece pawn(PieceType::PAWN,Colour::BLACK,i,6);
            string key = "P" + std::to_string(i);
            black_pieces[key] = pawn;
        }

        return 0;
    }

    // int board_positions(){

    //     std::cout << black_pieces["K"].X_position;

    //     for(auto P : white_pieces) 
    //         // vector<int> = {P.first, P.second};
    //         std::cout << P.second << std::endl;

    //     // for(int i=0; i < 8; i++){
    //     //     for(int j=0;j<8; j++){
    //     //         vector<int> P = {i,j};


    //     //     }
    //     // }
    //     return 0;
    // }


};

#endif