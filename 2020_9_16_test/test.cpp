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

double Add(double a, double b)
{
	return a + b;
}

int Add(int a, int b)
{
	return a + b;
}

long Add(long a, long b)
{
	return a + b;
}


int main()
{
	int ret1 = Add(10, 20);
	cout << "int : a + b = " << ret1 << endl;
	double ret2 = Add(1.2, 2.4);
	cout << "double : a + b = " << ret2 << endl;
	int ret3 = Add(10L, 20L);
	cout << "long : a + b = " << ret3 << endl;
	printf("'1' + '2' = %d\n",Add('1', '2'));//char��int������ʽ����ת��,���Ի����int Add
	
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