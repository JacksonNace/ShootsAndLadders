#include <iostream>
#include <string>
#include "board.h"
#include "player.h"

using namespace std;

Player::Player(string pName, Board& board) : gameBoard(board){
  pos = gameBoard.getHead(); // originally you had Board:: isSpecial(pos) on this buts its a member of the board class
  // and you need an instance of the board class to call it. You had the polayer class passing the board object as a copy, not the original
  name = pName;
  sStat = 0;
  lStat = 0;
  mStat = 0;
  tStat = 0;
  fin = false;
}

void Player::tileType()
{
  if (gameBoard.isSpecial(pos)){
    unsigned int start = pos->pos;
    unsigned int end = pos->movement->pos;
    if (start > end)
    {
      printSnakeHit(start, end);
      tStat += start - end;
      sStat++;
      pos = pos->movement;
    }
    else if (end > start)
    {
        printLadderHit(start, end);
        tStat += end - start;
        lStat++;
        pos = pos->movement;
    }
  }
}

void Player::move(unsigned int roll)
{
  if (roll == 1)
  {
    cout << name + " rolled an " << roll << "." << endl;
  }
  else
  {
    cout << name + " rolled a " << roll << "." << endl;
  }

  mStat++;
  while (pos->next != nullptr && roll > 0)
  {
    pos = pos->next;
    roll--;
    tStat++;
  }

  if (pos->next == nullptr)
  {
    fin = true;
  }

  tileType();

  cout << name + " is now on tile " << pos->pos << "." << endl;
}

void Player::printSnakeHit(unsigned int start, unsigned int end)
{
  cout << name + " landed on a snake. They have moved from tile " << start << " to tile " << end << "." << endl;
}

void Player::printLadderHit(unsigned int start, unsigned int end)
{
  cout << name + " landed on a ladder. They have moved from tile " << start << " to tile " << end << "." << endl;
}

bool Player::isFinished()
{
  return fin;
}

void Player::printStats()
{
  cout << "[" + name + "'s Stats || Snakes Hit: " << sStat << " || Ladders Hit: " << lStat << " || Number of Roles: " << mStat << " || Total Spaces Moved: " << tStat << "]" << endl;
}

Player::~Player()
{
}