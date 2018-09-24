// Gamja Comment
// 
// �̴� "���� �ڱ��ϴ� C++ STL" å�� ������ �����ϸ� �ǽ��� ���Դϴ�.
//
// * �����Լ��� �̿��� ������ �����ε�
// * friend
//		1. ���� : �Լ� ������, Ŭ���� ������
//		2. �Լ��� Ŭ������ ������� �����ϸ� ��� Ŭ���� ����� �������� ���� ��밡��
//		3. ������ �Լ��� ĸ��ȭ�� ������ �� ���� 


#include <iostream>
using namespace std;


class Point {

public:
	Point(int X = 0, int Y = 0) : x(X), y(Y){}
	
	void Print() const {
		cout << "Print : ( " << x << ", " << y << " )" << endl;
	}
	
	int GetX() const {
		return x;
	}
	int GetY() const {
		return y;
	}

	//������ �Լ��� ����� �����ε� 
	friend const Point operator+(const Point& a, const Point & b);

	// �Ϲ����� ����Լ��� �̿��� ������ �����ε�
	//const Point operator-(const Point& arg) {
	//	return Point(this->x - arg.x, this->y - arg.y);
	//}

private:
	int x;
	int y;
};

//������ �Լ��� �̿�
const Point operator+(const Point & a, const Point & b) {
	return Point(a.x + b.x, a.y + b.y);
}

// �����Լ��� �̿��� ������ �����ε�
const Point operator-(const Point & a, const Point & b) {
	return Point(a.GetX() - b.GetX(), a.GetY() - b.GetY());
}

int main() {
	Point a(2, 3), b(1, 1), c,d;

	c = a - b;
	c.Print();

	c = a + b;
	c.Print();

	return 0;
}