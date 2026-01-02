

#ifndef GAME_JOBS_H
#define GAME_JOBS_H

#pragma once
#include <vector>
#include "Database.h"


extern const std::vector<std::string>jobs;
extern const std::vector<double>salaries;
std::string job(Database &db, const std::string& username);


#endif //GAME_JOBS_H