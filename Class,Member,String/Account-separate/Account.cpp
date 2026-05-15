#include<iostream>
#include<string>
#include "Account.h"
using namespace std;
Account::Account(double initialBalance=0.0){
    if (initialBalance<0.0){
        balance=0.0;
        cerr<<"Initial balance was invalid."<<endl;
    }
    else balance=initialBalance;
}
void Account::credit(double amount){
    balance+=amount;
}
void Account::debit(double amount){
    if (amount>balance) cerr<<"Debit amount exceeded account balance."<<endl;
    else balance-=amount;
}
double Account::getBalance() const{
    return balance;
}