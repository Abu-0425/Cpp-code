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
	//空
};

class  Student
{
public:
	// 成员变量
	char _name[20];
	char _gender[3];
	int _age;

public:
	// 成员函数
	// 看起来该函数有三个参数，实际上有4个参数
	// 另外一个参数是：隐藏的this指针
	// 在写代码期间，用户不用显式给出this指针，编译器在编译代码时，会自动加上this指针的参数
	void InitStudent(char name[], char gender[], int age);
	//{
	//	// 不能给this指针来进行赋值----Student* const this
	//	//                          类类型* const
	//	//this = nullptr;

	//	cout << this << endl;

	//	// 有了this指针，成员函数就知道现在是在操作那个对象
	//	// 注意：对成员变量的操作都是通过this指针来进行的
	//	strcpy(this->_name, name);
	//	strcpy(this->_gender, gender);
	//	this->_age = age;
	//}

	// 注意：成员函数如果在类内部类进行定义，成员函数可能会被编译器当成内联函数来对待
	void PrintStudent()
	{
		cout << this << endl;
		cout << _name << "-" << _gender << "-" << _age << endl;
	}

	void SetAge(int age)
	{
		cout << this << endl;
		_age = age;
	}

	void TestFunc(...);
	//{}
};

int main()
{
	cout << "sizeof(class(A)) = " << sizeof(A) << endl;
	cout << "sizeof(class(B)) = " << sizeof(B) << endl;
	cout << "sizeof(class(C)) = " << sizeof(C) << endl;

	system("pause");
	return 0;
}