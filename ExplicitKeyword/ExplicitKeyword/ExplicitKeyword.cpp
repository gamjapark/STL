// Gamja Comment
// 
// �̴� "���� �ڱ��ϴ� C++ STL" å�� ������ �����ϸ� �ǽ��� ���Դϴ�.
//
// * explicit Keyword
//		���� ���, Ŭ���� ��ü�� ������ ���� ���� ���� ��,
//		������ ���ڷ� �޴� �����ڰ� ������ �����Ϸ��� �ش� �����ڸ� ȣ�⿡ ��ü�� ������
//		-> �̷��� �ϸ� �Ǽ��� ���� ���� �����ص� �������� �����Ͽ� ���װ� ��
//		-> ������ �̿��� ����ȯ�� �ǵ�ġ �ʴ´ٸ� �����ڴ� ����� ȣ�⸸ �����ϵ��� explicit Ű���带 ����

#include <iostream>
using namespace std;

class Point {

public:
	explicit Point(int X = 0, int Y = 0):x(X), y(Y){}
	void Print() const {
		cout << "Print : ( " << x << ", " << y << " )" << endl;
	}
private:
	int x;
	int y;
};

int main() {

	Point a;
	a.Print();

	//explicit Ű���带 �������� �ʾ��� ���, ������ ���ڷ� �޴� �����ڰ� �ֱ⶧���� Point(10,0)�� ȣ���ؼ� ����
	//a = 10;
	//a.Print();

	//explicit Ű���带 ������ ���, ��������� ȣ���� ��쿡�� ��� ����
	a = Point(10);
	a.Print();

	

	return 0;
}
