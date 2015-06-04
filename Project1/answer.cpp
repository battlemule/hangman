// ----------------------------------------------------------------------------
// hangman - answer.cpp                                                  v. 1.0
//                                                                   6 May 2015
// Answer class                                           Author: Robert Willis
//
// Stores the answer to the current game the player is trying to guess.
// Answer string is generated in main and passed through game.
// Length is equal to length of provided string.
// ----------------------------------------------------------------------------
#include "answer.h"

// ----------------------------------------------------------------------------
// Answer class
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// setAnswer(string answer)
//
// Sets length to size of provided string and splits provided string by char
// before storing in answer as vector of strings
// ----------------------------------------------------------------------------
void Answer::setAnswer(string input)
{
	// Temporary string for storing each letter of input
	string inputChar;

	// For length of input string
	for (unsigned int i = 0; i < input.length(); ++i)
	{
		// Set inputChar to char at index in input string
		inputChar = input.at(i);
		// Push that char into answer vector
		answer.push_back(inputChar);
	}

}

// ----------------------------------------------------------------------------
// getAnswer()
//
// Return answer as vector of strings.
// ----------------------------------------------------------------------------
vector<string> & Answer::getAnswer()
{
	return answer;
}

// ----------------------------------------------------------------------------
// getChar(int index)
//
// Get specific letter from answer by index returned as string.
// ----------------------------------------------------------------------------
string & Answer::getChar(int index)
{
	return answer[index];
}

// ----------------------------------------------------------------------------
// getAnswerString()
//
// Get answer as string
// ----------------------------------------------------------------------------
string Answer::getAnswerString()
{
	string returnString;

	// For length of partialAnswer
	for (unsigned int i = 0; i < answer.size(); ++i)
		// Append partialAnswer contents to returnString
		returnString += answer[i];

	return returnString;
}
