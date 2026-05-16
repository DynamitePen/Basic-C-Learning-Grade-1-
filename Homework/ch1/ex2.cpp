#include<iostream>
#include<iomanip>
using namespace std;
class Time
{
private:
    int hour,minute,second;
public:
    Time(int h=0,int m=0,int s=0)
    {
        setTime(h,m,s); 
    }
    void setTime(int h,int m,int s)
    {
        if(h>=0&&h<=24)hour=h;
        else throw invalid_argument("Invalid hour!");
        if(m>=0&&m<=60)minute=m;
        else throw invalid_argument("Invalid minute!");
        if(s>=0&&s<=60)second=s;
        else throw invalid_argument("Invalid second!");
        
    }
    void printTime()
    {
        int h12=hour%12;
        if(hour==0||hour==12)h12=12;
        cout<<setfill('0');
        cout<<setw(2)<<h12<<":"<<setw(2)<<minute<<":"<<setw(2)<<second<<" ";
        cout<<((hour>=12)?"PM\n":"AM\n");
    }
    void tick()
    {
        ++second;
        if(second>=60)
        {
            second-=60;
            minute++;
        }
        if(minute>=60)
        {
            minute-=60;
            hour++;
        }
        if(hour>=24)hour=0;
    }
};
int main()
{
    int hh,mm,ss;
    cin>>hh>>mm>>ss;
    Time t{hh,mm,ss};
    int sec=0;
    cin>>sec;
    for(int i=1;i<=sec;i++)
    {
        t.tick();
        t.printTime();
    }
    return 0;
}