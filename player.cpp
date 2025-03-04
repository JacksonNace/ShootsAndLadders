//I, Jackson Nace ID 2300153 worked with Hayden Vontz 2486072 on this project. Both of us are in the 8:30 section on T/TH


#include <string>
#include <iostream>
#include "board.h"
#include "player.h"

Player::Player(std::string pName, Board board)
    {
    pos = board.getHead();
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
            }
        else if(end > start)
            {
            printLadderHit(start,end);
            tStat += end - start;
            lStat++;
            pos = pos->movement;
            }
        }
    }

void Player::move(unsigned int roll)
    {
    if(roll == 1)
        {
        std::cout << name + " rolled an " << roll << "." << std::endl;
        }
    else//Grammer    
        {
        std::cout << name + " rolled a " << roll << "." << std::endl;
        }

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
    }

 void Player::printSnakeHit(unsigned int start, unsigned int end)
    {
    std::cout << name + " landed on a snake. They have moved from tile" << start << " to tile" << end <<"." << std::endl;
    }

 void Player::printLadderHit(unsigned int start, unsigned int end)
    {
    std::cout << name + " landed on a ladder. They have moved from tile" << start << " to tile" << end <<"." << std::endl;
    }

bool Player::isFinished()
    {
    return fin;
    }

void Player::printStats()
    {
    std::cout << "[" + name + "'s Stats || Snakes Hit: " << sStat << " || Ladders Hit: " << lStat << " || Number of Roles: " << mStat << " || Total Spaces Moved: " << tStat << "]" << std::endl;
    }

Player::~Player()
    {
    pos = nullptr;
    }