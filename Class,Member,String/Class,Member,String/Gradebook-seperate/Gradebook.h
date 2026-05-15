#include <iostream>
#include <string>

class Gradebook
{
private:
    std::string courseName;
public:
    Gradebook(std::string name);
    void setCourseName(std::string name);
    std::string getCourseName() const;
    void displayMessage() const;
};
