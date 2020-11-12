#include <iostream>
#include <string>
using namespace std;

#if 0
int main()
{
	string s1("hello");
	s1.resize(15, '#');
	char *str = (char *)s1.c_str();
	system("pause");
	return 0;
}
#endif

#if 0 
int main()
{
	string a = "hello world";
	string b = a;
	if (a.c_str() == b.c_str())
	{
		cout << "true" << endl;
	}
	else cout << "false" << endl;
	string c = b;
	c = "";
	if (a.c_str() == b.c_str())
	{
		cout << "true" << endl;
	}
	else cout << "false" << endl;
	a = "";
	if (a.c_str() == b.c_str())
	{
		cout << "true" << endl;
	}
	else cout << "false" << endl;
	//false false false
	return 0;
}
#endif

#if 0
int main()
{
	string str("Hello Bit.");
	str.reserve(111);
	str.resize(5);
	str.reserve(50);
	cout << str.size() << ":" << str.capacity() << endl;//111:5

	return 0;

}
#endif

#if 0
int main(int argc, char *argv[])
{
	string strText = "How are you?";
	string strSeparator = " ";
	string strResult;
	int size_pos = 0;
	int size_prev_pos = 0;
	while ((size_pos = strText.find_first_of(strSeparator, size_pos)) != string::npos)
	{
		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
		cout << strResult << " ";
		size_prev_pos = ++size_pos;
	}
	if (size_prev_pos != strText.size())
	{
		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
		cout << strResult << " ";
	}
	cout << endl;
	return 0;

}
#endif

#if 0
int main()
{
	string str = "Hello Bit.";
	string::iterator it = str.begin();
	while (it != str.end())
	{
		if (*it != ' ')
			cout << *it;
		else
			str.erase(it);
		it++;
	}
	return 0;
}
#endif

#if 0
int main()
{
	string s1 = "hello world";
	string s2 = "change world";
	string::iterator it = s1.begin();
	swap(s1, s2);
	while (it != s1.end())
		cout << *it;
	cout << endl;
	return 0;
}
#endif

#if 0 
void find_first_single(string &s)
{
	for(int i = 0; i < s.size(); i++) {
		//按照顺序，找指定字符的第一次出现和最后一次出现，
		//如果在同一个位置，则说明是只出现一次
		if(s.find_first_of(s[i])==s.find_last_of(s[i])) {
			printf("%d\n", s.find_last_of(s[i]));
			cout << s[i] << endl;
			break;
		}
		//走到这里说明不存在这样的字符
		if(i == s.size() - 1) {
			cout << -1 <<endl;
		}
	}
}

int main()
{
	string s;
	while (cin >> s) {
		find_first_single(s);
	}
	return 0;
}
#endif

#if 0 
int main()
{
	string s;
	getline(cin, s);
	char blank = ' ';
	int pos = 0;
	if (s.find_last_of(blank) != string::npos) {
		pos = s.find_last_of(blank);
		string lastword = s.substr(pos + 1);
		cout << lastword.size() << endl;;
	}
	else {
		cout << s.size() << endl;
	}
	return 0;
}
#endif

#if 0
bool isPalindrome(string s) {
	int start = 0;
	int end = s.size() - 1;
	while (start < end) {
		while (start < end && !isalnum(s[start])) {
			start++;
		}
		while (start < end && !isalnum(s[end])) {
			end--;
		}
		if (start < end) {
			if (tolower(s[start]) != tolower(s[end])) {
				return false;
			}
			start++;
			end--;
		}
	}
	return true;
}

int main()
{
	printf("%d\n", 'P');
	string s("0P");
	if (isPalindrome(s)) {
		printf("Yes!\n");
	}
	else {
		printf("No!\n");
	}
	system("pause");
	return 0;
}
#endif 

#pragma warning (disable:4996)
class String{
public:
	/*
	//传统版本
	//构造
	String(const char *str = "")
	{
	    if (nullptr == str) {
	        str = "";
	}
	    _str = new char[strlen(str) + 1];
	    strcpy(_str, str);
	}
	//拷贝构造
	String(const String &s) : _str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}
	//赋值运算符的重载
	String& operator=(const String &s)
	{
		if (this != &s) {
			delete[]_str;
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);
		}
		return *this;
	}
	*/

	//现代版本
	String(const char *str = "") 
	{
		if (nullptr == str) {
			 str = "";
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	String(const String &s) : _str(nullptr)
	{
		String tmpStr(s._str);
		//交换完毕后tmpStr._str==nullptr
		swap(_str, tmpStr._str);
	}

	/*
	String& operator=(const String &s)
	{
		if (this != &s) {
			String tmpStr(s);
			swap(_str, tmpStr._str);

		}
		return *this;
	}
	*/
	String& operator=(String s)
	{
		swap(s._str, _str);
		return *this;
	}

	//析构函数
	~String()
	{
		if (_str) {
			delete[]_str;
			_str = nullptr;
		}
	}
private:
	char *_str;
};

//测试方法
void TestString1()
{
	String s1("hello world!");
	String s2(s1);
	String s3("bit 666!");
	s2 = s3;
}

int main()
{
	TestString1();
	return 0;
}
