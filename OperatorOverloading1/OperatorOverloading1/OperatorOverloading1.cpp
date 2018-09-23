// Gamja Comment
// 
// �̴� "���� �ڱ��ϴ� C++ STL" å�� ������ �����ϸ� �ǽ��� ���Դϴ�.
//
// *������ �����ε�
//	1. ����� Ŭ���� Ÿ�Կ� C++ �����ڸ� ����� �� �ְ� ��
//	2. �ڵ��� ������, ������ ������
//  3. �����ε� ������ ���� ������ : !, &, ~, *, +, -. ++. -- ����ȯ ������
//  4. �����ε� ������ ���� ������ : +, -, *, /, ==, !=, <, <= ��
//  5. ���� 
//		1) ��� �Լ��� �̿��� ������ �����ε� - �Ϲ������� ���
//		2) ���� �Լ��� �̿��� ������ �����ε� - 1)�� ����� �� ���� �� ���
//			ex) ���� ������ ���� ���� ������ �����ε� ��ü�� �ƴ� ��� 1)�� ����� �� ����
//				-> ���� ���� ������ ���� ��ü�� �������� ������ �����ε� ��� �Լ��� ȣ����

#include <iostream>
using namespace std;

class Point
{
public:
	Point(int X = 0, int Y = 0) : x(X), y(Y) {

	}
	
	void Print() const {
		cout << "Print : ( " << x << ", " << y << " )" << endl;
	}
	
	// + ������ �����ε�
	const Point operator+(Point arg) {
		return Point(this->x + arg.x, this->y + arg.y);
	}
	// - ������ �����ε�
	const Point operator-(const Point& arg) const {
		return Point(x - arg.x, y - arg.y);
	}

	// ���� �����ڴ� ���� �����ڿ� �����ϱ� ���� ��� �Լ� ȣ��� dummy(�ǹ̾���) ������ ���� 0�� ������

	// ���� ++ ������ �����ε�
	const Point& operator++() {
		++x; ++y;
		return *this;
	}
	// ���� ++ ������ �����ε�
	const Point operator++(int) {
		Point tmp = *this;
		++*this;
		return tmp;
	}
	// ���� --������ �����ε�
	const Point& operator--() {
		--x; --y;
		return *this;
	}
	// ���� --������ �����ε�
	const Point operator--(int) {
		Point tmp = *this;
		--*this;
		return tmp;
	}
	// ==������ �����ε�
	bool operator==(const Point& arg) const {
		return (x == arg.x) && (y == arg.y);
	}
	// !=������ �����ε�
	bool operator!=(const Point& arg) const {
		return !(*this == arg);
	}


private:
	int x;
	int y;
};

int main() {
	Point p1(2, 3), p2(5, 5), p3;
	
	
	////////////////// +operator/////////////////
	cout << "------- +operator -------" << endl;
	p3 = p1 + p2;

	// �����Ϸ��� p1.operator+(p2);�� �ؼ��ؼ� ȣ��;
	cout << "�����Ϸ��� p1.operator+(p2)�� �ؼ� ȣ�� -> ";
	p3.Print();

	p3 = p1.operator+(p2);
	// ���� ȣ��
	cout << "���� ȣ��				-> ";
	p3.Print();
	cout << endl;

	////////////////// operator/////////////////
	cout << "------- -operator -------" << endl;
	p3 = p1 - p2;
	p3.Print();
	cout << endl;

	////////////////// ����++operator/////////////////
	cout << "------- ����++operator -------" << endl;
	Point result1 = ++p1; 
	p1.Print();				// (3, 4)
	result1.Print();		// (3, 4)
	cout << endl;

	////////////////// ����++operator/////////////////
	cout << "------- ����++operator -------" << endl;

	Point result2 = p2++;
	p2.Print();				// (6, 6)
	result2.Print();		// (5, 5)
	cout << endl;

	////////////////// ����--operator/////////////////
	cout << "------- ����--operator -------" << endl;
	Point result3 = --p1;
	p1.Print();				// (2, 3)
	result3.Print();		// (2, 3)
	cout << endl;

	////////////////// ����--operator/////////////////
	cout << "------- ����--operator -------" << endl;
	Point result4 = p2--;
	p2.Print();				// (5, 5)
	result4.Print();		// (6, 6)
	cout << endl;

	////////////////// ==operator/////////////////
	cout << "------- ==operator -------" << endl;
	Point a(1, 1), b(2, 2), c(1, 1);
	cout << "a."; a.Print();
	cout << "b."; b.Print();
	cout << "c."; c.Print();
	if (a == b)	cout << "result : a�� b�� �����ϴ�." << endl;
	if (a == c) cout << "result : a�� c�� �����ϴ�." << endl;
	cout << endl;


	////////////////// !=operator/////////////////
	cout << "------- ==operator -------" << endl;
	cout << "a."; a.Print();
	cout << "b."; b.Print();
	cout << "c."; c.Print();
	if (a != b)	cout << "result : a�� b�� �ٸ��ϴ�." << endl;
	if (a != c) cout << "result : a�� c�� �ٸ��ϴ�." << endl;
	cout << endl;


	return 0;
}