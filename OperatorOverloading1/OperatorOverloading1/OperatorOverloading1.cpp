// Gamja Comment
// 
// 이는 "뇌를 자극하는 C++ STL" 책의 내용을 정리하며 실습한 것입니다.
//
// *연산자 오버로딩
//	1. 사용자 클래스 타입에 C++ 연산자를 사용할 수 있게 함
//	2. 코드의 직관성, 가독성 좋아짐
//  3. 오버로딩 가능한 단항 연산자 : !, &, ~, *, +, -. ++. -- 형변환 연산자
//  4. 오버로딩 가능한 이항 연산자 : +, -, *, /, ==, !=, <, <= 등
//  5. 종류 
//		1) 멤버 함수를 이용한 연산자 오버로딩 - 일반적으로 사용
//		2) 전역 함수를 이용한 연산자 오버로딩 - 1)을 사용할 수 없을 때 사용
//			ex) 이항 연신의 왼쪽 항이 연산자 오버로딩 객체가 아닌 경우 1)을 사용할 수 없음
//				-> 보통 이항 연산의 왼쪽 객체를 기준으로 연산자 오버로딩 멤버 함수를 호출함

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
	
	// + 연산자 오버로딩
	const Point operator+(Point arg) {
		return Point(this->x + arg.x, this->y + arg.y);
	}
	// - 연산자 오버로딩
	const Point operator-(const Point& arg) const {
		return Point(x - arg.x, y - arg.y);
	}

	// 후위 연산자는 전위 연산자와 구별하기 위해 멤버 함수 호출시 dummy(의미없는) 정수형 인자 0을 전달함

	// 전위 ++ 연산자 오버로딩
	const Point& operator++() {
		++x; ++y;
		return *this;
	}
	// 후위 ++ 연산자 오버로딩
	const Point operator++(int) {
		Point tmp = *this;
		++*this;
		return tmp;
	}
	// 전위 --연산자 오버로딩
	const Point& operator--() {
		--x; --y;
		return *this;
	}
	// 후위 --연산자 오버로딩
	const Point operator--(int) {
		Point tmp = *this;
		--*this;
		return tmp;
	}
	// ==연산자 오버로딩
	bool operator==(const Point& arg) const {
		return (x == arg.x) && (y == arg.y);
	}
	// !=연산자 오버로딩
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

	// 컴파일러가 p1.operator+(p2);로 해석해서 호출;
	cout << "컴파일러가 p1.operator+(p2)로 해석 호출 -> ";
	p3.Print();

	p3 = p1.operator+(p2);
	// 직접 호출
	cout << "직접 호출				-> ";
	p3.Print();
	cout << endl;

	////////////////// operator/////////////////
	cout << "------- -operator -------" << endl;
	p3 = p1 - p2;
	p3.Print();
	cout << endl;

	////////////////// 전위++operator/////////////////
	cout << "------- 전위++operator -------" << endl;
	Point result1 = ++p1; 
	p1.Print();				// (3, 4)
	result1.Print();		// (3, 4)
	cout << endl;

	////////////////// 후위++operator/////////////////
	cout << "------- 후위++operator -------" << endl;

	Point result2 = p2++;
	p2.Print();				// (6, 6)
	result2.Print();		// (5, 5)
	cout << endl;

	////////////////// 전위--operator/////////////////
	cout << "------- 전위--operator -------" << endl;
	Point result3 = --p1;
	p1.Print();				// (2, 3)
	result3.Print();		// (2, 3)
	cout << endl;

	////////////////// 후위--operator/////////////////
	cout << "------- 후위--operator -------" << endl;
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
	if (a == b)	cout << "result : a와 b는 같습니다." << endl;
	if (a == c) cout << "result : a와 c는 같습니다." << endl;
	cout << endl;


	////////////////// !=operator/////////////////
	cout << "------- ==operator -------" << endl;
	cout << "a."; a.Print();
	cout << "b."; b.Print();
	cout << "c."; c.Print();
	if (a != b)	cout << "result : a와 b는 다릅니다." << endl;
	if (a != c) cout << "result : a와 c는 다릅니다." << endl;
	cout << endl;


	return 0;
}