// Gamja Comment
// 
// 이는 "뇌를 자극하는 C++ STL" 책의 내용을 정리하며 실습한 것입니다.
//
// *Const 멤버 함수
//	1. 멤버 함수 내에서 객체의 멤버 변수를 변경하지 않는 다는 것을 보장
//	2. const 객체는 const 멤버함수만 호출할 수 있음
//	3. const멤버 함수에서 멤버 변수를 변경하려고 하면 컴파일 에러

#include <iostream>
using namespace std;

class Point
{
public:
	Point(int X, int Y) : x(X), y(Y){}

	void Print() const {
		cout << "Print : ( " << x << ", " << y << " )" << endl;
	}

	// x를 반환해주는 const 함수 
	int GetX() const {	
		return x;
	}

	// y를 반환해주는 const 함수 
	int GetY() const {
		return y;
	}
	
	// x 값을 변경하는 비 const 함수
	void SetX(int X) {
		x = X;
	}

	// y 값을 변경하는 비 const 함수
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

	// Print 함수를 호출하여 출력
	cout << "Const Object."; ConstObject.Print();
	cout << "Not Const Object."; NotConstObject.Print();
	cout << endl;

	// Get 함수를 이용하여 출력
	cout << "Const Object Get : ( " << ConstObject.GetX() << " ," << ConstObject.GetY() << " )" << endl;
	cout << "Not Const Object Get : ( " << NotConstObject.GetX() << " ," << NotConstObject.GetY() << " )" << endl;
	cout << endl;

	// const 객체의 멤버변수 변경 불가 => 컴파일 에러 
	//ConstObject.SetX(4);
	//ConstObject.SetY(4);

	// 비 const 객체의 멤버변수 변경 가능 
	NotConstObject.SetX(4);
	NotConstObject.SetY(4);

	cout << "Const Object."; ConstObject.Print();
	cout << "Not Const Object."; NotConstObject.Print();
	cout << endl;

	return 0;
}