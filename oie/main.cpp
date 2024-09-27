#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <iomanip>
#include <ctime>
using namespace std;

struct Bread {
    string name;
    time_t expiryDate;

    bool operator<(const Bread& other) const {
        return expiryDate > other.expiryDate; 
    }
};

class BreadInventory {
private:
    priority_queue<Bread> shelf;

public:
    void addBread(const string& bread, const time_t& expiryDate) {
        Bread newBread = {bread, expiryDate};
        shelf.push(newBread);
    }

    void removeOldestBread() {
        if (!shelf.empty()) {
            shelf.pop();
        } else {
            cout << "No bread to remove!" << endl;
        }
    }

    void buyBread() {
        if (!shelf.empty()) {
            cout << shelf.top().name << " has been bought and removed from the inventory." << endl;
            shelf.pop();
        } else {
            cout << "No bread available to buy." << endl;
        }
    }

    void displayInventory(bool showExpiry = true) const {
        cout << "Current Bread Inventory:\n";
        cout << "+----------------------+\n";
        cout << "|       Bread          |\n";
        cout << "+----------------------+\n";
        auto tempShelf = shelf;
        while (!tempShelf.empty()) {
            const auto& bread = tempShelf.top();
            cout << "| " << setw(20) << left << bread.name;
            if (showExpiry) {
                cout << " | " << put_time(localtime(&bread.expiryDate), "%Y-%m-%d");
            }
            cout << " |\n";
            tempShelf.pop();
        }
        cout << "+----------------------+\n";
    }
};

void adminMenu(BreadInventory& inventory) {
    int choice;
    string bread;
    string expiryDateStr;
    struct tm tm;

    do {
        cout << "\nAdmin Menu\n";
        cout << "1. Add Bread\n";
        cout << "2. Remove Oldest Bread\n";
        cout << "3. Display Inventory\n";
        cout << "4. Exit to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;



        switch (choice) {
            case 1:
                cout << "Enter the name of the bread to add: ";
                cin >> bread;
                cout << "Enter the expiry date (YYYY-MM-DD): ";
                cin >> expiryDateStr;
                strptime(expiryDateStr.c_str(), "%Y-%m-%d", &tm);
                inventory.addBread(bread, mktime(&tm));
                break;
            case 2:
                inventory.removeOldestBread();
                break;
            case 3:
                inventory.displayInventory();
                break;
            case 4:
                cout << "Exiting to Main Menu...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);
}

void customerMenu(BreadInventory& inventory) {
    int choice;

    do {
        cout << "\nCustomer Menu\n";
        cout << "1. Buy Bread\n";
        cout << "2. Display Inventory\n";
        cout << "3. Exit to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Invalid choice. Please try again.\n";
            continue;
        }

        switch (choice) {
            case 1:
                inventory.buyBread();
                break;
            case 2:
                inventory.displayInventory(false);
                break;
            case 3:
                cout << "Exiting to Main Menu...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);
}

int main() {
    BreadInventory inventory;

    struct tm tm = {};
    strptime("2022-10-01", "%Y-%m-%d", &tm);
inventory.addBread("bread1", mktime(&tm));
  strptime("2022-10-02", "%Y-%m-%d", &tm);
    inventory.addBread("bread2", mktime(&tm));
     strptime("2019-10-03", "%Y-%m-%d", &tm);
    inventory.addBread("bread3", mktime(&tm));
    strptime("2019-10-04", "%Y-%m-%d", &tm);
    inventory.addBread("bread4", mktime(&tm));
    strptime("2023-10-05", "%Y-%m-%d", &tm);
    inventory.addBread("bread5", mktime(&tm));
    strptime("2023-10-06", "%Y-%m-%d", &tm);
    inventory.addBread("bread6", mktime(&tm));
    strptime("2023-10-07", "%Y-%m-%d", &tm);
    inventory.addBread("bread7", mktime(&tm));
    strptime("2023-10-08", "%Y-%m-%d", &tm);
    inventory.addBread("bread8", mktime(&tm));
    strptime("2023-10-09", "%Y-%m-%d", &tm);
    inventory.addBread("bread9", mktime(&tm));
    strptime("2023-10-10", "%Y-%m-%d", &tm);
    inventory.addBread("bread10", mktime(&tm));

    int choice;
    string passkey;

    do {
        cout << "\nBread Inventory Management System\n";
        cout << "1. Admin Menu\n";
        cout << "2. Customer Menu\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Invalid choice. Please try again.\n";
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter admin passkey: ";
                cin >> passkey;
                if (passkey == "12345") {
                    adminMenu(inventory);
                } else {
                    cout << "Invalid passkey. Access denied.\n";
                }
                break;
            case 2:
                customerMenu(inventory);
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}