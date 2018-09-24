// Gamja Comment
// 
// �̴� "���� �ڱ��ϴ� C++ STL" å�� ������ �����ϸ� �ǽ��� ���Դϴ�.
//
// * �޸� ����, Ŭ���� ��� ���� ������ �����ε�
//		1. *, -> �����ڴ� ����Ʈ �����ͳ� �ݺ��� �� Ư���� ��ü�� ���
//			cf) ������ ������ : ������ó�� �����ϴ� Ŭ���� ���ø�(��� ���� �޸� �ڵ� ����)
//		2. �Ϲ� �����͸� ����ϸ� new���� �� delete ������ ȣ������ ������ �޸� ���� �߻�
//		3. ��� �� �Լ� �����ϰų� ���� �� �߻��� �������� �Ҵ��� �޸𸮸� �������� ���ϴ� ���� �߻�

#include <iostream>
using namespace std;

class Point {
public:
	Point(int X = 0, int Y = 0) :x(X), y(Y){}
	void Print() const{
		cout << "Print : ( " << x << ", " << y << " )" << endl;
	}
private:
	int x;
	int y;
};

class PointPtr {
public:
	PointPtr(Point *p) :ptr(p){}
	~PointPtr() { 
		delete ptr; 
	}

	// -> ������ �����ε�
	Point* operator->() const {
		return ptr;				// ��ä.operator->()->Print()�� ȣ���ϴ� ��
	}

	// * ������ �����ε�
	Point& operator*() const {
		return *ptr;			// ��ü.operator*().Print()�� ȣ���ϴ� �� 
	}
private:
	Point *ptr;
};

int main() {

	//�Ϲ����� �޸� �Ҵ� 
	Point *a = new Point(2, 3);
	Point *b = new Point(5, 5);

	cout << "---- Point Class ----" << endl;
	a->Print();
	b->Print();
	cout << endl;

	//�޸� ����
	delete a;
	delete b;

	// ���� delete�� ����Ͽ� �޸𸮸� ���� ������ �־�� ��

	PointPtr c = new Point(2, 3);
	PointPtr d = new Point(5, 5);

	cout << "---- PointPtr Class ----" << endl;
	c->Print(); 
	d->Print();
	cout << endl;

	(*c).Print();
	(*d).Print();
	cout << endl;

	return 0;
}