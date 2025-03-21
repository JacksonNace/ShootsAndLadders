#include "Board_t.h"
#include <iostream>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <thread>

//Generates 40 rand num of different values to act as the snakes and ladders
void Board::genMove() {
  srand(time(0));
  unordered_set<unsigned int> uniqueNumbers; // iterate over a set of 40 numbers and put them into proper vectors
  while (uniqueNumbers.size() < 40) {
    unsigned int num = rand() % 98 + 2;
    uniqueNumbers.insert(num);
  }

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
    //std::cout << count << std::endl;
    count++;
  



  actPos.resize(20);
  endPos.resize(20);

  actPos.erase(remove(actPos.begin(), actPos.end(), 0), actPos.end());
  endPos.erase(remove(endPos.begin(), endPos.end(), 0), endPos.end());

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

  for (unsigned int i = 2; i <= 100; ++i) {
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
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
  std::cout << std::endl << "      ╔═══════════════════════════════╗";
  std::this_thread::sleep_for(std::chrono::milliseconds(500));  
  std::cout << std::endl << "      ║  Generating Snakes & Ladders  ║" << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
  std::cout << "      ╠═══════════════════════════════╣"<< std::endl;
  for (size_t i = 0; i < actPos.size(); ++i) {
    std::this_thread::sleep_for(std::chrono::milliseconds(250));
    tile* startTile = head;
    while (startTile != nullptr && startTile->pos != actPos[i]) {
      startTile = startTile->next;
    }
    //std::cout << actPos[i] << "->";
    tile* endTile = head;
    while (endTile != nullptr && endTile->pos != endPos[i]) {
      endTile = endTile->next;
    }
    //std::cout << endPos[i] << std::endl;
    if (startTile != nullptr && endTile != nullptr) {
      startTile->special = true;
      startTile->movement = endTile;

    }

    if (actPos[i] > endPos[i])
      {
      std::cout << "      ║There is a Snake  from "; //<< actPos[i] << " to " << endPos[i];
      if ( actPos[i] < 10)
        {std::cout << " ";}
      std::cout << actPos[i] << " to ";
      if (endPos[i] < 10)
        {std::cout << " ";}
      std::cout << endPos[i];
      }
    else  
      {
      std::cout << "      ║There is a Ladder from ";
      if ( actPos[i] < 10)
        {std::cout << " ";}
      std::cout << actPos[i] << " to ";
      if (endPos[i] < 10)
        {std::cout << " ";}
      std::cout << endPos[i];
      }
    std::cout << "║       " << std::endl;
  }//——￣
  //std::cout << "____________________________________________"<< std::endl;
    std::cout << "      ╚═══════════════════════════════╝"<< std::endl; 
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << std::endl;
}

//returns if tile is special
bool Board::isSpecial(tile* pPos) {
  if (pPos == nullptr) return false;
  return pPos->special;
}

Board::~Board()
    {
    //delete actPos;
    tile* current = head;
  
    
    while(current)
      {
      tile* temp = current;
      //temp->next = nullptr;
      current = current->next;
      //current->prev = nullptr;
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