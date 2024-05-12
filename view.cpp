#include "view.h"
#include <iostream>
#include <string>
using namespace std;

bool View :: validateInput(int userInput, int min, int max){
    if(userInput >= min && userInput <= max){
        return false;
    }else{
        cout << endl;
        cout << "ERROR: Input must be from " << min <<  " to " << max << "." << endl;
        cout << endl;
        return true;
    }
}

int View :: mainmenu(){
    int choice;
    do{
        cout << endl;
        cout << "Welcome to My Eid Cookies and Cakes Hub" << endl;
        cout << endl;
        cout << "Please enter (0-2):" << endl;
        cout << "0. Exit" << endl;
        cout << "1. Staff" << endl;
        cout << "2. Customer" << endl;
        cout << "Your choice: ";
        cin >> choice;
    }while(validateInput(choice, 0, 2));
    return choice;
}

int View :: logSignUI(){
    int choice;
    do{
        cout << endl;
        cout << "Login/Signup?" << endl;
        cout << "0. Exit" << endl;
        cout << "1. Login" << endl;
        cout << "2. Signup" << endl;
        cout << "3. Back to Choose Role" << endl;
        cout << "Your choice: ";
        cin >> choice;
    }while(validateInput(choice, 0, 3));
    return choice;
}

int View :: staffMenuDisplay(){
    int choice;
    do{
        cout << endl;
        cout << "Staff" << endl;
        cout << "0. Exit" << endl;
        cout << "1. " << endl;
        cout << "2. " << endl;
        cout << "3. " << endl;
        cout << "Your choice: ";
        cin >> choice;
    }while(validateInput(choice, 0, 3));
    return choice;
}

void View :: loginUI(string &username, string &password){
    cout << endl;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;
}

void View :: signUpUI(string &username, string &password){
    cout << endl;
    cout << "Enter new username: ";
    cin >> username;
    cout << "Enter new password: ";
    cin >> password;
}

void View :: failLogin(){
    cout << endl;
    cout << "Your username or password is incorrect. Please try again." << endl;
}

void View :: failSignUP(){
    cout << endl;
    cout << "Your username has been used. Please try again." << endl;
}

void View :: successLogin(string username){
    cout << endl;
    cout << "Login successfully. Welcome " << username << endl;
}

void View :: successSignUP(string username){
    cout << endl;
    cout << "Sign up successfully. Welcome " << username << endl;
}