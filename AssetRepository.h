#ifndef GAME_ASSETREPOSITORY_H
#define GAME_ASSETREPOSITORY_H
#include "Database.h"

class AssetRepository {
public:
    static void saveAsset(Database& db, int playerID, const std::string& asset, double quantity);
    static void logTransaction(Database& db, int playerID, const std::string& asset, double quantity, double price, const std::string& type);

};


#endif //GAME_ASSETREPOSITORY_H