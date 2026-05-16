#include<iostream>
using namespace std;
class IntegerSet
{
private:
    bool gather[101]={0};
public:
    void insertElement(int element)
    {
        if(element>=0&&element<=100) gather[element]=1;
    }
    void deleteElement(int element)
    {
        if(element>=0&&element<=100) gather[element]=0;
    }
    void printSet()
    {
       for(int i=0;i<101;i++)
       {
           if(gather[i]) cout<<i<<" ";
       }
    }
    bool isEqualTo(IntegerSet &integerSet)
    {
        for(int i=0;i<101;i++)
        {
            if(gather[i]!=integerSet.gather[i]) return false;
        }
         return true;
    }
    IntegerSet unionOfSets(IntegerSet &integerSet)
    {
        IntegerSet temp;
        for(int i=0;i<101;i++)
        {
            if(gather[i]||integerSet.gather[i]) temp.insertElement(i);
        }
        return temp;
    }
    IntegerSet intersectionOfSets(IntegerSet &integerSet)
    {
        IntegerSet temp;
        for(int i=0;i<101;i++)
        {
            if(gather[i]&&integerSet.gather[i]) temp.insertElement(i);
        }
        return temp;
    }
};
int main()
{
    IntegerSet s1, s2;
    cout<<"Enter elements for set 1 (0-100, -1 to end): ";
    int element;
    while(cin>>element&&element!=-1)
    {
        s1.insertElement(element);
    }
    cout<<"Enter elements for set 2 (0-100, -1 to end): ";
    while(cin>>element&&element!=-1)
    {
        s2.insertElement(element);
    }
    cout<<"Set 1: ";
    s1.printSet();
    cout<<"\nSet 2: ";
    s2.printSet();
    int choice;
    cout<<"\nMenu:\n1. Insert element\n2. Delete element\n3. Union of sets\n4. Intersection of sets\n5. Check if sets are equal\n-1 to exit\n";
    while(cin>>choice&&choice!=-1)
    {
        if(choice==1)
        {
            int setnum, element;
            cout<<"Enter set number (1 or 2) \n";
            cin>>setnum;
            cout<<"Enter element to insert (0-100) ,-1 to end: \n";
            while(cin>>element&&element!=-1)
            {
                if(setnum==1) s1.insertElement(element);
                else if(setnum==2) s2.insertElement(element);
            }
            cout<<"Set "<<setnum<<": ";
            if(setnum==1) s1.printSet();
            else if(setnum==2) s2.printSet();
        }
        else if(choice==2)
        {
            int setnum, element;
            cout<<"Enter set number (1 or 2) \n";
            cin>>setnum;
            cout<<"Enter element to delete (0-100) ,-1 to end: \n";
            while(cin>>element&&element!=-1)
            {
                if(setnum==1) s1.deleteElement(element);
                else if(setnum==2) s2.deleteElement(element);
            }
            cout<<"Set "<<setnum<<": ";
            if(setnum==1) s1.printSet();
            else if(setnum==2) s2.printSet();
        }
        else if(choice==3)
        {
            cout<<"Union of sets: ";
            IntegerSet s3=s1.unionOfSets(s2);
            s3.printSet();
            cout<<'\n';
        }
        else if(choice==4)
        {
            cout<<"Intersection of sets: ";
            IntegerSet s4=s1.intersectionOfSets(s2);
            s4.printSet();
            cout<<'\n';
        }
        else if(choice==5)
        {
            if(s1.isEqualTo(s2)) cout<<"Sets are equal\n";
            else cout<<"Sets are not equal\n";
        }
    }
    return 0;
}