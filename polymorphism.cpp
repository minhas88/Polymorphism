#include <iostream>
#include <string>
#include <memory> 
#include <vector> 
#include <cmath>
#define _USE_MATH_DEFINES

class Shape
{
protected:
    std::string shapename;
public:
    Shape(std::string);
    ~Shape();
    virtual std::string shapeName();
    virtual float CalArea();
    virtual float CalPerimeter();
};

Shape::Shape(std::string shp)
{
    shapename = shp;
}

Shape::~Shape()
{
}

std::string Shape::shapeName(){
    return shapename;
}

float Shape::CalArea(){
    return 1;
}

float Shape::CalPerimeter(){
    return 1;
}

class Square:public Shape
{
protected:
    float length;
public:
    Square(std::string, float);
    ~Square();
    std::string shapeName();
    float CalArea();
    float CalPerimeter();
};

Square::Square(std::string shp, float len):Shape(shp)
{
    length = len;
}

Square::~Square()
{
}

std::string Square::shapeName(){
    return shapename;
}

float Square::CalArea(){
    float ans = pow(length,2);
    return ans;
}

float Square::CalPerimeter(){
    float ans = 4 * length;
    return ans;
}

class Rectangle:public Shape
{
protected:
    float length, width;
public:
    Rectangle(std::string, float, float);
    ~Rectangle();
    std::string shapeName();
    float CalArea();
    float CalPerimeter();
};

Rectangle::Rectangle(std::string shp, float len, float wdth):Shape(shp)
{
    length = len;
    width = wdth;
}

Rectangle::~Rectangle()
{
}

std::string Rectangle::shapeName(){
    return shapename;
}

float Rectangle::CalArea(){
    float ans = length * width;
    return ans;
}

float Rectangle::CalPerimeter(){
    float ans = (length + width)/2;
    return ans;
}

class Triangle:public Shape
{
protected:
    float side1, side2, side3;
public:
    Triangle(std::string, float, float, float);
    ~Triangle();
    std::string shapeName();
    float CalArea();
    float CalPerimeter();
};

Triangle::Triangle(std::string shp, float s1, float s2, float s3):Shape(shp)
{
    side1 = s1;
    side2 = s2;
    side3 = s3;
}

Triangle::~Triangle()
{
}

std::string Triangle::shapeName(){
    return shapename;
}

float Triangle::CalArea(){
    float ans =  (side1 * side2)/2;
    return ans;
}

float Triangle::CalPerimeter(){ 
    float ans = side1 + side2 + side3;
    return ans;
}


class Circle:public Shape
{
protected:
    float radi;
public:
    Circle(std::string, float);
    ~Circle();
    std::string shapeName();
    float CalArea();
    float CalPerimeter();
};

Circle::Circle(std::string shp, float rad):Shape(shp)
{
    radi = rad;
}

Circle::~Circle()
{
}

std::string Circle::shapeName(){
    return shapename;
}

float Circle::CalArea(){
    float ans =  M_PI * pow(radi,2);
    return ans;
}

float Circle::CalPerimeter(){
    float ans = 2 * M_PI * radi;
    return ans;
}

int main(){
    std::string shapeName;
    float val1, val2, val3;
    std::cout << "Enter the name of the shape : ";
    std::cin >> shapeName;
    std::vector<std::unique_ptr<Shape>> shape;
    char firstChr = shapeName[0];
    switch (firstChr)
    {
    case 's':
    case 'S':
        std::cout << "Enter the value of length : ";
        std::cin >> val1;
        shape.push_back(std::make_unique<Square>(shapeName, val1));
        break;

    case 'r':
    case 'R':
        std::cout << "Enter the value of width : ";
        std::cin >> val1;
        std::cout << "Enter the value of length : ";
        std::cin >> val2;
        shape.push_back(std::make_unique<Rectangle>(shapeName, val2, val1));
        break;

    case 't':
    case 'T':
        std::cout << "Enter the value of side1 : ";
        std::cin >> val1;
        std::cout << "Enter the value of side2 : ";
        std::cin >> val2;
        std::cout << "Enter the value of side3 : ";
        std::cin >> val3;
        shape.push_back(std::make_unique<Triangle>(shapeName, val1, val2, val3));
        break;

    case 'c':
    case 'C':
        std::cout << "Enter the value of radius : ";
        std::cin >> val1;
        shape.push_back(std::make_unique<Circle>(shapeName, val1));
        break;
    
    default:
        break;
    }
    
    for (const auto& sh : shape)
    {
        std::cout << "Area of "<< sh->shapeName() << " = " << sh->CalArea() << std::endl;
        std::cout << "Perimeter of "<< sh->shapeName() << " = " << sh->CalPerimeter() << std::endl;
    }
    

    std::cout << "Press any key to exit...";
    std::cin.ignore();
    std::cin.get();
    return 0;
}