#include "view.h"
#include <iostream>
using namespace std;

void View :: start(int& choice){
    cout << "Welcome to My Eid Cookies and Cakes Hub" << endl;
    cout << endl;
    cout << "Please enter (1-2):" << endl;
    cout << "1. Staff" << endl;
    cout << "2. Customer" << endl;
    cout << "Your role? ";
    cin >> choice;
}

void View :: accountCheck(int& choice){
    cout << "Login/Signup?" << endl;
    cout << "1. Login" << endl;
    cout << "2. Signup" << endl;
    cout << "3. Back to Choose Role" << endl;
    cout << "Your choice: ";
    cin >> choice;
}