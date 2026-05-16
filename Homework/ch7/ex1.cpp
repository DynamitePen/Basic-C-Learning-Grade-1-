#include <iostream>
#include <stdexcept>

using namespace std;

class TestException : public runtime_error {
public:
    TestException(const string& msg) : runtime_error(msg) {}
};

int main() {
    try {
        try {
            cout << "Throwing first exception..." << endl;
            throw TestException("First exception thrown");
        }
        catch (TestException& e) {
            cout << "Caught in inner handler: " << e.what() << endl;
            cout << "Re-throwing the same exception..." << endl;
            throw;
        }
    }
    catch (TestException& e) {
        cout << "Caught in outer handler: " << e.what() << endl;
        cout << "Re-throwing again..." << endl;
        throw;
    }

    cout << "This line will not be reached" << endl;
    return 0;
}
