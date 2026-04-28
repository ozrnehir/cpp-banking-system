#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <fstream>
#include <unistd.h>

using namespace std;

void displayBanner() {
    cout << "\n";
    cout << "============================================\n";
    cout << "|        BANKING SYSTEM - TERMINAL APP      |\n";
    cout << "|        Developed by Elif Nehir Özer       |\n";
    cout << "|         Object-Oriented in C++            |\n";
    cout << "============================================\n";
    sleep(1);
    cout << "\nWelcome To Your Secure Bank...\n\n";
    cout << "============================================\n";
    sleep(1);
}

class Account {
protected:
    int accountNumber;
    string holderName;
    float balance;

public:
    Account(int accNo, string name, float bal)
        : accountNumber(accNo), holderName(name), balance(bal) {
        }

    virtual void deposit(float amount) {
        if (amount < 0)
            throw invalid_argument("Error: Deposit amount cannot be negative.");
        balance += amount;
    }

    virtual void withdraw(float amount) {
        if (amount > balance)
            throw runtime_error("Error: Insufficient balance.");
        if (amount < 0)
            throw invalid_argument("Error: Cannot withdraw a negative amount.");
        balance -= amount;
    }

    virtual void displayDetails()
    const {
        cout << fixed << setprecision(2);
        cout << "Account Number : " << accountNumber << "\n"
             << "Holder Name    : " << holderName << "\n"
             << "Balance        : " << balance << " EUR\n";
    }

    int getAccountNumber()
    const {
        return accountNumber;
    }
    string getHolderName()
    const {
        return holderName; }
    float getBalance()
    const {
        return balance; }
};

class SavingsAccount :
public Account {
    float interestRate;

public:
    SavingsAccount(int accNo, string name, float bal, float rate)
        : Account(accNo, name, bal), interestRate(rate) {
        }

    void applyInterest() {
        balance += balance * (interestRate / 100);
    }

    void displayDetails()
    const override {
        Account::displayDetails();
        cout << "Interest Rate  : " << interestRate << "%\n";
    }

    float getInterestRate()
    const {
        return interestRate;
    }
};

void showMenu() {
    cout << "Welcome To The Main Menu. Please Choose An Option...";
    cout << "\n=========== Main Menu ===========\n";
    cout << "1. Create a New Bank Account\n";
    cout << "   -> Register a savings account with your details.\n";
    cout << "2. Deposit or Withdraw Funds\n";
    cout << "   -> Manage the balance of an existing account.\n";
    cout << "3. Display All Accounts\n";
    cout << "   -> Review all registered bank accounts.\n";
    cout << "4. Apply Interest to All Accounts\n";
    cout << "   -> Increase balances based on the interest rate.\n";
    cout << "5. Save Accounts to File\n";
    cout << "   -> Save all data to 'accounts.txt'.\n";
    cout << "6. Exit\n";
    cout << "   -> Safely close the system.\n";
    cout << "=================================\n";
    cout << "Choose an option: ";
}

void saveToFile(const vector<SavingsAccount>& accounts) {
    ofstream file("accounts.txt");
    for (const auto& acc : accounts) {
        file << acc.getAccountNumber() << ","
             << acc.getHolderName() << ","
             << acc.getBalance() << ","
             << acc.getInterestRate() << endl;
    }
    file.close();
    cout << "Accounts saved to accounts.txt successfully.\n";
}
SavingsAccount* findAccount(vector<SavingsAccount>& accounts, int accNo) {
    for (auto& acc : accounts) {
        if (acc.getAccountNumber() == accNo)
            return &acc;
    }
    return nullptr;
}

int main() {
    vector<SavingsAccount> accounts;
    bool running = true;
    
    displayBanner();
    
    int choice;
    int nextAccountNumber = 1001;

    do {
        showMenu();
        cin >> choice;
        
        switch (choice) {
            case 1: {
                int accNo = nextAccountNumber++; // otomatik numara
                string name;
                float bal, rate;
                cout << "Enter holder name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter initial balance: ";
                cin >> bal;
                cout << "Enter interest rate: ";
                cin >> rate;
                accounts.emplace_back(accNo, name, bal, rate);
                cout << "Account created successfully! \n";
                cout << "Assigned Account Number: " << accNo <<"\n";
                saveToFile(accounts);
                break;
            }
            case 2: {
                int accNo;
                cout << "Enter your account number: ";
                cin >> accNo;
                SavingsAccount* acc = findAccount(accounts, accNo);
                if (!acc) {
                    cout << " Error: Account not found.\n";
                    break;
                }
                int subChoice;
                cout << "1. Deposit\n2. Withdraw\nEnter your choice: ";
                cin >> subChoice;
                float amount;
                cout << "Enter amount: ";
                cin >> amount;
                try {
                    if (subChoice == 1)
                        acc->deposit(amount);
                    else if (subChoice == 2)
                        acc->withdraw(amount);
                    else
                        cout << "Invalid option.\n";
                } catch (exception& e) {
                    cout << e.what() << '\n';
                }
                break;
            }
            case 3:
                for (const auto& acc : accounts) {
                    acc.displayDetails();
                    cout << "--------------------------\n";
                }
                break;
            case 4:
                for (auto& acc : accounts) {
                    acc.applyInterest();
                }
                cout << "Interest applied to all accounts.\n";
                break;
            case 5: {
                ofstream outFile("accounts.txt");
                for (const auto& acc : accounts) {
                    outFile << acc.getAccountNumber() << "," << acc.getHolderName() << ","
                    << acc.getBalance() << "," << acc.getInterestRate() << endl;
                }
                outFile.close();
                cout << "Accounts saved to file successfully.\n";
                break;
            }
            case 6:
                cout << "Logging out... Thank you for using the system.\n";
                cout << "See you soon...\n";
                running = false;
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (running);
    
    return 0;
}
