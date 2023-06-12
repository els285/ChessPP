#ifndef ChessPieces
#define ChessPieces

#include <string>
#include <iostream>
#include<vector>

using std::string;
using std::vector;

class Piece{

  public:
    string colour;    
    int X_position;
    int Y_position;
    bool status;
    vector<vector<int>> all_moves;


    // This is the constructor for Piece
    Piece(string input_colour, int x0, int y0){
        colour     = input_colour;
        X_position = x0;
        Y_position = y0;
        vector<int> v0 = {X_position, Y_position};
        all_moves.push_back(v0);     
    }

    // Function which makes move
    int update_position(int Xnew, int Ynew){
        X_position = Xnew;
        Y_position = Ynew;

        vector<int> v1 = {X_position , Y_position};
        all_moves.push_back(v1);
        return 0;
    }

};


#endif