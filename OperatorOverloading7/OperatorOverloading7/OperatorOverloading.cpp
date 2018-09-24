// Gamja Comment
// 
// 이는 "뇌를 자극하는 C++ STL" 책의 내용을 정리하며 실습한 것입니다.
//
// *타입 변환 연산자 오버로딩
//		1. 자신의 타입을 다른 타입으로 변환할 수 있음


#include <iostream>
using namespace std;

class A {
};

class B {
public:
	operator A() {
		cout << "Operator A() 호출" << endl;
		return A();
	}

	operator int() {
		cout << "operator int() 호출" << endl;
		return 10;
	}

	operator double() {
		cout << "operator double() 호출" << endl;
		return 5.5;
	}
};

int main() {

	A a, a_;
	int n, N;
	double d, D;

	B b;

	//암시적 호출
	a = b;
	n = b;
	d = b;
	cout << endl;

	//명시적 호출
	a_ = b.operator A();
	N = b.operator int();
	D = b.operator double();

	return 0;
}
