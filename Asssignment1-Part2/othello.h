// Author: Lucas Nation
//
// Date: 8/10/17
//
// Description: This is my header file for the othello class 
//

#ifndef OTHELLO_H
#define OTHELLO_H
#include "piece.h"
#include "game.h"

namespace main_savitch_14 {

class othello: public game {

  public:
    void display_status() const;    
    bool is_legal(const std::string& move) const;
    void make_move(const std::string& move);
    void restart();
    bool is_game_over() const;
    game::who winning() const;
    int evaluate() const;
    void compute_moves(std::queue<std::string>& moves) const;
    game* clone() const {return new othello(*this);}  
    ~othello() {}

  private:
    piece board[8][8];
};
}

#endif
