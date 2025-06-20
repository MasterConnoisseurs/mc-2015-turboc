#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <conio.h>
#include <ctime>
using namespace std;

const string usbPath = "E:\\";  // Change to your actual USB drive
const string accountFile = usbPath + "account.dat";
const string logFile = usbPath + "receipt.txt";

struct Account {
    string username;
    string pin;
    float balance;
};

bool fileExists(const string& path) {
    ifstream file(path.c_str());
    return file.good();
}

vector<Account> loadAccounts() {
    vector<Account> accounts;
    ifstream file(accountFile.c_str());
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string user, pin, balStr;
        getline(ss, user, ',');
        getline(ss, pin, ',');
        getline(ss, balStr, ',');
        accounts.push_back({ user, pin, stof(balStr) });
    }

    return accounts;
}

void saveAccounts(const vector<Account>& accounts) {
    ofstream file(accountFile.c_str());
    for (const auto& acc : accounts) {
        file << acc.username << "," << acc.pin << "," << fixed << setprecision(2) << acc.balance << endl;
    }
}

int findAccountIndex(const vector<Account>& accounts, const string& user) {
    for (int i = 0; i < accounts.size(); ++i) {
        if (accounts[i].username == user)
            return i;
    }
    return -1;
}

string inputMaskedPIN() {
    string pin = "";
    char ch;
    while ((ch = getch()) != '\r') {
        if (ch == '\b' && !pin.empty()) {
            cout << "\b \b";
            pin.pop_back();
        } else if (isdigit(ch)) {
            cout << "*";
            pin += ch;
        }
    }
    cout << endl;
    return pin;
}

string getTimestamp() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    char buffer[50];
    sprintf(buffer, "%02d/%02d/%d %02d:%02d:%02d",
        ltm->tm_mday, ltm->tm_mon + 1, 1900 + ltm->tm_year,
        ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
    return string(buffer);
}

void logTransaction(const string& username, const string& action, float amount, float balance) {
    ofstream log(logFile.c_str(), ios::app);
    log << "[" << getTimestamp() << "] "
        << "[" << username << "] "
        << action << ": ₱" << fixed << setprecision(2) << amount
        << " | New Balance: ₱" << balance << endl;
}

void atmMenu(Account& acc, vector<Account>& accounts) {
    int choice;
    float amount;
    char again;

    do {
        system("cls");
        cout << "\n==============================\n";
        cout << "     WELCOME, " << acc.username << "\n";
        cout << "==============================\n";
        cout << "1. View Balance\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Change PIN\n";
        cout << "5. Exit\n";
        cout << "==============================\n";
        cout << "Select option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nBalance: ₱" << fixed << setprecision(2) << acc.balance << endl;
                logTransaction(acc.username, "View Balance", 0, acc.balance);
                break;
            case 2:
                cout << "Enter deposit amount: ₱";
                cin >> amount;
                if (amount > 0) {
                    acc.balance += amount;
                    saveAccounts(accounts);
                    logTransaction(acc.username, "Deposit", amount, acc.balance);
                    cout << "Deposit successful.\n";
                }
                break;
            case 3:
                cout << "Enter withdraw amount: ₱";
                cin >> amount;
                if (amount <= acc.balance && amount > 0) {
                    acc.balance -= amount;
                    saveAccounts(accounts);
                    logTransaction(acc.username, "Withdraw", amount, acc.balance);
                    cout << "Withdrawal successful.\n";
                } else {
                    cout << "Insufficient funds or invalid amount.\n";
                }
                break;
            case 4: {
                cout << "Enter new PIN: ";
                string newPin = inputMaskedPIN();
                acc.pin = newPin;
                saveAccounts(accounts);
                logTransaction(acc.username, "Changed PIN", 0, acc.balance);
                cout << "PIN changed successfully.\n";
                break;
            }
            case 5:
                return;
            default:
                cout << "Invalid choice.\n";
        }

        cout << "\nAnother transaction? (Y/N): ";
        cin >> again;
        again = toupper(again);
    } while (again == 'Y');
}

int main() {
    if (!fileExists(accountFile)) {
        cout << "Account file not found on USB.\n";
        return 1;
    }

    vector<Account> accounts = loadAccounts();
    string username;
    string enteredPIN;
    int index = -1;

    cout << "Enter username: ";
    cin >> username;

    index = findAccountIndex(accounts, username);
    if (index == -1) {
        cout << "Account not found.\n";
        return 1;
    }

    int attempts = 0;
    while (attempts < 3) {
        cout << "Enter PIN: ";
        enteredPIN = inputMaskedPIN();

        if (enteredPIN == accounts[index].pin) {
            atmMenu(accounts[index], accounts);
            break;
        } else {
            attempts++;
            cout << "Incorrect PIN. Attempt " << attempts << "/3\n";
        }
    }

    if (attempts == 3) {
        cout << "Too many incorrect attempts. Access denied.\n";
    }

    cout << "\nThank you for using the ATM.\n";
    return 0;
}
