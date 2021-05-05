#include "ATM.h"
#include "Transaction.h"
#include "BalanceInquiry.h"
#include "Withdrawal.h"
#include "Deposit.h"

enum MenuOption { BALANCE_INQUIRY = 1, WITHDRAWAL , DEPOSIT , EXIT
};

//ATM default constructor
ATM::ATM():userAuth(false), currentAccountNumber(0) //user tidak terautentikasi untuk memulai dan tidak ada account number yang sekarang untuk dimulai
{
}

void ATM::run()
{
	while (true){
		while (!userAuth){
			screen.displayMessageLine("========================");
			screen.displayMessageLine("Welcome to ATM simulator");
			screen.displayMessageLine("========================");
			authUser();
		}
		performTransactions();
		userAuth = false;
	currentAccountNumber = 0;
	screen.displayMessageLine("Thank you ! Good Bye!\n");
	}
}

void ATM::authUser()
{
	screen.displayMessage("Please Enter your account number : ");
	int accountNumber = keypad.getInput(); 
	screen.displayMessage("Enter Your Pin : ");
	int pin = keypad.getInput();
	
	userAuth = bankDb.authenticateUser(accountNumber , pin);
	
	if (userAuth){
		currentAccountNumber = accountNumber;
	}
	else 
	screen.displayMessageLine("Invalid account number or PIN. Please try again.\n ");
}

//menunjukan menu utama dan melakukan transaksi
void ATM::performTransactions()
{
	Transaction *currentTransactionPtr; //pointer local untuk menyimpan transaksi yang sedang diproses
	
	bool userExited = false; //user tidak memilih untuk keluar
	
	//loop while user tidak memilih opsi untuk keluar system
	while (!userExited)
	{
		//menampilkan menu utama dan mendapat pilihan dari user
		int mainMenuSelection = displayMainMenu();
		
		//memutuskan bagaimana untuk memproses berdasarkan pilihan user
		switch(mainMenuSelection)
		{
			//user memilih untuk melakukan salah satu dari 3 tipe transaksi
			case BALANCE_INQUIRY:
			case WITHDRAWAL:
			case DEPOSIT:
				//inisialisasi sebagai objek baru dari tipe yang dipilih
				currentTransactionPtr = createTransaction(mainMenuSelection);
			
				currentTransactionPtr->execute(); //eksekusi transaksi
			
				//membebaskan tempat untuk dynamically allocated transaction
				delete currentTransactionPtr;
			
				break;
			case EXIT: // user memilih untuk menghentikan sesi
				screen.displayMessageLine("Exiting the system ...");
				userExited = true;
				break;
			default: //user tidak input sebuah integer 1-4
				screen.displayMessageLine("You did not enter a valid selection. Try again.");
				break;	
		}
	}
}

//menampilkan menu utama dan mengembalikan sebuah input yang dipilih
int ATM::displayMainMenu() const
{
	screen.displayMessageLine("Main menu:");
	screen.displayMessageLine( "1 - View my balance" );
	screen.displayMessageLine( "2 - Withdraw cash" );
	screen.displayMessageLine( "3 - Deposit funds" );
	screen.displayMessageLine( "4 - Exit" );
	screen.displayMessage( "Enter a choice: " );
	return keypad.getInput(); //mengembalikan pilihan user
}

//mengembalikan object dari class turunan Transaction tertentu
Transaction *ATM::createTransaction(int type)
{
	Transaction *tempPtr; //pointer transaction sementara
	
	//menentukan jenis Transaksi yang akan dibuat
	switch(type)
	{
		case BALANCE_INQUIRY: //membuat transaksi balance inquiry baru
			tempPtr = new BalanceInquiry(currentAccountNumber,screen,bankDb);
			break;
		case WITHDRAWAL:
			tempPtr = new Withdrawal( currentAccountNumber, screen,bankDb, keypad, cashDispenser );
 			break;	
		case DEPOSIT: //membuat transaksi deposit baru
			tempPtr = new Deposit(currentAccountNumber,screen,bankDb,keypad,depositSlot);
			break;	
	}
	
	return tempPtr; //mengembalikan objek yang baru dibuat
}
