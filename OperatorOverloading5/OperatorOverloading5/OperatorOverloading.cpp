// Gamja Comment
// 
// 이는 "뇌를 자극하는 C++ STL" 책의 내용을 정리하며 실습한 것입니다.
//
// * 메모리 접근, 클래스 멤버 접근 연산자 오버로딩
//		1. *, -> 연산자는 스마트 포인터나 반복자 등 특수한 객체에 사용
//			cf) 스마프 포인터 : 포인터처럼 동작하는 클래스 템플릿(사용 끝난 메모리 자동 해제)
//		2. 일반 포인터를 사용하면 new연산 후 delete 연산을 호출하지 않으면 메모리 누수 발생
//		3. 사용 중 함수 종료하거나 예외 등 발생시 동적으로 할당한 메모리를 해제하지 못하는 문제 발샘

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

	// -> 연산자 오버로딩
	Point* operator->() const {
		return ptr;				// 객채.operator->()->Print()를 호출하는 것
	}

	// * 연산자 오버로딩
	Point& operator*() const {
		return *ptr;			// 객체.operator*().Print()를 호출하는 것 
	}
private:
	Point *ptr;
};

int main() {

	//일반적인 메모리 할당 
	Point *a = new Point(2, 3);
	Point *b = new Point(5, 5);

	cout << "---- Point Class ----" << endl;
	a->Print();
	b->Print();
	cout << endl;

	//메모리 해제
	delete a;
	delete b;

	// 위는 delete를 사용하여 메모리를 직접 해제해 주어야 함

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