//
// Created by Marius Karpatiuk on 26.12.2025.
//

#include "Database.h"
using namespace mysqlx;
using namespace std;

Database::Database()
    : session(make_unique<Session>("localhost", 33060, "app_user","app_password")),
    schema(session->getSchema("app_db")){}

Schema& Database::getSchema() {
    return schema;
}

