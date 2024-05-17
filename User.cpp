#include <iostream>
#include <fstream>
#include "User.h"
using namespace std;

// Constructor initializes username and password as empty strings
User::User() {
    username = "";
    password = "";
}

Staff::Staff() : User() {}

bool Staff::login(string userN, string pw) {
    fstream staffFile;
    staffFile.open("staff.txt", ios::in);
    string u, p, header;
    getline(staffFile, header);
    //Reading data from the input file stream 'staffFile'
    while (staffFile >> u >> p) {
        //If the u and p data (stored inside file) same with userN and pw which is user's input, it will stored in username and password which in protected access specifier
        if (userN == u && pw == p) {
            username = userN;
            password = pw;
            staffFile.close();
            return true;
        }
    }
    staffFile.close();
    return false;
}

// The signUP method checks if the username is unique and adds the new user to the staff.txt file
bool Staff::signUP(string newUsername, string newPassword) {
    fstream staffFile;
    staffFile.open("staff.txt", ios::in);
    string u, p, header;
    getline(staffFile, header);
    // Check if the new username already exists in the staff.txt file
    while (staffFile >> u >> p) {
        if (newUsername == u) {
            return false; // Username already exists, sign-up failed
        }
    }
    staffFile.close();
    staffFile.open("staff.txt", ios::app);
    // If the username is unique, write the new user's data to the staff.txt file
    staffFile << newUsername << " " << newPassword << endl;
    // Update the username and password for the current Staff object
    username = newUsername;
    password = newPassword;
    staffFile.close();
    return true; // Sign-up successful
}

Customer::Customer() : User() {}

// The login method checks if the given username and password match the stored data in the customer.txt file
bool Customer::login(string userN, string pw) {
    fstream customerFile;
    customerFile.open("customer.txt", ios::in);
    string u, p, header;
    int c;
    getline(customerFile, header);
    // Read data from the customer.txt file
    while (customerFile >> u >> p >> c) {
        // If the username and password match the input, update the username, password, and purchaseCount for the current Customer object
        if (userN == u && pw == p) {
            username = userN;
            password = pw;
            purchaseCount = c;
            customerFile.close();
            return true; // Login successful
        }
    }
    customerFile.close();
    return false; // Login failed
}

// The signUP method checks if the username is unique and adds the new user to the customer.txt file
bool Customer::signUP(string newUsername, string newPassword) {
    fstream customerFile;
    customerFile.open("customer.txt", ios::in);
    string u, p, header;
    int c;
    getline(customerFile, header);
    // Check if the new username already exists in the customer.txt file
    while (customerFile >> u >> p >> c) {
        if (newUsername == u) {
            return false; // Username already exists, sign-up failed
        }
    }
    customerFile.close();
    customerFile.open("customer.txt", ios::app);
    // If the username is unique, write the new user's data to the customer.txt file
    customerFile << newUsername << " " << newPassword << " " << 0 << endl;
    // Update the username, password, and purchaseCount for the current Customer object
    username = newUsername;
    password = newPassword;
    purchaseCount = 0;
    customerFile.close();
    return true; // Sign-up successful
}

// The addPurchaseRecord method updates the purchase count for the current Customer object and writes the updated data to the customer.txt file
void Customer::addPurchaseRecord() {
    // customer made a purchase so purchaseCount +1
    purchaseCount++;
    // Update the purchaseCount to txt file
    fstream customerFile("customer.txt", ios::in | ios::out);
    streampos position = 0;
    string linetochange = username + " " + password + " " + to_string(purchaseCount - 1);
    string newline = username + " " + password + " " + to_string(purchaseCount);
    string line;
    // Skip the header of the file
    getline(customerFile, line);
    // Search for the line in the customer.txt file that matches the linetochange string
    while (true) {
        position = customerFile.tellg();
        while (getline(customerFile, line)) {
            if (line == linetochange) {
                // If the line is found, update the position and write the newline string to the customer.txt file
                customerFile.seekp(position - static_cast<streamoff>(to_string(purchaseCount).length()));
                customerFile << newline;
                customerFile.close();
                return;
            }
            else {
                break;
            }
        }
    }
}
