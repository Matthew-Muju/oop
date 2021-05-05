#ifndef CASH_DISPENSER_H
#define CASH_DISPENSER_H

class CashDispenser
{
	private:
		const static int INITIAL_COUNT = 500;
		int count; //kelipatan $20
	public:
		CashDispenser(); //constructor yang menginisialisasi bill count ke 500

		//mensimulasikan pengeluaran uang tunai dalam jumlah tertentu
		void dispenseCash( int );

		//menunjukkan apakah mesin ATM dapat mengeluarkan jumlah yang diinginkan
		bool isSufficientCashAvailable( int ) const;
}; 

#endif
