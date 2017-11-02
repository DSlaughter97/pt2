// Author: Lucas Nation
//
// Date: 8/10/17
//
// Description: This is my application file for the othello game.
//

#include "game.h"
#include "othello.h"
#include<iostream>
using namespace main_savitch_14;

int main() {

othello mygame;

mygame.play();

if(mygame.winning() == game::HUMAN)
  cout << "Player 1 won the game!" << endl;
else if(mygame.winning() == game::COMPUTER)
  cout << "The computer beat you how lame!" << endl;
else
  cout << "Lame, the game ended in a tie." << endl;

return 0;
}
