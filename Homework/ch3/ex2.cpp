#include <iostream>
using namespace std;
class MyBase31 {
int a, b, c;
public:
MyBase31(int x, int y, int z) :a(x), b(y), c(z)
{
cout << "...BaseClass31 Object is created!" << endl;
cout << a << " " << b << " " << c << endl;
}
~MyBase31(){ cout << "...BaseClass31 Object is destroyed!" << endl; }
int getA() { return a; }
int getB() { return b; }
int getC() { return c; }
};

class MyBase32 {
int a, b, c;
public:
MyBase32(int x, int y, int z)
{
cout << "...BaseClass32 Object is created!" << endl;
cout << a << " " << b << " " << c << endl;// random garbage value
a=x, b=y, c=z;
cout << a << " " << b << " " << c << endl;
}
~MyBase32(){ cout << "...BaseClass32 Object is destroyed!" << endl; }
};

class MyDerived1 : public MyBase31 {
MyBase31 a;
int c;
public:
MyDerived1(int x) : MyBase31(x,8,9), a(5,6,7), c(x)
{
cout << "...Base Object has been created!" << endl;
cout << "...Member Object has been created! " << a.getA() << " " << a.getB() << " " << a.getC() << endl;
//cannot access base class's private members directly, but can access through public member functions
cout << "...Derived Object is created! " << c << endl;
}
};

int main()
{
MyBase31 a(1,2,3);
cout<<"-----------------------------"<<endl;
MyBase32 b(4,5,6);
cout<<"-----------------------------"<<endl;
MyDerived1 c(88);
cout<<"-----------------------------"<<endl;
return 0;
}
