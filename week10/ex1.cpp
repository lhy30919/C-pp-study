#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	string address("경기도 화성시");
	string phone = "010-1234-1234";
	string copyAddress(address);

	cout << address << endl;
	cout << phone << endl;
	cout << copyAddress << endl;
	//c 스트링 방식
	char text[] = { 'L','o','v','e',' ','C','+','+','\0' };
	string title(text);
	cout << title << endl;

	cout << "문자열 입력" << endl;
	cin >> str;
	cout << str << endl;

	cout << "\n문자열을 숫자로 변환 " << endl;
	string s = "123";
	int n = stoi(s);
	cout << "숫자 n = " << n << endl;
	
	cout << "\nstring 객체의 동적 생성" << endl;
	string* pStr = new string("C++");
	cout << *pStr;


	return 0;
}
