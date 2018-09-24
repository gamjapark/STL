// Gamja Comment
// 
// �̴� "���� �ڱ��ϴ� C++ STL" å�� ������ �����ϸ� �ǽ��� ���Դϴ�.
//
// * Ÿ�� ��ȯ ������ �����ε�
//		1. ����ڰ� ���� �����ؼ� ����� �� �ִ� Ÿ�� ��ȯ ����
//			1) �����ڸ� �̿��� Ÿ�� ��ȯ
//			2) Ÿ�� ��ȯ ������ �����ε��� �̿��� Ÿ�� ��ȯ
// * �����ڸ� �̿��� Ÿ�� ��ȯ
//		1. Ư�� Ÿ���� ���ڷ� �޴� �����ڰ� ������ ��ü ���� �� ������ ������
//		2. �����ڷ� �ٸ� Ÿ���� �ڽ��� Ÿ������ ��ȯ ����

#include <iostream>
using namespace std;

class A {

};

class B {
public:
	B() {
		cout << " B() ������" << endl;
	}

	//class A Ÿ���� ��ü�� ���ڷ� �޴� �����ڰ� �ֱ� ������
	// �� �����ڸ� ȣ���� BŸ���� ��ü�� ����
	B(A& a) {
		cout << "B(A a) ������" << endl;
	}

	B(int n) {
		cout << "B(int n) ������" << endl;
	}
	B(double d) {
		cout << "B(double d) ������" << endl;
	}
};

int main() {
	A a;
	int n = 10;
	double d = 5.5;

	//������ ȣ�� 
	B b;

	//���� �Ͻ��� ������ ȣ�� �� ���� 
	b = a;
	b = n;
	b = d;

	return 0;
}