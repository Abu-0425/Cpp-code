#include <iostream>
using namespace std;

#include "add.h"

int main()
{
	int a = 10;
	int b = 20;
	int *pa = &a;
	*pa = 30; //ͨ�������ò����޸�a��ֵ
	cout << "a = " << *pa << endl; //ͨ�������ô�ӡa��ֵ(30)
	int &rb = b;
	rb = 40; //ͨ������ֱ���޸�b��ֵ
	cout << "b = " << rb << endl; //ͨ������ֱ�Ӵ�ӡbֵ(40)
	//int a = 10;
	//int *pa = &a; //����һ��ָ��,ָ��һ��ͬ���ͱ���
	//int **ppa = &pa; //�������ָ�룬ָ��һ��һ��ָ��
	//int &ra = a; //��������
	//int &&rra = ra; //����û�ж༶����
	//int arr[] = { 1, 3, 5, 7 };
	//int *p = &arr[0];
	//p++;//ָ����һ��Ԫ��
	//cout << "*p = " << *p << endl; //3
	//int &r = arr[0];
	//r++; //�����õ�ʵ���Լ�1����arr[0] = arr[0] + 1
	//cout << "r = " << r << endl; //2
	//cout << "arr[0] = " << arr[0] << endl; //ͬ��
	//char c = 'a';
	//char *pc = &c;
	//char &rc = c;
	//cout << "sizeof(pc) = " << sizeof(pc) << endl; //4
	//cout << "sizeof(rc) = " << sizeof(rc) << endl; //1
	//int a = 10;
	//int b = 20;
	//int &ra = a;
	////&ra = b; //�ᱨ��,����һ�����壬��������������ʵ��
	////ra = b; //���ᱨ��������������˼�ǽ�b��ֵ����ra(a)����������������ʵ��
	//int *pa = &a;
	//pa = &b; //��ȷ���޸�pa��ָ��ʹ��ָ�����b

	//int a = 10;
	////int &ra; //�ᱨ�������ڶ���ʱ����ͬʱ���г�ʼ��
	//int &ra = a; //��ȷ�Ķ��巽ʽ
	//int *p; //����ʱ���Բ���ʼ��

	return 0;
}

/*
int main()
{
	//�۲췴������
	int a = 10;
	int *pa = &a;
	*pa = 20;
	int &ra = a;
	ra = 20;

	//int a = 10;
	//int &ra = a; //������������
	//ra = 20; //ͨ�������޸�a��ֵ
	//cout << "a = " << a << endl; //20
	//cout << "ra = " << ra << endl; //20

	//int a = 10;
	//int *pa = &a; //����ָ�����pa��ָ�����α���a
	//*pa = 20; //ͨ��ָ��ý����ò����޸�a��ֵ
	//cout << "a = " << a << endl;
	////Add(10, 20);
	return 0;
}

/*
//��������
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