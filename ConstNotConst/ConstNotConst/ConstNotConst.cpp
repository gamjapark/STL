// Gamja Comment
// 
// �̴� "���� �ڱ��ϴ� C++ STL" å�� ������ �����ϸ� �ǽ��� ���Դϴ�.
//
// *Const ��� �Լ�
//	1. ��� �Լ� ������ ��ü�� ��� ������ �������� �ʴ� �ٴ� ���� ����
//	2. const ��ü�� const ����Լ��� ȣ���� �� ����
//	3. const��� �Լ����� ��� ������ �����Ϸ��� �ϸ� ������ ����

#include <iostream>
using namespace std;

class Point
{
public:
	Point(int X, int Y) : x(X), y(Y){}

	void Print() const {
		cout << "Print : ( " << x << ", " << y << " )" << endl;
	}

	// x�� ��ȯ���ִ� const �Լ� 
	int GetX() const {	
		return x;
	}

	// y�� ��ȯ���ִ� const �Լ� 
	int GetY() const {
		return y;
	}
	
	// x ���� �����ϴ� �� const �Լ�
	void SetX(int X) {
		x = X;
	}

	// y ���� �����ϴ� �� const �Լ�
	void SetY(int Y) {
		y = Y;
	}

private:
	int x;
	int y;

};

int main() {

	const Point ConstObject(0, 0);
	Point NotConstObject(2, 3);

	// Print �Լ��� ȣ���Ͽ� ���
	cout << "Const Object."; ConstObject.Print();
	cout << "Not Const Object."; NotConstObject.Print();
	cout << endl;

	// Get �Լ��� �̿��Ͽ� ���
	cout << "Const Object Get : ( " << ConstObject.GetX() << " ," << ConstObject.GetY() << " )" << endl;
	cout << "Not Const Object Get : ( " << NotConstObject.GetX() << " ," << NotConstObject.GetY() << " )" << endl;
	cout << endl;

	// const ��ü�� ������� ���� �Ұ� => ������ ���� 
	//ConstObject.SetX(4);
	//ConstObject.SetY(4);

	// �� const ��ü�� ������� ���� ���� 
	NotConstObject.SetX(4);
	NotConstObject.SetY(4);

	cout << "Const Object."; ConstObject.Print();
	cout << "Not Const Object."; NotConstObject.Print();
	cout << endl;

	return 0;
}