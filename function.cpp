/* Function di C++ */

#include <iostream>

using namespace std;

//Fungsi yang tidak mengembalikan nilai dan tidak ada parameter
void welcomemess(){
	cout <<"===============================" <<endl;
	cout <<"Welcome to Grading System v1.00" <<endl;
	cout <<"===============================" <<endl;
}

//Funfsi yang tidak mengembalikan nilai dan ada parameter

void input(string nama, string gender, int age){
	cout << endl << "Nama : "; getline(cin,nama);
	cout << endl << "Gender : "; cin >> gender;
	cout << endl << "Umur : "; cin >> age;
	
	//Tampilan data dari inputtan user
	cout << endl << endl << "Dibawah ini adalah identitas anda" << endl;
	cout << endl << "Nama Anda : " << nama << endl << "Gender Anda : " << gender ;
	cout << endl << "Umur anda : " << age << " Tahun." << endl;
}

//Fungsi yang mengembalikan nilai dan ada parameter

int rata2grade (int grade[] , int length){
	int rata2 = 0, total = 0;
	for(int i=0; i<length ; i++){
		total += grade[i];
	}
	return rata2 = total / 3;
}

int main(){
	int grade[] = {7 , 8 , 9};
	int sizeofgrade = sizeof(grade)/sizeof(grade[0]);
	
	welcomemess();
	input("Matthew" , "M" , 20);
	
	cout << "Average = " << rata2grade(grade , sizeofgrade) << endl;
	
	return 0;
}
