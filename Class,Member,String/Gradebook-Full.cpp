#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Gradebook {
private:
    string courseName;
public:
    Gradebook(string name="No available course name!") { //initialize courseName with name
        //initialize courseName with default value if name is not provided
        setCourseName(name);
    }
    void setCourseName(string name) { //set the course name
        if(name.length() > 25) { 
            courseName = name.substr(0, 25); //the usage of substr() to limit the course name to 25 characters
            cerr << "Name \"" << name << "\" exceeds maximum length (25). Limiting 25 characters." << endl;
        } 
        else courseName = name;
    }
    string getCourseName() const { //get the course name
        return courseName;
    }
    void displayMessage() const { //display a welcome message to the Gradebook user
        cout << "Welcome to the grade book for\n" << getCourseName() << "!" << endl;
    }
};

int main() {
    
Gradebook myGradebook1("CS101 Introduction to C++ Programming");
myGradebook1.displayMessage();
Gradebook myGradebook2("CS102 C++ Data Structures");
myGradebook2.displayMessage();
Gradebook myGradebook3; //use default constructor
myGradebook3.displayMessage();
return 0;
}

