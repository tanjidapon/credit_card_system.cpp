#include <iostream>
#include <string>
using namespace std;

// Class representing a transaction
class Transaction {
public:
    string type;  // "Purchase" or "Payment"
    double amount;
    Transaction() : type(""), amount(0.0) {}

    Transaction(string t, double amt) : type(t), amount(amt) {}

    void displayTransaction() const {
        if (amount > 0) {
            cout << type << ": $" << amount << endl;
        }
    }
};
// Class representing a credit card
class CreditCard {
private:
    string cardNumber;
    string cardHolder;
    double creditLimit;
    double balance;
    Transaction transactions[100];  // Fixed-size array to store transactions
    int transactionCount;           // To keep track of the number of transactions
public:
    CreditCard(string number, string holder, double limit)
        : cardNumber(number), cardHolder(holder), creditLimit(limit), balance(0.0), transactionCount(0) {}
    void makePurchase(double amount) {
        if (amount <= (creditLimit - balance)) {
            balance += amount;
            if (transactionCount < 100) {
                transactions[transactionCount++] = Transaction("Purchase", amount);
            }
            cout << "Purchase successful! New balance: $" << balance << endl;
        } else {
            cout << "Purchase failed: Not enough credit available!" << endl;
        }
    }
    void makePayment(double amount) {
        if (amount > 0) {
            balance -= amount;
            if (transactionCount < 100) {
                transactions[transactionCount++] = Transaction("Payment", amount);
            }
            cout << "Payment successful! New balance: $" << balance << endl;
        } else {
            cout << "Invalid payment amount!" << endl;}
    }
    void displayBalance() const {
        cout << "Card Holder: " << cardHolder << endl;
        cout << "Card Number: " << cardNumber << endl;
        cout << "Current Balance: $" << balance << endl;
        cout << "Available Credit: $" << (creditLimit - balance) << endl;
    }
    void displayTransactions() const {
        cout << "\n--- Transaction History ---\n";
        if (transactionCount == 0) {
            cout << "No transactions available.\n";
        } else {
            for (int i = 0; i < transactionCount; ++i) {
                transactions[i].displayTransaction();
            }
        }
    }
};
// Main function to test the CreditCard class
int main() {
    // Creating a CreditCard object
    CreditCard myCard("1234-5678-9101-1121", "John Doe", 5000.0);
    int choice;
    double amount;
    do {
        cout << "\n--- Credit Card Management ---\n";
        cout << "1. Make a Purchase\n";
        cout << "2. Make a Payment\n";
        cout << "3. Check Balance\n";
        cout << "4. View Transaction History\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter purchase amount: $";
            cin >> amount;
            myCard.makePurchase(amount);
            break;
        case 2:
            cout << "Enter payment amount: $";
            cin >> amount;
            myCard.makePayment(amount);
            break;
        case 3:
            myCard.displayBalance();
            break;
        case 4:
            myCard.displayTransactions();
            break;
        case 5:
            cout << "Exiting Credit Card Management System. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
