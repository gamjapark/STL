// Gamja Comment
// 
// �̴� "���� �ڱ��ϴ� C++ STL" å�� ������ �����ϸ� �ǽ��� ���Դϴ�.
//
// * �Լ� ȣ�� ������ �����ε� ()
//		1. ��ü�� �Լ�ó�� �����ϰ� �ϴ� ������ 

#include <iostream>

using namespace std;

// C++ struct Ű���� => class Ű����� ����
// -> ��� ���� �����ڸ� �������� ������ struct�� public�� �⺻ �Ӽ�, class�� private�� �⺻ �Ӽ��� ��
struct FuncObject
{
public:
	void operator()(int arg) const
	{
		cout << "���� : " << arg << endl;
	}

	void operator()(int a, int b) const {
		cout << "���� : " << a << ", " << b << endl;
	}

	void operator()(int a, int b, int c) const {
		cout << "���� : " << a << ", " << b << ", " << c << endl;
	}
};
void Print1(int arg);


int main() {
	void(*Print2)(int) = Print1;
	FuncObject Print3;

	cout << "---- �Լ��� ����� ���� ��� ----" << endl;
	Print1(10); //�Լ��� ����� ���� ���
	cout << endl;

	cout << "---- �Լ� �����͸� ����� ���� ��� ----" << endl;
	Print2(10);	//�Լ� �����͸� �礿���� ���� ���
	cout << endl;

	cout << "---- �Լ� ��ä�� ����� ���� ���(�Ͻ���) ----" << endl;
	Print3(10);	//�Լ� ��ü�� ����� ���� ���
	Print3(10, 20);
	Print3(10, 20, 30);
	cout << endl;

	cout << "---- �Լ� ��ä�� ����� ���� ���(�����) ----" << endl;
	Print3.operator()(10);	
	Print3.operator()(10, 20);
	Print3.operator()(10, 20, 30);
	cout << endl;

	cout << "---- �ӽ� ��ä�� ����� ���� ���(�Ͻ���) ----" << endl;
	FuncObject()(10);	//�ӽ� ��ü�� ����� ���� ���
	FuncObject()(10, 20);
	FuncObject()(10, 20, 30);
	cout << endl;

	cout << "---- �ӽ� ��ä�� ����� ���� ���(�����) ----" << endl;
	FuncObject().operator()(10);
	FuncObject().operator()(10, 20);
	FuncObject().operator()(10, 20, 30);
	cout << endl;

	// Ŭ���� �̸����� ������ �ӽð�ü�� �ش� ���忡�� �����ǰ� ���� ����� �Ҹ�� 


	return 0;
}

void Print1(int arg) {
	cout << "���� : " << arg << endl;
}