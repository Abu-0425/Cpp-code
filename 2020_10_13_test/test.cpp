#include <iostream>
#include <string>
#pragma warning(disable:4996)
using namespace std;

#if 0
struct Student{
	char name[20];
	char sex[3];
	int age;
};

void InitStudent(struct Student *ps, char *n, char *s, int a)
{
	strcpy(ps->name, n);
	strcpy(ps->sex, s);
	ps->age = a;
}

void PrintStudent(struct Student *ps) {
	cout << ps->name << "-" << ps->sex << "-" << ps->age << endl;
}
#endif


class Student{
public:
	void InitStudent(char *n, char *s, int a) {
		strcpy(name, n);
		strcpy(sex, s);
		age = a;
	}

	/*
	void InitStudent(Student *const this, char *n, char *s, int a) {
		strcpy(this->name, n);
		strcpy(this->sex, s);
		this->age = a;
	}
	*/

	void PrintStudent() {
		cout << name << "-" << sex << "-" << age << endl;
	}

	/*
	void PrintStudent(Student *const this) {
		cout << this->name << "-" << this->sex << "-" << this->age << endl;
	}
	*/

private:
	char name[20];
	char sex[3];
	int age;
};


int main()
{
	Student s1, s2, s3;
	s1.InitStudent("С��", "��", 19);
	s2.InitStudent("С��", "Ů", 18);
	s3.InitStudent("С��", "��", 20);
	s1.PrintStudent();
	s2.PrintStudent();
	s3.PrintStudent();

	system("pause");
	return 0;
}

#if 0
int main() 
{
	struct Student s1, s2, s3;
	InitStudent(&s1, "С��", "��", 19);
	InitStudent(&s2, "С��", "Ů", 18);
	InitStudent(&s3, "С��", "��", 20);

	PrintStudent(&s1);
	PrintStudent(&s2);
	PrintStudent(&s3);

	system("pause");
	return 0;
}
#endif