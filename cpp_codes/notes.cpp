#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ar array
#define pii pair<int, int>
const int maxn = 2000001, maxt = 100002, mod = 1000000007;
int di[4] = { 0, 1, 0, -1 };
int dj[4] = { 1, 0, -1, 0 };
int did[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };
int djd[8] = { 1, 0, -1, 0, 1, -1, 1, -1 };
int dp[maxt], ans[maxn];
int a, b, c, d, e, i, j, k, l = INT_MAX, m = -1, n, o, p, q, r, s, t = 1, u, v,
w, x, y, z, tot = 0, si = -1, sj, ei = 0, ej = 0;
bool flag, flag2;
string str, str2;
bool isValid(int i, int j, vector<string>& v) {
    return i > -1 && i < n&& j > -1 && j < m&& v[i][j] == '.';
}

// public members of a class can be accessed from anywhere in the program
// only member functions or the friend functions are allowed to access the
// private data members can’t be accessed outside of its class unless with the
// help of a friend class or sub class
class Shape {
private:
    string name;

protected:
    int count;

public:
    // Shape() {} //default constructor
    Shape(string name) { this->name = name; }
    ~Shape() {} // destructor deconstructor  // dont have to call explicitly, c++ will do it itself
    void setName(string name) { this->name = name; }
    string getName() const { return name; }
    virtual double getArea() const = 0;
    // now that we have added a virtual function, there MUST be an overrider in
    // each base class pure virtual function "Shape::getArea" has no overrider
};
class Circle: public Shape {
private:
    double radius;

public:
    // : Shape(name)
    Circle(string name, double radius): Shape(name) {
        //? constructor for 'Circle' must explicitly initialize the
        //? base class 'Shape' which does not have a
        //? default constructor thats why
        // todo                      : Shape(name) is necessary
        this->radius = radius;
    }
    void setRadius(double radius) { this->radius = radius; }
    double getRadius() const { return this->radius; }

    void setCount(int count) { //?protected
        this->count = count;
    }
    int getCount() { return this->count; }

    void modifyName() {
        string name = getName();
        setName(name + "modified");
    }

    double getArea() const { return M_PI * radius * radius; }
    // void setName(string name) {
    //     this->name = name; //!member "Shape::name" is inaccessible
    // }
    // string getName() const {
    //     return name;  //!member "Shape::name" is inaccessible
    // }
};
// class Rectangle:public Shape, /* for any of public/private*/ public  Circle {
// //? 'Shape' is inaccessible due to ambiguity: (which happened due to indirect
// inheritance) private:
//     int height, width;
// public:
//     Rectangle(string name, int height, int width): Shape(name),Circle(name,
//     double(5)) {

//     }

// };
class Rectangle: public Shape {
private:
    int height, width;

public:
    Rectangle(string name, int height, int width): Shape(name) {
        this->height = height;
        this->width = width;
    }
    int getHeight() const {
        return this->height;
        return height;
    }
    int getWidth() const {
        return this->width;
        return width;
    }
    void setHeight(int height) { this->height = height; }
    void setWidth(int width) { this->width = width; }

    double getArea() const { //? const here show read only
        return 1.0 * height * width;
    }
};
class Cuboid: public Rectangle {
private:
    int depth;
public:
    Cuboid(string name, int height, int width, int depth)
        : Rectangle(name, height, width) {
        this->depth = depth;
    }
    double getArea() const {
        return 2.0 * (getHeight() * getWidth() + getHeight() * depth +
            getWidth() * depth);
    }
};
int32_t main() {
    //*** this whole code was working before we added virtual function in Shape
    //class and made it abstract base class(for which we're supposed to create an
    //object)
    /***
        // Shape* shape = new Shape("Shape");
        // shape->setName("Cylinder");
        // cout << shape->getName() << endl;

        // Shape* circle = new Circle(
        //     "Shape", 5); //? Decalring a shape object using circle, can't do it
    other
        // // way around (because Circle's constructor eventually calling
        // // Shape's constructor)
        // circle->setName("circle");
        // cout << circle->getName();
        // // cout<<circle->getRadius()<<endl;    //! wont work since circle is of
    class


    ***/
    // Inheritance:

    // Polymorphism:
    vector<Shape*> shapes{ new Circle("Circle", 2.32),
                           new Rectangle("Rectangle", 5, 4),
                           new Cuboid("cuboid", 1, 2, 3) };


    // Run time (Function overriding, virtual functions)
    // Compile time (Function Overloading and Operator Overloading) 

    //changing the number of arguments or/and changing the type of arguments
    //Complex operator+(Complex const& obj){
    //     Complex res;
    //     res.real = real + obj.real;
    //     res.imag = imag + obj.imag;
    //     return res;
    // }


    //     Abstract Class :
    //     friend class F; //? should be written in some class, after than class F can access both private and protected members of that class; (Friendship is not mutual)
    // friend function can be granted special access to private and protected members of a class in C++
    // friend function can be global as well as member of other function (helps in  calcucaltion/comparison across classes)


    //Solid
    // Single Responsibility Principle: class should do one thing and therefore it should have only a single reason to change
    // Open-Closed Principle: classes should be open for extension and closed to modification
    // Liskov Substitution Principle: subclasses should be substitutable for their base classes //all public methods of parent class should work for child class
    // Interface Segregation Principle: separating the interfaces
    // Dependency Inversion Principle: classes should depend upon interfaces or abstract classes instead of concrete classes and functions

    return 0;
}

/*
class Parent {
public:
    void GeeksforGeeks() {
        cout<<"Parent\n";
    }
};
class Child: public Parent {
public:
    void GeeksforGeeks() {
        cout<<"Child\n";
    }
};
int main() {
    Child Child_Derived;
    Child_Derived.GeeksforGeeks(); //prints Child
    return 0;
}
*/