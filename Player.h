
#pragma once
#include<string>
#include <unordered_map>

class Player {
    private:
        int id;
        std::string username;
        double balance;
        std::string job;
        double monthly_salary;
        std::unordered_map<std::string, double>assets;

    public:
        Player(int id,const std::string &name, double bal,const std::string &job, double salary);

        void deposit(double amount);
        void applyTaxes(double taxRate);
        void applyMonthlySalary();
        bool withdraw(double amount);
        void setJob(const std::string&  newJob, double salary);

        //Assets
        void addAsset(const std::string&  asset, double quantity);
        bool removeAsset(const std::string&  asset, double quantity);
        bool hasAsset(const std::string&  asset, double quantity=1) const;


        int getId() const;
        const std::string& getUsername() const;
        double getMonthlySalary()const;
        double getBalance() const;
        const std::string& getJob() const;


};


