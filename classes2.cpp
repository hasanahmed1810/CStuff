#include <iostream>
using namespace std;

class CashRegister{
private:
    int cashOnHand;
public:
    CashRegister() {
        cashOnHand = 500;
    }

    CashRegister(int cashOnHand) : cashOnHand(cashOnHand) {}

    int getCashOnHand(){
        return cashOnHand;
    }

    void acceptAmount(int amount){
        this->cashOnHand += amount;
    }
};

class DispenserType{
private:
    int numberOfItems;
    int cost;
public:
    DispenserType() {
        cost = 50;
        numberOfItems = 50;
    }

    DispenserType(int numberOfItems, int cost) : numberOfItems(numberOfItems), cost(cost) {}

    int getNumberOfItems(){
        return numberOfItems;
    }

    int getCost(){
        return cost;
    }

    void makeSale(){
        numberOfItems--;
    }
};

void showSelection(){
    cout << "Enter 1 to buy candy\nEnter 2 to buy chips\nEnter 3 to buy gum\nEnter 4 to buy cookie\nEnter 5 to exit\nEnter your choice: " << endl;
}

void sellProduct(DispenserType &dispenserType, CashRegister &cashRegister){
    cout << "The cost of the item is: " << dispenserType.getCost() << endl;
    cout << "Pay the required amount or enter 1 to cancel transaction" << endl;
    int amount;
    cin >> amount;
    while (true){
        if (dispenserType.getCost() == amount){
            cashRegister.acceptAmount(amount);
            dispenserType.makeSale();
            cout << "Releasing Item..." << endl;
            cout << "Item Released" << endl;
            cout << "Transaction complete" << endl;
            cout << endl;
            break;
        }
        if(amount == 1){
            cout << "Cancelling transaction..." << endl;
            cout << endl;
            break;
        }
        cout << "Enter the correct amount" << endl;
        cin >> amount;
    }
}

int main(){
    CashRegister counter;
    DispenserType candy(100, 50);
    DispenserType chips(100, 65);
    DispenserType gum(75, 45);
    DispenserType cookies(50, 85);
    int choice;
    showSelection();
    cin >> choice;
    while (choice != 5){
        switch (choice){
            case 1:
                sellProduct(candy, counter);
                break;
            case 2:
                sellProduct(chips, counter);
                break;
            case 3:
                sellProduct(gum, counter);
                break;
            case 4:
                sellProduct(cookies, counter);
                break;
            default:
                cout << "Invalid selection." << endl;
        }
        showSelection();
        cin >> choice;
    }

    cout << "Exiting the system..." << endl;
    return 0;
}