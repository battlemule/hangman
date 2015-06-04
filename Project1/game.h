// ----------------------------------------------------------------------------
// hangman - game.h                                                      v. 1.0
//                                                                   6 May 2015
// Game class                                             Author: Robert Willis
//
// Game class acts as the main container and driver for all elements of the
// hangman game. It creates and stores an instance of answer, player and
// man and updates and prints each in response to calls from main().
// ----------------------------------------------------------------------------
#ifndef GAME_H
#define GAME_H

using namespace std;

#include <string>
#include <list>
#include <iterator>

#include "answer.h"
#include "man.h"
#include "player.h"

// ----------------------------------------------------------------------------
// Game class
// ----------------------------------------------------------------------------
class Game
{

private:

	// Stores an answer, man and player for each game.
	Answer answer;
	Man man;
	Player player;

public:

	// Constructor. Instantiates and sets new answer, instantiates a new
	// man with no pieces and new player with no current guesses.
	Game(string answer);

	// Get answer.
	Answer & getAnswer();
	// Get man.
	Man & getMan();
	// Get player.
	Player & getPlayer();

	// Checks if guess input has previously been input as a guess
	// and returns 1 if so
	bool checkGuess(string guessInput);
	// Creates and add new guess to player guess list.
	// Determines if guess is a letter or word and runs
	// corresponding guest function. If guess was correct
	// and solves puzzle returns 1, if guess was correct
	// and puzzle is not solved returns 0, if guess was
	// incorrect updates pieces of man and returns 0.
	bool takeGuess(string guessInput);
	// Compares provided guess to answer string.
	bool guessWord(Guess guess);
	// Compares provided string to each element of answer vector.
	bool guessLetter(Guess guess);


};

#endif
