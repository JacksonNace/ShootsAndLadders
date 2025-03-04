//I, Jackson Nace ID 2300153 worked with Hayden Vontz 2486072 on this project. Both of us are in the 8:30 section on T/TH


#include "board.h"
#include <iostream>
#include <algorithm>
#include <ctime>

//Generates 40 rand num of different values to act as the snakes and ladders
void Board::genMove() {
  
  unordered_set<unsigned int> uniqueNumbers; // iterate over a set of 40 numbers and put them into proper vectors
  while (uniqueNumbers.size() < 40) {
    unsigned int num = rand() % 98 + 2;
    uniqueNumbers.insert(num);
  }
/*
  actPos.resize(20);
  endPos.resize(20);

  int count = 0;
  for (unsigned int num : uniqueNumbers) {
    
      if (count % 2 == 0) { // odd numbers go into the vector actPos
          
          actPos.push_back(num);
      }
    
      else if (count % 2 == 1) { // even numbers go into the vector endPos
          endPos.push_back(num);
      }
    }
    std::cout << count << std::endl;
    count++;
  }

*/

  actPos.resize(20);
  endPos.resize(20);

  //actPos.erase(remove(actPos.begin(), actPos.end(), 0), actPos.end());
  //endPos.erase(remove(endPos.begin(), endPos.end(), 0), endPos.end());

  vector<unsigned int> allUnique(uniqueNumbers.begin(), uniqueNumbers.end());
  int actIndex = 0;
  int endIndex = 0;

  while (actPos.size() < 20) {
    if (actIndex % 2 == 1 && find(actPos.begin(), actPos.end(), allUnique[actIndex]) == actPos.end()){
      actPos.push_back(allUnique[actIndex]);
    }
    actIndex++;
  }

  while (endPos.size() < 20) {
    if (endIndex % 2 == 0 && find(endPos.begin(), endPos.end(), allUnique[endIndex]) == endPos.end())
    {
      endPos.push_back(allUnique[endIndex]);
    }
    endIndex++;
  }

}

void Board::setBoard() {
  
  head = new tile();
  head->pos = 1;
  tile* current = head;

  for (unsigned int i = 2; i <= size; ++i) {
    tile* newTile = new tile();
    newTile->pos = i;
    current->next = newTile;
    newTile->prev = current;
    current = newTile;
  }

  tail = current;

  
}

//Fills the board with generated snakes and ladders.
void Board::fillBoard() {
  
  for (size_t i = 0; i < actPos.size(); ++i) {
    tile* startTile = head;
    while (startTile != nullptr && startTile->pos != actPos[i]) {
      startTile = startTile->next;
    }

    tile* endTile = head;
    while (endTile != nullptr && endTile->pos != endPos[i]) {
      endTile = endTile->next;
    }

    if (startTile != nullptr && endTile != nullptr) {
      startTile->special = true;
      startTile->movement = endTile;
    }
  }
}

//returns if tile is special
bool Board::isSpecial(tile* pPos) {
  if (pPos == nullptr) return false;
  return pPos->special;
}

Board::~Board()
    {
    tile* current = head;
    while(current)
      {
      tile* temp = current;
      current = current->next;
      delete temp;
      }    
    //head = nullptr;
    //tail = nullptr;
    }

//Returns head for use in player class.
// tile* Board::getHead(){

// }

//friend class game;
//Allows game class to access private elements