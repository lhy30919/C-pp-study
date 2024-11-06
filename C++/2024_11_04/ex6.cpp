#include<iostream>
#include<string>
using namespace std;
class Car {
	string model;
	int speed;
public:
	Car(string model, int speed) {
		this->model = model;
		this->speed = speed;
	}
	Car& operator +=(Car op2);
	Car& operator -=(Car op2);
	void show() {
		cout << model << " speed = " << speed << endl;	}
};
Car& Car::operator+=(Car op2) {
	this->speed += op2.speed;
	return *this;	}
Car& Car::operator-=(Car op2) {
	this->speed -= op2.speed;
	return *this;	}
int main() {
	Car myCar("그랜저", 100);
	Car yourCar("아반떼", 70);
	myCar.show();
	yourCar.show();
	cout << "\n< myCar += yourCar 결과 >" << endl;
	myCar += yourCar;
	myCar.show();
	cout << "\n< myCar -= yourCar 결과 >" << endl;
	myCar -= yourCar;
	myCar.show();
}