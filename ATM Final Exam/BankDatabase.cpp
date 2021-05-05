#include "BankDatabase.h" //Definisi class BankDatabase
#include <string.h>

//BankDatabase default constructor menginisialisasi accounts
BankDatabase::BankDatabase()
{
// buat 2 Account objek untuk percobaan
Account account1( 12345, 54321, 1000.0, 1200.0 );
Account account2( 98765, 56789, 200.0, 200.0 );

// tambah objek account ke vector account
accounts.push_back( account1 ); // tambah account1 ke akhir vektor
accounts.push_back( account2 ); // tambah account2 ke akhir vektor
}

//mengambil objek account yang berisi nomor account tertentu
Account * BankDatabase::getAccount( int accountNumber )
{
//loop melalui account yang mencari nomor account yang cocok
for ( size_t i = 0; i < accounts.size(); i++ )
{
//mengembalikan account saat ini jika yang cocok ditemukan
if ( accounts[ i ].getAccountNumber() == accountNumber )
return &accounts[ i ];
}

return NULL; // jika tidak ada account yang cocok ditemukan, kembalikan NULL
}

//menentukan apakah nomor account yang ditentukan pengguna dan PIN cocok
//account yang ada didatabase
bool BankDatabase::authenticateUser( int userAccountNumber,int userPIN )
{
//mencoba untuk mengambil akun dengan nomor account tersebut
Account * const userAccountPtr = getAccount( userAccountNumber );

//jika account ada,kembalikan hasil dari fungsi account validatePIN
if ( userAccountPtr != NULL )
return userAccountPtr->validatePIN( userPIN );
else
return false; //nomor account tidak ditemukan, jadi kembalikan false
}

//mengembalikan saldo account tersedia dengan nomor accountntu
double BankDatabase::getAvailableBalance( int userAccountNumber )
{
Account * const userAccountPtr = getAccount( userAccountNumber );
return userAccountPtr->getAvailableBalance();
}

// mengembalikan saldo total Account dengan nomor account tertentu
double BankDatabase::getTotalBalance( int userAccountNumber )
{
Account * const userAccountPtr = getAccount( userAccountNumber );
return userAccountPtr->getTotalBalance();
}

// mengkreditkan sejumlah ke account dengan nomor account yang ditentukan
void BankDatabase::credit( int userAccountNumber, double amount )
{
Account * const userAccountPtr = getAccount( userAccountNumber );
userAccountPtr->credit( amount );
}

// mendebit sejumlah dari account dengan nomor account tertentu
void BankDatabase::debit( int userAccountNumber, double amount )
{
Account * const userAccountPtr = getAccount( userAccountNumber );
userAccountPtr->debit( amount );
}
