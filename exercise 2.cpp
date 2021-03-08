#include <iostream>

using namespace std;

class tollBooth{
	private :
		unsigned int numCars;
		float money;
	public :
		tollBooth(){
			this->numCars = 0;
			this->money = 0;
		}
		void payingCar(){
			this->numCars++;
			this->money+=0.50;
		}
		void nopayCar(){
			this->numCars++;
		}
		void display(){
			cout << "Number of Cars = " << numCars << endl;
			cout << "Amount of Money = " << money << endl;
		}
};

int main(){
	int menuCh;
	tollBooth test;
	
	do{
		cout << "Menu For Test TollBooth Program" << endl;
		cout << "1. For Paying Cars" << endl;
		cout << "2. For non-Paying Cars" << endl;
		cout << "3. Exit & Display" << endl;
		cout << "Enter Your Choice : ";
		cin >> menuCh;
		switch(menuCh){
			case 1:
				test.payingCar();
				cout << "==================" << endl;
				cout << "Car Has Been Added" << endl;
				cout << "==================" << endl;
				break;
			case 2:
				test.nopayCar();
				cout << "==================" << endl;
				cout << "Car Has Been Added" << endl;
				cout << "==================" << endl;
				break;
			case 3:
				test.display();
				break;
				
		}
	}while(menuCh !=3);
	
	return 0;
}
