
#ifndef GAME_MARKET_H
#define GAME_MARKET_H
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Player;

struct Asset {
  std::string name;
  double price;
  double volatility;
};

class Market {
private:
  vector<Asset> assets;
  public:
  Market();

  const vector<Asset>& getAssets() const;
  bool buy(Player& player, int assetIndex, double amount);
  bool sell(Player& player, int  assetIndex, double amount);

  void updatePrices();
};


#endif //GAME_MARKET_H