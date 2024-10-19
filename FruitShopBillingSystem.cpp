#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <unordered_map>

using namespace std;

class Item {
public:
    string name;
    double price;
    int quantity;

    Item(string n, double p, int q) : name(n), price(p), quantity(q) {}

    void displayItem() const {
        cout << setw(15) << left << name
             << setw(8) << fixed << setprecision(2) << price
             << setw(10) << quantity << endl;
    }
};

class Cart {
public:
    vector<Item> items;

    void addItem(Item& item, int qty) { // Pass by reference
        if (qty <= item.quantity) {
            items.push_back(Item(item.name, item.price, qty));
            item.quantity -= qty;  // Reduce the available quantity
        } else {
            cout << "Not enough quantity available!" << endl;
        }
    }

    double calculateTotal() {
        double total = 0.0;
        for (const auto& item : items) {
            total += item.price * item.quantity; // Corrected to multiply price and quantity
        }
        return total;
    }

    void displayCart() {
        cout << "Items in Cart:" << endl;
        cout << setw(15) << left << "Name"
             << setw(8) << "Price"
             << setw(10) << "Quantity" << endl;
        for (const auto& item : items) {
            cout << setw(15) << left << item.name
                 << setw(8) << fixed << setprecision(2) << item.price
                 << setw(10) << item.quantity << endl;
        }
        cout << "Total: " << fixed << setprecision(2) << calculateTotal() << endl;
    }
};

class Supermarket {
public:
    vector<Item> inventory;
    unordered_map<string, int> itemMap; // Maps abbreviations to inventory indices

    void addInventoryItem(Item item) {
        inventory.push_back(item);
        // Populate the itemMap with abbreviations
        if (item.name == "Apple")         itemMap["app"] = inventory.size() - 1;
        else if (item.name == "Banana")   itemMap["ban"] = inventory.size() - 1;
        else if (item.name == "Orange")   itemMap["org"] = inventory.size() - 1;
        else if (item.name == "Mango")    itemMap["man"] = inventory.size() - 1;
        else if (item.name == "Grapes")   itemMap["gra"] = inventory.size() - 1;
        else if (item.name == "Pineapple")itemMap["pin"] = inventory.size() - 1;
        else if (item.name == "Strawberry")itemMap["str"] = inventory.size() - 1;
        else if (item.name == "Blueberry") itemMap["blu"] = inventory.size() - 1;
        else if (item.name == "Kiwi")     itemMap["kiw"] = inventory.size() - 1;
        else if (item.name == "Watermelon")itemMap["wat"] = inventory.size() - 1;
        else if (item.name == "Peach")    itemMap["pea"] = inventory.size() - 1;
        else if (item.name == "Plum")     itemMap["plu"] = inventory.size() - 1;
        else if (item.name == "Cherry")   itemMap["cher"] = inventory.size() - 1;
        else if (item.name == "Lemon")    itemMap["lem"] = inventory.size() - 1;
        else if (item.name == "Apricot")  itemMap["apr"] = inventory.size() - 1;
        else if (item.name == "Papaya")   itemMap["pap"] = inventory.size() - 1;
    }

    void displayInventory() {
        cout << "Available Items:" << endl;
        cout << setw(15) << left << "Name"
             << setw(8) << "Price"
             << setw(10) << "Quantity" << endl;
        for (const auto& item : inventory) {
            item.displayItem(); // Now works correctly
        }
    }

    void processTransaction() {
        Cart cart;
        string choice;
        int qty;
        while (true) {
            displayInventory();
            cout << "Enter the item abbreviation to add to cart (type 'exit' to finish): ";
            cin >> choice;
            if (choice == "exit") break;

            // Check if the abbreviation is valid
            if (itemMap.find(choice) == itemMap.end()) {
                cout << "Invalid item abbreviation! Please try again." << endl;
                continue;
            }

            cout << "Enter quantity: ";
            cin >> qty;

            // Add item to cart based on the abbreviation
            cart.addItem(inventory[itemMap[choice]], qty);
        }
        cart.displayCart();
    }
};

int main() {
    Supermarket supermarket;

    // Adding a variety of fruits with prices and quantities
    supermarket.addInventoryItem(Item("Apple", 0.50, 100));
    supermarket.addInventoryItem(Item("Banana", 0.30, 150));
    supermarket.addInventoryItem(Item("Orange", 0.80, 80));
    supermarket.addInventoryItem(Item("Mango", 1.00, 60));
    supermarket.addInventoryItem(Item("Grapes", 2.50, 40));
    supermarket.addInventoryItem(Item("Pineapple", 3.00, 30));
    supermarket.addInventoryItem(Item("Strawberry", 4.00, 25));
    supermarket.addInventoryItem(Item("Blueberry", 5.00, 20));
    supermarket.addInventoryItem(Item("Kiwi", 1.50, 50));
    supermarket.addInventoryItem(Item("Watermelon", 0.70, 15));
    supermarket.addInventoryItem(Item("Peach", 1.20, 35));
    supermarket.addInventoryItem(Item("Plum", 1.00, 45));
    supermarket.addInventoryItem(Item("Cherry", 3.50, 10));
    supermarket.addInventoryItem(Item("Lemon", 0.40, 70));
    supermarket.addInventoryItem(Item("Apricot", 2.00, 30));
    supermarket.addInventoryItem(Item("Papaya", 1.80, 25));

    supermarket.processTransaction();

    return 0;
}
