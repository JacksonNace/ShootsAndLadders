#include <string>
#include <cstdlib>
#include <unordered_set>
using namespace std;


#ifndef Board_H
#define Board_H

class Board
  {
  private:
  struct tile//Structure that holds the information of the tile.
    {
    unsigned int pos;
    tile* next;
    tile* prev;
    bool special;
    tile* movement;

    tile() : pos(0), special(false), next(nullptr), prev(nullptr), movement(nullptr) {}
    };

  const unsigned int size = 100;
  tile* head;
  tile* tail;

  unsigned int actPos[20];
  unsigned int endPos[20];  

  void genMove();//Generates 40 rand num of different values to act as the snakes and ladders
    

  void setBoard();//Creates the linked list of size 100 to act as the board.

  void fillBoard();//Fills the board with generated snakes and ladders.

  bool isSpecial(tile* pPos);//returns if tile is special

  tile* getHead(){//Returns head for use in player class.
    return head;
  }

  public:

  //friend class game;//Allows game class to access private elements

  friend class Player;//Allows player class to access private elements

  Board(){//Only public method of this class. It creates the board. May set to private though...
    genMove();
    setBoard();
    fillBoard();
  };




  //tile* getStart();


  };







#endif