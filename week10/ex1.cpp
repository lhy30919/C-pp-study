#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	string address("��⵵ ȭ����");
	string phone = "010-1234-1234";
	string copyAddress(address);

	cout << address << endl;
	cout << phone << endl;
	cout << copyAddress << endl;
	//c ��Ʈ�� ���
	char text[] = { 'L','o','v','e',' ','C','+','+','\0' };
	string title(text);
	cout << title << endl;

	cout << "���ڿ� �Է�" << endl;
	cin >> str;
	cout << str << endl;

	cout << "\n���ڿ��� ���ڷ� ��ȯ " << endl;
	string s = "123";
	int n = stoi(s);
	cout << "���� n = " << n << endl;
	
	cout << "\nstring ��ü�� ���� ����" << endl;
	string* pStr = new string("C++");
	cout << *pStr;


	return 0;
}
