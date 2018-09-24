// Gamja Comment
// 
// 이는 "뇌를 자극하는 C++ STL" 책의 내용을 정리하며 실습한 것입니다.
//
// * 함수 호출 연산자 오버로딩 ()
//		1. 객체를 함수처럼 동작하게 하는 연산자 

#include <iostream>

using namespace std;

// C++ struct 키워드 => class 키워드와 동일
// -> 멤버 접근 한정자를 지정하지 않으면 struct는 public이 기본 속성, class는 private가 기본 속성이 됨
struct FuncObject
{
public:
	void operator()(int arg) const
	{
		cout << "정수 : " << arg << endl;
	}

	void operator()(int a, int b) const {
		cout << "정수 : " << a << ", " << b << endl;
	}

	void operator()(int a, int b, int c) const {
		cout << "정수 : " << a << ", " << b << ", " << c << endl;
	}
};
void Print1(int arg);


int main() {
	void(*Print2)(int) = Print1;
	FuncObject Print3;

	cout << "---- 함수를 사용한 정수 출력 ----" << endl;
	Print1(10); //함수를 사용한 정수 출력
	cout << endl;

	cout << "---- 함수 포인터를 사용한 정수 출력 ----" << endl;
	Print2(10);	//함수 포인터를 사ㅏ용한 정수 출력
	cout << endl;

	cout << "---- 함수 객채를 사용한 정수 출력(암시적) ----" << endl;
	Print3(10);	//함수 객체를 사용한 정수 출력
	Print3(10, 20);
	Print3(10, 20, 30);
	cout << endl;

	cout << "---- 함수 객채를 사용한 정수 출력(명시적) ----" << endl;
	Print3.operator()(10);	
	Print3.operator()(10, 20);
	Print3.operator()(10, 20, 30);
	cout << endl;

	cout << "---- 임시 객채를 사용한 정수 출력(암시적) ----" << endl;
	FuncObject()(10);	//임시 객체를 사용한 정수 출력
	FuncObject()(10, 20);
	FuncObject()(10, 20, 30);
	cout << endl;

	cout << "---- 임시 객채를 사용한 정수 출력(명시적) ----" << endl;
	FuncObject().operator()(10);
	FuncObject().operator()(10, 20);
	FuncObject().operator()(10, 20, 30);
	cout << endl;

	// 클래스 이름으로 생성한 임시객체는 해당 문장에서 생성되고 문장 벗어나면 소멸됨 


	return 0;
}

void Print1(int arg) {
	cout << "정수 : " << arg << endl;
}