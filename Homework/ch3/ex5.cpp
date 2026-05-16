#include <iostream>
#include <string>

using namespace std;

class Date {
private:
    int year, month, day;
public:
    Date(int y, int m, int d) : year(y), month(m), day(d) {}
    string toString() const {
        
    }
};

class FinalTest {
public:
    FinalTest(string t, Date d) : title(t), dueDate(d) {}
    FinalTest(string t) : title(t), dueDate(Date(2014, 1, 1)) {}
    void setDue(Date d) {
        dueDate = d;
    }
    void print() const {
        cout << "Title: " << title << endl;
        cout << "Test Date: " << dueDate.toString() << endl;
    }
private:
    string title;
    Date dueDate;
};

int main() {
    FinalTest item1("C++ Test", Date(2014, 6, 2));
    item1.print();
    FinalTest item2("Java");
    item2.print();
    item2.setDue(Date(2014, 6, 10));
    item2.print();
    return 0;
}
