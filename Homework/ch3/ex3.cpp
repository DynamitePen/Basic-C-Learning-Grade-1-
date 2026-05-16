#include <iostream>
using namespace std;

class MyBase3 {
private:
    int x;
    void fun1() { cout << "MyBase3---fun1()" << endl; }
protected:
    int y;
    void fun2() { cout << "MyBase3---fun2()" << endl; }
public:
    int z;
    void fun3() { cout << "MyBase3---fun3()" << endl; }
    MyBase3(int a, int b, int c) { x = a; y = b; z = c; }
    int getX() { return x; }
    int getY() { return y; }
    int getZ() { return z; }
    
};

// 2. public继承
class MyDerived1 : public MyBase3 {
    int p;
public:
    MyDerived1(int a) : MyBase3(a, a + 1, a + 2), p(a) {}
    int getP() { cout << "MyDerived---p:" << endl; return p; }
    void display() {
        cout << p << " " << getX() /*x cannot be accessed */ << " " << y << " " << z << endl;
        // fun1(); // private, cannot access
        cout<<"fun1() cannot be accessed due to private type in base class."<<endl;
        fun2();
        fun3();
    }
};

// 3. private继承
class MyDerived2 : private MyBase3 {
    int p;
public:
    MyDerived2(int a) : MyBase3(a, a + 1, a + 2), p(a) {}
    int getP() { cout << "MyDerived---p:" << endl; return p; }
    void display() {
        cout << p << " " << getX() /*x cannot be accessed */ << " " << y << " " << z << endl;
        // fun1(); // private, cannot access
        cout<<"fun1() cannot be accessed due to private type in base class."<<endl;
        fun2();
        fun3();
    }
};

class MyDerived21 : public MyDerived2 {
    int p;
public:
    MyDerived21(int a) : MyDerived2(a), p(a) {}
    int getP() { cout << "MyDerived21---p:" << endl; return p; }
    void display1() {
        cout << p << endl; // cannot access base class members
        cout<<"Cannot access base class members."<<endl;
        cout<<"fun1(), fun2(), fun3() cannot be accessed due to private type in base class."<<endl;
    }
};

// 4. protected继承
class MyDerived3 : protected MyBase3 {
    int p;
public:
    MyDerived3(int a) : MyBase3(a, a + 1, a + 2), p(a) {}
    int getP() { cout << "MyDerived---p:" << endl; return p; }
    void display() {
        cout << p << " " << getX() /*x cannot be accessed */ << " " << y << " " << z << endl;
        // fun1(); // private, cannot access
        cout<<"fun1() cannot be accessed due to private type in base class."<<endl;
        fun2();
        fun3();
    }
};

class MyDerived31 : public MyDerived3 {
    int p;
public:
    MyDerived31(int a) : MyDerived3(a), p(a) {}
    int getP() { cout << "MyDerived31---p:" << endl; return p; }
    void display1() {
        cout << p << endl; // cannot access base class members due to protected inheritance
        cout<<"Cannot access base class members."<<endl;
        cout<<"fun1(), fun2(), fun3() cannot be accessed due to protected type in base class."<<endl;
    }
};

class MyBase {
public:
void f1(){ cout << "...MyBase f1-----!" << endl; }
void f2(){ cout << "...MyBase f2-----!" << endl; }
};

class MyDerived : public MyBase {
public:
void f2(){ cout << "...MyDerived f2-----!" << endl; }
void f22(){ MyBase::f2(); cout << "...MyDerived f2-----!" << endl; }
void f3(){ cout << "...MyDerived f3-----!" << endl; }
};

int main() {
    // 2. public继承
    cout << "--public inheritance--" << endl;
    MyDerived1 a(3);
    cout<<"display"<<endl;
    a.display();
    cout << a.getP() << " " << a.getX() << " " << a.getY() << " " << a.getZ() << endl;

    // 3. private继承
    cout << "--private inheritance--" << endl;
    MyDerived2 b(3);
    cout<<"display"<<endl;
    b.display();
    // cout << b.getP() << " " << b.getX() << " " << b.getY() << " " << b.getZ() << endl; // 无法访问，因为private继承
    cout << b.getP() << endl; // 只能访问派生类的public
    cout <<"-----"<<endl;
    MyDerived21 c(6);
    c.display1();

    // 4. protected继承
    cout << "--protected inheritance--" << endl;
    MyDerived3 d(3);
    cout<<"display"<<endl;
    d.display();
    // cout << d.getP() << " " << d.getX() << " " << d.getY() << " " << d.getZ() << endl; // 无法访问，因为protected继承
    cout << d.getP() << endl;
    cout <<"-----"<<endl;
    MyDerived31 e(6);
    e.display1();

    cout<<"-----------------------------"<<endl;
    MyDerived f;
    f.f1(); // MyBase f1
    f.f2(); // MyDerived f2
    f.f3(); // MyDerived f3
    f.f22(); // MyBase f2 + MyDerived f2
}
