#include<iostream>
using namespace std;
class Complex
{
private:
    double realPart;
    double imaginaryPart;
public:
    Complex(double real=0.0, double imagine=0.0)
    {
        realPart=real;
        imaginaryPart=imagine;
    }
    Complex add(Complex other)
    {
        return Complex(realPart+other.realPart,imaginaryPart+other.imaginaryPart);
    }
    Complex minus(Complex other)
    {
        return Complex(realPart-other.realPart,imaginaryPart-other.imaginaryPart);
    }
    void print()
    {
        cout<<"("<<realPart<<","<<imaginaryPart<<")";
    }

};
int main()
{
    double a1,b1,a2,b2;
    char act;
    cin>>a1>>b1>>act>>a2>>b2;
    Complex num1={a1, b1},num2={a2, b2};
    if(act=='+')
    {
        num1.print();
        cout<<" + ";
        num2.print();
        cout<<" = ";
        num1.add(num2).print();
        cout<<endl;
    }
    else if(act=='-')
    {
        num1.print();
        cout<<" - ";
        num2.print();
        cout<<" = ";
        num1.minus(num2).print();
        cout<<endl;
    }
    else cout<<"Invalid\n";
    return 0;
}