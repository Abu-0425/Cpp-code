#include <iostream>
#include <vector>
using namespace std;

#pragma warning(disable:4996)

class Data{
public:
	Data(int data = 10) : _data(data) {}
private:
	int _data;
};

void TestVector1()
{
	vector<int> v1;
	vector<int> v2(5, 1);
	vector<char> v3(5, 'a');
	vector<int> v4{ 1, 2, 3, 4, 5 };
	vector<Data> v5(5);

	//����
	for (size_t i = 0; i < v2.size(); i++) {
		cout << v2[i] << " ";
	}
	cout << endl;
	//��Χfor ; C++11��������
	for (auto e : v3) {
		cout << e << " ";
	}
	cout << endl;
	//ʹ�õ��������б���
	vector<int>::iterator it = v4.begin();
	while (it != v4.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void TestVector2()
{
	//���ֹ��췽ʽҲ��C++11��������
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(3);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.reserve(8);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	v.reserve(15);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	v.resize(20, 6);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
}

void TestVector3()
{
	int a = 10;
	vector<int> v;
	v.push_back(a);
	cout << &a << endl;
	cout << &v[0] << endl;
	v.insert(v.begin(), 1);
	v.insert(find(v.begin(), v.end(), 10), 3, 2);
	v.insert(v.begin(), v.begin(), v.end());
}

void TestVector4()
{
	vector<int> v{1, 2, 3, 4, 5};
	vector<int>::iterator it1 = v.begin() + 4;
	cout << *it1 << endl;
	vector<int>::iterator it2 = v.end() - 1;
	cout << *it2 << endl;
	cout << v.back() << endl;
}

void TestVector5()
{
	vector<int> v{1, 2, 3};
	auto it = v.begin();
	v.assign(10, 6);
	//���ܻᵼ�µ�����ʧЧ��λ�ö���������¸�ֵ
	it = v.begin();
	while (it != v.end()) {
		cout << *it << endl;
		++it;
	}
}

void TestVector6()
{
	vector<int> v{ 1, 2, 3 };
	auto it = v.begin();
	//erase�ķ���ֵ�ǵ�ǰɾ��Ԫ�ص���һ��λ��
	it = v.erase(it);
	cout << *it << endl;
}

void printYang(int row)
{
	vector<vector<int>> yang;
	for (int i = 0; i < row; i++) {
		yang.push_back(vector<int>(i + 1, 1));
	}

	for (int i = 0; i < row; i++) {
		for (int j = 1; j < i; j++) {
			yang[i][j] = yang[i - 1][j - 1] + yang[i - 1][j];
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j <= i; j++) {
			printf("%d ", yang[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	//TestVector1();
	//TestVector2();
	//TestVector3();
	//TestVector4();
	//TestVector5();
	//TestVector6();
	int row;
	printf("����Ҫ��ӡ���е�������� : \n");
	scanf("%d", &row);
	printYang(row);

	system("pause");
	return 0;
}