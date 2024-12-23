//
//  BeetleGame.h
//
//

#ifndef BeetleGameH
#define BeetleGameH
#include <string>

#include "Beetle.h"
#include "Die.h"

namespace cs31
{
    
    class BeetleGame
    {
    public:
        BeetleGame();
        
        // the possible outcome choices
        enum class GameOutcome { HUMANWONGAME, COMPUTERWONGAME, GAMENOTOVER };
        
        // draw the board by using a BeetleDrawing to draw the two Beetles
        std::string display( std::string msg = "" ) const;
        
        // when amount is zero, it is a random roll...
        // otherwise, an amount value is a cheating value...
        void humanRoll( int amount = 0 );
        
        // return the value of the Human's die
        int getHumanDie( ) const;
        
        // convert the Human's die value to a Beetle's body part and
        // if possible, build the desired body part on the Human's beetle
        bool humanPlay( );
        
        // when amount is zero, it is a random roll...
        // otherwise, an amount value is a cheating value...
        void computerRoll( int amount = 0 );
        
        // return the value of the Computer's die
        int getComputerDie( ) const;
        
        // convert the Computer's die value to a Beetle's body part and
        // if possible, build the desired body part on the Computer's beetle
        bool computerPlay( );
        
        // what is the current state of the game
        GameOutcome  determineGameOutcome( ) const;
        std::string  stringifyGameOutcome( ) const;
        // has the game ended with a winner?
        bool gameIsOver() const;
        
        // for testing purposes
        Beetle getHumanBeetle( ) const;
        Beetle getComputerBeetle( ) const;
    private:
        Beetle mHuman,    mComputer;
        Die    mHumanDie, mComputerDie;
    };
    
}

#endif
