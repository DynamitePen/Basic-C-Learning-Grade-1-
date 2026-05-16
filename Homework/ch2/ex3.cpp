#include <iostream>
using namespace std;
class RationalNumber
{
public:
RationalNumber(int num = 0, int den = 1){
    numerator=num;
    denominator=den;
    if (denominator == 0)throw invalid_argument("Denominator cannot be zero");
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
    reduction();
}
RationalNumber operator+(const RationalNumber &r) 
{
    RationalNumber result;
    result.numerator = numerator * r.denominator + denominator * r.numerator;
    result.denominator = denominator * r.denominator;
    result.reduction();
    return result;
}
RationalNumber operator-(const RationalNumber &r) 
{
    RationalNumber result;
    result.numerator = numerator * r.denominator - denominator * r.numerator;
    result.denominator = denominator * r.denominator;
    result.reduction();
    return result;
}
RationalNumber operator*(const RationalNumber &r) 
{
    RationalNumber result;
    result.numerator = numerator * r.numerator;
    result.denominator = denominator * r.denominator;
    result.reduction();
    return result;
}
RationalNumber operator/(const RationalNumber &r) 
{
    if (r.numerator == 0)throw invalid_argument("Division by zero");
    RationalNumber result;
    result.numerator = numerator * r.denominator;
    result.denominator = denominator * r.numerator;
    if (result.denominator < 0) 
    {
        result.numerator = -result.numerator;
        result.denominator = -result.denominator;
    }
    result.reduction();
    return result;
}
bool operator>(const RationalNumber& r) const {
    return numerator * r.denominator > denominator * r.numerator;
}
bool operator<(const RationalNumber& r) const {
    return numerator * r.denominator < denominator * r.numerator;
}
bool operator>=(const RationalNumber& r) const {
    return !(*this < r);
}
bool operator<=(const RationalNumber& r) const {
    return !(*this > r);
}
bool operator==(const RationalNumber& r) const {
    return numerator == r.numerator && denominator == r.denominator;
}
bool operator!=(const RationalNumber& r) const {
    return !(*this == r);
}
void printRational() const {
    if (denominator == 1) cout << numerator;
    else cout << numerator << "/" << denominator;
}
void reduction() 
{
    int g = gcd(numerator, denominator);
    numerator /= g;
    denominator /= g;
}
int gcd(int a, int b) {
    if(b==0) return a;
    return gcd(b, a % b);
}
private:
    int numerator;
    int denominator;
};
int main()
{
 RationalNumber c( 7, 3 ), d( 3, 9 ), x;
 c.printRational();
 cout << " + " ;
 d.printRational();
 cout << " = ";
 x = c + d; // test overloaded operators + and =
 x.printRational();
 cout << '\n';
 c.printRational();
 cout << " - " ;
 d.printRational();
 cout << " = ";
 x = c - d; // test overloaded operators - and =
 x.printRational();
 cout << '\n';
 c.printRational();
 cout << " * " ;
 d.printRational();
 cout << " = ";
 x = c * d; // test overloaded operators * and =
 x.printRational();
 cout << '\n';
 c.printRational();
 cout << " / " ;
 d.printRational();
 cout << " = ";
 x = c / d; // test overloaded operators / and =
 x.printRational();
 cout << '\n';
 c.printRational();
 cout << " is:\n";
 // test overloaded greater than operator
 cout << ( ( c > d ) ? " > " : " <= " );
 d.printRational();
 cout << " according to the overloaded > operator\n";
 // test overloaded less than operator
 cout << ( ( c < d ) ? " < " : " >= " );
 d.printRational();
 cout << " according to the overloaded < operator\n";
 // test overloaded greater than or equal to operator
 cout << ( ( c >= d ) ? " >= " : " < " );
 d.printRational();
 cout << " according to the overloaded >= operator\n";
 // test overloaded less than or equal to operator
 cout << ( ( c <= d ) ? " <= " : " > " );
 d.printRational();
 cout << " according to the overloaded <= operator\n";
 // test overloaded equality operator
 cout << ( ( c == d ) ? " == " : " != " );
 d.printRational();
 cout << " according to the overloaded == operator\n";
 // test overloaded inequality operator
 cout << ( ( c != d ) ? " != " : " == " );
 d.printRational();
 cout << " according to the overloaded != operator" << endl;
 return 0;
} // end main
