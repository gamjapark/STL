// Gamja Comment
// 
// 이는 "뇌를 자극하는 C++ STL" 책의 내용을 정리하며 실습한 것입니다.
//
// * 전역함수를 이용한 연산자 오버로딩
// * friend
//		1. 종류 : 함수 프렌드, 클래스 프렌드
//		2. 함수나 클래스를 프렌드로 지정하면 모든 클래스 멤버를 접근제한 없이 사용가능
//		3. 프렌드 함수는 캡슐화를 저해할 수 있음 


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

	//프랜드 함수를 사용한 오버로딩 
	friend const Point operator+(const Point& a, const Point & b);

	// 일반적인 멤버함수를 이용한 연산자 오버로딩
	//const Point operator-(const Point& arg) {
	//	return Point(this->x - arg.x, this->y - arg.y);
	//}

private:
	int x;
	int y;
};

//프렌드 함수를 이용
const Point operator+(const Point & a, const Point & b) {
	return Point(a.x + b.x, a.y + b.y);
}

// 전역함수를 이용한 연산자 오버로딩
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