#include <iostream>
#include <string>
#pragma warning(disable:4996)
using namespace std;

struct Student{
	char name[20];
	char sex[3];
	int age;
};

void InitStudent(struct Student *s, char *n, char *c, int a)
{

}

#if 0
class Student{
public:
	void InitStudent(char *n, char *c, int a) {
		strcpy(name, n);
		strcpy(sex, c);
		age = a;
	}
	void PrintStudent() {
		cout << name << "-" << sex << "-" << age << endl;
	}
private:
	char name[20];
	char sex[3];
	int age;
};


int main()
{
	Student s1, s2, s3;
	s1.InitStudent("小王", "男", 19);
	s2.InitStudent("小李", "女", 18);
	s3.InitStudent("小张", "男", 20);
	s1.PrintStudent();
	s2.PrintStudent();
	s3.PrintStudent();

	system("pause");
	return 0;
}
#endif

int main() 
{
	struct Student s1, s2, s3;
	InitStudent(&s1, "小王", "男", 19);
	InitStudent(&s2, "小李", "女", 18);
	InitStudent(&s3, "小张", "男", 20);

	system("pause");
	return 0;
}