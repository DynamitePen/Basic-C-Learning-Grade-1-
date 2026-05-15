#include<iostream>
#include<string>
#include "Gradebook.h"
using namespace std;
Gradebook::Gradebook(string name){
    setCourseName(name);
}
void Gradebook::setCourseName(string name){
    if(name.length()>25)
    {
        courseName=name.substr(0,25);
        cerr<<"Name \""<<name<<"\" exceeds maximum length (25). Limiting 25 characters."<<endl;
    }
    else courseName=name;
}
string Gradebook::getCourseName() const{
    return courseName;
}
void Gradebook::displayMessage() const{
    cout<<"Welcome to the grade book for\n"<<getCourseName()<<"!"<<endl;
}
