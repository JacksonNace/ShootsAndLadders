#include "board.h"
#include "player.h"
#include <string>
#include <chrono>
#include <thread>
#include <iostream>
#include <ctime>
#include <random>

int main()
    {
    std::cout << "              Snakes & Ladders" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "____________________________________________" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    Board board;//Constructs the board.
    std::string p1 = "Player1";
    Player player1(p1, &board);//Constructs player 1 and passes the board object.
    std::string p2 = "Player2";
    Player player2(p2, &board);//Constructs player 2 and passes the board object.



    srand(time(0));

    while(player1.isFinished() == false && player2.isFinished() == false)
        {
        std::this_thread::sleep_for(std::chrono::milliseconds(250));

        std::cout << std::endl << "╔═══════════════╗" << std::endl;
        std::cout << "║Press R to roll║" << std::endl;
        std::cout << "╚═══════════════╝"<< std::endl;
        /*
        I need to implement a pause in the loop to allow for players to roll.
        This will likely take time.
        */
        std::string input = "";
        while(input != "R" && input != "r")
            {
            std::cin >> input;
            }
        //std::cout << "\r" << std::endl;
        //std::cout << "\r" << std::string(1, ' ') << "\r" <<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
        std::cout << "\x1b[1A\x1b[K" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        unsigned int roll1 = rand() % 6 + 1;
        unsigned int roll2 = rand() % 6 + 1;

        player1.move(roll1);
        std::cout << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
        player2.move(roll2);
        }

    std::this_thread::sleep_for(std::chrono::milliseconds(750));
    if(player1.isFinished() == true && player2.isFinished() == true)
        {
        std::cout << std::endl << "It's a tie." << std::endl;
        }
    else if(player1.isFinished() == true)
        {
        std::cout<< std::endl << p1 << " is the winner." << std::endl;
        }
    else if(player2.isFinished() == true)
        {
        std::cout << std::endl << p2 << " is the winner." << std::endl;
        }
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    player1.printStats();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    player2.printStats();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    //I need to create deconstructors for player and board.

    }