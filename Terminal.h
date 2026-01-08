

#ifndef GAME_TERMINAL_H
#define GAME_TERMINAL_H
#pragma once
#include "Database.h"
#include "Player.h"
#include "Authentification.h"
#include  "Market.h"

class Terminal {
private:
    Database db;
    Authentification auth;
    Player* player = nullptr;
    Market market;
    bool running = true;

    void showWelcome();
    void showHelp();
    void gameLoop();
    void handleLogIn();
    void handleSignUp();
    void handleMarket();

public:
    void run();
};


#endif //GAME_TERMINAL_H