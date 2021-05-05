#include "BalanceInquiry.h" //Definisi class BalanceInquiry 
#include "Screen.h" //Definisi class Screen 
#include "BankDatabase.h" //Definisi class BankDatabase

//BalanceInquiry constructor menginisialisasi base-class data members
BalanceInquiry:: BalanceInquiry( int userAccountNumber, Screen &atmScreen,BankDatabase &atmBankDatabase ): Transaction( userAccountNumber, atmScreen, atmBankDatabase )
{
//empty body
}

//melakukan transaksi; mengesampingkan pure virtual function Transaksi
void BalanceInquiry::execute()
{
//mendapatkan references ke bank database dan screen
BankDatabase &bankDatabase = getBankDatabase();
Screen &screen = getScreen();

//mendapatkan saldo yang tersedia untuk current user's Account
double availableBalance = bankDatabase.getAvailableBalance( getAccountNumber() );

// mendapatkan saldo total untuk current user's Account
double totalBalance = bankDatabase.getTotalBalance( getAccountNumber() );

//menampilkan informasi saldo di screen
screen.displayMessageLine( "Balance Information:" );
screen.displayMessage( " - Available balance: " );
screen.displayDollarAmount( availableBalance );
screen.displayMessage( "- Total balance: " );
screen.displayDollarAmount( totalBalance );
screen.displayMessageLine( "" );
}
