#include "Board.h"

//Generates 40 rand num of different values to act as the snakes and ladders
void Board::genMove(){ 

  unordered_set<int> uniqueNumbers;
  while (uniqueNumbers.size() < 40) {
    int num = rand() % 98 + 1;
    uniqueNumbers.insert(num);
  }
  // divide first 20 into actPos
  // divide second half into endPos
  for (num : uniqueNumbers){
    if (num % 2 == 0) {

    }
    if (num % 2 == 1) {
      
    }
    
  }  
}    

void Board::setBoard(){

}
//Fills the board with generated snakes and ladders.
void Board::fillBoard(){ 
}

//returns if tile is special
bool Board::isSpecial(tile* pPos){

}

//Returns head for use in player class.
// tile* Board::getHead(){

// }

//friend class game;
//Allows game class to access private elements