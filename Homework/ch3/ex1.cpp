#include <iostream>

using namespace std;

class MyBase1 {
public:
    MyBase1() { cout << "...BaseClass1 Object is created!" << endl; }
    ~MyBase1() { cout << "...BaseClass1 Object is destroyed!" << endl; }
};

class MyBase2 {
    MyBase1 a1;
public:
    MyBase2() { cout << "...BaseClass2 Object is created!" << endl; }
    ~MyBase2() { cout << "...BaseClass2 Object is destroyed!" << endl; }
};

class MyDerived1 : public MyBase2 {
    MyBase1 a1;
public:
    MyDerived1() { cout << "...First layer derived Object is created!" << endl; }
    ~MyDerived1() { cout << "...First layer derived Object is Destroyed!" << endl; }
};

class MyDerived11 : public MyDerived1 {
public:
    MyDerived11() { cout << "...Second layer derived Object is created!" << endl; }
    ~MyDerived11() { cout << "...Second layer derived Object is destroyed!" << endl; }
};

int main() {
    MyBase2 a;
    cout<<"-----------------------------"<<endl;
    MyDerived1 b;
    cout<<"-----------------------------"<<endl;
    MyDerived11 c;
    cout<<"-----------------------------"<<endl;
    return 0;
}
