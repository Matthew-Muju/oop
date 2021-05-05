#ifndef ATM_H
#define ATM_H

#include<iostream>
using namespace std;

#include "Screen.h" //definisi class screen
#include "Keypad.h" //definisi class keypad
#include "CashDispenser.h" //definisi class cash dispenser
#include "DepositSlot.h" //definisi class depositslot
#include "BankDatabase.h" //definisi class bankdatabase

class Transaction;

class ATM
{
	private :
		bool userAuth; //apakah user telah ter-autentikasi
		int currentAccountNumber; //user account number yang sekarang
		Screen screen; //ATM screen
		Keypad keypad; //ATM keypad
		CashDispenser cashDispenser; //ATM cash dispenser
		DepositSlot depositSlot; //ATM deposit slot
		BankDatabase bankDb; //database informasi account
		
		//fungsi utilitas pribadi
		void authUser(); //mencoba untuk mengautentikasi user
		void performTransactions(); // melakukan transaksi
		int displayMainMenu() const; //menampilkan menu utama
		Transaction *createTransaction(int);
	public :
		ATM(); //constructor untuk menginisialisasi data dari member
		void run(); //untuk mulai ATM
};

#endif
