#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;

class Student {
private:
    int id;
    char firstName[50];
    char lastName[50];
    double grade;

public:
    Student() : id(0), grade(0.0) {
        firstName[0] = '\0';
        lastName[0] = '\0';
    }

    Student(int id, const char* fn, const char* ln, double g) : id(id), grade(g) {
        strcpy(firstName, fn);
        strcpy(lastName, ln);
    }

    void display() const {
        cout << setw(8) << id << setw(20) << firstName << setw(20) << lastName << setw(10) << fixed << setprecision(2) << grade << endl;
    }

    int getId() const {
        return id;
    }

    const char* getFirstName() const {
        return firstName;
    }

    const char* getLastName() const {
        return lastName;
    }

    double getGrade() const {
        return grade;
    }

    void setData(int value, const char* fn, const char* ln, double g) {
        id = value;
        strcpy(firstName, fn);
        strcpy(lastName, ln);
        grade = g;
    }

    bool isDeleted() const {
        return id == -1;
    }

    void markDeleted() {
        id = -1;
    }
};

void displayAllRecords(const char* filename) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cout << "Cannot open file!" << endl;
        return;
    }

    Student s;
    int count = 0;
    double sum = 0.0;

    cout << "\n========== All Student Records ==========" << endl;
    cout << setw(8) << "ID" << setw(20) << "First Name" << setw(20) << "Last Name" << setw(10) << "Grade" << endl;
    cout << "========================================" << endl;

    while (file.read((char*)&s, sizeof(Student))) {
        if (!s.isDeleted()) {
            s.display();
            sum += s.getGrade();
            count++;
        }
    }

    file.close();

    if (count > 0) {
        cout << "========================================" << endl;
        cout << "Average Grade: " << fixed << setprecision(2) << (sum / count) << endl;
        cout << "Total Students: " << count << endl;
    } else {
        cout << "No records found!" << endl;
    }
    cout << endl;
}

void addRecord(const char* filename) {
    fstream file(filename, ios::in | ios::out | ios::binary | ios::ate);
    if (!file) {
        file.open(filename, ios::out | ios::binary);
    }

    Student s;
    int id;
    char firstName[50];
    char lastName[50];
    double grade;

    cout << "Enter Student ID: ";
    cin >> id;
    cout << "Enter First Name: ";
    cin >> firstName;
    cout << "Enter Last Name: ";
    cin >> lastName;
    cout << "Enter Grade: ";
    cin >> grade;

    s.setData(id, firstName, lastName, grade);

    file.seekp(0, ios::end);
    file.write((char*)&s, sizeof(Student));
    file.close();

    cout << "Record added successfully!" << endl;
}

void deleteRecord(const char* filename) {
    int delId;
    cout << "Enter Student ID to delete: ";
    cin >> delId;

    fstream file(filename, ios::in | ios::out | ios::binary);
    if (!file) {
        cout << "Cannot open file!" << endl;
        return;
    }

    Student s;
    bool found = false;

    while (file.read((char*)&s, sizeof(Student))) {
        if (s.getId() == delId) {
            s.markDeleted();
            file.seekp(-sizeof(Student), ios::cur);
            file.write((char*)&s, sizeof(Student));
            found = true;
            break;
        }
    }

    file.close();

    if (found) {
        cout << "Record deleted successfully!" << endl;
    } else {
        cout << "Record not found!" << endl;
    }
}

void modifyRecord(const char* filename) {
    int modId;
    cout << "Enter Student ID to modify: ";
    cin >> modId;

    fstream file(filename, ios::in | ios::out | ios::binary);
    if (!file) {
        cout << "Cannot open file!" << endl;
        return;
    }

    Student s;
    bool found = false;

    while (file.read((char*)&s, sizeof(Student))) {
        if (s.getId() == modId && !s.isDeleted()) {
            cout << "Current Record: " << endl;
            cout << "ID: " << s.getId() << ", First Name: " << s.getFirstName() << ", Last Name: " << s.getLastName() << ", Grade: " << s.getGrade() << endl;

            int id;
            char firstName[50];
            char lastName[50];
            double grade;

            cout << "Enter New ID: ";
            cin >> id;
            cout << "Enter New First Name: ";
            cin >> firstName;
            cout << "Enter New Last Name: ";
            cin >> lastName;
            cout << "Enter New Grade: ";
            cin >> grade;

            s.setData(id, firstName, lastName, grade);

            file.seekp(-sizeof(Student), ios::cur);
            file.write((char*)&s, sizeof(Student));
            found = true;
            break;
        }
    }

    file.close();

    if (found) {
        cout << "Record modified successfully!" << endl;
    } else {
        cout << "Record not found!" << endl;
    }
}

int main() {
    const char* filename = "file.dat";
    int choice;

    while (true) {
        cout << "\n========== Student Management System ==========" << endl;
        cout << "1. Display All Records" << endl;
        cout << "2. Add New Record" << endl;
        cout << "3. Delete Record" << endl;
        cout << "4. Modify Record" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayAllRecords(filename);
                break;
            case 2:
                addRecord(filename);
                break;
            case 3:
                deleteRecord(filename);
                break;
            case 4:
                modifyRecord(filename);
                break;
            case 5:
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
