#include <iostream>

using namespace std;

class employees{
	private :
		int empNum;
		float empComp;
	public :
		void input(){
			cout << "Input Employee Number = ";
			cin >> empNum;
			cout << "Input Employee Compensation = ";
			cin >> empComp;
		}
		void display(){
			cout << "Employee Number = " << empNum << endl;
			cout << "Employee Compensation = " << empComp << endl;
		}
};

int main(){
	employees emp1;
	employees emp2;
	employees emp3;
	
	emp1.input();
	emp1.display();
	emp2.input();
	emp2.display();
	emp3.input();
	emp3.display();
	return 0;
}
