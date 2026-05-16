#include<iostream>
#include<cstring>
#include<string>
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
HugeInteger operator+( const HugeInteger &huge )// HugeInteger + HugeInteger 
{
    HugeInteger temp;
    for(int i=maxDigits-1;i>=0;i--)
    {
        temp.integer[i]+=integer[i]+huge.integer[i];
        if(temp.integer[i]>9)
        {
            if(i==0) throw invalid_argument("Addition overflow");
            temp.integer[i]-=10;
            temp.integer[i-1]++;
        }
    }
    return temp;
}
HugeInteger operator+( int huge )// HugeInteger + int 
{
    HugeInteger temp(huge);
    return *this + temp;
}
HugeInteger operator+( const char *huge )// HugeInteger + string that represents large integer value
{
    HugeInteger temp(huge);
    return *this + temp;
}
HugeInteger operator-( const HugeInteger &huge )// HugeInteger - HugeInteger 
{
    HugeInteger temp;
    for(int i=maxDigits-1;i>=0;i--)
    {
        temp.integer[i]+=integer[i]-huge.integer[i];
        if(temp.integer[i]<0)
        {
            if(i==0) throw invalid_argument("Subtraction overflow");
            temp.integer[i]+=10;
            temp.integer[i-1]--;
        }
    }
    return temp;
} 
HugeInteger subtract( int huge )// HugeInteger - int 
{
    HugeInteger temp(huge);
    return *this - temp;
}
HugeInteger subtract( const char *huge )// HugeInteger - string that represents large integer value 
{
    HugeInteger temp(huge);
    return *this - temp;
}
bool operator==(const HugeInteger &huge ) const // is equal to 
{
    for(int i=0;i<maxDigits;i++)
    {
        if(integer[i]!=huge.integer[i]) return false;
    }
    return true;
}
bool operator==(int huge) const // is equal to int 
{
    HugeInteger temp(huge);
    return operator==(temp);
}
bool operator==(const char *huge) const // is equal to string that represents large integer value 
{
    HugeInteger temp(huge);
    return operator==(temp);
}
bool operator>(const HugeInteger &huge ) const // greater than 
{
    for(int i=0;i<maxDigits;i++)
    {
        if(integer[i]>huge.integer[i]) return true;
        else if(integer[i]<huge.integer[i]) return false;
    }
    return false;
}
bool operator<(const HugeInteger &huge ) const // less than 
{
    for(int i=0;i<maxDigits;i++)
    {
        if(integer[i]<huge.integer[i]) return true;
        else if(integer[i]>huge.integer[i]) return false;
    }
    return false;
}
bool operator>=(const HugeInteger &huge ) const // greater than or equal to 
{
    if(operator>(huge)||operator==(huge)) return true;
    else return false;
}
bool operator<=(const HugeInteger &huge ) const // less than or equal 
{
    if(operator<(huge)||operator==(huge)) return true;
    else return false;
}
// bool isZero() // is zero 
// {
//     for(int i=0;i<maxDigits;i++)
//     {
//         if(integer[i]!=0) return false;
//     }
//     return true;
// }
friend istream& operator>>(istream &is, HugeInteger &huge ) // input 
{
    char hugeT[maxDigits];
    is>>hugeT;
    int size=strlen(hugeT)-1;
    for(int i=maxDigits-1;i>=0;i--)
    {
        if(size>=0)
        {
            huge.integer[i]=hugeT[size]-'0';
            size--;
        }
        else huge.integer[i]=0;
    }
    return is;
}
friend ostream& operator<<(ostream &os, const HugeInteger &huge ) // output 
{
    int i=0;
    while(i<maxDigits-1&&huge.integer[i]==0) i++;
    while(i<maxDigits)os<<huge.integer[i++];
    return os;
}
HugeInteger operator=( const HugeInteger &huge )// assignment operator 
{
    for(int i=0;i<maxDigits;i++)
    {
        integer[i]=huge.integer[i];
    }
    return *this;
}
HugeInteger operator=( int huge )
{
    HugeInteger temp(huge);
    return *this = temp;
}
HugeInteger operator=( const char *huge )
{
    HugeInteger temp(huge);
    return *this = temp;
}
public:
HugeInteger operator*( const HugeInteger &huge )// HugeInteger * HugeInteger 
{
    HugeInteger temp;
    for(int i=maxDigits-1;i>=0;i--)
    {
        for(int j=maxDigits-1;j>=0;j--)
        {
            temp.integer[i+j-maxDigits+1]+=integer[i]*huge.integer[j];
        }
    }
    for(int i=maxDigits-1;i>=0;i--)
    {
        if(temp.integer[i]>9)
        {
            if(i==0) throw invalid_argument("Multiplication overflow");
            temp.integer[i-1]+=temp.integer[i]/10;
            temp.integer[i]%=10;
        }
    }
    return temp;
}
HugeInteger operator*( int huge )// HugeInteger * int 
{
    HugeInteger temp(huge);
    return *this * temp;
}
HugeInteger operator*( const char *huge )// HugeInteger * string that represents large integer value 
{
    HugeInteger temp(huge);
    return *this * temp;
}
int getLength() const // get the number of digits
{
    int length=0;
    for(int i=0;i<maxDigits;i++)
    {
        if(integer[i]!=0)
        {
            length=maxDigits-i;
            break;
        }
    }
    return length;
}
HugeInteger operator/( const HugeInteger &huge )// HugeInteger / HugeInteger 
{
    if(huge==0) throw invalid_argument("Division by zero");
    HugeInteger quotient;
    HugeInteger temp(*this); // copy of dividend
    
    // Simple division by repeated subtraction
    while(temp>=huge)
    {
        temp=temp-huge;
        quotient=quotient+1;
    }
    
    return quotient;
}
private: 
int integer[ maxDigits ]={ 0 }; // maxDigits element array 
}; // end class HugeInteger
int main()
{
    HugeInteger huge1,huge2;
    cout<<"Enter first huge integer: ";
    cin>>huge1;
    cout<<"Enter second huge integer: ";
    cin>>huge2;
    if(huge1>huge2) cout<<huge1<<" is greater than "<<huge2<<endl;
    else if(huge1<huge2) cout<<huge1<<" is less than "<<huge2<<endl;
    else cout<<huge1<<" is equal to "<<huge2<<endl;
    cout<<"The sum is: "<<huge1+huge2<<endl;
    cout<<"The difference is: "<<huge1-huge2<<endl;
    cout<<"The product is: "<<huge1*huge2<<endl;
    cout<<"The quotient is: "<<huge1/huge2<<endl;
    return 0;
}