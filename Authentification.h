#ifndef GAME_AUTHENTIFICATION_H
#define GAME_AUTHENTIFICATION_H

#pragma once
#include <string>
#include "Database.h"
#include "Player.h"

using namespace std;
class Authentification {
    public:
    bool signup(Database& db, const std::string &username, const std::string &password);
    Player* login(Database& db, const std::string &username, const std::string &password);
};


#endif