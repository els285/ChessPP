#ifndef ChessAlgebra
#define ChessAlgebra

#include <string>
#include <iostream>
#include<vector>
#include <map>
#include <cassert>

using std::string;
using std::vector;
using std::map;

namespace Translator{
   

string translate_position_to_algebra(vector<int> position){

    map<int, string> Trans_Dict;
    Trans_Dict[0] = "a";
    Trans_Dict[1] = "b";
    Trans_Dict[2] = "c";
    Trans_Dict[3] = "d";
    Trans_Dict[4] = "e";
    Trans_Dict[5] = "f";
    Trans_Dict[6] = "g";
    Trans_Dict[7] = "h";

    string output = Trans_Dict[position[0]] + std::to_string(position[1]);

    return output;
};


// vector<int> algebra_to_position(string algebra){

//     vector<char> vec(algebra.begin(), algebra.end());

//     assert(("Algebra string is of wrong size", vec.size()==1));

//     map<string, int> Trans_Dict;
//     Trans_Dict[std::to_char("a")] = 0;
//     Trans_Dict[std::to_char("b")] = 1;
//     Trans_Dict[std::to_char("c")] = 2;
//     Trans_Dict[std::to_char("d")] = 3;
//     Trans_Dict[std::to_char("e")] = 4;
//     Trans_Dict[std::to_char("f")] = 5;
//     Trans_Dict[std::to_char("g")] = 6;
//     Trans_Dict[std::to_char("h")] = 7;

//     int x = Trans_Dict[vec[0]];
//     int y = vec[1] - '0';
//     vector<int> position = {x , y};

//     return position;
// };



};
#endif