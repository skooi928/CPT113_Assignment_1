#ifndef VIEW_H
#define VIEW_H
#include <string>
using namespace std;

class View{
    public:
        // All UI here (including logic reasoning)
        bool validateInput(int, int , int);
        int mainmenu();
        int logSignUI();
        void loginUI(string&, string&);
        void signUpUI(string&, string&);
        void failLogin();
        void failSignUP();
        void successLogin(string);
        void successSignUP(string);
        int staffMenuDisplay();    
        // int customerMenuDisplay();
};

#endif