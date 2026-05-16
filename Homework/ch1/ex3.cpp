#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
const int maxDigits=40; // maximum digits in a HugeInteger
class HugeInteger 
{ 
public: 
HugeInteger(int huge=0) // conversion/default constructor 
{
    for(int i=maxDigits-1;i>=0;i--)
    {
        if(huge>0)
        {
            integer[i]=huge%10;
            huge/=10;
        }
        else integer[i]=0;
    }
}
HugeInteger( const char *huge ) // conversion constructor 
{
    int size=strlen(huge)-1;
    for(int i=maxDigits-1;i>=0;i--)
    {
        if(size>=0)
        {
            integer[i]=huge[size]-'0';
            size--;
        }
        else integer[i]=0;
    }
}
HugeInteger add( const HugeInteger &huge )// HugeInteger + HugeInteger 
{
    HugeInteger temp;
    for(int i=maxDigits-1;i>=0;i--)
    {
        temp.integer[i]+=integer[i]+huge.integer[i];
        if(temp.integer[i]>9)
        {
            temp.integer[i]-=10;
            temp.integer[i-1]++;
        }
    }
    return temp;
} 
HugeInteger add(int huge)// HugeInteger + int 
{
    HugeInteger temp(huge);
    return add(temp);
}
HugeInteger add( const char *huge )// // HugeInteger + string that represents large integer value
{
    HugeInteger temp(huge);
    return add(temp);
}
HugeInteger subtract( const HugeInteger &huge )// HugeInteger - HugeInteger 
{
    HugeInteger temp;
    for(int i=maxDigits-1;i>=0;i--)
    {
        temp.integer[i]+=integer[i]-huge.integer[i];
        if(temp.integer[i]<0)
        {
            temp.integer[i]+=10;
            temp.integer[i-1]--;
        }
    }
    return temp;
} 
HugeInteger subtract( int huge )// HugeInteger - int 
{
    HugeInteger temp(huge);
    return subtract(temp);
}
HugeInteger subtract( const char *huge )// HugeInteger - string that represents large integer value 
{
    HugeInteger temp(huge);
    return subtract(temp);
}
bool isEqualTo( HugeInteger &huge )// is equal to 
{
    for(int i=0;i<maxDigits;i++)
    {
        if(integer[i]!=huge.integer[i]) return false;
    }
    return true;
}
bool isGreaterThan(HugeInteger &huge ) // greater than 
{
    for(int i=0;i<maxDigits;i++)
    {
        if(integer[i]>huge.integer[i]) return true;
        else if(integer[i]<huge.integer[i]) return false;
    }
    return false;
}
bool isLessThan( HugeInteger &huge ) // less than 
{
    for(int i=0;i<maxDigits;i++)
    {
        if(integer[i]<huge.integer[i]) return true;
        else if(integer[i]>huge.integer[i]) return false;
    }
    return false;
}
bool isGreaterThanOrEqualTo( HugeInteger &huge ) // greater than or equal to 
{
    if(isGreaterThan(huge)||isEqualTo(huge)) return true;
    else return false;
}
bool isLessThanOrEqualTo( HugeInteger &huge ) // less than or equal 
{
    if(isLessThan(huge)||isEqualTo(huge)) return true;
    else return false;
}
bool isZero() // is zero 
{
    for(int i=0;i<maxDigits;i++)
    {
        if(integer[i]!=0) return false;
    }
    return true;
}
void input( const char *huge ) // input 
{
    int size=strlen(huge)-1;
    for(int i=maxDigits-1;i>=0;i--)
    {
        if(size>=0)
        {
            integer[i]=huge[size]-'0';
            size--;
        }
        else integer[i]=0;
    }
}
void output() // output 
{
    int i=0;
    while(i<maxDigits-1&&integer[i]==0) i++;
    while(i<maxDigits)cout<<integer[i++];
}
private: 
int integer[ maxDigits ]={ 0 }; // maxDigits element array 
}; // end class HugeInteger
int main()
{
    char huge1[ maxDigits ], huge2[ maxDigits ];
    cout<<"Enter first huge integer: ";
    cin>>huge1;
    cout<<"Enter second huge integer: ";
    cin>>huge2;
    HugeInteger integer1( huge1 ), integer2( huge2 );
    cout<<"First huge integer is: ";
    integer1.output();
    cout<<"\nSecond huge integer is: ";
    integer2.output();
    cout<<"\n\nSum is: ";
    integer1.add( integer2 ).output();
    cout<<"\nDifference is: ";
    integer1.subtract( integer2 ).output();
    if ( integer1.isEqualTo( integer2 ) )
        cout<<"\n\nFirst huge integer is equal to second huge integer";
    if ( integer1.isGreaterThan( integer2 ) )
        cout<<"\n\nFirst huge integer is greater than second huge integer";
    if ( integer1.isLessThan( integer2 ) )
        cout<<"\n\nFirst huge integer is less than second huge integer";
    if ( integer1.isGreaterThanOrEqualTo( integer2 ) )
        cout<<"\n\nFirst huge integer is greater than or equal to second huge integer";
    if ( integer1.isLessThanOrEqualTo( integer2 ) )
        cout<<"\n\nFirst huge integer is less than or equal to second huge integer";
    if ( integer1.isZero() )
        cout<<"\n\nFirst huge integer is zero";
    if ( integer2.isZero() )
        cout<<"\n\nSecond huge integer is zero";
    return 0;
}