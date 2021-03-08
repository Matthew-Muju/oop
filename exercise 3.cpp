#include <iostream>

using namespace std;

class time{
	private :
		int hours;
		int minutes;
		int seconds;
	public :
		time(){
			this->hours = 0;
			this->minutes = 0;
			this->seconds = 0;
		}
		time (int hours, int minutes, int seconds){
			this->hours = hours;
			this->minutes = minutes;
			this->seconds = seconds;
		}
		int getHours(){
			return this->hours;
		}
		int getMinutes(){
			return this->minutes;
		}
		int getSeconds(){
			return this->seconds;
		}
		void display(){
			cout << "Time = " << hours << ":" << minutes << ":" << seconds << endl;
		}
		time add(time var1, time var2){
			int addHours = var1.getHours() + var2.getHours();
			if(addHours > 23){
				addHours -= 24;
			}
			int addMinutes = var1.getMinutes() + var2.getMinutes();
			if(addMinutes > 59){
				addMinutes -= 60;
			}
			int addSeconds = var1.getSeconds() + var2.getSeconds();
			if(addSeconds > 59){
				addSeconds -= 60;
			}
			
			time var3(addHours , addMinutes , addSeconds);
			return var3;
		}
};

int main(){
	time var1(12 ,40 ,30);
	time var2(21, 22, 23);
	time var3;
	var3 = var3.add(var1 , var2);
	var1.display();
	var2.display();
	var3.display();

	return 0;
}
