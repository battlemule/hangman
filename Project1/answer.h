// ----------------------------------------------------------------------------
// hangman - answer.h                                                    v. 1.0
//                                                                   6 May 2015
// Answer class                                           Author: Robert Willis
//
// Stores the answer to the current game the player is trying to guess.
// Answer string is generated in main and passed through game.
// Length is equal to length of provided string.
// ----------------------------------------------------------------------------
#ifndef ANSWER_H
#define ANSWER_H

using namespace std;

#include <string>
#include <vector>

// ----------------------------------------------------------------------------
// Answer class
// ----------------------------------------------------------------------------
class Answer
{

private:

	// Word for current game stored as vector of strings.
	// One character per string.
	vector<string> answer;

public:

	// Sets answer to provided string
	void setAnswer(string answer);

	// Get full answer vector.
	vector<string> & getAnswer();
	// Get specific letter from answer by index.
	string & getChar(int index);
	// Get answer as string
	string getAnswerString();

};

#endif
