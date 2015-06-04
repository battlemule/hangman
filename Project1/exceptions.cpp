// ----------------------------------------------------------------------------
// hangman - exceptions.cpp                                              v. 1.0
//                                                                   6 May 2015
// Exceptions Class                                       Author: Robert Willis
//
// Exception prototypes and definitions
// ----------------------------------------------------------------------------
#include "exceptions.h"

const E_whiteSpace e_whiteSpace;
const E_length e_length;
const E_containsInt e_containsInt;
const E_notInt e_notInt;
const E_intRange e_intRange;

// ----------------------------------------------------------------------------
// E_whiteSpace
//
// Thrown when whitespace detected in user input
// ----------------------------------------------------------------------------
const char* E_whiteSpace::what() const throw()
{
	return "Incorrect input. White Space Detected.";
}

// ----------------------------------------------------------------------------
// E_length
//
// Thrown when user input is under or exceeds expected length
// ----------------------------------------------------------------------------
const char* E_length::what() const throw()
{
	return "Incorrect input. Wrong length.";
}

// ----------------------------------------------------------------------------
// E_containsInt
//
// Thrown when user input contains an unexpected int
// ----------------------------------------------------------------------------
const char* E_containsInt::what() const throw()
{
	return "Incorrect input. Must not contain an int.";
}

// ----------------------------------------------------------------------------
// E_notInt
//
// Thrown when user input is not an int when an int is expected
// ----------------------------------------------------------------------------
const char* E_notInt::what() const throw()
{
	return "Incorrect input. Input must be an int.";
}

// ----------------------------------------------------------------------------
// E_intRange
//
// Thrown when user input int is out of range of expectation
// ----------------------------------------------------------------------------
const char* E_intRange::what() const throw()
{
	return "Incorrect input. Int out of range.";
}
