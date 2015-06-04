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
#ifndef MAIN_H
#define MAIN_H

using namespace std;

#include <string>

#include "game.h"
#include "utility.h"

// main
int main();

#endif
