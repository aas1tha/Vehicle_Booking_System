#pragma once
#include <iostream>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

struct Vehicle; 

struct User{
    string userId;
    string name;
    string aadharCard;
    vector<Vehicle> vehicles;
    
};