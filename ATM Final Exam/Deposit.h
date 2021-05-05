#ifndef DEPOSIT_H
#define DEPOSIT_H

#include "Transaction.h" //Definisi class Transaction
class Keypad; //forward declaration dari class Keypad
class DepositSlot; //forward declaration dari class DepositSlot

class Deposit : public Transaction
{
	private:
		double amount; //jumlah untuk dideposit
		Keypad &keypad; //reference ke ATM's keypad
		DepositSlot &depositSlot; //refrence ke ATM's deposit slot
		double promptForDepositAmount() const; //mengambil jumlah deposit dari user
	public:
		Deposit( int, Screen &, BankDatabase &, Keypad &, DepositSlot & );
		virtual void execute(); //melakukan transaksi

};

#endif
