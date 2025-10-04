// Bank managemnent

#include <iostream>
#include <vector>
using namespace std;


class Account {
protected:
    int accNumber;
    string name;
    double balance;

public:
    Account(int accNo, string custName, double bal)
        : accNumber(accNo), name(custName), balance(bal) {}

    
    virtual void display() {
        cout << "Account Number: " << accNumber << endl;
        cout << "Customer Name: " << name << endl;
        cout << "Balance: " << balance << endl;
    }

    virtual ~Account() {}  
};

class SavingsAccount : public Account {
    double interestRate;

public:
    SavingsAccount(int accNo, string custName, double bal, double rate)
        : Account(accNo, custName, bal), interestRate(rate) {}

    void display() override {
        cout << "--- Savings Account ---" << endl;
        cout << "Account Number: " << accNumber << endl;
        cout << "Customer Name: " << name << endl;
        cout << "Balance: " << balance << endl;
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

class CurrentAccount : public Account {
    double overdraftLimit;

public:
    CurrentAccount(int accNo, string custName, double bal, double overdraft)
        : Account(accNo, custName, bal), overdraftLimit(overdraft) {}

    void display() override {
        cout << "--- Current Account ---" << endl;
        cout << "Account Number: " << accNumber << endl;
        cout << "Customer Name: " << name << endl;
        cout << "Balance: " << balance << endl;
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }
};

int main() {
    
    vector<Account*> accounts;

   
    accounts.push_back(new SavingsAccount(101, "Alice", 5000, 3.5));

    
    accounts.push_back(new CurrentAccount(102, "Bob", 10000, 2000));

    
    accounts.push_back(new SavingsAccount(103, "Charlie", 7000, 4.0));

    cout << "\n=== Bank Account Details ===\n";
    for (Account* acc : accounts) {
        acc->display();  
        cout << "----------------------\n";
    }

    
    for (Account* acc : accounts) {
        delete acc;
    }

    return 0;
}
