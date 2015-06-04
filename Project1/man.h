// ----------------------------------------------------------------------------
// hangman - man.h                                                       v. 1.0
//                                                                   6 May 2015
// Man class                                              Author: Robert Willis
//
// Stores and increments the amount of pieces added to man (incorrect guesses
// made by the player).
// ----------------------------------------------------------------------------
#ifndef MAN_H
#define MAN_H

using namespace std;

// ----------------------------------------------------------------------------
// Man class
// ----------------------------------------------------------------------------
class Man
{

private:

	// The number of pieces added to man.
	// Value set to 0 during construction.
	int pieces;

public:

	// Constructor. Initialises pieces to 0.
	Man();

	// Add a piece to man (increment value of pieces).
	void addPiece();

	// Get pieces.
	int & getPieces();

};

#endif
