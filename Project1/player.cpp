// ----------------------------------------------------------------------------
// hangman - player.cpp                                                  v. 1.0
//                                                                   6 May 2015
// Player class                                           Author: Robert Willis
//
// Player class stores, adds to and returns a list of all guesses the player
// has taken (guesses),  as well as the current amount of correct letters
// guessed and their placement in relation to the answer (partial answer).
// ----------------------------------------------------------------------------
#include "player.h"

// ----------------------------------------------------------------------------
// Player class
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// setPartialAnswer(int answerLength)
//
// Fills each element of partialAnswer array with '_' string to size
// of the answer (representing no current correct player guesses).
// ----------------------------------------------------------------------------
void Player::setPartialAnswer(int answerLength)
{
	// For length of the answer
	for (int i = 0; i < answerLength; ++i)
		// Add index to partialAnswer with value "_"
		partialAnswer.push_back("_");
}

// ----------------------------------------------------------------------------
// addGuess()
//
// Add input string to guesses.
// ----------------------------------------------------------------------------
void Player::addGuess(Guess guess)
{
	guesses.push_back(guess);
}

// ----------------------------------------------------------------------------
// updatePartialAnswer()
//
// Update partial answer at index i with provided char string.
// ----------------------------------------------------------------------------
void Player::updatePartialAnswer(int i, string guess)
{
	partialAnswer[i] = guess;
}

// ----------------------------------------------------------------------------
// getGuesses()
//
// Return guesses as list.
// ----------------------------------------------------------------------------
list<Guess> & Player::getGuesses()
{
	return guesses;
}

// ----------------------------------------------------------------------------
// getPartialAnswer()
//
// Get partialAnswer as vector.
// ----------------------------------------------------------------------------
vector<string> Player::getPartialAnswer()
{
	return partialAnswer;
}

// ----------------------------------------------------------------------------
// getPartialAnswerString()
//
// Get partialAnswer as string.
// ----------------------------------------------------------------------------
string Player::getPartialAnswerString()
{
	string returnString;

	// Set size type of i to string to iterate through vector
	// avoids compiler warning re: int/const comparison
	for (vector<string>::size_type i = 0; i < partialAnswer.size(); ++i)
		// Append partialAnswer at index value to returnString
		returnString += partialAnswer[i];

	return returnString;
}
