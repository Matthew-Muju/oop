#include "Withdrawal.h" //Definisi class Withdrawal 
#include "Screen.h" //Definisi class Screen 
#include "BankDatabase.h" //Definisi class BankDatabase 
#include "Keypad.h" //Definisi class Keypad 
#include "CashDispenser.h" //Definisi class CashDispenser 

//konstanta global yang sesuai dengan opsi menu untuk membatalkan
const static int CANCELED = 6;

//Withdrawal constructor menginisialisasi class's data members
Withdrawal::Withdrawal( int userAccountNumber, Screen &atmScreen,BankDatabase &atmBankDatabase, Keypad &atmKeypad,CashDispenser &atmCashDispenser ): Transaction( userAccountNumber, atmScreen, atmBankDatabase ),keypad( atmKeypad ), cashDispenser( atmCashDispenser )
{
//empty body
}

//melakukan transaksi; overrides Transaction's pure virtual function
void Withdrawal::execute()
{
bool cashDispensed = false; //uang tunai belum dibagikan
bool transactionCanceled = false; //transaksi belum dibatalkan

//mendapatkan references ke bank database and screen
BankDatabase &bankDatabase = getBankDatabase();
Screen &screen = getScreen();

//loop sampai uang tunai dibagikan atau user membatalkan
do
{
//dapatkan jumlah penarikan yang dipilih dari pengguna
int selection = displayMenuOfAmounts();

//cek apakah user memilih jumlah withdrawal atau membatalkan
if ( selection != CANCELED )
{
amount = selection; //set jumlah ke jumlah dolar yang dipilih

//mengambil saldo yang tersedia dari account yang terlibat
double availableBalance =bankDatabase.getAvailableBalance( getAccountNumber() );

// cek apakah user memiliki uang yang cukup dalam account
if ( amount <= availableBalance )
{
//cek apakah cash dispenser memiliki uang yang cukup
if ( cashDispenser.isSufficientCashAvailable( amount ) )
{
//perbarui account yang terlibat untuk mencerminkan penarikan
bankDatabase.debit( getAccountNumber(), amount );

cashDispenser.dispenseCash( amount ); //membagikan uang tunai
cashDispensed = true; //uang tunai dibagikan

//menginstruksikan user untuk mengambil uang tunai
screen.displayMessageLine("Please take your cash from the cash dispenser." );
}
else //cash dispenser tidak memiliki uang yang cukup
screen.displayMessageLine("Insufficient cash available in the ATM.""Please choose a smaller amount." );
} 
else //tidak cukup uang yang tersedia dalam user's account
{
screen.displayMessageLine("Insufficient funds in your account.""Please choose a smaller amount." );
}
}
else //user memilih batal di opsi menu
{
screen.displayMessageLine( "Canceling transaction..." );
transactionCanceled = true; //user membatalkan transaksi
}
} while ( !cashDispensed && !transactionCanceled );
}

//menampilkan menu jumlah withdrawal dan opsi untuk membatalkan;
//mengembalikan jumlah yang dipilih atau 0 jika user memilih untuk dibatalkan
int Withdrawal::displayMenuOfAmounts() const
{
int userChoice = 0; //variabel local untuk menyimpan nilai yang dikembalikan

Screen &screen = getScreen(); //mendapat screen reference

//array jumlah yang sesuai dengan nomor menu
int amounts[] = { 0, 20, 40, 60, 100, 200 };

//loop while sementara tidak ada pilihan yang valid yang dibuat 
while ( userChoice == 0 )
{
//tampilkan menu
screen.displayMessageLine( "Withdrawal options:" );
screen.displayMessageLine( "1 - $20" );
screen.displayMessageLine( "2 - $40" );
screen.displayMessageLine( "3 - $60" );
screen.displayMessageLine( "4 - $100" );
screen.displayMessageLine( "5 - $200" );
screen.displayMessageLine( "6 - Cancel transaction" );
screen.displayMessage( "Choose a withdrawal option (1-6): " );

int input = keypad.getInput(); //mendapat input user lewat Keypad

//memutuskan bagaimana untuk memproses berdasarkan nilai input
switch ( input )
{
case 1: // jika user memilih withdrawal amount
case 2: // (contoh, opsi pilihan 1, 2, 3, 4 or 5), kembalikan
case 3: // jumlah yang sesuai dari jumlah array
case 4:
case 5:
userChoice = amounts[ input ]; //simpan pilihan user
break;
case CANCELED: //user memilih untuk membatalkan
userChoice = CANCELED; //simpan pilihan user
break;
default: //user tidak memasukan nilai 1-6
screen.displayMessageLine( "Invalid selection. Try again." );
} 
} 
return userChoice; //mengembalikan withdrawal amount or CANCELED
}
