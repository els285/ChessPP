#ifndef Chess_Pieces
#define Chess_Pieces

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

class King: public Piece{

    public:

        string Name = "King";
        vector<vector<int>> AllMoves = generate_possible_moves();

        King(string input_colour, int x0, int y0):Piece(input_colour,x0,y0){}

        // Function for generating possible King moves
        vector<vector<int>> generate_possible_moves(){
            vector<vector<int>> possible_moves;

            for(int i=-1; i<2; i++){
                for(int j=-1; j<2; j++){

                    int Xnew = X_position + i;
                    int Ynew = Y_position + j;
                    if (Xnew >= 0 && Xnew <=7 && Ynew >= 0 && Ynew <=7){
                        vector<int> Vnew = {Xnew,Ynew};
                        possible_moves.push_back(Vnew);
                    }
                };
            }
            return possible_moves;
        }
};


// Function for generating bishop-like moves
vector<vector<int>> generate_bishop_moves(int X_position,int Y_position){
    vector<vector<int>> possible_moves;

    int sum  = X_position + Y_position;
    int diff = abs(X_position - Y_position); 

    for(int i=-8; i<8; i++){
        for(int j=-8; j<8; j++){
            int Xnew = X_position + i;
            int Ynew = Y_position + j;

            int sum_ij  = Xnew + Ynew;
            int diff_ij = abs(Xnew-Ynew) ;

            if (Xnew >= 0 && Xnew <=7 && Ynew >= 0 && Ynew <=7
                && (sum==sum_ij || diff==diff_ij)){
                vector<int> Vnew = {Xnew,Ynew};
                possible_moves.push_back(Vnew);
            }
        };
    }
    return possible_moves;
}


// Function for generating Rook-like moves
vector<vector<int>> generate_rook_moves(int X_position,int Y_position){
    vector<vector<int>> possible_moves;

    for(int i=-8; i<8; i++){
        int Xnew = X_position + i;
        if (Xnew >= 0 && Xnew <=7){
            vector<int> Vnew = {Xnew,Y_position};
            possible_moves.push_back(Vnew);
        }

        int Ynew = Y_position + i;
        if (Ynew >= 0 && Ynew <=7){
            vector<int> Vnew = {X_position,Ynew};
            possible_moves.push_back(Vnew);
        }

    }
    return possible_moves;
}


class Bishop: public Piece{

    public:

        string Name = "Bishop";
        int value   = 3;
        vector<vector<int>> AllMoves = generate_possible_moves();

        Bishop(string input_colour, int x0, int y0):Piece(input_colour,x0,y0){}

        vector<vector<int>> generate_possible_moves(){
            return generate_bishop_moves(X_position,Y_position);
            }

};

class Rook: public Piece{

    public:

        string Name = "Rook";
        int value   = 5;
        vector<vector<int>> AllMoves = generate_possible_moves();

        Rook(string input_colour, int x0, int y0):Piece(input_colour,x0,y0){}

        vector<vector<int>> generate_possible_moves(){
            return generate_bishop_moves(X_position,Y_position);
            }

};



class Queen: public Piece{

  public:
    string Name = "Queen";
    int value   = 9;
    vector<vector<int>> AllMoves = generate_possible_moves();

    Queen(string input_colour, int x0, int y0):Piece(input_colour,x0,y0){}

    vector<vector<int>> generate_possible_moves(){

        vector<vector<int>> RookMoves   = generate_rook_moves(X_position,Y_position);
        vector<vector<int>> BishopMoves = generate_bishop_moves(X_position,Y_position);

        vector<vector<int>> AllMoves(RookMoves.size() + BishopMoves.size());
        merge(RookMoves.begin(),
                RookMoves.end(),
                BishopMoves.begin(),
                BishopMoves.end(),
                AllMoves.begin()); 

        return AllMoves;
    }
};



#endif