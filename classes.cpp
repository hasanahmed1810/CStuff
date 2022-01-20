
#include <iostream>
using namespace std;

class BankAccount{
private:
    string customer_name;
    int account_number;
public:
    BankAccount(string customerName, int accountNumber) : customer_name(customerName),account_number(accountNumber){}
};

class CurrentAccount : BankAccount{
private:
    double balance;
public:
    CurrentAccount(string customerName, int accountNumber, double balance) : BankAccount(customerName, accountNumber), balance(balance) {}

    double getBalance(){
        return balance;
    }

    void setBalance(double balance) {
        this->balance = balance;
    }

    void deposit(double amount){
        setBalance(getBalance() + amount);
        cout << "Your current account balance after the deposit is: " << getBalance() << endl;
    }

    void withdraw(double amount){
        setBalance(getBalance() - amount);
        cout << "Your current account balance after the withdrawal is: " << getBalance() << endl;
    }
};

class SavingsAccount : BankAccount{
private:
    double balance;
public:
    SavingsAccount(const string &customerName, int accountNumber, double balance) : BankAccount(customerName,accountNumber),balance(balance) {}

    double getBalance(){
        return balance;
    }

    void setBalance(double balance) {
        this->balance = balance;
    }

    void deposit(double amount){
        setBalance(getBalance() + amount);
        cout << "Your savings account balance after the deposit is: " << getBalance() << endl;
    }

    void withdraw(double amount){
        setBalance(getBalance() - amount);
        cout << "Your savings account balance after the withdrawal is: " << getBalance() << endl;
    }
};

int main(){
    CurrentAccount currentAccount("Hasan", 568484, 50000);
    currentAccount.deposit(10000);
    currentAccount.withdraw(20000);

    SavingsAccount savingsAccount("Ahmed",548164, 20000);
    savingsAccount.deposit(10000);
    savingsAccount.withdraw(20000);

    return 0;
}
