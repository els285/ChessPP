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

int main(){

    Game Game1;

    // Game1.Whi
    Queen WhiteQueen("white",1,0);
    WhiteQueen.generate_possible_moves();

    vector<vector<int>> po = WhiteQueen.AllMoves;

    for(int i=0; i<po.size();i++){
        std::cout << po[i][0] << "   " << po[i][1] <<std::endl;
    }


    // for(vector i : po){ 
    //     for(int j: i){
    //         std::cout << "j = " << j << "    ";
    //     }
    //     std::cout<< "\n";
    // }

    
    

    // for(int i=0; i<2; i++){
    //     std::cout << Game1.all_pieces[i] << std::endl;
    // }

    // Queen BlackQueen("black",1,2);
    // BlackQueen.update_position(3,4);
    // BlackQueen.update_position(5,6);

    // for (int i=0; i < BlackQueen.all_moves.size(); i++){
    //     std::cout << BlackQueen.all_moves[i][0] << std::endl;
    // }

    return 0;
}