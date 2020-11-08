#include <iostream>
using namespace std;

template <class T>
class SeqList
{
public:
	//构造函数
	SeqList(size_t capacity = 10)
		: _array(new T[capacity])
		, _capacity(capacity)
		, _size(0)
	{}

	//下方俩个函数仅为举例说明，未具体实现
	SeqList(const SeqList<T>& s); //拷贝构造函数
	SeqList<T>& operator=(const SeqList<T>& s); //赋值运算符的重载

	//析构函数
	~SeqList()
	{
		if (_array)
		{
			delete[] _array;
			_capacity = 0;
			_size = 0;
		}
	}

	//具体的各种成员函数
	size_t size()const
	{
		return _size;
	}

	size_t capacity()const
	{
		return _capacity;
	}

	bool empty()const
	{
		return 0 == _size;
	}

	/*未具体实现*/
	void push_back(const T& data);
	void pop_back();
	//...等等

	//下标运算符的重载
	T& operator[](size_t index)
	{
		assert(index < _size);
		return _array[index];
	}

	const T& operator[](size_t index)const
	{
		assert(index < _size);
		return _array[index];
	}

private:
	T* _array;
	size_t _capacity;
	size_t _size;
};

//函数模板
template <class T>
T Add(T x, T y)
{
	T ret = x + y;
	return ret;
}

int main()
{
	int i1 = 10;
	int i2 = 20;
	Add(i1, i2);
	double d1 = 10.0;
	double d2 = 20.0;
	Add(d1, d2);
	char c1 = 'a';
	char c2 = 'b';
	Add(c1, c2);

	Add<int>(i1, d2); //显式实例化

	//类模板的实例化
	SeqList<int> s1;
	SeqList<char> s2;

	return 0;
}