#include <string>
#include <iostream>
#include<vector>
#include <any>


#include "pieces.h"
#include "game.h"
#include "algebra.h"


using std::string;
using std::vector;



int main(){

    std::cout << __cplusplus << std::endl;

    Game Game1;

    Game1.initialise_pieces();

    std::cout << Game1.white_pieces.size() << std::endl;
    // string out = Translator::translate_position_to_algebra(vector<int> {4,3});
    // std::cout << out << std::endl;



    // // Game1.Whi
    // Knight WhiteKnight("white",7,7);
    // WhiteKnight.generate_possible_moves();

    // vector<vector<int>> po = WhiteKnight.AllMoves;

    // for(int i=0; i<po.size();i++){
    //     std::cout << po[i][0] << "   " << po[i][1] <<std::endl;
    // }


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