#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
    double amount=1000.0;
    double rate=0.05;
    double balance;
    cout<<"Year"<<setw(22)<<setfill(' ')<<"Amount on deposit\n";//the usage of setw, "right""setfill(' ')" on default
    for(int year=1;year<=10;year++)
    {
        balance=amount*pow(1.0+rate,year);
        cout<<setw(4)<<year<<setw(22)<<fixed<<setprecision(2)<<balance<<endl;//the usage of setprecision and fixed 
    }
}
/* setw: sets the width of the output field           */
/* |        abc| cout<<right<<setw(10)<<abc;          */
/* |abc        | cout<<left<<setw(10)<<abc;           */
/* |&&&&&&&&abc| cout<<setfill('&')<<setw(10)<<abc;   */