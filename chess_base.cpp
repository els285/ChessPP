#include <string>
#include <iostream>
#include<vector>
#include "pieces.h"
#include "game.h"

using std::string;
using std::vector;



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