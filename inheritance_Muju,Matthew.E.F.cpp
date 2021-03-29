#include <iostream>
#include <string>

using namespace std;

class Person {
	private :
		string name;
		char gender;
	public :
		Person(){}
		void setName(string newname = ""){
			name = newname;
		}
		void setGender(char newgender){
			gender = newgender;
		}
		string getName(){
			return name;
		}
		char getGender(){
			return gender;
		}
};

class Teacher : public Person{
	private :
		int nik;
		string faculty;
	public :
		void setNik(int newnik){
			nik = newnik;
		}
		int getNik(){
			return nik;
		}
		void setFaculty(string newfaculty = ""){
			faculty = newfaculty;
		}
		string getFaculty(){
			return faculty;
		}
		void setData(){
		}
		void displayData(){
		}
};

class Student : public Person {
	private :
		int nim;
		string regNum;
		string prodi;
	public :
		void setNim(int newnim){
			nim = newnim;
		}
		void setRegNum(string newregNum = ""){
			regNum = newregNum;
		}
		void setProdi(string newprodi = ""){
			prodi = newprodi;
		}
		int getNim(){
			return nim;
		}
		string getRegNum(){
			return regNum;
		}
		string getProdi(){
			return prodi;
		}
};

int main(){
	Teacher a;
	Student b;
	cout << "==============================" << endl;
	cout << "Teacher Data" << endl;
	cout << "==============================" << endl;
	a.setName("Reymon Rotikan");
	cout << "Name : " << a.getName();
	cout << endl;
	a.setGender('M');
	cout << "Gender : " << a.getGender();
	cout << endl;
	a.setNik(1010218);
	cout << "NIK : " << a.getNik();
	cout << endl;
	a.setFaculty("Ilmu Komputer");
	cout << "Faculty : " << a.getFaculty();
	cout << endl;
	cout << endl;
	
	cout << "==============================" << endl;
	cout << "Student Data" << endl;
	cout << "==============================" << endl;
	b.setName("Matthew Muju");
	cout << "Name : " << b.getName();
	cout << endl;
	b.setGender('M');
	cout << "Gender : " << b.getGender();
	cout << endl;
	b.setNim(1050212);
	cout << "NIM : " << b.getNim();
	cout << endl;
	b.setRegNum("S21810058");
	cout << "Registration Number : " << b.getRegNum();
	cout << endl;
	b.setProdi("Teknik Informatika");
	cout << "Prodi : " << b.getProdi();
	cout << endl;
	
	
	return 0;
}
