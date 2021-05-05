#include <iostream>
using std::cout;
using std::endl;
using std::fixed;

#include <iomanip>
using std::setprecision;

#include "Screen.h" //Definisi class Screen 

//output a message without a newline
void Screen::displayMessage( string message ) const
{
cout << message;
} 

//output a message with a newline
void Screen::displayMessageLine( string message ) const
{
cout << message << endl;
} 

//output a dollar amount
void Screen::displayDollarAmount( double amount ) const
{
cout << fixed << setprecision( 2 ) << "$" << amount;
}
