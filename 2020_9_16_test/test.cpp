#include <iostream>
using namespace std;

//ȱʡ��Ĭ�ϲ�������ں�������ʱ����
void TestFunc(int a = 10, int b = 20, int c = 30);


//�����ռ�
namespace N {
	int a = 10;
	int b = 20;
	int add(int x, int y)
	{
		return x + y;
	}
}

//int a = 20;

//using  namespace N;
//using N::a;

//ȱʡ������Ĭ�ϲ���
void TestFunc(int a, int b, int c)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}

//��������
//����ͬ�������У�������������ͬ���������б���벻ͬ
//�����б�ͬ�����֣�
//1.����������ͬ 2.�������Ͳ�ͬ 3.��������ͬ
//ע�⣺��������Ǻ�������ֵ���Ͳ�ͬ�����ܹ��ɺ�������

//double Add(double a, double b)
//{
//	return a + b;
//}
//
//int Add(int a, int b)
//{
//	return a + b;
//}
//
//long Add(long a, long b)
//{
//	return a + b;
//}

void fun(int a = 10)
{
	cout << "123!" << endl;
}

//void fun(int a)
//{
//	cout << "321!" << endl;
//}

void Swap(int &x, int &y)
{
	int tmp = x;
	x = y;
	y = tmp;
}

int &Add(int x, int y)
{
	int ret = x + y;
	return ret;
}

int main()
{
	int &result = Add(1, 2);
	cout << result << endl;
	Add(3, 4);
	cout << result << endl;
	Add(5, 6);
	cout << result << endl;
	//int a = 100;
	//int i = a++;
	//printf("%d\n", i);
	//cout << a << endl; 
	//int a = 10;
	//int b = 20;
	//int &ra = a;
	//int &rb = b;
	//Swap(ra, rb);
	//Swap(a, b);
	//double a = 12.34;
	//const int &ra = a;
	//a = 34.56;
	//cout << ra << endl;//ra = 12
	//int a = 10;
	//int b = 20;
	//int &ra = a;
	//ra = b; //b��ֵ������ra

	//fun(1);
	//int ret1 = Add(10, 20);
	//cout << "int : a + b = " << ret1 << endl;
	//double ret2 = Add(1.2, 2.4);
	//cout << "double : a + b = " << ret2 << endl;
	//int ret3 = Add(10L, 20L);
	//cout << "long : a + b = " << ret3 << endl;
	//printf("'1' + '2' = %d\n",Add('1', '2'));
	//char��int������ʽ����ת��,���Ի����int Add
	
	//TestFunc();
	//TestFunc(1);
	//TestFunc(1, 2);
	//TestFunc(1, 2, 3);
	//int a = 30;
	//cout << a << endl;
	//cout << ::a << endl;
	//cout << N::a << endl;

	system("pause");
	return 0;
}