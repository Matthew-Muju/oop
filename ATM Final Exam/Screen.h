#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
using std::string;

class Screen
{
	public:
		void displayMessage( string ) const; //output a message
		void displayMessageLine( string ) const; //output message with newline
		void displayDollarAmount( double ) const; //output a dollar amount
};

#endif
