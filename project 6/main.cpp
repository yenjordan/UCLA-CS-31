//
//  main.cpp
//
//
#include <cassert>
#include <iostream>
#include "Beetle.h"
#include "BeetleGame.h"
#include "BeetleDrawing.h"
#include "Die.h"

void clearScreen();

int main()
{
    using namespace cs31;
    using namespace std;
    
    clearScreen();
    
    BeetleGame game;

    // sample test code working with Die
             Die d;
             d.roll();
             int value = d.getValue();
             assert( value >= 1 && value <= 6 );

             // sample test code working with Beetle
             Beetle b;

             // beetle does what you tell it to do, not enforce rules of the game.  
             // rules of the game are left to BeetleGame to implement

             assert( b.hasHead() == false );
             assert( b.isComplete() == false );
             b.buildHead();
             assert( b.hasHead() );
             assert( b.isComplete() == false );

             // build Leg1 before Leg2 before Leg3 before Leg4
             assert( b.hasLeg1() == false );
             assert( b.hasLeg2() == false );
             assert( b.hasLeg3() == false );
             assert( b.hasLeg4() == false );
             assert( b.isComplete() == false );
             b.buildLeg();
             assert( b.hasLeg1() );
             assert( b.hasLeg2() == false );
             assert( b.hasLeg3() == false );
             assert( b.hasLeg4() == false );
             b.buildLeg();
             assert( b.hasLeg1() );
             assert( b.hasLeg2() );
             assert( b.hasLeg3() == false );
             assert( b.hasLeg4() == false );
             b.buildLeg();
             assert( b.hasLeg1() );
             assert( b.hasLeg2() );
             assert( b.hasLeg3() );
             assert( b.hasLeg4() == false );
             b.buildLeg();
             assert( b.hasLeg1() );
             assert( b.hasLeg2() );
             assert( b.hasLeg3() );
             assert( b.hasLeg4() );
             assert( b.isComplete() == false );

             // build Eye1 before Eye2
             assert( b.hasEye1() == false );
             assert( b.hasEye2() == false );
             assert( b.isComplete() == false );
             b.buildEye();
             assert( b.hasEye1() );
             assert( b.hasEye2() == false );
             b.buildEye();
             assert( b.hasEye1() );
             assert( b.hasEye2() );
             assert( b.isComplete() == false );

             assert( b.hasTail() == false );
             assert( b.isComplete() == false );
             b.buildTail();
             assert( b.hasTail() );
             assert( b.isComplete() == false );

             // build Antenna1 before Antenna2
             assert( b.hasAntenna1() == false );
             assert( b.hasAntenna2() == false );
             assert( b.isComplete() == false );
             b.buildAntenna();
             assert( b.hasAntenna1() );
             assert( b.hasAntenna2() == false );
             b.buildAntenna();
             assert( b.hasAntenna1() );
             assert( b.hasAntenna2() );
             assert( b.isComplete() == false );

             assert( b.hasBody() == false );
             assert( b.isComplete() == false );
             b.buildBody();
             assert( b.hasBody() );
             assert( b.isComplete() == true );

             // cheating play
             BeetleGame bGame;
             assert( game.gameIsOver() == false );
             bGame.humanRoll( 1 );
             bGame.humanPlay();
             bGame.computerRoll( 1 );
             bGame.computerPlay();
             assert( bGame.getHumanBeetle().isComplete() == false );
             assert( bGame.getHumanBeetle().hasBody() == false );
             assert( bGame.getComputerBeetle().isComplete() == false );
             assert( bGame.getComputerBeetle().hasBody() == false );
             assert( bGame.gameIsOver() == false );
             bGame.humanRoll( 6 );
             bGame.humanPlay();
             bGame.computerRoll( 6 );
             bGame.computerPlay();
             assert( bGame.getHumanBeetle().isComplete() == false );
             assert( bGame.getHumanBeetle().hasBody() );
             assert( bGame.getComputerBeetle().isComplete() == false );
             assert( bGame.getComputerBeetle().hasBody() );

             cout << "all tests passed!" << endl; 

    std::string action, spots, message = "(r)oll (q)uit: ";

    
    do
    {
        cout << game.display( message ) << endl;
        cin.clear();
        getline( cin, action );
        while (action.size() == 0)
        {
            getline( cin, action );  // no blank entries allowed....
        }
        switch (action[0])
        {
            default:   // if bad move, nobody moves
                cout << '\a' << endl;  // beep
                continue;
            case 'Q':
            case 'q':
                exit( 0 );
                break;
            case 'r':
            case 'R':
                game.humanRoll();
                cout << "human rolled:" << game.getHumanDie() << endl;
                if (game.humanPlay( ))
                {
                }
                else
                {
                    cout << "no Human move possible!" << endl;
                }
                game.computerRoll();
                cout << "computer rolled:" << game.getComputerDie() << endl;
                if (game.computerPlay())
                {
                }
                else
                {
                    cout << "no Computer move possible!" << endl;
                }
                break;
        }
    } while( !game.gameIsOver() );
    cout << game.display( ) << endl;
    cout << game.stringifyGameOutcome() << endl;

    return( 0 );
}



void clearScreen();



///////////////////////////////////////////////////////////////////////////
//  clearScreen implementations
///////////////////////////////////////////////////////////////////////////

// DO NOT MODIFY OR REMOVE ANY CODE BETWEEN HERE AND THE END OF THE FILE!!!
// THE CODE IS SUITABLE FOR VISUAL C++, XCODE, AND g++ UNDER LINUX.

// Note to Xcode users:  clearScreen() will just write a newline instead
// of clearing the window if you launch your program from within Xcode.
// That's acceptable.

#ifdef _MSC_VER  //  Microsoft Visual C++

#include <windows.h>

void clearScreen()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    COORD upperLeft = { 0, 0 };
    DWORD dwCharsWritten;
    FillConsoleOutputCharacter(hConsole, TCHAR(' '), dwConSize, upperLeft,
                               &dwCharsWritten);
    SetConsoleCursorPosition(hConsole, upperLeft);
}

#else  // not Microsoft Visual C++, so assume UNIX interface

#include <cstring>

void clearScreen()  // will just write a newline in an Xcode output window
{
    using namespace std;
    static const char* term = getenv("TERM");
    if (term == nullptr  ||  strcmp(term, "dumb") == 0)
    {
        cout << endl << endl << endl << endl << endl << endl << endl << endl;
    }
    else
    {
        static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
        cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
    }
}

#endif
