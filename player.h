#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "board.h"
using namespace std;

/*Player will serve as the point of interaction for the main method. All methods that change the game state will be called
through player. This is a friend class of board allowing access to the private elements of board.*/
class Player {
private:

  Board::tile* pos;//Holds the position of the player on the board.
  unsigned int sStat;//Number of times snakes were hit
  unsigned int lStat;//Number of times ladders were hit
  unsigned int mStat;//Total number of roles performed
  unsigned int tStat;//Total tiles moved, includes movement from snakes and ladders
  bool fin;
  string name;
  //Board* brd;

  //Checks what type of tile was hit if special is true. Increases appropriate
  void tileType();
  void printSnakeHit(unsigned int start, unsigned int end);//When a snake is hit, this will print the location of the snake and the player's new position.
  void printLadderHit(unsigned int start, unsigned int end);//When a ladder is hit, this will print the location of the ladder and the player's new position.

  public:
  Player(std::string pName, Board board);
  void printStats();
  void move(unsigned int roll); //This will move the player according to the roll as well as perform the checks for special tiles.
  bool isFinished();//Returns true if player reaches end of board. Used to end game.
  ~Player();//Deconstructor
};
#endif