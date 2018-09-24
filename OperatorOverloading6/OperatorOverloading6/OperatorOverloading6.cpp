// Gamja Comment
// 
// 이는 "뇌를 자극하는 C++ STL" 책의 내용을 정리하며 실습한 것입니다.
//
// * 타입 변환 연산자 오버로딩
//		1. 사용자가 직접 정의해서 사용할 수 있는 타입 변환 종류
//			1) 생성자를 이용한 타입 변환
//			2) 타입 변환 연산자 오버로딩을 이용한 타입 변환
// * 생성자를 이용한 타입 변환
//		1. 특정 타입을 인자로 받는 생성자가 있으면 객체 생성 후 대입이 가능함
//		2. 생성자로 다른 타입을 자신의 타입으로 변환 가능

#include <iostream>
using namespace std;

class A {

};

class B {
public:
	B() {
		cout << " B() 생성자" << endl;
	}

	//class A 타입의 객체를 인자로 받는 생성자가 있기 때문에
	// 이 생성자를 호출해 B타입의 객체를 생성
	B(A& a) {
		cout << "B(A a) 생성자" << endl;
	}

	B(int n) {
		cout << "B(int n) 생성자" << endl;
	}
	B(double d) {
		cout << "B(double d) 생성자" << endl;
	}
};

int main() {
	A a;
	int n = 10;
	double d = 5.5;

	//생성자 호출 
	B b;

	//각각 암시적 생성자 호출 후 대입 
	b = a;
	b = n;
	b = d;

	return 0;
}