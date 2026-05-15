#include<string>

class Account{
private:
    double balance;
public:
    Account(double);
    void credit(double);
    void debit(double);
    double getBalance() const;
};