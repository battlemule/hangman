// ----------------------------------------------------------------------------
// hangman - exceptions.h                                                v. 1.0
//                                                                   6 May 2015
// Exceptions Class                                       Author: Robert Willis
//
// Exception prototypes and definitions
// ----------------------------------------------------------------------------
#ifndef __EXCEPTIONS_H__
#define __EXCEPTIONS_H__

using namespace std;

#include <exception>

// ----------------------------------------------------------------------------
// E_whiteSpace
//
// Thrown when whitespace detected in user input
// ----------------------------------------------------------------------------
class E_whiteSpace : public exception
{
	virtual const char* what() const throw();
};

// ----------------------------------------------------------------------------
// E_length
//
// Thrown when user input is under or exceeds expected length
// ----------------------------------------------------------------------------
class E_length : public exception
{
	virtual const char* what() const throw();
};

// ----------------------------------------------------------------------------
// E_containsInt
//
// Thrown when user input contains an unexpected int
// ----------------------------------------------------------------------------
class E_containsInt : public exception
{
	virtual const char* what() const throw();
};

// ----------------------------------------------------------------------------
// E_notInt
//
// Thrown when user input is not an int when an int is expected
// ----------------------------------------------------------------------------
class E_notInt : public exception
{
	virtual const char* what() const throw();
};

// ----------------------------------------------------------------------------
// E_intRange
//
// Thrown when user input int is out of range of expectation
// ----------------------------------------------------------------------------
class E_intRange : public exception
{
	virtual const char* what() const throw();
};

#endif
