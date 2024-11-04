	//������ �ߺ�
#include <iostream>
#include <string>
using namespace std;

class Color {
	string color;
public:
	Color() {}
	Color(string color) {
		this->color = color;
	}
	void show() {
		cout << "color = " << color << endl;
	}
	//Ŭ������ ����Լ��� ������ �ߺ� ����
//	Color operator +(Color op2);
	bool operator == (Color op2);

	//�ܺ� �Լ��� ������ ��� friend ó��
	friend Color operator+(Color op1, Color op2);

};
bool Color::operator==(Color op2) {
	bool result;
	if (this->color == op2.color)
		result = true;
	else 
		result = false;

	return result;
}

/*
Color Color::operator +(Color op2) {
	Color tmp;
	if (this->color == "BLUE" && op2.color == "RED")
		tmp.color = "PURPLE";
	return tmp;
}
*/
	//�ܺ��Լ�(�����Լ�)�� ������ �ߺ� ����
Color operator + (Color op1, Color op2) {
	Color tmp;
	if (op1.color == "BLUE" && op2.color == "RED")
		tmp.color = "PURPLE";
	return tmp;
}
int main() {
	Color a("BLUE"), b("RED"), c;
	c = a + b;
	a.show();
	b.show();
	c.show();

	cout << "< ���� �� >" << endl;
	if (a == b)
		cout << "a�� b�� ������ ����." << endl;
	else
		cout << "a�� b�� ������ �ٸ���." << endl;

}