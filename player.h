//I, Jackson Nace ID 2300153 worked with Hayden Vontz 2486072 on this project. Both of us are in the 8:30 section on T/TH


#include <string>
#include "board.h"


#ifndef Player_H
#define Player_H


/*Player will serve as the point of interaction for the main method. All methods that change the game state will be called
through player. This is a friend class of board allowing access to the private elements of board.*/
class Player
    {
    private:

    Board::tile* pos;//Holds the position of the player on the board.
    unsigned int sStat;//Number of times snakes were hit
    unsigned int lStat;//Number of times ladders were hit
    unsigned int mStat;//Total number of roles performed
    unsigned int tStat;//Total tiles moved, includes movement from snakes and ladders
    bool fin;
    std::string name;
    //Board* brd;
    
    //Checks what type of tile was hit if special is true. Increases appropriate
    void tileType();

    void printSnakeHit(unsigned int start, unsigned int end);//When a snake is hit, this will print the location of the snake and the player's new position.

    void printLadderHit(unsigned int start, unsigned int end);//When a ladder is hit, this will print the location of the ladder and the player's new position.

    public:


    Player(std::string pName, Board board);

    void printStats();

    //This will move the player according to the roll as well as perform the checks for special tiles.
    void move(unsigned int roll);

    bool isFinished();//Returns true if player reaches end of board. Used to end game.

    ~Player();//Deconstructor


    
    };

#endif