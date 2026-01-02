#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(int id, const std::string &name, double bal, const std::string &job, double salary)
    : id(id), username(name), balance(bal), job(job), monthly_salary(salary) {}

void Player::addMoney(double amount) {
    balance += amount;
}

void Player::Taxes(double taxRate) {
    balance -= balance*taxRate;
}

void Player::applyMonthlySalary()  {
    balance += monthly_salary;
}

int Player::getId() const {return id;}
const string& Player::getUsername() const {return username;}
double Player::getBalance() const {return balance;}
double Player::getMonthlySalary() const {return monthly_salary;}
