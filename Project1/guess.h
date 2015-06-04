// ----------------------------------------------------------------------------
// hangman - guess.h                                                     v. 1.0
//                                                                   6 May 2015
// Guess class                                            Author: Robert Willis
//
// Stores guesses made by the player as a string.
// ----------------------------------------------------------------------------
#ifndef GUESS_H
#define GUESS_H

using namespace std;

#include <string>

// ----------------------------------------------------------------------------
// Guess class
// ----------------------------------------------------------------------------
class Guess
{

private:

	// Guess player has input.
	string guess;

public:

	// Constructor.
	Guess(string guess);

	// Get guess.
	string & getGuess();

};

#endif
