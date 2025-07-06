#pragma once
#include <iostream>
#include <vector>
#include <time.h>
#include "user.hpp"
using namespace std;

struct User;

struct Train {
    string trainId;
    string name;
    string source;
    string destination;
    time_t time;
    vector<vector<User>> seats;
};