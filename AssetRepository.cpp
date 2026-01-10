#include "AssetRepository.h"
#include "Player.h"

void AssetRepository::saveAsset(Database &db, int playerID, const std::string &asset, double quantity) {
    auto table = db.getSchema().getTable("player_assets");

    RowResult res = table.select("quantity").where("id = :pi AND asset = :a")
    .bind("pi", playerID).bind("a", asset).execute();

    Row row = res.fetchOne();

    if (row) {
        double current = row[0].get<double>();
        double newQty = current + quantity;

        if (newQty <= 0) {
            table.remove().where("id = :pi AND asset = :a").bind("pi", playerID)
            .bind("a", asset).execute();
        }else {
            table.update().set("quantity", newQty).where("id = :pi AND asset = :a").bind("pi", playerID)
            .bind("a", asset).execute();
        }
    }else {
        table.insert("id", "asset", "quantity").values(playerID, asset, quantity).execute();
    }
}

void AssetRepository::logTransaction(Database &db, int playerID, const std::string &asset, double quantity, double price, const std::string &type) {
    auto table = db.getSchema().getTable("transaction");

    table.insert("player_id", "asset", "quantity","price", "type").values(playerID, asset, quantity, price, type).execute();
}
