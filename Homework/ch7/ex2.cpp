#include <iostream>
#include <stdexcept>

using namespace std;

class Item {
private:
    int value;

public:
    Item(int v) : value(v) {
        cout << "Item constructor called with value " << v << endl;
        if (value == 3) {
            throw runtime_error("An exception was thrown");
        }
    }

    ~Item() {
        cout << "Item destructor called for value " << value << endl;
    }

    int getValue() const {
        return value;
    }
};

int main() {
    try {
        cout << "Creating Item 1..." << endl;
        Item item1(1);

        cout << "Creating Item 2..." << endl;
        Item item2(2);

        cout << "Creating Item 3 (this will throw exception)..." << endl;
        Item item3(3);

        cout << "Creating Item 4 (this will not be reached)..." << endl;
        Item item4(4);
    }
    catch (runtime_error& e) {
        cout << "Exception caught: " << e.what() << endl;
    }

    cout << "Program ended" << endl;
    return 0;
}
