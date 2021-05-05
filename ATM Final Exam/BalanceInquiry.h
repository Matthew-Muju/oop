#ifndef BALANCE_INQUIRY_H
#define BALANCE_INQUIRY_H

#include "Transaction.h" //Definisi class Transaction

class BalanceInquiry : public Transaction
{
	public:
		BalanceInquiry( int, Screen &, BankDatabase & ); 
		virtual void execute(); //melakukan transaksi
}; 

#endif
