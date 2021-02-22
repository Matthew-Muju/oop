/* Array - Variabel yang dapat menyimpan lebih dari satu value dengan tipe data yang sama */

#include <iostream>

using namespace std;

int main(){
	//deklarasi array
	int rata2 = 0, total = 0;
	int grade[3] = {7 , 8 , 9};
	
	for(int i=0; i<3 ; i++){
		total += grade[i];
	}
	rata2 = total / 3;
	cout << "Nilai Rata-rata = " << rata2 << endl;
	
	return 0;	
}
