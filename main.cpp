// main.cpp
#include "board.h"
#include "player.h"
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib> // For rand() and srand()

using namespace std;

int main(){
  Board board; // Constructs the board.
  string p1 = "Player1";
  Player player1(p1, board); // Constructs player 1 and passes the board object.
  string p2 = "Player2";
  Player player2(p2, board); // Constructs player 2 and passes the board object.

  cout << "                Snakes & Ladders" << endl;
  cout << "____________________________________________" << endl;

  srand(static_cast<unsigned int>(time(0))); // Seed the random number generator

  while (!player1.isFinished() && !player2.isFinished())
  {
    cout << "Press R to roll" << endl;

    string input = "";
    while (input != "R" && input != "r")
    {
      cin >> input;
    }

    unsigned int roll1 = rand() % 6 + 1;
    player1.move(roll1);

    if(!player1.isFinished() && !player2.isFinished())
    {
      cout << "Press R to roll" << endl;

      input = "";
      while (input != "R" && input != "r")
      {
        cin >> input;
      }

      unsigned int roll2 = rand() % 6 + 1;
      player2.move(roll2);
    }
  }

  if (player1.isFinished() && player2.isFinished())
  {
    cout << "It's a tie." << endl;
  }
  else if (player1.isFinished())
  {
    cout << p1 << " is the winner." << endl;
  }
  else if (player2.isFinished())
  {
    cout << p2 << " is the winner." << endl;
  }

  player1.printStats();
  player2.printStats();

  return 0;
}