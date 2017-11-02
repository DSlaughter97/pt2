// Author: Lucas Nation
//
// Date: 8/10/17
//
// Description: This is my header file for a space in the othello game.
//

#ifndef PIECE_H
#define PIECE_H
#include "colors.h"

namespace main_savitch_14 {

class piece {

  public:
    piece() {white=false; black=false; occupied=false;}
    bool is_empty() const {return !occupied;}
    bool is_white() const {return white;}
    bool is_black() const {return black;}
    string get_color() const {if(is_white())return WHITE; else return BLACK;}
    void flip() {if(is_white()){white=false; black=true;}else{white=true;black=false;}}
    void set_piece(bool p) {occupied = p;}
    void set_color(string s) {if(s==WHITE){white=true;black=false;}else{black=true;white=false;}}

  private:
    bool white,black,occupied;
};
}

#endif

