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
		//三角形面积公式(已知三边)
		double p = (a + b + c) / 2;
		return sqrt(p * (p - a) * (p - b) * (p - c));
	}
	virtual void shapeName() const {
		cout << "Triangle: ";
	}
private:
	//三边长
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

/*编写一个程序,定义抽象基类Shape，由它派生出5个派生类：
Cricle（圆形),Square（正方形)， Rectangle（矩形）， 
Trapezoid （梯形）,Triangle（三角形）。
用虚函数分别计算图形面积，并求所有图形面积的和．
要求用基类指针数组，使它的每一个元素指向一个派生类对象。*/
#include <iostream>
using namespace std;
//定义抽象基类Shape
class Shape
{
public:
	virtual double area() const = 0;                                //纯虚函数
};

//定义Circle(圆形)类
class Circle :public Shape
{
public:
	Circle(double r) :radius(r){}                                     //结构函数
	virtual double area() const { 
		return 3.14159*radius*radius; 
	}  //定义虚函数
protected:
	double radius;                                                 //半径
};

//定义Square(正方形)类
class Square :public Shape
{
public:
	Square(double s) :side(s){}                                     //结构函数     
	virtual double area() const { return side*side; }                //定义虚函数
protected:
	double side;
};

//定义Rectangle(矩形)类
class Rectangle :public Shape
{
public:
	Rectangle(double w, double h) :width(w), height(h){}               //结构函数
	virtual double area() const { return width*height; }              //定义虚函数
protected:
	double width, height;                                           //宽与高
};

//定义Trapezoid(梯形)类
class Trapezoid :public Shape
{
public:
	Trapezoid(double t, double b, double h) :top(t), bottom(b), height(h){} //结构函数
	virtual double area() const { return 0.5*(top + bottom)*height; }      //定义虚函数
protected:
	double top, bottom, height;                                          //上底、下底与高
};

//定义Triangle(三角形)类
class Triangle :public Shape
{
public:
	Triangle(double w, double h) :width(w), height(h){}                //结构函数
	virtual double area() const { return 0.5*width*height; }          //定义虚函数
protected:
	double width, height;                                            //宽与高
};

int main()
{
	Circle circle(12.6);                                             //建立Circle类对象circle
	Square square(3.5);                                              //建立Square类对象square
	Rectangle rectangle(4.5, 8.4);                                    //建立Rectangle类对象rectangle
	Trapezoid trapezoid(2.0, 4.5, 3.2);                                //建立Trapezoid类对象trapezoid
	Triangle triangle(4.5, 8.4);                                      //建立Triangle类对象
	Shape *pt[5] = { &circle, &square, &rectangle, &trapezoid, &triangle };
	//定义基类指针数组pt，使它每一个元素指向一个派生类对象
	double areas = 0.0;                                                //areas为总面积
	for (int i = 0; i < 5; i++)
	{
		areas = areas + pt[i]->area();
	}
	cout << "totol of all areas=" << areas << endl;   //输出总面积

	system("pause");
	return 0;
}

/*分别定义Teacher(教师)类和Cadre（干部）类，采用多重继承方式
由这两个类派生出新类Teacher_Cadre（教师兼干部）。要求： 
（1）在两个基类中都包含姓名、年龄、性别、地址、电话等数据成员。 
（2）在Teacher类中还包含数据成员title(职称)，在Cadre类中还包含
数据成员post（职务），在Teacher_Cadre类中还包含数据成员wages(工资)。 
（3）对两个基类中的姓名、年龄、性别、地址、电话等数据成员用相同
的名字，在引用这些数据成员时，指定作用域。 
（4）在类体中声明成员函数，在类外定义成员函数。 
（5）在派生类Teacher_Cadre的成员函数show中调用
Teacher类中的display函数，输出姓名、年龄、性别、职称、地址、电话，
然后再用cout语句输出职务与工资。 */

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
//		cout << "姓名：" << name << endl;
//		cout << "年龄：" << age << endl;
//		cout << "性别：" << sex << endl;
//		cout << "职称：" << title << endl;
//		cout << "地址：" << addr << endl;
//		cout << "电话：" << tel << endl;
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
//		cout << "姓名：" << name << endl;
//		cout << "年龄：" << age << endl;
//		cout << "性别：" << sex << endl;
//		cout << "职务：" << post << endl;
//		cout << "地址：" << addr << endl;
//		cout << "电话：" << tel << endl;
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
//		cout << "职务：" << Cadre::post << endl;
//		cout << "工资：" << wages << endl;
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