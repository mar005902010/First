#include "Jobs.h"
#include "Database.h"
#include "iostream"
using namespace std;
using namespace mysqlx;

const std::vector<std::string> jobs = {"Trader", "Data Analyst", "Driver","Teacher","Doctor","Cleaner"};

const std::vector<double> salaries = {3500.0, 4200.0, 2800.0, 3100.0, 5000.0, 2500.0};

std::string job(Database &db, const std::string& username) {

    auto schema = db.getSchema();
    Table users = schema.getTable("users");

    cout<<"Choose your job (you can change it later): ";

    for (int i=0; i<jobs.size(); i++) {
        cout<<i<<')'<<jobs[i]<<" - $"<<salaries[i]<<endl;
    }
    int job;
    cin>>job;

    std::string selectedJob = jobs[job];

    if (!cin||job<0||job>=jobs.size()) {
        cout<<"Invalid index"<<endl;
        cin.clear();
        cin.ignore(1000, '\n');
        return "";
    }

    users.update().set("job",jobs[job]).set("monthly_salary",salaries[job])
            .where("username = :un").bind("un", username).execute();

    return selectedJob;

}
