#include <iostream>
#include <stdexcept>

using namespace std;

class TestException : public runtime_error {
public:
    TestException(const string& msg) : runtime_error(msg) {}
};

void h() {
    cout << "  Entering h()" << endl;
    cout << "  Throwing TestException from h()" << endl;
    throw TestException("Exception thrown in function h()");
    cout << "  This line in h() will not be executed" << endl;
}

void g() {
    cout << " Entering g()" << endl;
    try {
        cout << " Calling h() from g()" << endl;
        h();
    }
    catch (TestException& e) {
        cout << " Caught in g(): " << e.what() << endl;
        cout << " Rethrowing from g()" << endl;
        throw;
    }
    cout << " This line in g() will not be executed" << endl;
}

void f() {
    cout << "Entering f()" << endl;
    try {
        cout << "Calling g() from f()" << endl;
        g();
    }
    catch (TestException& e) {
        cout << "Caught in f(): " << e.what() << endl;
        cout << "Rethrowing from f()" << endl;
        throw;
    }
    cout << "This line in f() will not be executed" << endl;
}

int main() {
    cout << "Starting program..." << endl;
    try {
        cout << "Calling f() from main()" << endl;
        f();
        cout << "This line in main() will not be executed" << endl;
    }
    catch (TestException& e) {
        cout << "Caught in main(): " << e.what() << endl;
    }
    catch (exception& e) {
        cout << "Caught exception in main(): " << e.what() << endl;
    }

    cout << "Program ended normally" << endl;
    return 0;
}
