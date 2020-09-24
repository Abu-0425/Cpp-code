#include <iostream>
using namespace std;

#include "add.h"

int main()
{
	int a = 10;
	int b = 20;
	int *pa = &a;
	*pa = 30; //通过解引用操作修改a的值
	cout << "a = " << *pa << endl; //通过解引用打印a的值(30)
	int &rb = b;
	rb = 40; //通过引用直接修改b的值
	cout << "b = " << rb << endl; //通过引用直接打印b值(40)
	//int a = 10;
	//int *pa = &a; //定义一级指针,指向一个同类型变量
	//int **ppa = &pa; //定义二级指针，指向一个一级指针
	//int &ra = a; //定义引用
	//int &&rra = ra; //错误，没有多级引用
	//int arr[] = { 1, 3, 5, 7 };
	//int *p = &arr[0];
	//p++;//指向下一个元素
	//cout << "*p = " << *p << endl; //3
	//int &r = arr[0];
	//r++; //其引用的实体自加1，即arr[0] = arr[0] + 1
	//cout << "r = " << r << endl; //2
	//cout << "arr[0] = " << arr[0] << endl; //同上
	//char c = 'a';
	//char *pc = &c;
	//char &rc = c;
	//cout << "sizeof(pc) = " << sizeof(pc) << endl; //4
	//cout << "sizeof(rc) = " << sizeof(rc) << endl; //1
	//int a = 10;
	//int b = 20;
	//int &ra = a;
	////&ra = b; //会报错,引用一旦定义，不能在引用其他实体
	////ra = b; //不会报错，但这条语句的意思是将b的值赋给ra(a)，并不是引用其他实体
	//int *pa = &a;
	//pa = &b; //正确，修改pa的指向，使其指向变量b

	//int a = 10;
	////int &ra; //会报错，引用在定义时必须同时进行初始化
	//int &ra = a; //正确的定义方式
	//int *p; //定义时可以不初始化

	return 0;
}

/*
int main()
{
	//观察反汇编代码
	int a = 10;
	int *pa = &a;
	*pa = 20;
	int &ra = a;
	ra = 20;

	//int a = 10;
	//int &ra = a; //定义引用类型
	//ra = 20; //通过引用修改a的值
	//cout << "a = " << a << endl; //20
	//cout << "ra = " << ra << endl; //20

	//int a = 10;
	//int *pa = &a; //定义指针变量pa，指向整形变量a
	//*pa = 20; //通过指针得解引用操作修改a的值
	//cout << "a = " << a << endl;
	////Add(10, 20);
	return 0;
}

/*
//函数重载
int Add(int x, int y)
{
	return x + y;
}

double Add(double x, double y)
{
	return x + y;
}

long Add(long x, long y)
{
	return x + y;
}

int main()
{
	int ret1 = Add(1, 2);
	double ret2 = Add(1.23, 2.34);
	long ret3 = Add(10L, 20L);
	cout << "int: " << ret1 << endl;
	cout << "double: " << ret2 << endl;
	cout << "long: " << ret3 << endl;

	return 0;
}
*/