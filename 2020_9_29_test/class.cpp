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
	//��
};

class  Student
{
public:
	// ��Ա����
	char _name[20];
	char _gender[3];
	int _age;

public:
	// ��Ա����
	// �������ú���������������ʵ������4������
	// ����һ�������ǣ����ص�thisָ��
	// ��д�����ڼ䣬�û�������ʽ����thisָ�룬�������ڱ������ʱ�����Զ�����thisָ��Ĳ���
	void InitStudent(char name[], char gender[], int age);
	//{
	//	// ���ܸ�thisָ�������и�ֵ----Student* const this
	//	//                          ������* const
	//	//this = nullptr;

	//	cout << this << endl;

	//	// ����thisָ�룬��Ա������֪���������ڲ����Ǹ�����
	//	// ע�⣺�Գ�Ա�����Ĳ�������ͨ��thisָ�������е�
	//	strcpy(this->_name, name);
	//	strcpy(this->_gender, gender);
	//	this->_age = age;
	//}

	// ע�⣺��Ա������������ڲ�����ж��壬��Ա�������ܻᱻ���������������������Դ�
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