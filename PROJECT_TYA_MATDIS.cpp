#include <iostream>
#include <vector>
#include <string>

using namespace std;

//TAMBAHKAN INI: Definisi struktur Order 
struct Order {
	std::string customerName;
	std::string serviceType;
	int quantity;
	double pricePerItem; // Tambahkan ini
	double totalCost; // Tambahkan ini 
};

vector<Order> orders; // Global  vector to store orders

// Function to add a new order
void addOrder() {
    Order newOrder;
    std::cout << "Enter customer name: ";
    std::cin >> newOrder.customerName;
    std::cout << "Enter service type (Wash/Dry Clean/Iron): ";
    std::cin >> newOrder.serviceType;
    std::cout << "Enter quantity: ";
    std::cin >> newOrder.quantity;
    std::cout << "Enter price per item: ";
    std::cin >> newOrder.pricePerItem;
    
    // Hitung totalcost jika perlu 
    newOrder.totalCost = newOrder.quantity * newOrder.pricePerItem;
   
    orders.push_back(newOrder); // Jangam lupa menambahkan order ke vector 
}

// Function to view all orders
void viewOrders() {
    if (orders.empty()) {
       std::cout << "No orders found." << std::endl;
        return;
    }
    std::cout << "List of orders:" << std::endl;
    for (size_t i = 0; i < orders.size(); i++) {
        std::cout << "Order " << i+ 1 << ":" << std::endl;
        std::cout << "Customer: " << orders[i].customerName << std::endl;
        // Tambahkan output lain jika perlu 
        
    }
}

// Function to calculate total revenue
void calculateRevenue() {
    double totalRevenue = 0.0;
    for (size_t i = 0; i < orders.size(); ++i) {
        totalRevenue += orders[i].totalCost;
    }
    cout << "Total Revenue: $" << totalRevenue << endl;
}

// Main menu function
void displayMenu() {
    cout << "\nLaundry Management System" << endl;
    cout << "1. Add Order" << endl;
    cout << "2. View Orders" << endl;
    cout << "3. Calculate Revenue" << endl;
    cout << "4. Exit" << endl;
    cout << "Choose an option: ";
}

// Main function
int main() {
    int choice;
    do {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                addOrder();
                break;
            case 2:
                viewOrders();
                break;
            case 3:
                calculateRevenue();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 4);
    return 0;
}