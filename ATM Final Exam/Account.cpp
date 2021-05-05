#include "Account.h" // Account class definition

//Account constructor menginisialisasi atribut
Account::Account( int theAccountNumber, int thePIN,double theAvailableBalance, double theTotalBalance ): accountNumber( theAccountNumber ),pin( thePIN ),availableBalance( theAvailableBalance ),totalBalance( theTotalBalance )
{
//empty body
}

//menentukan apakah PIN yang ditentukan pengguna cocok dengan PIN di Akun
bool Account::validatePIN( int userPIN ) const
{
if ( userPIN == pin )
return true;
else
return false;
}

//mengembalikan saldo yang tersedia
double Account::getAvailableBalance() const
{
return availableBalance;
}

//mengembalikan total saldo
double Account::getTotalBalance() const
{
return totalBalance;
}

//mengkredit sejumlah ke akun
void Account::credit( double amount )
{
totalBalance += amount; // menambah ke total saldo
}

//mendebit sejumlah uang dari akun
void Account::debit( double amount )
{
availableBalance -= amount; //mengurangi dari saldo yang tersedia
totalBalance -= amount; //mengurangi dari total saldo
}

//mengembalikan account number
int Account::getAccountNumber() const
{
return accountNumber;
}
