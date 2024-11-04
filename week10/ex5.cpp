//������ �ߺ�2
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
	Power operator + (Power op2);
	bool operator ==(Power op2);
	Power& operator +=(Power op2);
};
Power Power::operator+ (Power op2) {
	Power tmp;
	tmp.kick = this->kick + op2.kick;
	tmp.punch = this->punch + op2.punch;

	return tmp;
}
bool Power::operator==(Power op2) {
	bool result;
	if (this->kick == op2.kick && this->punch==op2.punch)
		result = true;
	else
		result = false;

	return result;
}
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

	cout << "< == ������ �ߺ� >" << endl;
	if (a == b)
		cout << "a, b �� �Ŀ��� ����." << endl;
	else
		cout << "a, b �� �Ŀ��� �ٸ���." << endl;

	cout << "\n < += ������ �ߺ� >" << endl;
	a += b;
	a.show();
	
}