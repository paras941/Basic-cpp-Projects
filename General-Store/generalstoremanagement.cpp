#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
using namespace std;

//  Product Class
class Product {
private:
    int id;
    string name;
    int quantity;
    double price;

public:
    Product() {}

    Product(int i, string n, int q, double p) {
        id = i;
        name = n;
        quantity = q;
        price = p;
    }

    int getId() const {return id;}
    int getQuantity() const { return quantity; }
    double getPrice() const { return price; }
    string getName() const { return name; }

    void reduceQuantity(int qty) {
        quantity -= qty;
    }

    void display() const {
        cout << id << "\t" << name << "\t"
             << quantity << "\t" << price << endl;
    }

    string toFileString() const {
        return to_string(id) + "," + name + "," +
               to_string(quantity) + "," + to_string(price);
    }
};

//  Inventory Class 
class Inventory {
private:
    vector<Product> products;

public:
    void loadFromFile() {
        ifstream file("products.txt");
        if (!file) return;

        int id, qty;
        double price;
        string name;

        while (file >> id) {
            file.ignore();
            getline(file, name, ',');
            file >> qty;
            file.ignore();
            file >> price;

            products.emplace_back(id, name, qty, price);
        }
        file.close();
    }

    void saveToFile() {
        ofstream file("products.txt");
        for (const auto& p : products)
            file << p.getId() << "," << p.getName() << ","
                 << p.getQuantity() << "," << p.getPrice() << endl;
        file.close();
    }

    Product* findProduct(int id) {
        for (auto& p : products)
            if (p.getId() == id)
                return &p;
        return nullptr;
    }

    void addProduct() {
        int id, qty;
        double price;
        string name;

        cout << "ID: ";
        cin >> id;

        if (findProduct(id)) {
            cout << "ID already exists.\n";
            return;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Name: ";
        getline(cin, name);

        cout << "Quantity: ";
        cin >> qty;
        cout << "Price: ";
        cin >> price;

        if (qty < 0 || price < 0) {
            cout << "Invalid input.\n";
            return;
        }

        products.emplace_back(id, name, qty, price);
        cout << "Product added.\n";
    }

    void displayProducts() const {
        if (products.empty()) {
            cout << "Inventory empty.\n";
            return;
        }

        cout << "\nID\tName\tQty\tPrice\n";
        for (const auto& p : products)
            p.display();
    }
};


class Billing {
private:
    double totalRevenue;

public:
    Billing() : totalRevenue(0) {}

    void sellProduct(Inventory& inv) {
        int id, qty;
        cout << "Product ID: ";
        cin >> id;

        Product* p = inv.findProduct(id);
        if (!p) {
            cout << "Product not found.\n";
            return;
        }

        cout << "Quantity: ";
        cin >> qty;

        if (qty <= 0 || qty > p->getQuantity()) {
            cout << "Invalid quantity.\n";
            return;
        }

        double amount = qty * p->getPrice();
        p->reduceQuantity(qty);
        totalRevenue += amount;

        cout << "Sold " << qty << " x " << p->getName()
             << " | Amount: " << amount << endl;
    }

    void showRevenue() const {
        cout << "Total Revenue: " << totalRevenue << endl;
    }
};

// Main Function 
  int main() {
    Inventory inventory;
    Billing billing;

    inventory.loadFromFile();

    int choice;
    do {
        cout << "\n--- Smart Inventory & Billing System ---\n";
        cout << "1. Add Product\n";
        cout << "2. Display Inventory\n";
        cout << "3. Sell Product\n";
        cout << "4. View Total Revenue\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: inventory.addProduct(); break;
            case 2: inventory.displayProducts(); break;
            case 3: billing.sellProduct(inventory); break;
            case 4: billing.showRevenue(); break;
            case 5:
                inventory.saveToFile();
                cout << "Data saved. Exiting program.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}
