#ifndef BANK_DATABASE_H
#define BANK_DATABASE_H

#include <vector> //kelas menggunakan vektor untuk menyimpan objek account
using std::vector;

#include "Account.h" //Definisi class Account

class BankDatabase
{
	private:
		vector< Account > accounts; //vector dari akun bank

		//fungsi utilitas pribadi
		Account * getAccount( int ); //mendapat pointer untuk objek account
	public:
		BankDatabase(); // constructor menginisialisasi accounts

		//menentukan apakah nomor akun dan PIN cocok dengan yang ada di Akun
		bool authenticateUser( int, int ); // mengembalikan true jika Account autentik
		double getAvailableBalance( int ); //mendapatkan saldo yang tersedia
		double getTotalBalance( int ); //mendapatkan Account's total saldo
		void credit( int, double ); //tambahkan jumlah ke account saldo
		void debit( int, double ); // mengurangi jumlah ke account saldo
}; // end class BankDatabase

#endif
