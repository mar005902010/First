#include "Market.h"
#include "Player.h"
#include <cstdlib>
using namespace std;
Market::Market() {
    assets.push_back({"Bitcoin", 43000, 0.08});
    assets.push_back({"Ethereum", 2300, 0.10});
    assets.push_back({"Solona", 98, 0.20});


}

const vector<Asset>& Market::getAssets() const {
    return assets;
}

bool Market::buy(Player& player, int i, double amount) {
    if (i<0 || i>=assets.size()) {
        return false;
    }
    double cost = amount * assets[i].price;
    if (player.getBalance()<cost) {
        return false;
    }
    player.withdraw(cost);
    player.addAsset
}
