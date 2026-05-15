#include<iostream>
#include<string>
#include "Gradebook.h"

using namespace std;
int main() {
    Gradebook myGradebook1("CS101 Introduction to C++ Programming");
    myGradebook1.displayMessage();
    Gradebook myGradebook2("CS102 C++ Data Structures");
    myGradebook2.displayMessage();
    Gradebook myGradebook3("CS103 C++ Algorithms");
    myGradebook3.displayMessage();
    return 0;
}