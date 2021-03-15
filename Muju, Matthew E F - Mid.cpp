#include <iostream>

using namespace std;

class nilai{
	private :
		float sum;
		float assignment;
		float quiz;
		float attendance;
		float mid;
		float final;
		float nilai1 , nilai2 , nilai3 , nilai4 , nilai5;
	public :
		int inputAssingment(){
			cout << "Assingment : ";
			cin >> this->assignment;
			this->nilai1 = (this->assignment*20)/100;
		}
		int inputQuiz(){
			cout << "Quiz : ";
			cin >> this->quiz;
			this->nilai2 = (this->quiz*10)/100;
		}
		int inputAttendance(){
			cout << "Attendance : ";
			cin >> this->attendance;
			this->nilai3 = (this->attendance*10)/100;
		}
		int inputMid(){
			cout << "Mid Exam : ";
			cin >> this->mid;
			this->nilai4 = (this->mid*30)/100;
		}
		int inputFinal(){
			cout << "Final Exam : ";
			cin >> this->final;
			this->nilai5 = (this->final*30)/100;
		}
		int summary(){
			this->sum = this->nilai1 + this->nilai2 + this->nilai3 + this->nilai4 + this->nilai5;
			cout << "Grade Anda : " << sum;
		}
		int gradesystem(){
			int grade = this->sum;
			if (this->sum >= 0 && this->sum <= 39){
				cout << " (F)" << endl;
			}
			else if (this->sum >=40 && this->sum <= 59){
				cout <<" (D)" << endl;
			}
			else if (this->sum >=60 && this->sum <= 66){
				cout <<" (C-)" << endl;
			}
			else if (this->sum >=67 && this->sum <= 69){
				cout <<" (C)" << endl;
			}
			else if (this->sum >=70 && this->sum <= 74){
				cout <<" (C+)" << endl;
			}
			else if (this->sum >=75 && this->sum <= 77){
				cout <<" (B-)" << endl;
			}
			else if (this->sum >=78 && this->sum <= 81){
				cout <<" (B)" << endl;
			}
			else if (this->sum >=82 && this->sum <= 84){
				cout <<" (B+)" << endl;
			}
			else if (this->sum >=85 && this->sum <= 90){
				cout <<" (A-)" << endl;
		    }
			else if (this->sum >=91 && this->sum <= 100){
				cout <<" (A)" << endl;
			}
			else {
				cout << "No Matching -- Error Input";
			}
		}
};

int main(){
	int mahasiswa;
	nilai test;
	
	cout << ">>>>>>>>>>>><<<<<<<<<<<<<" << endl;
	cout << "GRADING SYSTEM BY MATTHEW" << endl;
	cout << "^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
	
	cout << "Masukan Jumlah Mahasiswa : ";
	cin >> mahasiswa;
	for(int j=1 ; j<=mahasiswa ; j++){
		cout <<"Masukan Nilai Mahasiswa "<< j << endl;
		test.inputAssingment();
		test.inputQuiz();
		test.inputAttendance();
		test.inputMid();
		test.inputFinal();
		test.summary();
		test.gradesystem();
	}
	
	return 0;
}
