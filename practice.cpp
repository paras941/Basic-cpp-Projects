#include <iostream>
#include <vector>
using namespace std;

// ======== Base class ========
class Account {
protected:
    int accNumber;
    string name;
    double balance;

public:
    Account(int accNo, string custName, double bal)
        : accNumber(accNo), name(custName), balance(bal) {}

    // Virtual function for polymorphism
    virtual void display() {
        cout << "Account Number: " << accNumber << endl;
        cout << "Customer Name: " << name << endl;
        cout << "Balance: " << balance << endl;
    }

    virtual ~Account() {}  // Virtual destructor for cleanup
};

// ======== Derived class: Savings ========
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

// ======== Derived class: Current ========
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

// ======== Main Program ========
int main() {
    // Create a list of Account pointers
    vector<Account*> accounts;

    // Add a SavingsAccount
    accounts.push_back(new SavingsAccount(101, "Alice", 5000, 3.5));

    // Add a CurrentAccount
    accounts.push_back(new CurrentAccount(102, "Bob", 10000, 2000));

    // Add another SavingsAccount
    accounts.push_back(new SavingsAccount(103, "Charlie", 7000, 4.0));

    cout << "\n=== Bank Account Details ===\n";
    for (Account* acc : accounts) {
        acc->display();  // Polymorphic call!
        cout << "----------------------\n";
    }

    // Clean up
    for (Account* acc : accounts) {
        delete acc;
    }

    return 0;
}
