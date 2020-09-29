#include <iostream>
using namespace std;

class A {
private:
	int a;
public:
	void SetA(int _a) {
		a = _a;
	}
};

class B {
public:
	void EmptyClass() {
		cout << "This is a empty Class!" << endl;
	}
};

class C {
	//Пе
};

int main()
{
	cout << "sizeof(class(A)) = " << sizeof(A) << endl;
	cout << "sizeof(class(B)) = " << sizeof(B) << endl;
	cout << "sizeof(class(C)) = " << sizeof(C) << endl;

	system("pause");
	return 0;
}