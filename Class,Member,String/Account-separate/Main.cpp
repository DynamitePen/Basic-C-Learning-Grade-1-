#include<iostream>
#include<string>
#include "Account.h"
using namespace std;
int main(){
    Account account1(50.00);
    cout<<"account1 balance: $"<<account1.getBalance()<<endl;
    cout<<"Enter deposit amount for account1: ";
    double depositAmount;
    cin>>depositAmount;
    cout<<"adding "<<depositAmount<<" to account1 balance"<<endl;
    account1.credit(depositAmount);
    cout<<"account1 balance: $"<<account1.getBalance()<<endl;
    cout<<"Enter debit amount for account1: ";
    double debitAmount;
    cin>>debitAmount;
    cout<<"subtracting "<<debitAmount<<" from account1 balance"<<endl;
    account1.debit(debitAmount);
    cout<<"account1 balance: $"<<account1.getBalance()<<endl;
}