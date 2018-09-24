// Gamja Comment
// 
// 이는 "뇌를 자극하는 C++ STL" 책의 내용을 정리하며 실습한 것입니다.
//
// * explicit Keyword
//		예들 들어, 클래스 객체에 정수를 대입 연산 했을 때,
//		정수를 인자로 받는 생성자가 있으면 컴파일러는 해당 생성자를 호출에 객체를 생성합
//		-> 이렇게 하면 실수로 정수 값을 대입해도 컴파일이 성공하여 버그가 됨
//		-> 생성자 이용한 형변환을 의도치 않는다면 생성자는 명시적 호출만 가능하도록 explicit 키워드를 지정

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

	//explicit 키워드를 지정하지 않았을 경우, 정수를 인자로 받는 생성자가 있기때문에 Point(10,0)을 호출해서 가능
	//a = 10;
	//a.Print();

	//explicit 키워드를 지정한 경우, 명시적으로 호출한 경우에만 사용 가능
	a = Point(10);
	a.Print();

	

	return 0;
}
