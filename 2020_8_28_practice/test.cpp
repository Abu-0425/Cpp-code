#include <iostream>
using namespace std;

class Point {
public:
	Point(double x = 0, double y = 0);
	void setPoint(double, double);
	double getX() const{
		return x;
	}
	double getY() const{
		return y;
	}
	friend ostream& operator <<(ostream &, const Point &);
protected:
	double x;
	double y;
};

Point::Point(double a, double b)
{
	x = a;
	y = b;
}

void Point::setPoint(double a, double b)
{
	x = a;
	y = b;
}

ostream& operator <<(ostream &output, const Point &p)
{
	output << "[" << p.x << "," << p.y << "]" << endl;
	return output;
}

class Circle : public Point{
public:
	Circle(double x = 0, double y = 0, double r = 0);
	void setRadius(double);
	double getRadius() const;
	double getArea() const;
	friend ostream& operator <<(ostream &, Circle &);
protected:
	double radius;
};

Circle::Circle(double a, double b, double r) : Point(a, b), radius(r)
{}

void Circle::setRadius(double r)
{
	radius = r;
}

double Circle::getRadius() const
{
	return radius;
}

double Circle::getArea() const
{
	return 3.14 * radius * radius;
}

ostream& operator <<(ostream &output, Circle &c)
{
	output << "Center = [" << c.x << "," << c.y << "],r = "
		<< c.radius << ",area = " << c.getArea() << endl;
	return output;
}

class Cylinder : public Circle {
public:
	Cylinder(double x = 0, double y = 0, double r = 0, double h = 0);
	void setHeight(double);
	double getHeight() const;
	double getArea() const;
	double getVolume() const;
	friend ostream & operator <<(ostream &, Cylinder &);
protected:
	double height;
};

Cylinder::Cylinder(double a, double b, double r, double h)
: Circle(a, b, r), height(h){}

void Cylinder::setHeight(double h)
{
	height = h;
}

double Cylinder::getHeight() const
{
	return height;
}

double Cylinder::getArea() const
{
	return 2 * Circle::getArea() + 2 * 3.14 *radius *height;
}

double Cylinder::getVolume() const
{
	return Circle::getArea() * height;
}

ostream & operator <<(ostream &output, Cylinder &cy)
{
	output << "Center = [" << cy.x << "," << cy.y << "],r = "
		<< cy.radius << ",h = " << cy.height 
		<< "\narea = " << cy.getArea() << ",volume = "
		<< cy.getVolume() << endl;
	return output;
}

int main()
{
	//²âÊÔCylinderÀà
	Cylinder cy(1.1, 1.2, 3, 4);
	cout << "original Cylinder : \nx = " << cy.getX() << ",y = " << cy.getY()
		<< ",r = " << cy.getRadius() << ",h = " << cy.getHeight() 
		<< "\narea = " << cy.getArea()
		<< ",volume = " << cy.getVolume() << endl;
	cy.setHeight(2);
	cy.setRadius(2);
	cy.setPoint(1.0, 1.0);
	cout << "new Cylinder : \n" << cy;
	Point &pRef = cy;
	cout << "pRef as a point: " << pRef;
	Circle &cRef = cy;
	cout << "cRef as a circle: " << cRef;

	//²âÊÔCircleÀà
	//Circle c(1.2, 3.4, 5);
	//cout << "original circle:\n x = " << c.getX() << ",y = " << c.getY()
	//	<< ",r = " << c.getRadius() << ",area = " << c.getArea() << endl;
	//c.setPoint(1.1, 2.2);
	//c.setRadius(6);
	//cout << "new circle:\n " << c << endl;
	//Point &pRef = c;
	//cout << "pRef: " << pRef << endl;

	//²âÊÔPointÀà
	//Point  p(1.1, 1.2);
	//cout << "x= " << p.getX() << ",y= " << p.getY() << endl;
	//p.setPoint(2.5, 3.8);
	//cout << p;

	system("pause");
	return 0;
}