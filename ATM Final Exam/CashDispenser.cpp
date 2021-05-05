#include "CashDispenser.h" //Definisi class CashDispenser

//CashDispenser default constructor menginisialisasi count ke default
CashDispenser::CashDispenser()
{
count = INITIAL_COUNT; //set count attribute ke default
} 

//mensimulasikan pengeluaran uang tunai dalam jumlah tertentu ; asumsikan cukup uang tunai
//is available (panggilan sebemumnya ke isSufficientCashAvailable dikembalikan true)
void CashDispenser::dispenseCash( int amount )
{
int billsRequired = amount / 20; //angka $20 tagihan dibutuhkan
count -= billsRequired; //update count dari tagihan
}

//menunjukkan apakah mesin ATM dapat mengeluarkan jumlah yang diinginkan
bool CashDispenser::isSufficientCashAvailable( int amount ) const
{
int billsRequired = amount / 20; //angka $20 tagihan dibutuhkan

if ( count >= billsRequired )
return true; //tagihan cukup tersedia
else
return false; //tagihan tidak cukup tersedia
}
