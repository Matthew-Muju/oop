#include "Transaction.h" //Definisi class Transaction
#include "Screen.h" //Definisi class Screen
#include "BankDatabase.h" //Definisi class BankDatabase

//constructor menginisialisasi fitur umum dari semua Transaksi
Transaction::Transaction( int userAccountNumber, Screen &atmScreen,BankDatabase &atmBankDatabase ) 
: accountNumber(userAccountNumber),screen(atmScreen),bankDatabase(atmBankDatabase)
{
//empty body
}

//mengembalikan account number
int Transaction::getAccountNumber() const
{
return accountNumber;
}

//mengembalikan reference ke screen
Screen &Transaction::getScreen() const
{
return screen;
} 

//mengembalikan reference ke bank database
BankDatabase &Transaction::getBankDatabase() const
{
return bankDatabase;
}
