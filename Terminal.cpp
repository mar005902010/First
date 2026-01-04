#include "Terminal.h"
#include <iostream>

using namespace std;

void Terminal::run() {
    while (running) {
        showWelcome();

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: handleSignUp(); break;
            case 2: handleLogIn(); break;
            case 3:
                cout<<"Goodbye"<<endl;
                running = false;
                break;
            default:
                cout<<"Invalid choice"<<endl;
        }
    }
}

void Terminal::showWelcome() {
    cout<<"Welcome"<<endl;
    cout<<"1)Sign up\n";
    cout<<"2)Log in\n";
    cout<<"3)Exit\n";
    cout<<"Enter your choice: ";
}

void Terminal::handleSignUp() {
    std::string username, password;
    cout<<"Enter your username: ";cin>>username;
    cout<<"Enter your password: ";cin>>password;

    if (auth.signup(db, username, password)) {
        cout<<"Account successfully created\n";
    }else {
        cout<<"User already exists\n";
    }

}
void Terminal::handleLogIn() {
    std::string username, password;
    cout<<"Enter your username: ";cin>>username;
    cout<<"Enter your password: ";cin>>password;

    player = auth.login(db, username, password);

    if (!auth.login(db, username, password)) {
        cout<<"Invalid username or password, please try again\n";
        return;
    }

    cout<<"Welcome, "<<player->getUsername()<<"!\n";
    gameLoop();
}
void Terminal::showHelp() {
    cout << "\nAvailable commands:\n";
    cout << " balance  - Show balance\n";
    cout << " job      - Show current job\n";
    cout << " salary   - Receive monthly salary\n";
    cout << " market   - Show market\n";
    cout << " exit     - Logout\n";
}


void Terminal::gameLoop() {
    cin.ignore();

    std::string cmd;
    cout<<"Type help for the commands. \n";

    while (true) {
        cout<<" -> ";
        getline(cin,cmd);

        if (cmd=="exit") {
            cout<<"Logged Out. \n";
            delete player;
            player = nullptr;
            return;
        }else if (cmd == "balance") {
            cout<<"Balance: $"<<player->getBalance()<<"\n";
        }else if (cmd == "job") {
            cout<<"Current job: "<<player->getJob()<<"\n";
            cout<<"Salary: $"<<player->getMonthlySalary()<<"\n";
        }else if (cmd == "salary") {
            player ->applyMonthlySalary();
            cout<<"Salary received\n";
        }else if (cmd == "help") {
            showHelp();
        }
        else {
            cout<<"Unknown command\n";
        }
    }
}

