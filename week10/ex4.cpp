	//연산자 중복
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
	//클래스의 멤버함수로 연산자 중복 정의
//	Color operator +(Color op2);
	bool operator == (Color op2);

	//외부 함수로 정의한 경우 friend 처리
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
	//외부함수(전역함수)로 연산자 중복 정의
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

	cout << "< 색상 비교 >" << endl;
	if (a == b)
		cout << "a와 b는 색상이 같다." << endl;
	else
		cout << "a와 b는 색상이 다르다." << endl;

}