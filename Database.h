#ifndef GAME_DATABASE_H
#define GAME_DATABASE_H

#pragma once
#include <string>
#include <memory>
#include <mysqlx/xdevapi.h>

using namespace std;
using namespace mysqlx;
class Database {
    private:
        unique_ptr<Session> session;
        Schema schema;
    public:
        Database();
        Schema& getSchema();
};


#endif