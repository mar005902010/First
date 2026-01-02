
#include "Authentification.h"
#include "HashedPassword.h"
#include <mysqlx/xdevapi.h>
#include "Database.h"
#include "Player.h"

using namespace mysqlx;

bool Authentification::signup(Database& db, const std::string &username, const std::string &password) {

    auto schema = db.getSchema();
    Table users = schema.getTable("users");

    RowResult check = users.select("id").where("username = :un").bind("un",username).execute();

    if (check.count()>0) return false;

    users.insert("username", "password", "balance","job","monthly_salary").values(username, hash_password(password), 1000.0,"Unemployed",0.0).execute();

    return true;
}

Player* Authentification::login(Database &db, const std::string &username, const std::string &password) {
    auto schema = db.getSchema();
    Table users = schema.getTable("users");

    RowResult res = users.select("id","username","balance", "job","monthly_salary").
        where("username = :un AND password = :pw").bind("un",username).
        bind("pw",hash_password(password)).execute();

    Row row = res.fetchOne();

    if (!row) return nullptr;

    return new Player(row[0].get<int>(),row[1].get<std::string>(),row[2].get<double>(),
        row[3].get<std::string>(),
        row[4].get<double>());

}
