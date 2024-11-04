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
	//Ŭ������ ���� �Լ��� ������ �ߺ� ����
	Power operator + (Power op2);
	bool operator ==(Power op2);
	Power& operator +=(Power op2);

	// ���� �ǿ����ڰ� �⺻������ ���� ��� �ܺ��Լ��� �����ϰ�  freind
	friend Power operator + (int op1, Power op2);

	//++a �� ������ �ߺ� �����ϴ� ���
	Power& operator ++();
	//a++ �� ������ �ߺ� �����ϴ� ���(�Ű����� �ʿ�)
	Power operator ++(int x);
	

};
//a++�� ������ �ߺ� �����ϴ� ���
Power Power::operator++(int x) {
	Power tmp = *this; // �ٲ�� ���� ���� ���� ��ü
	this->kick++;
	this->punch++;
	return tmp;		//�����ϱ� ���� ���� ���� ��ü�� ����
}
//++a ������ �ߺ�
Power& Power::operator++() {
	this->kick++;
	this->punch++;
	return *this;
}
// �����Լ� + ������ �ߺ�
Power Power::operator+ (Power op2) {
	Power tmp;
	tmp.kick = this->kick + op2.kick;
	tmp.punch = this->punch + op2.punch;

	return tmp;
}
// �����Լ� + ������ �ߺ�
Power operator+(int op1, Power op2) {
	Power tmp;
	tmp.kick = op1 + op2.kick;
	tmp.punch = op1 + op2.punch;
	return tmp;
}
// �����Լ� == ������ �ߺ�
bool Power::operator==(Power op2) {
	bool result;
	if (this->kick == op2.kick && this->punch==op2.punch)
		result = true;
	else
		result = false;

	return result;
}
// �����Լ� += ������ �ߺ�
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
	
	cout << "\n < ������ �ǿ����ڰ� ����� ��� ������ �ߺ� > " << endl;
	c = a + 2;
	c.show();

	cout << "\n < ���� �ǿ����ڰ� ����� ��� ������ �ߺ� > " << endl;
	c = 2 + a;
	c.show();

	cout << "\n < ++a ������ �ߺ� >" << endl;
	a.show();
	c = ++a;
	c.show();

	cout << "\n < a++ ������ �ߺ� >" << endl;
	a.show();
	c = a++;
	c.show();
}