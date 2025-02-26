#include "board.h"
#include "player.h"
#include <string>
#include <iostream>
#include <ctime>
#include <random>

int main()
    {
    Board board;//Constructs the board.
    std::string p1 = "Player1";
    Player player1(p1, board);//Constructs player 1 and passes the board object.
    std::string p2 = "Player2";
    Player player2(p2,board);//Constructs player 2 and passes the board object.

    std::cout << "              Snakes & Ladders" << std::endl;
    std::cout << "____________________________________________" << std::endl;

    srand(time(0));

    while(player1.isFinished() == false && player2.isFinished() == false)
        {
        std::cout << "Press R to roll" << std::endl;

        /*
        I need to implement a pause in the loop to allow for players to roll.
        This will likely take time.
        */
        std::string input = "";
        while(input != "R" && input != "r")
            {
            std::cin >> input;
            }

        unsigned int roll1 = rand() % 6 + 1;
        unsigned int roll2 = rand() % 6 + 1;

        player1.move(roll1);
        player2.move(roll2);
        }

    if(player1.isFinished() == true && player2.isFinished() == true)
        {
        std::cout << "It's a tie." << std::endl;
        }
    else if(player1.isFinished() == true)
        {
        std::cout << p1 << " is the winner." << std::endl;
        }
    else if(player2.isFinished() == true)
        {
        std::cout << p2 << " is the winner." << std::endl;
        }

    player1.printStats();
    player2.printStats();

    //I need to create deconstructors for player and board.

    }