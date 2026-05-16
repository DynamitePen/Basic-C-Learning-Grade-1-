#include <iostream>
#include <cstring>
using namespace std;

class String
{
    
public:
    friend ostream &operator<<(ostream &output, const String &s)
    {
        output << s.sPtr;
        return output;
    }
    String(const char * const s = "")
    {
        if (s == nullptr)
        {
            length = 0;
            sPtr[0] = '\0';
        }
        else
        {
            length = strlen(s);
            strcpy(sPtr, s);
        }
        cout << "Conversion constructor: " << (s == nullptr ? "\"\"" : s) << endl;
    }
    
    String(const String &input)
    {
        length = input.length;
        cout << "Copy constructor: " << input.sPtr << endl;
        strcpy(sPtr, input.sPtr);
    }
    ~String()
    {
        cout << "Destructor: " << sPtr << endl;
    } 
    String operator=(const String &right) 
    {
        cout << "Assignment operator\n";
        if (this != &right)
        {
            length = right.length;
            strcpy(sPtr, right.sPtr);
        }
        else
        {
            cout << "Attempted self-assignment\n";
        }
        return *this; 
    }
    String operator+(const String &right)
    {
        cout << "Concatenation operator\n";
        String temp;
        temp.length = length + right.length;
        strcpy(temp.sPtr, sPtr);
        strcat(temp.sPtr, right.sPtr);
        return temp;
    }
    
private:
    char sPtr[100];
    int length;
};
int main()
{
    String string1, string2("The date is");
    String string3(" August 1, 1993");

    // test overloaded operators
    cout << "string1 = string2 + string3\n";
    string1 = string2 + string3; // tests overloaded = and + operator
    cout << "\"" << string1 << "\" = \"" << string2 << "\" + \""
         << string3 << "\"" << endl;

    return 0;
} // end main
