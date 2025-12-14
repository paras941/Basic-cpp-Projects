#include <iostream>
#include <vector>

// Define max length for C-style strings
#define MAX_NAME_LEN 30
#define MAX_ID_LEN 7

class Product {
private:
    char productID[MAX_ID_LEN];
    char name[MAX_NAME_LEN];
    double price;
    int quantityInStock;

public:
    // Manual strcpy needed for C-style strings
    Product(const char* id, const char* n, double p, int q)
        : price(p), quantityInStock(q) {
        strncpy(productID, id, MAX_ID_LEN - 1); productID[MAX_ID_LEN - 1] = '\0';
        strncpy(name, n, MAX_NAME_LEN - 1); name[MAX_NAME_LEN - 1] = '\0';
    }

    const char* getID() const { return productID; }
    const char* getName() const { return name; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantityInStock; }

    void addStock(int count) { 
        if (count > 0) quantityInStock += count; 
    }
    
    bool sellStock(int count) {
        if (count > 0 && quantityInStock >= count) {
            quantityInStock -= count;
            return true;
        }
        return false;
    }

    void displayDetails() const {
        // Manual formatting (no iomanip)
        std::cout << "| ID: " << productID 
                  << "| Name: " << name 
                  << "| Price: $" << price 
                  << "| Stock: " << quantityInStock 
                  << " |" << std::endl;
    }
};

class InventoryManager {
private:
    std::vector<Product> inventoryList;

    
    Product* searchProduct(const char* id) {
        for (size_t i = 0; i < inventoryList.size(); ++i) {
          
            if (strcmp(inventoryList[i].getID(), id) == 0) {
                return &inventoryList[i];
            }
        }
        return nullptr;
    }

public:
    void addOrUpdateProduct(const Product& newProduct) {
        Product* existingProduct = searchProduct(newProduct.getID());
        
        if (existingProduct) {
            existingProduct->addStock(newProduct.getQuantity());
            std::cout << "\n✅ Stock updated for " << newProduct.getName() << ".\n";
        } else {
            inventoryList.push_back(newProduct);
            std::cout << "\n✅ New product added: " << newProduct.getName() << ".\n";
        }
    }

    bool executeSale(const char* id, int count) {
        Product* p = searchProduct(id);
        if (p == nullptr) {
            std::cout << "\n❌ Error: Product ID not found.\n";
            return false;
        }

        if (p->sellStock(count)) {
            std::cout << "\n✅ Sale successful! Sold " << count << " units of " << p->getName() << ".\n";
            return true;
        } else {
            std::cout << "\n⚠️ Insufficient stock. Available: " << p->getQuantity() << ".\n";
            return false;
        }
    }

    void displayAllInventory() const {
        if (inventoryList.empty()) {
            std::cout << "\n--- Inventory is Empty ---\n";
            return;
        }
        std::cout << "\n--- Current Store Inventory (" << inventoryList.size() << " items) ---\n";
        std::cout << "------------------------------------------------------------------\n";
        
        for (const auto& p : inventoryList) {
            p.displayDetails();
        }
        std::cout << "------------------------------------------------------------------\n";
    }
    
    // Note: Low Stock Report (sorting) is omitted as std::algorithm is disallowed.
};

// Need cstring for strcmp and strncpy
#include <cstring>

int main() {
    InventoryManager storeInventory;

    storeInventory.addOrUpdateProduct(Product("A001", "Milk", 3.50, 50));
    storeInventory.addOrUpdateProduct(Product("B042", "Bread", 2.10, 30));
    storeInventory.addOrUpdateProduct(Product("C100", "Sugar", 1.99, 10));

    int menuChoice;
    char inputID[MAX_ID_LEN];
    int qty;

    do {
        std::cout << "\n\n--- Store Menu ---\n";
        std::cout << "1. Display Inventory\n";
        std::cout << "2. Process Sale\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter choice: ";
        
        if (!(std::cin >> menuChoice)) {
            std::cout << "Invalid input. Try again.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        switch (menuChoice) {
            case 1:
                storeInventory.displayAllInventory();
                break;
                
            case 2:
                std::cout << "Enter Product ID: "; std::cin >> inputID;
                std::cout << "Enter Quantity to sell: "; std::cin >> qty;
                storeInventory.executeSale(inputID, qty);
                break;
            
            case 3:
                std::cout << "\nExiting System. Goodbye!\n";
                break;

            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (menuChoice != 3);

    return 0;
}