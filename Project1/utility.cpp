// ----------------------------------------------------------------------------
// hangman - utility.cpp                                                 v. 1.0
//                                                                   6 May 2015
// Utility Functions                                      Author: Robert Willis
//
// Contains IO functions for retrieving and validating user input as well as
// printing formatted game output screens
// ----------------------------------------------------------------------------
#include "utility.h"

// ----------------------------------------------------------------------------
// User Input Functions
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// getInput()
//
// Gets and returns line from cin using getline().
// ----------------------------------------------------------------------------
string getInput()
{
	string line = "";
	getline(std::cin, line);
	return line;
}

// ----------------------------------------------------------------------------
// getMenuInput()
//
// Prompts for, validates to and returns either "1", "2" or "" from users input
// ----------------------------------------------------------------------------
string getMenuInput()
{
	string input = "";

	// Prompt for input
	cout << endl << "Menu Input (1 or 2): ";

	try
	{
		// Attempt to get input
		input = getInput();
		cout << endl;

		// Validate input was 1 char long
		validateLength(input, 1, 1);

		// If input contained white space throw exception
		if (validateContainsWhiteSpace(input))
			throw E_whiteSpace();

		// Validate input was an int
		if (validateIsInt(input))
		{
			// If so validate it fell in range 1-2
			validateIntRange(input, 1, 2);
			// Return if so
			return input;
		}
		else
			// Throw exception if not int
			throw E_notInt();

	}
	// If any validation fails print input exception
	catch (exception &e)
	{
		cout << e.what() << endl;
	}

	// Return empty string if exception was thrown
	return "";
}

// ----------------------------------------------------------------------------
// getGuessInput()
//
// Prompts for, validates to and returns a 1-20 char string with no ints from
// users input
// ----------------------------------------------------------------------------
string getGuessInput()
{
	string input = "";

	// Prompt for input
	cout << endl << "Please enter guess: ";

	try
	{
		// Attempt to get input
		input = getInput();
		cout << endl;

		// Validate input was 1-20 char long
		validateLength(input, 1, 20);

		// If input contained white space throw exception
		if (validateContainsWhiteSpace(input))
			throw E_whiteSpace();

		// If input contained only alpha characters
		if (validateIsAlpha(input))
			// Transform input to lower case
			transform(input.begin(), input.end(), input.begin(), ::tolower);
		else
			// Throw exception if input contained a non alpha character
			throw E_containsInt();

		// Return input if validated succesfully
		return input;

	}
	// If any validation fails print input exception
	catch (exception &e)
	{
		cout << e.what() << endl;
	}

	// Return empty string if exception was thrown
	return "";
}

// ----------------------------------------------------------------------------
// Input Validation Functions
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// validateContainsWhiteSpace(string input)
//
// Returns 1 if input string contained any white space characters
// ----------------------------------------------------------------------------
bool validateContainsWhiteSpace(string input)
{
	// For each char in input
	for (unsigned int i = 0; i < input.length(); ++i)
		// If char is white space
	if (isspace(input.at(i)))
		// return 1
		return 1;

	return 0;
}

// ----------------------------------------------------------------------------
// validateIsAlpha(string input)
//
// Returns 1 if input string contains only alpha characters
// ----------------------------------------------------------------------------
bool validateIsAlpha(string input)
{
	for (unsigned int i = 0; i < input.length(); ++i)
	if (!isalpha(input.at(i)))
		return 0;

	return 1;
}

// ----------------------------------------------------------------------------
// validateIsInt(string input)
//
// Returns 1 if input string is a valid int
// ----------------------------------------------------------------------------
bool validateIsInt(string input)
{
	// Check if string was empty, had leading or tailing whitespace
	if (input.empty() || ((!isdigit(input[0])) &&
		(input[0] != '-') &&
		(input[0] != '+')))
		// Return false if so
		return 0;

	// Char for strol to set to first non-integer char
	char * p;

	// Attempt to strtol a c_string of input
	strtol(input.c_str(), &p, 10);

	// If p is equal to tailing 0 on c_str then input is a valid int
	return (*p == 0);
}

// ----------------------------------------------------------------------------
// validateContainsInt(string input)
//
// Returns 1 if input string contains at least 1 int
// ----------------------------------------------------------------------------
bool validateContainsInt(string input)
{
	// If npos == a valid instance of an int, string contains an int
	if (string::npos != input.find_first_of("0123456789"))
		return 1;

	return 0;
}

// ----------------------------------------------------------------------------
// validateIntRange(string input, int low, int high)
//
// Throws exception if provided int was lower than low or higher than high.
// ----------------------------------------------------------------------------
void validateIntRange(string input, int low, int high)
{
	// Make sure input is an int before attempting atoi
	if (!validateIsInt(input))
		throw E_notInt();

	// Cast input string to int through atoi
	int inputInt = atoi(input.c_str());

	// If converted int is higher or lower than requested throw exception
	if (inputInt < low)
		throw E_intRange();

	if (inputInt > high)
		throw E_intRange();

}

// ----------------------------------------------------------------------------
// validateLength(string input, int low, int high)
//
// Throws exception if input string.length() is less than low or higher
// than high.
// ----------------------------------------------------------------------------
void validateLength(string input, int low, int high)
{
	// If input string is higher or lower than requested throw exception
	// Casted as unsigned to prevent compiler warning - value will never
	// be negative
	if (input.length() < (unsigned)low)
		throw E_length();

	if (input.length() > (unsigned)high)
		throw E_length();
}

// ----------------------------------------------------------------------------
// File Input functions
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// generateAnswer()
//
// Reads dictionary from file and returns a word at rand()
// ----------------------------------------------------------------------------
string generateAnswer()
{
	// Vector to hold dictionary in
	vector<string> wordList;
	// Open dictionary file (exception caught in main if no file)
	fstream input("words.dic");
	// Random number
	int rNum = 0;

	// For each line in file
	for (string line; getline(input, line);)
		// Fill wordList vector with line
		wordList.push_back(line);

	// Seed rand()
	srand(time(NULL));
	// Set rNum to random number between 0 and size of wordList vector
	rNum = rand() % wordList.size() + 0;

	// Return word from vector at position rnum
	return wordList[rNum];

}

// ----------------------------------------------------------------------------
// Output Screens
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// printMenu()
//
// Prints main menu.
// ----------------------------------------------------------------------------
void printMenu()
{
	cout << "--------------------------------------" << endl;
	cout << "       Hangman Challenge 4000" << endl;
	cout << "--------------------------------------" << endl << endl;
	cout << "Welcome to the Hangman Challenge 4000." << endl;
	cout << "Select from the following options." << endl << endl;
	cout << "1. Play Hangman" << endl;
	cout << "2. Quit" << endl;
}

// ----------------------------------------------------------------------------
// printIntroSplash()
//
// Prints game input instructions.
// ----------------------------------------------------------------------------
void printIntroSplash()
{
	cout << "--------------------------------------" << endl;
	cout << "       Hangman Challenge 4000" << endl << endl;
	cout << "  - Type a letter to guess a letter." << endl;
	cout << "  - Type a word to guess a word." << endl;
	cout << "  - Type 'quit' to quit." << endl;
	cout << "--------------------------------------" << endl << endl;
}

// ----------------------------------------------------------------------------
// printGuessesScreen()
//
// Print list of all guesses the player has taken. (Player requested).
// ----------------------------------------------------------------------------
void printGuessesScreen(list<Guess> guesses)
{
	list<Guess>::iterator it;

	cout << "--------------------------------------" << endl;
	cout << "Guessed: ";

	// For each guess
	for (it = guesses.begin(); it != guesses.end(); ++it)
		// Print each guess
		cout << it->getGuess() << " ";

	cout << endl;
	cout << "--------------------------------------" << endl;
}

// ----------------------------------------------------------------------------
// printEndTurnScreen()
//
// Prints current state of the game. (Printed at end of each turn).
// ----------------------------------------------------------------------------
void printEndTurnScreen(string partialAnswer, int man)
{
	// Create new string for print formatted version of partialAnswer string
	string formattedPartialAnswer = "";

	// For the length of partial answer
	for (unsigned int i = 0; i < partialAnswer.length(); ++i)
	{
		// Append partialAnswer char at i to formatted string
		formattedPartialAnswer += partialAnswer.at(i);
		// Append white space following char
		formattedPartialAnswer += " ";
	}

	cout << "--------------------------------------" << endl;

	// Output Line 1

	// If no pieces of man just print formatted partialAnswer
	if (man == 0)
		cout << endl << "    " << formattedPartialAnswer << endl << endl;
	// If man is greater than 0 always print man head
	if (man > 0)
		cout << " O " << endl;

	// Ouput Line 2

	// If man is equal to 1 ammend partialAnswer to next line
	if (man == 1)
		cout << "      " << formattedPartialAnswer << endl << endl;
	// If man is 2 or greater cout relevant man state and partial answer
	if (man == 2)
		cout << " |    " << formattedPartialAnswer << endl << endl;
	if (man == 3)
		cout << "-|    " << formattedPartialAnswer << endl << endl;
	if (man >= 4)
		cout << "-|-   " << formattedPartialAnswer << endl;

	// Output Line 3

	if (man == 4)
		cout << endl;
	// If man is 5 or 6 add legs
	if (man == 5)
		cout << "/" << endl;
	if (man == 6)
		cout << "/ \\" << endl;

	cout << "--------------------------------------" << endl;
}

// ----------------------------------------------------------------------------
// printWinScreen(string answer, int man)
//
// Print victory screen. (Player wins the game).
// ----------------------------------------------------------------------------
void printWinScreen(string answer, int man)
{
	cout << "--------------------------------------" << endl;

	// Output Line 1

	// If no pieces of man don't draw head
	if (man == 0)
		cout << "            You Win!" << endl << endl;
	// Else draw head
	else
		cout << " O          You Win!" << endl;

	// Ouput Line 2

	// If man is equal to 1 end line
	if (man == 1)
		cout << endl;
	// If man is 2 or greater cout relevant man state and partial answer
	if (man == 2)
		cout << " | " << endl;
	if (man == 3)
		cout << "-| " << endl;
	if (man >= 4)
		cout << "-|-" << endl;

	// Output Line 3

	// If man was less than or equal to 4 pad white space
	if (man <= 4)
		cout << "    ";
	// If man is 5 or 6 add legs
	if (man == 5)
		cout << "/   ";
	if (man == 6)
		cout << "/ \\ ";

	// Print answer
	cout << "The Answer was: " << answer << endl;

	cout << "--------------------------------------" << endl;
}

// ----------------------------------------------------------------------------
// printLoseScreen()
//
// Print lose screen. (Player loses the game).
// ----------------------------------------------------------------------------
void printLoseScreen(string answer)
{
	cout << "--------------------------------------" << endl;
	cout << " O             You Lose!               " << endl;
	cout << "-|-" << endl;
	cout << "/ \\    The Answer was: " << answer << endl;
	cout << "--------------------------------------" << endl;
}
