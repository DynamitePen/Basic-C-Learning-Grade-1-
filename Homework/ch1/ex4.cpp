#include <iostream>
using namespace std;
class SimpleCalculator {
public:
    double add(double a,double b) 
    {
        return a+b;
    }
    double subtract(double a,double b)
    {
        return a-b;
    } 
    double multiply(double a,double b)
    {
        return a*b;
    }
    double divide(double a,double b) 
    {
        if (b==0) 
        {
            cout << "Error: division by zero\n";
            return 0;
        }
        return a/b;
    }
};
int main() {
    SimpleCalculator sc; 
    double a, b;
    cout<<"The value of a is: ";
    cin>>a;
    cout<<"The value of b is: ";
    cin>>b;
    cout<<"Adding a and b yields: "<<sc.add(a, b)<<'\n';
    cout<<"Subtracting b from a yields: "<<sc.subtract(a, b)<<'\n';
    cout<<"Multiplying a and b yields: "<<sc.multiply(a, b)<<'\n';
    cout<<"Dividing a by b yields: "<<sc.divide(a, b)<<'\n';
    return 0;
}