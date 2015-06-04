// ----------------------------------------------------------------------------
// hangman - main.h                                                      v. 1.0
//                                                                   6 May 2015
// main()                                                 Author: Robert Willis
//
// Hangman game reads words from words.dic file and selects one at rand() to
// use for a game of hangman.
//
// Main prints and gets input from the games main menu before instantiating
// a game object. As it goes through the game loop main() requests and
// validates input from user before updating and printing the state of the
// current game. Main() exits when 2 is provided as input from main menu.
//
// See readme.txt for further information.
// ----------------------------------------------------------------------------
#include "main.h"

// ----------------------------------------------------------------------------
// main()
// ----------------------------------------------------------------------------
int main()
{
	// Begin menu loop
	while (true)
	{
		// Imput string
		string input = "";

		// Print main menu
		printMenu();

		// Take input until valid input is given ("1" or "2")
		while (input == "")
			input = getMenuInput();


		// If input == "2" exit program
		if (input == "2")
			break;

		Game *game;

		// Otherwise attempt to instantiate new game
		try
		{
			game = new Game(generateAnswer());
		}
		catch (exception &e)
		{
			// Exit program if anything goes wrong with file read
			cout << "Exiting. words.dic not found.";
			exit(1);
		}



		// Print game input instructions
		printIntroSplash();

		// Begin Game Loop
		while (true)
		{
			// Reset value of input
			input = "";

			// Print state of game
			printEndTurnScreen(game->getPlayer().getPartialAnswerString(),
				game->getMan().getPieces());
			// Print guesses player has made
			printGuessesScreen(game->getPlayer().getGuesses());

			// Take input until valid input is given (1-20 char string, no ints)
			while (input == "")
			{
				// Get input from cin
				input = getGuessInput();

				// If input has previously been guessed throw out
				if (game->checkGuess(input))
				{
					cout << "Already guessed " << input << "." << endl;
					input = "";
				}


			} // End guess input

			// Return to menu if user requested
			if (input == "quit")
				break;

			// Attempt guess.
			// If guess solves puzzle show win screen and exit.
			if (game->takeGuess(input))
			{
				printWinScreen(game->getAnswer().getAnswerString(),
					game->getMan().getPieces());
				break;
			}

			// If guess was incorrect and pieces of man has been incremented
			// to 6 show lose screen and exit
			if (game->getMan().getPieces() == 6)
			{
				printLoseScreen(game->getAnswer().getAnswerString());
				break;
			}

		} // End game loop

		// free game
		delete game;

	} // End menu loop

	return 0;

} // End main
