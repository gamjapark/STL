// Gamja Comment
// 
// �̴� "���� �ڱ��ϴ� C++ STL" å�� ������ �����ϸ� �ǽ��� ���Դϴ�.
//
// *Ÿ�� ��ȯ ������ �����ε�
//		1. �ڽ��� Ÿ���� �ٸ� Ÿ������ ��ȯ�� �� ����


#include <iostream>
using namespace std;

class A {
};

class B {
public:
	operator A() {
		cout << "Operator A() ȣ��" << endl;
		return A();
	}

	operator int() {
		cout << "operator int() ȣ��" << endl;
		return 10;
	}

	operator double() {
		cout << "operator double() ȣ��" << endl;
		return 5.5;
	}
};

int main() {

	A a, a_;
	int n, N;
	double d, D;

	B b;

	//�Ͻ��� ȣ��
	a = b;
	n = b;
	d = b;
	cout << endl;

	//����� ȣ��
	a_ = b.operator A();
	N = b.operator int();
	D = b.operator double();

	return 0;
}
