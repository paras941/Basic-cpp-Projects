// General-Store-Management-System

#include <iostream>
#include <vector>
using namespace std;

// Product class
class Product {
public:
    int id;
    string name;
    int quantity;
    float price;

    void input() {
        cout << "Enter Product ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Product Name: ";
        getline(cin, name);
        cout << "Enter Quantity: ";
        cin >> quantity;
        cout << "Enter Price: ";
        cin >> price;
    }

    void display() const {
        cout << id << "\t" << name << "\t"
             << quantity << "\t" << price << endl;
    }
};

// Store class 
class Store {
    vector<Product> products;

public:
    void addProduct() {
        Product p;
        p.input();
        products.push_back(p);
        cout << "Product added successfully.\n";
    }

    void displayProducts() const {
        if (products.empty()) {
            cout << "No products available.\n";
            return;
        }

        cout << "\nID\tName\tQty\tPrice\n";
        for (const Product& p : products)
            p.display();
    }

    void searchProduct() const {
        int id;
        cout << "Enter Product ID to search: ";
        cin >> id;

        for (const Product& p : products) {
            if (p.id == id) {
                cout << "\nProduct Found:\n";
                cout << "ID\tName\tQty\tPrice\n";
                p.display();
                return;
            }
        }
        cout << "Product not found.\n";
    }

    void sellProduct() {
        int id, qty;
        cout << "Enter Product ID: ";
        cin >> id;
        cout << "Enter Quantity to sell: ";
        cin >> qty;

        for (Product& p : products) {
            if (p.id == id) {
                if (p.quantity >= qty) {
                    p.quantity -= qty;
                    cout << "Product sold successfully.\n";
                } else {
                    cout << "Insufficient stock.\n";
                }
                return;
            }
        }
        cout << "Product not found.\n";
    }
};

int main() {
    Store store;
    int choice;

    do {
        cout << "\n--- General Store Management System ---\n";
        cout << "1. Add Product\n";
        cout << "2. Display Products\n";
        cout << "3. Search Product\n";
        cout << "4. Sell Product\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: store.addProduct(); 
            break;
            case 2: store.displayProducts(); 
            break;
            case 3: store.searchProduct();
             break;
            case 4: store.sellProduct(); 
            break;
            case 5: cout << "Exiting program.\n"; 
            break;
            default: cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}
