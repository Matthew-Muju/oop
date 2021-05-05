#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
	private:
		int accountNumber; //account number
		int pin; //PIN untuk autentikasi
		double availableBalance; //dana tersedia untuk penarikan
		double totalBalance; //dana tersedia + dana menunggu untuk dihapus
	public:
		Account( int, int, double, double ); //constructor mengatur atribut
		bool validatePIN( int ) const; //apakah PIN yang ditentukan pengguna benar?
		double getAvailableBalance() const; // mengembalikan saldo yang tersedia
		double getTotalBalance() const; //mengembalikan total saldo
		void credit( double ); //menambah jumlah ke saldo akun
		void debit( double ); //mengurangi jumlah dari saldo Akun
		int getAccountNumber() const; //mengembalikan account number

};

#endif
