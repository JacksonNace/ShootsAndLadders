#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include "Board_t.h"
#include "player.h"

Player::Player(std::string pName, Board* board)
    {
    board = board;
    pos = board->getHead();
    name = pName;
    sStat = 0;
    lStat = 0;
    mStat = 0;
    tStat = 0;
    fin = false;

    }

void Player::tileType()
    {
    if(Board::isSpecial(pos))
        {
        unsigned int start = pos->pos;
        unsigned int end = pos->movement->pos;
        if(start > end)
            {
            printSnakeHit(start,end);
            tStat += start - end;
            sStat++;
            pos = pos->movement;
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            }
        else if(end > start)
            {
            printLadderHit(start,end);
            tStat += end - start;
            lStat++;
            pos = pos->movement;
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            }
        }
    }

void Player::move(unsigned int roll)
    {


    std::cout << name + " rolled a " << roll << "." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(750));

    mStat++;
    while(pos->next != nullptr && roll > 0)
        {
        pos = pos->next;
        roll--;
        tStat++;
        }
    
    if(pos->next == nullptr)//Checks if it is at the end
        {
        fin = true;
        }

    tileType();

    std::cout << name + " is now on tile " << pos->pos << "." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    }

 void Player::printSnakeHit(unsigned int start, unsigned int end)
    {
    std::cout << name + " landed on a snake. They have moved from tile " << start << " to tile " << end <<"." << std::endl;
    }

 void Player::printLadderHit(unsigned int start, unsigned int end)
    {
    std::cout << name + " landed on a ladder. They have moved from tile " << start << " to tile " << end <<"." << std::endl;
    }

bool Player::isFinished()
    {
    return fin;
    }

void Player::printStats()
    {
    std::cout << "[" + name + "'s Stats || Snakes Hit: " << sStat << " || Ladders Hit: " << lStat << " || Number of Roles: " << mStat << " || Total Spaces Moved: " << tStat << "]" << std::endl;
    }
/*
Player::~Player()
    {
    delete pos;
    //delete board;
    }
*/