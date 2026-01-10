#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(int id, const std::string &name, double bal, const std::string &job, double salary)
    : id(id), username(name), balance(bal), job(job), monthly_salary(salary) {}

void Player::deposit(double amount) {
    if (amount>0) {
        balance += amount;
    }
}
bool Player::withdraw(double amount) {
    if (amount <= 0 || amount>balance) {
        return false;
    }
    balance -= amount;
    return true;

}

void Player::applyMonthlySalary() {
    balance += monthly_salary;
}

void Player::applyTaxes(double taxRate) {
    if (taxRate > 0 && taxRate < 1) {
        balance -= balance*taxRate;
    }

}

void Player::setJob(const std::string &newJob, double salary) {
    job = newJob;
    monthly_salary = salary;
}

//Assets

void Player::addAsset(const std::string& asset, double quantity) {
    if (quantity<=0) {return;}
    assets[asset]+= quantity;
}

bool Player::hasAsset(const std::string& asset, double quantity) const{
    if (quantity<=0) return false;

    auto it = assets.find(asset);
    if (it ==assets.end()) {
        return false;
    }
    return it->second >= quantity;
}

bool Player::removeAsset(const std::string& asset, double quantity) {
    if (!hasAsset(asset, quantity)) {
        return false;
    }
    assets[asset]-= quantity;
    if (assets[asset]==0) {
        assets.erase(asset);
    }
    return true;
}

int Player::getId() const {return id;}
const string& Player::getUsername() const {return username;}
double Player::getBalance() const {return balance;}
double Player::getMonthlySalary() const {return monthly_salary;}
const string& Player::getJob() const {return job;}
