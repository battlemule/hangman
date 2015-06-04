// ----------------------------------------------------------------------------
// hangman - utility.h                                                   v. 1.0
//                                                                   6 May 2015
// Utility Functions                                      Author: Robert Willis
//
// Contains IO functions for retrieving and validating user input as well as
// printing formatted game output screens
// ----------------------------------------------------------------------------
#ifndef __UTILITY_H__
#define __UTILITY_H__

using namespace std;

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

#include "guess.h"
#include "exceptions.h"

// ----------------------------------------------------------------------------
// User Input Functions
// ----------------------------------------------------------------------------

// Gets and returns line from cin using getline().
string getInput();
// Prompts for, validates to and returns either "1", "2" or "" from users input
string getMenuInput();
// Prompts for, validates to and returns a 1-20 char string with no ints from
// users input
string getGuessInput();

// ----------------------------------------------------------------------------
// Input Validation Functions
// ----------------------------------------------------------------------------

// Returns 1 if input string contained any white space characters
bool validateContainsWhiteSpace(string input);
// Returns 1 if input string contains only alpha characters
bool validateIsAlpha(string input);
// Returns 1 if input string is a valid int
bool validateIsInt(string input);
// Returns 1 if input string contains at least 1 int
bool validateContainsInt(string input);
// Throws exception if provided int was lower than low or higher than high.
void validateIntRange(string input, int low, int high);
// Throws exception if input string.length() is less than low or higher
// than high.
void validateLength(string input, int low, int high);

// ----------------------------------------------------------------------------
// File Input functions
// ----------------------------------------------------------------------------

// Open file, load word list and return word at random
string generateAnswer();

// ----------------------------------------------------------------------------
// Output Screens
// ----------------------------------------------------------------------------

// Prints main menu.
void printMenu();
// Prints game input instructions.
void printIntroSplash();
// Print list of all guesses the player has taken. (Player requested).
void printGuessesScreen(list<Guess> guesses);
// Prints current state of the game. (Printed at end of each turn).
void printEndTurnScreen(string partialAnswer, int man);
// Print victory screen. (Player wins the game).
void printWinScreen(string answer, int man);
// Print lose screen. (Player loses the game).
void printLoseScreen(string answer);

#endif
