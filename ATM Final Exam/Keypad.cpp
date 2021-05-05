#include <iostream>
using std::cin;

#include "Keypad.h" //Definisi class keypad

//mengembalikan nilai integer yang diinput oleh user
int Keypad::getInput() const
{
int input; //variabel untuk menyimpan input
cin >> input; 
return input; //mengembalikan nilai yang dimasukan user
}
