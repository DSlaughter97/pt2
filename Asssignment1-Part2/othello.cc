// Author: Lucas Nation
//
// Date: 8/10/17
//
// Description: This is my implementation file for the othello class.
//

#include "othello.h"
#include<iostream>
#include<string>
#include<queue>
namespace main_savitch_14 {

void othello :: display_status() const {
  cout << B_BLACK << WHITE << "   A  B  C  D  E  F  G  H   " << RESET << endl;
  for(int i=0; i<8; i++) {
    cout << B_BLACK << WHITE << " " << i+1;    
    for(int j=0; j<8; j++) {
      if(board[i][j].is_empty() && (i+j)%2==0)
        cout << B_RED << "   "; 
      else if(board[i][j].is_empty() && (i+j)%2!=0)
        cout << B_BLUE << "   ";
      else if(!board[i][j].is_empty() && (i+j)%2==0)
        cout << B_RED << board[i][j].get_color() << " * ";
      else if(!board[i][j].is_empty() && (i+j)%2!=0)
        cout << B_BLUE << board[i][j].get_color() << " * ";
    }
    cout << B_BLACK << "  ";
    cout << RESET << endl;
  }
  cout << B_BLACK << "                            " << RESET << endl;
}

bool othello :: is_legal(const std::string& move) const {

char c[1];
c[0] = toupper(move.at(0));
c[1] = move.at(1);
int temp,temp2;
if(c[0] == 'A')
  temp2 = 0;
else if(c[0] == 'B')
  temp2 = 1;
else if(c[0] == 'C')
  temp2 = 2;
else if(c[0] == 'D')
  temp2 = 3;
else if(c[0] == 'E')
  temp2 = 4;
else if(c[0] == 'F')
  temp2 = 5;
else if(c[0] == 'G')
  temp2 = 6;
else
  temp2 = 7;
if(c[1] == '1')
  temp = 0;
else if(c[1] == '2')
  temp = 1;
else if(c[1] == '3')
  temp = 2;
else if(c[1] == '4')
  temp = 3;
else if(c[1] == '5')
  temp = 4;
else if(c[1] == '6')
  temp = 5;
else if(c[1] == '7')
  temp = 6;
else
  temp = 7;
int test = temp,test2=temp2;
bool result = false;
int count = 0;

if(next_mover() == HUMAN) { //black pieces
  //vertical check 1 (down)
  if(board[temp][temp2].is_empty()) {
  while(test+1 < 8 && board[test+1][test2].is_white()) {
    test++;
    count++;
  }
  if(test+1 < 8 && board[test+1][test2].is_black() && count!=0)
    result = true;
  //vertical check 2 (up)
  if(!result) {
    count = 0;
    test = temp;
    test2 = temp2;
    while(test-1 >= 0 && board[test-1][test2].is_white()) {
      test--;
      count++;
    }
  if(test-1 >= 0 && board[test-1][test2].is_black() && count!=0)
    result = true;
  }
  //horizontal check 1 (right)
  if(!result) {
    count = 0;
    test = temp;
    test2 = temp2;
    while(test2+1 < 8 && board[test][test2+1].is_white()) {
      test2++;
      count++;
    }
    if(test2+1 < 8 && board[test][test2+1].is_black() && count!=0)
      result = true;
  }
  //horizontal check 2 (left)
  if(!result) {
    count = 0;
    test = temp;
    test2 = temp2;
    while(test2-1 >= 0 && board[test][test2-1].is_white()) {
      test2--;
      count++;
    }
    if(test2-1 >= 0 && board[test][test2-1].is_black() && count!=0)
      result = true;
  }
  //diagonal check 1 (+,+)
  if(!result) {
    count = 0;
    test = temp;
    test2 = temp2;
    while(test+1 < 8 && test2+1 < 8 && board[test+1][test2+1].is_white()) {
      test++;
      test2++;
      count++;
    }
  if(test+1 < 8 && test2+1 < 8 && board[test+1][test2+1].is_black() && count!=0)
    result = true;
  }
  //diagonal check 2 (-,+)
  if(!result) {
    count = 0;
    test = temp;
    test2 = temp2;
    if(test-1 >= 0 && test2+1 < 8 && board[test-1][test2+1].is_white()) {
      test--;
      test2++;
      count++;
    }
    if(test-1 >= 0 && test2+1 < 8 && board[test-1][test2+1].is_black() && count!=0)
      result = true;
  }
  //diagonal check 3 (-,-)
  if(!result) {
    test = temp;
    test2 = temp2;
    while(test-1 >= 0 && test2-1 >= 0 && board[test-1][test2-1].is_white()) {
      test--;
      test2--;
      count++;
    }
    if(test-1 >= 0 && test2-1 >= 0 && board[test-1][test2-1].is_black() && count!=0)
      result = true;
  }
  //diagonal check 4 (+,-)
  if(!result) {
    count = 0;
    test = temp;
    test2 = temp2;
    while(test+1 < 8 && test2-1 >= 0 && board[test+1][test2-1].is_white()) {
      test++;
      test2--;
      count++;
    }
  if(test+1 < 8 && test2-1 >= 0 && board[test+1][test2-1].is_black() && count!=0)
    result = true;
  }
  }
return result;
}
else if(next_mover() == COMPUTER) { //white pieces
  //vertical check 1 (down)
  if(board[temp][temp2].is_empty()) {
  while(test+1 < 8 && board[test+1][test2].is_black()) {
    test++;
    count++;
  }
  if(test+1 < 8 && board[test+1][test2].is_white() && count!=0)
    result = true;
  //vertical check 2 (up)
  if(!result) {
    count = 0;
    test = temp;
    test2 = temp2;
    while(test-1 >= 0 && board[test-1][test2].is_black()) {
      test--;
      count++;
    }
    if(test-1 >= 0 && board[test-1][test2].is_white() && count!=0)
      result = true;
  }
  //horizontal check 1 (right)
  if(!result) {
    count = 0;
    test = temp;
    test2 = temp2;
    while(test2+1 < 8 && board[test][test2+1].is_black()) {
      test2++;
      count++;
    }
    if(test2+1 < 8 && board[test][test2+1].is_white() && count!=0)
      result = true;
  }
  //horizontal check 2 (left)
  if(!result) {
    count = 0;
    test = temp;
    test2 = temp2;
    while(test2-1 >= 0 && board[test][test2-1].is_black()) {
      test2--;
      count++;
    }
    if(test2-1 >= 0 && board[test][test2-1].is_white() && count!=0)
      result = true;
  }
  //diagonal check 1 (+,+)
  if(!result) {
    count = 0;
    test = temp;
    test2 = temp2;
    while(test+1 < 8 && test2+1 < 8 && board[test+1][test2+1].is_black()) {
      test++;
      test2++;
      count++;
    }
  if(test+1 < 8 && test2+1 < 8 && board[test+1][test2+1].is_white() && count!=0)
    result = true;
  }
  //diagonal check 2 (-,+)
  if(!result) {
    count = 0;
    test = temp;
    test2 = temp2;
    if(test-1 >= 0 && test2+1 < 8 && board[test-1][test2+1].is_black()) {
      test--;
      test2++;
      count++;
  }
  if(test-1 >= 0 && test2+1 < 8 && board[test-1][test2+1].is_white() && count!=0)
    result = true;
  }
  //diagonal check 3 (-,-)
  if(!result) {
    count = 0;
    test = temp;
    test2 = temp2;
    while(test-1 >= 0 && test2-1 >= 0 && board[test-1][test2-1].is_black()) {
      test--;
      test2--;
      count++;
  }
  if(test-1 >= 0 && test2-1 >= 0 && board[test-1][test2-1].is_white() && count!=0)
    result = true;
  }
  //diagonal check 4 (+,-)
  if(!result) {
    count = 0;
    test = temp;
    test2 = temp2;
    while(test+1 < 8 && test2-1 >= 0 && board[test+1][test2-1].is_black()) {
      test++;
      test2--;
      count++;
  }
  if(test+1 < 8 && test2-1 >= 0 && board[test+1][test2-1].is_white() && count!=0)
    result = true;
  }
}
return result;
}
}

void othello :: make_move(const std::string& move) {
char c[1];
c[0] = toupper(move.at(0));
c[1] = move.at(1);
int temp,temp2;
if(c[0] == 'A')
  temp2 = 0;
else if(c[0] == 'B')
  temp2 = 1;
else if(c[0] == 'C')
  temp2 = 2;
else if(c[0] == 'D')
  temp2 = 3;
else if(c[0] == 'E')
  temp2 = 4;
else if(c[0] == 'F')
  temp2 = 5;
else if(c[0] == 'G')
  temp2 = 6;
else
  temp2 = 7;
if(c[1] == '1')
  temp = 0;
else if(c[1] == '2')
  temp = 1;
else if(c[1] == '3')
  temp = 2;
else if(c[1] == '4')
  temp = 3;
else if(c[1] == '5')
  temp = 4;
else if(c[1] == '6')
  temp = 5;
else if(c[1] == '7')
  temp = 6;
else
  temp = 7;
int test=temp,test2=temp2;
int stop,stop2;

if(next_mover() == HUMAN) { //black pieces
  board[temp][temp2].set_piece(true);
  board[temp][temp2].set_color(BLACK);
  //vertical check 1 (down)
  while(test+1 < 8 && board[test+1][test2].is_white())
    test++;
  if(test+1 < 8 && board[test+1][test2].is_black()) {
    stop = test+1;
    test = temp;
    while(test != stop) {
      if(board[test][test2].is_white())
        board[test][test2].flip();
      test++;
    }
  }
  //vertical check 2 (up)
  test = temp;
  test2 = temp2;
  while(test-1 >= 0 && board[test-1][test2].is_white())
    test--;
  if(test-1 >= 0 && board[test-1][test2].is_black()) {
    stop = test-1;
    test = temp;
    while(test != stop) {
      if(board[test][test2].is_white())
        board[test][test2].flip();
      test--;
    }
  }
  //horizontal check 1 (right)
  test = temp;
  test2 = temp2;
  while(test2+1 < 8 && board[test][test2+1].is_white())
    test2++;
  if(test2+1 < 8 && board[test][test2+1].is_black()) {
    stop2 = test2+1;
    test2 = temp2;
    while(test2 != stop2) {
      if(board[test][test2].is_white())
        board[test][test2].flip();
      test2++;
    }
  }
  //horizontal check 2 (left)
    test = temp;
    test2 = temp2;
    while(test2-1 >= 0 && board[test][test2-1].is_white())
      test2--;
    if(test2-1 >= 0 && board[test][test2-1].is_black()) {
      stop2 = test2-1;
      test2 = temp2;
      while(test2 != stop2) {
        if(board[test][test2].is_white())
          board[test][test2].flip();
        test2--;
      }
    }
  //diagonal check 1 (+,+)
  test = temp;
  test2 = temp2;
  while(test+1 < 8 && test2+1 < 8 && board[test+1][test2+1].is_white()) {
    test++;
    test2++;
  }
  if(test+1 < 8 && test2+1 < 8 && board[test+1][test2+1].is_black()) {
    stop = test+1;
    stop2 = test2+1;
    test = temp;
    test2 = temp2;
    while(test != stop && test2 != stop2) {
      if(board[test][test2].is_white())
        board[test][test2].flip();
      test++;
      test2++;
    }
  }
  //diagonal check 2 (-,+)
  test = temp;
  test2 = temp2;
  if(test-1 >= 0 && test2+1 < 8 && board[test-1][test2+1].is_white()) {
    test--;
    test2++;
  }
  if(test-1 >= 0 && test2+1 < 8 && board[test-1][test2+1].is_black()) {
    stop = test-1;
    stop2 = test2+1;
    test = temp;
    test2 = temp2;
    while(test != stop && test2 != stop2) {
      if(board[test][test2].is_white())
        board[test][test2].flip();
      test--;
      test2++;
    }
  }
  //diagonal check 3 (-,-)
  test = temp;
  test2 = temp2;
  while(test-1 >= 0 && test2-1 >= 0 && board[test-1][test2-1].is_white()) {
    test--;
    test2--;
  }
  if(test-1 >= 0 && test2-1 >= 0 && board[test-1][test2-1].is_black()) {
    stop = test-1;
    stop2 = test2-1;
    test = temp;
    test2 = temp2;
    while(test != stop && test2 != stop2) {
      if(board[test][test2].is_white())
        board[test][test2].flip();
      test--;
      test2--;
    }
  }
  //diagonal check 4 (+,-)
  test = temp;
  test2 = temp2;
  while(test+1 < 8 && test2-1 >= 0 && board[test+1][test2-1].is_white()) {
    test++;
    test2--;
  }
  if(test+1 < 8 && test2-1 >= 0 && board[test+1][test2-1].is_black()) {
    stop = test+1;
    stop2 = test-1;
    test = temp;
    test2 = temp2;
    while(test != stop && test2 != stop2) {
      if(board[test][test2].is_white())
        board[test][test2].flip();
      test++;
      test2--;
    }
  }
} 
else if(next_mover() == COMPUTER) { //white pieces
  board[temp][temp2].set_piece(true);
  board[temp][temp2].set_color(WHITE);
  //vertical check 1 (down)
  while(test+1 < 8 && board[test+1][test2].is_black())
    test++;
  if(test+1 < 8 && board[test+1][test2].is_white()) {
    stop = test+1;
    test = temp;
    while(test != stop) {
      if(board[test][test2].is_black())
        board[test][test2].flip();
      test++;
    }
  }
  //vertical check 2 (up)
  test = temp;
  test2 = temp2;
  while(test-1 >= 0 && board[test-1][test2].is_black())
    test--;
  if(test-1 >= 0 && board[test-1][test2].is_white()) {
    stop = test-1;
    test = temp;
    while(test != stop) {
      if(board[test][test2].is_black())
        board[test][test2].flip();
      test--;
    }
  }
  //horizontal check 1 (right)
  test = temp;
  test2 = temp2;
  while(test2+1 < 8 && board[test][test2+1].is_black())
    test2++;
  if(test2+1 < 8 && board[test][test2+1].is_white()) {
    stop2 = test2+1;
    test2 = temp2;
    while(test2 != stop2) {
      if(board[test][test2].is_black())
        board[test][test2].flip();
      test2++;
    }
  }
  //horizontal check 2 (left)
    test = temp;
    test2 = temp2;
    while(test2-1 >= 0 && board[test][test2-1].is_black())
      test2--;
    if(test2-1 >= 0 && board[test][test2-1].is_white()) {
      stop2 = test2-1;
      test2 = temp2;
      while(test2 != stop2) {
        if(board[test][test2].is_black())
          board[test][test2].flip();
        test2--;
      }
    }
  //diagonal check 1 (+,+)
  test = temp;
  test2 = temp2;
  while(test+1 < 8 && test2+1 < 8 && board[test+1][test2+1].is_black()) {
    test++;
    test2++;
  }
  if(test+1 < 8 && test2+1 < 8 && board[test+1][test2+1].is_white()) {
    stop = test+1;
    stop2 = test2+1;
    test = temp;
    test2 = temp2;
    while(test != stop && test2 != stop2) {
      if(board[test][test2].is_black())
        board[test][test2].flip();
      test++;
      test2++;
    }
  }
  //diagonal check 2 (-,+)
  test = temp;
  test2 = temp2;
  if(test-1 >= 0 && test2+1 < 8 && board[test-1][test2+1].is_black()) {
    test--;
    test2++;
  }
  if(test-1 >= 0 && test2+1 < 8 && board[test-1][test2+1].is_white()) {
    stop = test-1;
    stop2 = test2+1;
    test = temp;
    test2 = temp2;
    while(test != stop && test2 != stop2) {
      if(board[test][test2].is_black())
        board[test][test2].flip();
      test--;
      test2++;
    }
  }
  //diagonal check 3 (-,-)
  test = temp;
  test2 = temp2;
  while(test-1 >= 0 && test2-1 >= 0 && board[test-1][test2-1].is_black()) {
    test--;
    test2--;
  }
  if(test-1 >= 0 && test2-1 >= 0 && board[test-1][test2-1].is_white()) {
    stop = test-1;
    stop2 = test2-1;
    test = temp;
    test2 = temp2;
    while(test != stop && test2 != stop2) {
      if(board[test][test2].is_black())
        board[test][test2].flip();
      test--;
      test2--;
    }
  }
  //diagonal check 4 (+,-)
  test = temp;
  test2 = temp2;
  while(test+1 < 8 && test2-1 >= 0 && board[test+1][test2-1].is_black()) {
    test++;
    test2--;
  }
  if(test+1 < 8 && test2-1 >= 0 && board[test+1][test2-1].is_white()) {
    stop = test+1;
    stop2 = test-1;
    test = temp;
    test2 = temp2;
    while(test != stop && test2 != stop2) {
      if(board[test][test2].is_black())
        board[test][test2].flip();
      test++;
      test2--;
    }
  }
}
game::make_move(move); //increments move_number
}

void othello :: restart() {
  for(int i=0; i<8; i++) {
    for(int j=0; j<8; j++) {
      if((i==3 && j==3) || (i==4 && j==4)) {
        board[i][j].set_color(WHITE);
        board[i][j].set_piece(true);
      }
      else if((i==3 && j==4) || (i==4 && j==3)) {
        board[i][j].set_color(BLACK);
        board[i][j].set_piece(true);
      }
      else
        board[i][j].set_piece(false);      
    }
  }
game::restart();
}

bool othello :: is_game_over() const {
/*int count=0;
  for(int i=0; i<8; i++) {
    for(int j=0; j<8; j++) {
      if(!board[i][j].is_empty())
        count++;
    }
  }
  if(count == 64)
    return true;
  else
    return false;
*/
std::queue<std::string> moves;
compute_moves(moves);
if(moves.empty())
  return true;
else
  return false;
}

game::who othello :: winning() const {
  int black=0,white=0;
  for(int i=0; i<8; i++) {
    for(int j=0; j<8; j++) {
      if(!board[i][j].is_empty() && board[i][j].is_black())
        black++;
      else if(!board[i][j].is_empty() && board[i][j].is_white())
        white++;
    }
  }
  if(black > white)
    return HUMAN;
  else
    return COMPUTER;
}

int othello :: evaluate() const {
  int sum = 0;
  for(int i=0; i<8; i++) {
    for(int j=0; j<8; j++) {
      //weighted corners
      if((i == 0 && j == 0) || (i == 0 && j == 7) || (i==7 && j == 0) || (i==7 && j==7)) {
        if(board[i][j].is_black())
          sum+=4;
        else
          sum-=4;
      }
      else {
        if(board[i][j].is_white())
          sum++;
        else
          sum--;
      }
    }
  }
return sum;
}

void othello :: compute_moves(std::queue<std::string>& moves) const {
  char row = 'A';
  char col = '1';
  string temp = "  ";
  while(row != 'I') {
    while(col != '9') {
      temp[0] = row;
      temp[1] = col;
      if(is_legal(temp))
        moves.push(temp);
      col++;
    }
    row++;
    col = '0';
  }
}
}
