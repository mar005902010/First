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
    player.addAsset(assets[i].name, amount);
    return true;
}

bool Market::sell(Player& player, int i, double amount) {
    if (i<0 || i>=assets.size() || amount<=0) {
        return false;
    }
    /*if (!player.hasAsset(assets[i].name)) {
        return false;
    }*/
    player.removeAsset(assets[i].name, amount);
    player.deposit(amount * assets[i].price);
    return true;
}


void Market::updatePrices() {
    for (auto& a : assets) {
        double change = ((rand()%2000-1000)/1000.0)*a.volatility;
        a.price += a.price * change ;
        if (a.price < 1) {
            a.price = 1;
        }
    }
}
