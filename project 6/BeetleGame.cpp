//
//  BeetleGame.cpp
//

#include "BeetleGame.h"
#include "BeetleDrawing.h"

#include <iostream>

namespace cs31
{

BeetleGame::BeetleGame() : mHuman(), mComputer(), mHumanDie(), mComputerDie()
{
    
}

// draw the board by using a BeetleDrawing to draw the two Beetles
std::string BeetleGame::display( std::string msg ) const
{
    BeetleDrawing drawing( mHuman, mComputer );
    std::string result = drawing.draw() + "\n" + msg;
    return( result );
}


// when amount is zero, it is a random roll...
// otherwise, an amount value is a cheating value...
void BeetleGame::humanRoll( int amount )
{
    if (amount == 0)
    {
        mHumanDie.roll();
    }
    else
    {
        mHumanDie.setValue(amount);
    }
}

// return the value of the Human's die
int BeetleGame::getHumanDie( ) const
{
    return(mHumanDie.getValue());
}

// convert the Human's die value to a Beetle's body part
// then depending on the body part involved, enforce the game ordering of body parts:
// - namely, body before everything else and head before eyes or antenna
// if allowed, build the desired body part on the Human's beetle
// if a body part was successfully built, return true
// otherwise, return false
bool BeetleGame::humanPlay( )
{
    int dieValue = getHumanDie();

    if (dieValue == 6)
    {
        if (!mHuman.hasBody()) {
            mHuman.buildBody();
            return mHuman.hasBody(); // checks if body was successfully built
        }
    }
    else if (dieValue == 5)
    {
        if (mHuman.hasBody())  // checks if body has been built before building head
        {
            mHuman.buildHead();
            return mHuman.hasHead(); // checks if head was successfully built
        }
    }
    else if (dieValue == 4)
    {
        if (mHuman.hasBody())  // checks if body has been built before building tail
        {
            mHuman.buildTail();
            return mHuman.hasTail(); // checks if tail was successfully built
        }
    }
    else if (dieValue == 3)
    {
        if (mHuman.hasBody())  // checks if body has been built before building leg(s)
        {
            mHuman.buildLeg();
            return mHuman.hasLeg1() || mHuman.hasLeg2() || mHuman.hasLeg3() || mHuman.hasLeg4(); // checks if leg(s) were successfully built
        }
    }
    else if (dieValue == 2)
    {
        if (mHuman.hasHead())  // checks if head has been built before building antenna(s)
        {
            mHuman.buildAntenna();
            return mHuman.hasAntenna1() || mHuman.hasAntenna2(); // checks if antenna(s) were successfully built
        }
    }
    else if (dieValue == 1)
    {
        if (mHuman.hasHead())  // checks if head has been built before building eye(s)
        {
            mHuman.buildEye();
            return mHuman.hasEye1() || mHuman.hasEye2(); // checks if eye(s) were successfully built
        }
    }

    return false; // default case
}

// when amount is zero, it is a random roll...
// otherwise, an amount value is a cheating value...
void BeetleGame::computerRoll( int amount )
{
    if( amount == 0 )
    {
        mComputerDie.roll();
    }
    else
    {
        mComputerDie.setValue( amount );
    }
}

// return the value of the Computer's die
int BeetleGame::getComputerDie( ) const
{
    return(mComputerDie.getValue());
}

// convert the Computer's die value to a Beetle's body part
// then depending on the body part involved, enforce the game ordering of body parts:
// - namely, body before everything else and head before eyes or antenna
// if allowed, build the desired body part on the Computer's beetle
// if a body part was successfully built, return true
// otherwise, return false
bool BeetleGame::computerPlay()
{
    int dieValue = getComputerDie();

    if (dieValue == 6)
    {
        if (!mComputer.hasBody()) {
            mComputer.buildBody();
            return mComputer.hasBody(); // checks if body was successfully built
        }
    }
    else if (dieValue == 5)
    {
        if (mComputer.hasBody())  // checks if body has been built before building head
        {
            mComputer.buildHead();
            return mComputer.hasHead(); // checks if head was successfully built
        }
    }
    else if (dieValue == 4)
    {
        if (mComputer.hasBody())  // checks if body has been built before building tail
        {
            mComputer.buildTail();
            return mComputer.hasTail(); // checks if tail was successfully built
        }
    }
    else if (dieValue == 3)
    {
        if (mComputer.hasBody())  // checks if body has been built before building leg(s)
        {
            mComputer.buildLeg();
            return mComputer.hasLeg1() || mComputer.hasLeg2() || mComputer.hasLeg3() || mComputer.hasLeg4(); // checks if leg(s) were successfully built
        }
    }
    else if (dieValue == 2)
    {
        if (mComputer.hasHead())  // checks if head has been built before building antenna(s)
        {
            mComputer.buildAntenna();
            return mComputer.hasAntenna1() || mComputer.hasAntenna2(); // checks if antenna(s) were successfully built
        }
    }
    else if (dieValue == 1)
    {
        if (mComputer.hasHead())  // checks if head has been built before building eye(s)
        {
            mComputer.buildEye();
            return mComputer.hasEye1() || mComputer.hasEye2(); // checks if eye(s) were successfully built
        }
    }

    return false; // default case
}


// what is the current state of the game
BeetleGame::GameOutcome  BeetleGame::determineGameOutcome( ) const
{
    if (mHuman.isComplete())
    {
        return GameOutcome::HUMANWONGAME;
    }
    else if (mComputer.isComplete())
    {
        return GameOutcome::COMPUTERWONGAME;
    }
    else
    {
        return GameOutcome::GAMENOTOVER;
    }   
}


std::string  BeetleGame::stringifyGameOutcome( ) const
{
    std::string result = "";
    switch( determineGameOutcome() )
    {
        case GameOutcome::COMPUTERWONGAME:
            result = "Computer Won!";
            break;
        case GameOutcome::HUMANWONGAME:
            result = "Human Won!";
            break;
        case GameOutcome::GAMENOTOVER:
            result = "Game Not Over!";
            break;
    }
    return( result );
}

// has the game ended with a winner?
bool BeetleGame::gameIsOver() const
{
    return( determineGameOutcome() != GameOutcome::GAMENOTOVER ); // returns true if the game outcome is not "Game Not Over" and false if the game outcome is "Game Not Over"
}


Beetle BeetleGame::getHumanBeetle( ) const
{
    return( mHuman );
}

Beetle BeetleGame::getComputerBeetle( ) const
{
    return( mComputer );
}

}


