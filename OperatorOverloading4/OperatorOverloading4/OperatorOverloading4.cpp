// Gamja Comment
// 
// �̴� "���� �ڱ��ϴ� C++ STL" å�� ������ �����ϸ� �ǽ��� ���Դϴ�.
//
// * �迭 �ε��� ������ �����ε� []
//		1. �迭�� ����ϴ� [] �����ڸ� ��ü���� ����� �� ����
//		2. �Ϲ������� ���� ��ü�� �����ϰ� �����ϴ� ��ü�� ����
//		3. �Ϲ������� �����̳� ��ü�� ��� -> �����̳� ��ü�� �����ϴ� ���� ���ҿ� ���ٽ� ���

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

	// [] ������ ���� ��� ���� ���굵 �����ؾ� �ϹǷ� const�� �� const�Լ��� ��� ���� �ؾ���
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
	//b[0] = 100; -> ����

	return 0;
}