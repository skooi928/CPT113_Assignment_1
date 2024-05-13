#include <iostream>
#include <fstream>
#include "user.h"
#include "pastry.h"
#include "shop.h"
#include "cart.h"
#include "view.h"
using namespace std;

User :: User(){
    username = "";
    password = "";
}

Staff :: Staff() : User(){}

bool Staff :: login(string userN, string pw){
    fstream staffFile;
    staffFile.open("staff.txt", ios::in);
    string u, p;
    while(staffFile >> u >> p){
        if(userN == u && pw == p){
            username = userN;
            password = pw;
            staffFile.close();
            return true;
        }
    }
    staffFile.close();
    return false;
}

bool Staff :: signUP(string newUsername, string newPassword){
    fstream staffFile;
    staffFile.open("staff.txt", ios::in);
    string u, p;
    while(staffFile >> u >> p){
        if(newUsername == u){
            return false;
        }
    }
    staffFile.close();
    staffFile.open("staff.txt", ios::app);
    // Writing the data to respective .txt file
    staffFile << newUsername << " " << newPassword << endl;
    username = newUsername;
    password = newPassword;
    staffFile.close();
    return true;
}

Customer :: Customer() : User(){}

bool Customer :: login(string userN, string pw){
    fstream customerFile;
    customerFile.open("customer.txt", ios::in);
    string u, p;
    int c;
    while(customerFile >> u >> p >> c){
        if(userN == u && pw == p){
            username = userN;
            password = pw;
            purchaseCount = c;
            customerFile.close();
            return true;
        }
    }
    customerFile.close();
    return false;
}

bool Customer :: signUP(string newUsername, string newPassword){
    fstream customerFile;
    customerFile.open("customer.txt", ios::in);
    string u, p;
    int c;
    while(customerFile >> u >> p >> c){
        if(newUsername == u){
            return false;
        }
    }
    customerFile.close();
    customerFile.open("customer.txt", ios::app);
    // Writing the data to respective .txt file
    customerFile << newUsername << " " << newPassword << " " << 0 << endl;
    username = newUsername;
    password = newPassword;
    purchaseCount = 0;
    customerFile.close();
    return true;
}

void Customer :: addPurchaseRecord(){
    purchaseCount++;
    fstream customerFile("customer.txt", ios::in | ios::out);
    streampos position = 0;
    string linetochange = username + " " + password + " " + to_string(purchaseCount-1);
    string newline = username + " " + password + " " + to_string(purchaseCount);
    string line;
    while(true){
        position = customerFile.tellg();
        while(getline(customerFile, line)){
            if(line == linetochange){
                customerFile.seekp(position - static_cast<streamoff>(to_string(purchaseCount).length()));
                cout << "DEBUG: Line added: " << newline << endl;
                customerFile << newline;
                customerFile.close();
                return;
            }else{
                break;
            }
        }
    }
}