// ----------------------------------------------------------------------------
// hangman - player.h                                                    v. 1.0
//                                                                   6 May 2015
// Player class                                           Author: Robert Willis
//
// Player class stores, adds to and returns a list of all guesses the player
// has taken (guesses),  as well as the current amount of correct letters
// guessed and their placement in relation to the answer (partial answer).
// ----------------------------------------------------------------------------
#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

#include <string>
#include <list>
#include <vector>
#include "guess.h"

// ----------------------------------------------------------------------------
// Player class
// ----------------------------------------------------------------------------
class Player
{

private:

	// Stores both letter and word guesses
	list<Guess> guesses;

	// Players current partial answer as array of chars as string
	// e.g. If word="test" and player has guessed "e", partialAnswer="_e__"
	vector<string> partialAnswer;

public:

	// Fills each element of partialAnswer array with '_' string to size
	// of the answer (representing no current correct player guesses).
	void setPartialAnswer(int answerLength);


	// Add input string to guesses.
	void addGuess(Guess guess);

	// Update partial answer at index i with provided char as string.
	void updatePartialAnswer(int i, string guess);


	// Return guesses as list.
	list<Guess> & getGuesses();

	// Get partialAnswer as vector.
	vector<string> getPartialAnswer();
	// Get partialAnswer as string.
	string getPartialAnswerString();

};

#endif
