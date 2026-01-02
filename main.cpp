#include "Authentification.h"
#include "Jobs.h"
#include "Database.h"
#include <iostream>

using namespace std;
using namespace mysqlx;




int main() {
    Database db;
    Authentification auth;
    std::string choice, username, password;



    bool running = true;
    bool sign = true;

    while (running) {
        while (sign) {
            cout<<"1) Sign Up\n2) Log In\n3) Exit\n";
            cout<<"Choice: ";cin>>choice;
            if (choice == "1") {
                cout<<"Enter username: ";cin>>username;
                cout<<"Enter password: ";cin>>password;
                if (auth.signup(db, username, password)) {
                    cout<<"Sign Up succesfully"<<endl;
                    job(db, username);
                }else {
                    cout<<"Sign Up failed"<<endl;
                }

            }else if (choice == "2") {
                cout<<"Enter username: ";cin>>username;
                cout<<"Enter password: ";cin>>password;
                if (auth.login(db, username, password)) {
                    cout<<"Log In successfully"<<endl;
                    job(db, username);
                }else {
                    cout<<"Log In failed"<<endl;
                }

            }else if (choice == "3") {
                sign = false;
                running = false;
            }
        }
    }
}