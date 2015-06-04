// ----------------------------------------------------------------------------
// hangman - game.cpp                                                    v. 1.0
//                                                                   6 May 2015
// Game class                                             Author: Robert Willis
//
// Game class acts as the main container and driver for all elements of the
// hangman game. It creates and stores an instance of answer, player and
// man and updates and prints each in response to calls from main().
// ----------------------------------------------------------------------------
#include "game.h"

// ----------------------------------------------------------------------------
// Game class
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// Game()
//
// Constructor. Sets new answer and corresponding player partial answer.
// ----------------------------------------------------------------------------
Game::Game(string answer)
{
	this->answer.setAnswer(answer);
	this->player.setPartialAnswer(answer.length());
}

// ----------------------------------------------------------------------------
// getAnswer()
//
// Get answer.
// ----------------------------------------------------------------------------
Answer & Game::getAnswer()
{
	return answer;
}

// ----------------------------------------------------------------------------
// getMan()
//
// Get man.
// ----------------------------------------------------------------------------
Man & Game::getMan()
{
	return man;
}

// ----------------------------------------------------------------------------
// getPlayer()
//
// Get player.
// ----------------------------------------------------------------------------
Player & Game::getPlayer()
{
	return player;
}

// ----------------------------------------------------------------------------
// checkGuess(string guessInput)
//
// Checks if guess input has previously been input as a guess
// and returns 1 if so
// ----------------------------------------------------------------------------
bool Game::checkGuess(string guessInput)
{
	// Iterator
	list<Guess>::iterator it;

	// For each item in guess list
	for (it = player.getGuesses().begin(); it != player.getGuesses().end(); ++it)
		// If guess was equal to new guess input
	if (guessInput == it->getGuess())
		// Return 1
		return 1;

	// If no matches found return 0
	return 0;
}

// ----------------------------------------------------------------------------
// takeGuess(string guessInput)
//
// Creates new guess from provided input string and then determines if guess
// was a letter or word and runs corresponding guest function.
// If guess was correct and solves puzzle returns 1, if guess was correct and
// puzzle is not solved returns 0, if guess was incorrect updates pieces of
// man and returns 0.
// ----------------------------------------------------------------------------
bool Game::takeGuess(string guessInput)
{
	// Create new guess from input
	Guess guess(guessInput);
	// Store guess in players guess list
	player.addGuess(guess);

	// Flag for any correct letters guessed
	int correct = 0;

	// If input guess length was equal to 1
	if (guess.getGuess().length() == 1)
		// Attempt to guess a letter
	if (guessLetter(guess))
		// Flag if guess was correct
		++correct;

	// If input guess length was greater than 1
	if (guess.getGuess().length() > 1)
		// Attempt to guess answer with input
	if (guessWord(guess))
		return 1;

	// If player.partialAnswerString now equals answer return 1
	if (guessWord(player.getPartialAnswerString()))
		return 1;

	// Add a piece to man if guess was incorrect
	if (!correct)
		man.addPiece();

	return 0;

}

// ----------------------------------------------------------------------------
// guessWord(Guess guess)
//
// Compares provided guess to answer string and returns 1 if matched
// ----------------------------------------------------------------------------
bool Game::guessWord(Guess guess)
{
	if (guess.getGuess() == answer.getAnswerString())
		return 1;

	return 0;
}

// ----------------------------------------------------------------------------
// guessLetter(Guess guess)
//
// Compares provided string to each element of answer vector. If a match
// is found it adds the letter to the corresponding element of players
// partialAnswer and 1 is returned.
// ----------------------------------------------------------------------------
bool Game::guessLetter(Guess guess)
{
	// Flag to allow for searching for repeat matches in string
	int correct = 0;

	// For length of the answer
	for (unsigned int i = 0; i < answer.getAnswerString().length(); ++i)
	{
		// If guess matches letter of answer at index
		if (guess.getGuess() == answer.getChar(i))
		{
			// Update corresponding partial answer at same index
			player.updatePartialAnswer(i, guess.getGuess());
			// Flag a match found
			++correct;
		}
	}

	// Return 1 if at least 1 match was found
	if (correct)
		return 1;

	return 0;

}