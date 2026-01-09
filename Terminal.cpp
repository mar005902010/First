#include "Terminal.h"
#include "AssetRepository.h"
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

void Terminal::handleMarket() {
    while (true) {
        cout<<"\n====== MARKET ======\n";
        cout<<"Balance: $"<<player->getBalance()<<"\n";

        const auto& assets = market.getAssets();
        for (size_t i = 0; i < assets.size(); ++i) {
            cout<<i<<")"
                << assets[i].name
                <<"| Price: $"<<assets[i].price
                <<"| Volatility: "<<assets[i].volatility
                <<"\n";
        }

        cout<<"\n1) Buy\n";
        cout<<"2) Sell\n";
        cout<<"3) Update Prices\n";
        cout<<"4) Back\n";
        cout<<"Choose: ";

        int choice;
        cin>>choice;

        if (choice == 1) {
            int index;
            double amount;
            cout<<"Asset index: ";cin>>index;
            cout<<"Amount: ";cin>>amount;

            if (market.buy(*player, index, amount)) {
                const auto& asset  = market.getAssets()[index];
                cout<<"Buy succeeded\n";
                AssetRepository::saveAsset(db, player->getId(),asset.name, amount);
                AssetRepository::logTransaction(db, player->getId(),asset.name, amount,asset.price,"BUY");
            }else {
                cout<<"Buy failed\n";
            }
        }else if (choice == 2) {
            int index;
            double amount;
            cout<<"Asset index: ";cin>>index;
            cout<<"Amount: ";cin>>amount;

            if (market.sell(*player, index, amount)) {
                const auto& asset  = market.getAssets()[index];
                cout<<"Sell succeeded\n";
                AssetRepository::saveAsset(db, player->getId(),asset.name, amount);
                AssetRepository::logTransaction(db, player->getId(),asset.name, amount,asset.price,"Sell");

            }else {
                cout<<"Sell failed\n";
            }
        }else if (choice == 3) {
            market.updatePrices();
            cout<<"Market Updated\n";
        }else if (choice == 4) {
            break;
        }else {
            cout<<"Unknown command\n";
        }
    }

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
        }else if (cmd=="balance") {
            cout<<"Balance: "<<player->getBalance()<<"\n";
        }else if (cmd=="job") {
            cout<<"Job: "<<player->getJob()<<"\n";
            cout<<"Salary: $"<<player->getMonthlySalary()<<"\n";
        }else if (cmd=="salary") {
            player->applyMonthlySalary();
            cout<<"Salary is recevied!!\n";
            cout<<"Balance: $"<<player->getBalance()<<"\n";
        }else if (cmd=="market") {
            handleMarket();
        }else if (cmd == "help") {
            showHelp();
        }
        else {
            cout<<"Unknown command\n";
        }
    }
}

