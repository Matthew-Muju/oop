#ifndef WITHDRAWAL_H
#define WITHDRAWAL_H

#include "Transaction.h" //Definisi class Transaction
class Keypad; // forward declaration of class Keypad
class CashDispenser; // forward declaration of class CashDispenser

class Withdrawal : public Transaction
{
	private:
		int amount; //jumlah untuk diwithdraw
		Keypad &keypad; //reference ke ATM keypad
		CashDispenser &cashDispenser; //reference ke ATM cash dispenser
		int displayMenuOfAmounts() const; //menampilkan menu withdrawal
	public:
		Withdrawal( int, Screen &, BankDatabase &, Keypad &, CashDispenser & );
		virtual void execute(); //melakukan transaksi

};

#endif
