#include <iostream>

using namespace std;

int main(){
  string nama;
  int umur;

  cout << "Nama : ";
  getline(cin, nama);

  cout << "Umur : ";
  cin >> umur;

  cout << "Nama : " << nama << endl;
  cout << "Umur : " << umur << " Tahun" << endl;

  return 0;
}
