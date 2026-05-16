#include <iostream>
#include <string>
#include <ctime>
using namespace std;
class Date {
public:
    Date(int m = 1, int d = 1, int y = 1900)
        : month(m), day(d), year(y) {}
    int getMonth() const { return month; }
    int getDay() const { return day; }
    int getYear() const { return year; }
    void print() const { cout << month << "/" << day << "/" << year; }
private:
    int month;
    int day;
    int year;
};
class Employee {
public:
    Employee(const string& first, const string& last, const string& ssn, const Date& birth)
        : first(first), last(last), ssn(ssn), birth(birth) {}

    virtual ~Employee() {}
    Date getBirthDate() const { return birth; }
    string getFirst() const { return first; }
    string getLast() const { return last; }
    string getSSN() const { return ssn; }
    virtual double earnings() const = 0;
    virtual void printExtra() const {}

protected:
    string first;
    string last;
    string ssn;
    Date birth;
};
class Salaried : public Employee {
public:
    Salaried(const string& first, const string& last, const string& ssn,
             const Date& birth, double salary)
        : Employee(first, last, ssn, birth), salary(salary) {}

    double earnings() const override { return salary; }
    double getSalary() const { return salary; }
    void printExtra() const override {
        cout << "salaried employee:\n"
             << "weekly salary: " << salary << "\n";
    }

private:
    double salary;
};
class Hourly : public Employee {
public:
    Hourly(const string& first, const string& last, const string& ssn,
           const Date& birth, double wage, double hours)
        : Employee(first, last, ssn, birth), wage(wage), hours(hours) {}

    double earnings() const override {
        if (hours <= 40)
            return wage * hours;
        else
            return 40 * wage + (hours - 40) * wage * 1.5;
    }
    double getWage() const { return wage; }
    double getHours() const { return hours; }
    void printExtra() const override {
        cout << "hourly employee:\n"
             << "hourly wage: " << wage << "\n"
             << "hours worked: " << hours << "\n";
    }

private:
    double wage;
    double hours;
};
class Commission : public Employee {
public:
    Commission(const string& first, const string& last, const string& ssn,
               const Date& birth, double sales, double rate)
        : Employee(first, last, ssn, birth), sales(sales), rate(rate) {}

    double earnings() const override { return sales * rate; }
    double getSales() const { return sales; }
    double getRate() const { return rate; }
    void printExtra() const override {
        cout << "commission employee:\n"
             << "gross sales: " << sales << "\n"
             << "commission rate: " << rate << "\n";
    }

protected:
    double sales;
    double rate;
};
class BaseCommission : public Commission {
public:
    BaseCommission(const string& first, const string& last, const string& ssn,
                   const Date& birth, double sales, double rate, double base)
        : Commission(first, last, ssn, birth, sales, rate), base(base) {}

    double earnings() const override { return base + Commission::earnings(); }
    double getBase() const { return base; }
    void printExtra() const override {
        cout << "base-salaried commission employee:\n"
             << "gross sales: " << sales << "\n"
             << "commission rate: " << rate << "\n"
             << "base salary: " << base << "\n";
    }

private:
    double base;
};

int main() {
    Salaried s1("John", "Smith", "111-11-1111", Date(6, 15, 1980), 800.0);
    Hourly h1("Karen", "Price", "222-22-2222", Date(7, 29, 1975), 16.75, 40);
    Commission c1("Sue", "Jones", "333-33-3333", Date(6, 5, 1981), 10000, 0.06);
    BaseCommission b1("Bob", "Lewis", "444-44-4444", Date(9, 8, 1979), 5000, 0.04, 300);

    Employee* emps[] = { &s1, &h1, &c1, &b1 };
    int n = sizeof(emps) / sizeof(emps[0]);

    time_t now = time(nullptr);
    int curMonth = localtime(&now)->tm_mon + 1;

    cout << "Current month: " << curMonth << "\n\n";

    for (int i = 0; i < n; ++i) {
        Employee* p = emps[i];
        cout << p->getFirst() << " " << p->getLast() << "\n"
             << "social security number: " << p->getSSN() << "\n"
             << "birth date: ";
        p->getBirthDate().print();
        cout << "\n";

        p->printExtra();

        double pay = p->earnings();
        if (p->getBirthDate().getMonth() == curMonth) {
            pay += 100.0;
            cout << "Happy birthday! $100.00 bonus added.\n";
        }
        cout << "earned: $" << pay << "\n\n";
    }

    return 0;
}
