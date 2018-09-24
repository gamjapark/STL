// Gamja Comment
// 
// 이는 "뇌를 자극하는 C++ STL" 책의 내용을 정리하며 실습한 것입니다.
//
// * 배열 인덱스 연산자 오버로딩 []
//		1. 배열에 사용하는 [] 연산자를 객체에도 사용할 수 있음
//		2. 일반적으로 많은 객체를 저장하고 관리하는 객체에 사용됨
//		3. 일반적으로 컨테이너 객체에 사용 -> 컨테이너 객체가 관리하는 내부 원소에 접근시 사용

#include <iostream>
using namespace std;

class Array {

public:
	Array(int cap = 100) : arr(0), size(0), capacity(cap) {
		arr = new int[capacity];
	}
	~Array() {
		delete[] arr;
	}

	void Add(int data) {
		if (size < capacity) arr[size++] = data;
	}
	int Size() const {
		return size;
	}
	int operator[](int index) const {
		return arr[index];
	}

	// [] 연산자 같은 경우 쓰기 연산도 가능해야 하므로 const와 비 const함수를 모두 제공 해야함
	int & operator[](int index) {
		return arr[index];
	}
private :
	int *arr;
	int size;
	int capacity;
};

int main() {
	Array a(10);

	a.Add(10);
	a.Add(20);
	a.Add(30);

	for (int i = 0; i < a.Size(); i++) cout << i << ". " << a[i] << endl;
	cout << endl;

	const Array& b = a;
	for (int i = 0; i < a.Size(); i++) cout << i << ". " << b[i] << endl;
	cout << endl;

	a[0] = 100;
	for (int i = 0; i < a.Size(); i++) cout << i << ". " << b[i] << endl;
	cout << endl;
	//b[0] = 100; -> 에러

	return 0;
}