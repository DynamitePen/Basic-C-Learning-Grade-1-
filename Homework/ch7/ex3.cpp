#include <iostream>
#include <stdexcept>

using namespace std;

class TestException : public runtime_error {
public:
    TestException(const string& msg) : runtime_error(msg) {}
};

void g() {
    try {
        cout << "In function g(): Throwing TestException" << endl;
        throw TestException("Exception from function g()");
    }
    catch (exception& e) {
        cout << "In g() catch block: Caught exception" << endl;
        cout << "Exception message in g(): " << e.what() << endl;
        cout << "In g() catch block: Re-throwing the exception" << endl;
        throw;
    }
}

int main() {
    try {
        cout << "In main(): Calling function g()" << endl;
        g();
        cout << "This line will not be reached" << endl;
    }
    catch (TestException& e) {
        cout << "In main() catch block: Caught TestException" << endl;
        cout << "Exception message: " << e.what() << endl;
    }

    cout << "Program ended normally" << endl;
    return 0;
}
