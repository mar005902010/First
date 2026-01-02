
#pragma once
#include  <string>
#include<array>

class Player {
    private:
        int id;
        std::string username;
        double balance;
        std::string job;
        double monthly_salary;


    public:
        Player(int id,const std::string &name, double bal,const std::string &job, double salary);

        void addMoney(double amount);
        void Taxes(double taxRate);
        void applyMonthlySalary();

        int getId() const;
        const std::string& getUsername() const;
        double getMonthlySalary()const;
        double getBalance() const;


};


