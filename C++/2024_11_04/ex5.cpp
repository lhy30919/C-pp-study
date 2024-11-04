//연산자 중복2
#include <iostream>
#include <string>
using namespace std;

class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick;
		this->punch = punch;
	}
	void show() {
		cout << "kick = " << kick << ", punch = " << punch << endl;
	}
	//클래스의 내부 함수로 연산자 중복 정의
	Power operator + (Power op2);
	bool operator ==(Power op2);
	Power& operator +=(Power op2);

	//외부 함수로 연산자 중복 정의
	friend Power operator + (int op1, Power op2);
};
// 내부함수 + 연산자 중복
Power Power::operator+ (Power op2) {
	Power tmp;
	tmp.kick = this->kick + op2.kick;
	tmp.punch = this->punch + op2.punch;

	return tmp;
}
// 전역함수 + 연산자 중복
Power operator+(int op1, Power op2) {
	Power tmp;
	tmp.kick = op1 + op2.kick;
	tmp.punch = op1 + op2.punch;
	return tmp;
}
// 내부함수 == 연산자 중복
bool Power::operator==(Power op2) {
	bool result;
	if (this->kick == op2.kick && this->punch==op2.punch)
		result = true;
	else
		result = false;

	return result;
}
// 내부함수 += 연산자 중복
Power& Power::operator+=(Power op2) {
	this->kick += op2.kick;
	this->punch += op2.punch;
	return *this;
}

int main() {
	Power a(3, 5), b(4, 6), c;
	c = a + b;

	a.show();
	b.show();
	c.show();

	cout << "< == 연산자 중복 >" << endl;
	if (a == b)
		cout << "a, b 두 파워가 같다." << endl;
	else
		cout << "a, b 두 파워가 다르다." << endl;

	cout << "\n < += 연산자 중복 >" << endl;
	a += b;
	a.show();
	
	cout << "\n < 오른쪽 피연산자가 상수인 경우 연산자 중복 > " << endl;
	
	c = a + 2;
	c.show();

	cout << "\n < 왼쪽 피연산자가 상수인 경우 연산자 중복 > " << endl;

	c = 2 + a;
	c.show();

}