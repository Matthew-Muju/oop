#include "Deposit.h" //Definisi class Deposit 
#include "Screen.h" //Definisi class Screen
#include "BankDatabase.h" //Definisi class BankDatabase 
#include "Keypad.h" //Definisi class Keypad 
#include "DepositSlot.h" //Definisi class DepositSlot 

const static int CANCELED = 0; // constant representing cancel option

// Deposit constructor initializes class's data members
Deposit::Deposit( int userAccountNumber, Screen &atmScreen,BankDatabase &atmBankDatabase, Keypad &atmKeypad,DepositSlot &atmDepositSlot )
: Transaction( userAccountNumber, atmScreen, atmBankDatabase ),
keypad( atmKeypad ), depositSlot( atmDepositSlot )
{
// empty body
}

//melakukan transaksi; overrides Transaction's pure virtual function
void Deposit::execute()
{
BankDatabase &bankDatabase = getBankDatabase(); //mengambil reference
Screen &screen = getScreen(); //mengambil reference

amount = promptForDepositAmount(); //mengambil jumlah deposit dari user

//cek apakah user memasukan jumlah deposit atau membatalkan
if ( amount != CANCELED )
{
//meminta amplop deposit yang berisi jumlah tertentu
screen.displayMessage("Please insert a deposit envelope containing " );
screen.displayDollarAmount( amount );
screen.displayMessageLine( " in the deposit slot." );

//menerima amplop deposit
bool envelopeReceived = depositSlot.isEnvelopeReceived();

//cek apakah amplop deposit diterima
if ( envelopeReceived )
{
screen.displayMessageLine( "Your envelope has been received.""NOTE: The money just will not be available until we""verify the amount of any enclosed cash, and any enclosed ""checks clear." );

//credit account untuk mencerminkan deposit
bankDatabase.credit( getAccountNumber(), amount );
} 
else //amplop deposit tidak diterima
{
screen.displayMessageLine( "You did not insert an ""envelope, so the ATM has canceled your transaction." );
} 
}
else //user membatalkan daripada memasukan jumlah
{
screen.displayMessageLine( "Canceling transaction..." );
}
}

//prompt user untuk memasukan jumlah deposit dalam cents
double Deposit::promptForDepositAmount() const
{
Screen &screen = getScreen(); //mengambil reference untuk screen

//menampilkan prompt dan menerima input
screen.displayMessage( "Please enter a deposit amount in ""CENTS (or 0 to cancel): " );
int input = keypad.getInput(); //menerima input dari jumlah deposit

//cek apakah user membatalkan atau memasukan jumlah yang valid
if ( input == CANCELED )
return CANCELED;
else
{
return static_cast< double >( input ) / 100; //mengembalikan jumlah dolar
}
}
