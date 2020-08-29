/*#include <iostream>
#include <math.h>
using namespace std;

class Shape {
public:
	virtual double area() {
		return 0.0;
	}
	virtual void shapeName() const = 0;
};

class Circle : public Shape {
public:
	Circle(double x = 0, double y = 0, double r = 0);
	virtual double area();
	virtual void shapeName() const {
		cout << "Circle: ";
	}
private:
	double x;
	double y;
	double radius;
};

Circle::Circle(double a, double b, double r)
{
	x = a;
	y = b;
	radius = r;
}

double Circle::area()
{
	return 3.14 * radius * radius;
}

class Rectangle : public Shape {
public:
	Rectangle(double l, double w) : length(l), width(w){}
	virtual double area();
	virtual void shapeName() const {
		cout << "Rectangle: ";
	}
private:
	double length;
	double width;
};

double Rectangle::area()
{
	return length * width;
}

class Triangle : public Shape {
public:
	Triangle(double, double, double);
	virtual double area()  {
		//�����������ʽ(��֪����)
		double p = (a + b + c) / 2;
		return sqrt(p * (p - a) * (p - b) * (p - c));
	}
	virtual void shapeName() const {
		cout << "Triangle: ";
	}
private:
	//���߳�
	double a;
	double b;
	double c;
};

Triangle::Triangle(double x, double y, double z) :a(x), b(y), c(z){}

int main()
{
	Circle c(1.1, 1.2, 2);
	Rectangle rect(2.0, 3.0);
	Triangle t(6, 8, 10);
	c.shapeName();
	cout << endl << "area: " << c.area() << endl;
	rect.shapeName();
	cout << endl << "area: " << rect.area() << endl;
	t.shapeName();
	cout << endl << "area: " << t.area() << endl;

	system("pause");
	return 0;
}*/

/*��дһ������,����������Shape������������5�������ࣺ
Cricle��Բ��),Square��������)�� Rectangle�����Σ��� 
Trapezoid �����Σ�,Triangle�������Σ���
���麯���ֱ����ͼ���������������ͼ������ĺͣ�
Ҫ���û���ָ�����飬ʹ����ÿһ��Ԫ��ָ��һ�����������*/
#include <iostream>
using namespace std;
//����������Shape
class Shape
{
public:
	virtual double area() const = 0;                                //���麯��
};

//����Circle(Բ��)��
class Circle :public Shape
{
public:
	Circle(double r) :radius(r){}                                     //�ṹ����
	virtual double area() const { 
		return 3.14159*radius*radius; 
	}  //�����麯��
protected:
	double radius;                                                 //�뾶
};

//����Square(������)��
class Square :public Shape
{
public:
	Square(double s) :side(s){}                                     //�ṹ����     
	virtual double area() const { return side*side; }                //�����麯��
protected:
	double side;
};

//����Rectangle(����)��
class Rectangle :public Shape
{
public:
	Rectangle(double w, double h) :width(w), height(h){}               //�ṹ����
	virtual double area() const { return width*height; }              //�����麯��
protected:
	double width, height;                                           //�����
};

//����Trapezoid(����)��
class Trapezoid :public Shape
{
public:
	Trapezoid(double t, double b, double h) :top(t), bottom(b), height(h){} //�ṹ����
	virtual double area() const { return 0.5*(top + bottom)*height; }      //�����麯��
protected:
	double top, bottom, height;                                          //�ϵס��µ����
};

//����Triangle(������)��
class Triangle :public Shape
{
public:
	Triangle(double w, double h) :width(w), height(h){}                //�ṹ����
	virtual double area() const { return 0.5*width*height; }          //�����麯��
protected:
	double width, height;                                            //�����
};

int main()
{
	Circle circle(12.6);                                             //����Circle�����circle
	Square square(3.5);                                              //����Square�����square
	Rectangle rectangle(4.5, 8.4);                                    //����Rectangle�����rectangle
	Trapezoid trapezoid(2.0, 4.5, 3.2);                                //����Trapezoid�����trapezoid
	Triangle triangle(4.5, 8.4);                                      //����Triangle�����
	Shape *pt[5] = { &circle, &square, &rectangle, &trapezoid, &triangle };
	//�������ָ������pt��ʹ��ÿһ��Ԫ��ָ��һ�����������
	double areas = 0.0;                                                //areasΪ�����
	for (int i = 0; i < 5; i++)
	{
		areas = areas + pt[i]->area();
	}
	cout << "totol of all areas=" << areas << endl;   //��������

	system("pause");
	return 0;
}

/*�ֱ���Teacher(��ʦ)���Cadre���ɲ����࣬���ö��ؼ̳з�ʽ
��������������������Teacher_Cadre����ʦ��ɲ�����Ҫ�� 
��1�������������ж��������������䡢�Ա𡢵�ַ���绰�����ݳ�Ա�� 
��2����Teacher���л��������ݳ�Աtitle(ְ��)����Cadre���л�����
���ݳ�Աpost��ְ�񣩣���Teacher_Cadre���л��������ݳ�Աwages(����)�� 
��3�������������е����������䡢�Ա𡢵�ַ���绰�����ݳ�Ա����ͬ
�����֣���������Щ���ݳ�Աʱ��ָ�������� 
��4����������������Ա�����������ⶨ���Ա������ 
��5����������Teacher_Cadre�ĳ�Ա����show�е���
Teacher���е�display������������������䡢�Ա�ְ�ơ���ַ���绰��
Ȼ������cout������ְ���빤�ʡ� */

//#include <iostream>
//#include<string>
//using namespace std;
//class Teacher
//{
//public:
//	Teacher(){}
//	Teacher(string nam, int a, char s, string tit, string ad, string t) :
//		name(nam), age(a), sex(s), title(tit), addr(ad), tel(t){}
//	void display()
//	{
//		cout << "������" << name << endl;
//		cout << "���䣺" << age << endl;
//		cout << "�Ա�" << sex << endl;
//		cout << "ְ�ƣ�" << title << endl;
//		cout << "��ַ��" << addr << endl;
//		cout << "�绰��" << tel << endl;
//	}
//protected:
//	string name;
//	int age;
//	char sex;
//	string title;
//	string addr;
//	string tel;
//};
//class Cadre
//{
//public:
//	Cadre(){}
//	Cadre(string nam, int a, char s, string p, string ad, string t) :
//		name(nam), age(a), sex(s), post(p), addr(ad), tel(t){}
//	void display()
//	{
//		cout << "������" << name << endl;
//		cout << "���䣺" << age << endl;
//		cout << "�Ա�" << sex << endl;
//		cout << "ְ��" << post << endl;
//		cout << "��ַ��" << addr << endl;
//		cout << "�绰��" << tel << endl;
//	}
//protected:
//	string name;
//	int age;
//	char sex;
//	string post;
//	string addr;
//	string tel;
//};
//class Teacher_Cadre :public Teacher, public Cadre
//{
//private:
//	int wages;
//public:
//	Teacher_Cadre(){}
//	Teacher_Cadre(string nam, int ag, char se, string tit, string pos, string add, string te, int wag) :
//		Teacher(nam, ag, se, tit, add, te),
//		Cadre(nam, ag, se, pos, add, te),
//		wages(wag)
//	{}
//	void Show()
//	{
//		Teacher::display();
//		cout << "ְ��" << Cadre::post << endl;
//		cout << "���ʣ�" << wages << endl;
//	}
//};
//int main()
//{
//	Teacher_Cadre te_ca("Wang-li", 50, 'f', "prof.", "president",
//		"135 Beijing Road,Shanghai", "(021)61234567", 1534);
//	te_ca.Show();
//
//	system("pause");
//	return 0;
//}