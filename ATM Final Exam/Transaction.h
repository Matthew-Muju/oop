#ifndef TRANSACTION_H
#define TRANSACTION_H

class Screen; //forward declaration of class Screen
class BankDatabase; //forward declaration of class BankDatabase

class Transaction
{
	private:
		int accountNumber; //menunjukan akun yang terlibat
		Screen &screen; //reference ke screen dari ATM
		BankDatabase &bankDatabase; //reference ke account info database
	public:
		//constructor menginisialisasi fitur umum dari semua Transaksi
		Transaction( int, Screen &, BankDatabase& );

		virtual ~Transaction() { } //virtual destructor dengan empty body

		int getAccountNumber() const; //mengembalikan account number
		Screen &getScreen() const; //mengembalikan reference ke screen
		BankDatabase &getBankDatabase() const; //mengembalikan reference ke database

		//pure virtual function untuk melakukan transaksi
		virtual void execute() = 0;// overridden di kelas turunan

};

#endif
