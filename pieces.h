#ifndef ChessPieces
#define ChessPieces

#include <string>
#include <iostream>
#include<vector>
#include "moves.h"

using std::string;
using std::vector;

enum class Colour { WHITE , BLACK };
enum class PieceType { KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN };


class Piece{

  public:
    
    PieceType piece_type; 
    Colour colour; 
    int X_position;
    int Y_position;
    bool status;
    vector<vector<int>> all_moves;
    vector<vector<int>> generate_all_possible_moves();

    // This is the constructor for Piece
    /*
    Default values passed so that the objects are Default-Constructable
    */
    Piece(PieceType input_piece_type = PieceType::KING, 
            Colour input_colour = Colour::WHITE, 
            int x0 = 0, 
            int y0 = 0)
            {
        piece_type = input_piece_type;
        colour     = input_colour;
        X_position = x0;
        Y_position = y0;
        vector<int> v0 = {X_position, Y_position};
    }

    // Copy constructor
    // Piece(Piece &obj) {
    //     piece_type = obj.piece_type;
    //     colour     = obj.colour;
    //     X_position = obj.X_position;
    //     Y_position = obj.Y_position;
    //     vector<int> v0 = {obj.X_position, obj.Y_position};
    // }

    // Function which makes move
    int update_position(int Xnew, int Ynew){
        X_position = Xnew;
        Y_position = Ynew;

        vector<int> v1 = {X_position , Y_position};
        all_moves.push_back(v1);
        return 0;
    }
  
};


// Function to generate all possible moves, using switch to choose piece type
// Defined outside the class definition because we can
vector<vector<int>> Piece::generate_all_possible_moves(){

    vector<vector<int>> all_moves;

    switch(piece_type){
    case PieceType::KING:
        all_moves = Moves::generate_king_moves(X_position,Y_position);
        break;
    case PieceType::QUEEN:
        all_moves = Moves::generate_queen_moves(X_position,Y_position);  
        break;
    case PieceType::ROOK:
        all_moves = Moves::generate_rook_moves(X_position,Y_position);       
        break;
    case PieceType::BISHOP:
        all_moves = Moves::generate_bishop_moves(X_position,Y_position);   
        break;    
    case PieceType::KNIGHT:
        all_moves = Moves::generate_knight_moves(X_position,Y_position);    
        break;   
    case PieceType::PAWN:
        all_moves = Moves::generate_pawn_moves(X_position,Y_position);     
        break;              
        }
    return all_moves;
}

#endif