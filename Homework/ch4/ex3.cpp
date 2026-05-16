#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Account {
public:
    Account(double balance) : balance(balance) {}
    virtual ~Account() {}

    virtual void credit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    virtual bool debit(double amount) {
        if (amount > balance) {
            cout << "Debit amount exceeded account balance.\n";
            return false;
        }
        if (amount > 0) {
            balance -= amount;
            return true;
        }
        return false;
    }

    double getBalance() const {
        return balance;
    }

    virtual string getType() const = 0;

protected:
    double balance;
};

class SavingsAccount : public Account {
public:
    SavingsAccount(double balance, double interestRate)
        : Account(balance), interestRate(interestRate) {}

    double calculateInterest() const {
        return balance * interestRate;
    }

    string getType() const override {
        return "SavingsAccount";
    }

private:
    double interestRate;
};

class CheckingAccount : public Account {
public:
    CheckingAccount(double balance, double fee)
        : Account(balance), transactionFee(fee) {}

    void credit(double amount) override {
        if (amount > 0) {
            balance += amount;
            balance -= transactionFee;
        }
    }

    bool debit(double amount) override {
        double total = amount + transactionFee;
        if (total > balance) {
            cout << "Debit amount plus transaction fee exceeded account balance.\n";
            return false;
        }
        if (amount > 0) {
            balance -= total;
            return true;
        }
        return false;
    }

    string getType() const override {
        return "CheckingAccount";
    }

private:
    double transactionFee;
};

int main() {
    Account* accounts[] = {
        new SavingsAccount(1000.0, 0.03),
        new CheckingAccount(1000.0, 1.50),
        new SavingsAccount(500.0, 0.04),
        new CheckingAccount(200.0, 1.00)
    };
    int n = sizeof(accounts) / sizeof(accounts[0]);

    cout << fixed << setprecision(2);

    for (int i = 0; i < n; ++i) {
        Account* acct = accounts[i];
        cout << "Account " << (i + 1) << " (" << acct->getType() << ")\n";
        cout << "Current balance: $" << acct->getBalance() << "\n";

        double withdrawAmount;
        cout << "Enter debit amount: ";
        cin >> withdrawAmount;
        acct->debit(withdrawAmount);
        cout << "Balance after debit: $" << acct->getBalance() << "\n";

        double depositAmount;
        cout << "Enter credit amount: ";
        cin >> depositAmount;
        acct->credit(depositAmount);
        cout << "Balance after credit: $" << acct->getBalance() << "\n";

        SavingsAccount* savings = dynamic_cast<SavingsAccount*>(acct);
        if (savings != nullptr) {
            double interest = savings->calculateInterest();
            savings->credit(interest);
            cout << "Interest added: $" << interest << "\n";
            cout << "Balance after interest: $" << savings->getBalance() << "\n";
        }

        cout << "Updated balance: $" << acct->getBalance() << "\n\n";
    }

    for (int i = 0; i < n; ++i) {
        delete accounts[i];
    }
    return 0;
}
