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
    Complex operator+(Complex other)
    {
        return Complex(realPart+other.realPart,imaginaryPart+other.imaginaryPart);
    }
    Complex operator-(Complex other)
    {
        return Complex(realPart-other.realPart,imaginaryPart-other.imaginaryPart);
    }
    Complex operator=(Complex other)
    {
        realPart=other.realPart;
        imaginaryPart=other.imaginaryPart;
        return *this;
    }
    Complex operator*(Complex other)
    {
        return Complex(realPart*other.realPart-imaginaryPart*other.imaginaryPart,realPart*other.imaginaryPart+imaginaryPart*other.realPart);
    }
    bool operator==(Complex other)
    {
        return realPart==other.realPart && imaginaryPart==other.imaginaryPart;
    }
    bool operator!=(Complex other)
    {
        return realPart!=other.realPart || imaginaryPart!=other.imaginaryPart;
    }
    friend ostream& operator<<(ostream& os, Complex& c)
    {
        os<<"("<<c.realPart<<","<<c.imaginaryPart<<")";
        return os;
    }
    friend istream& operator>>(istream& is, Complex& c)
    {
        char act;
        is>>act>>c.realPart>>act>>c.imaginaryPart>>act;
        return is;
    }  
};
int main()
{
 Complex x, y( 4.3, 8.2 ), z( 3.3, 1.1 ), k;
 cout << "Enter a complex number in the form: (a, b)\n? ";
 cin >> k; // demonstrating overloaded >>
 cout << "x: " << x << "\ny: " << y << "\nz: " << z << "\nk: "
 << k << '\n'; // demonstrating overloaded <<
 x = y + z; // demonstrating overloaded + and =
 cout << "\nx = y + z:\n" << x << " = " << y << " + " << z << '\n';
 x = y - z; // demonstrating overloaded - and =
 cout << "\nx = y - z:\n" << x << " = " << y << " - " << z << '\n';
 x = y * z; // demonstrating overloaded * and =
 cout << "\nx = y * z:\n" << x << " = " << y << " * " << z << "\n\n";
 if ( x != k ) // demonstrating overloaded !=
 cout << x << " != " << k << '\n';
 cout << '\n';
 x = k;
 if ( x == k ) // demonstrating overloaded ==
 cout << x << " == " << k << '\n';
 return 0;
} // end main