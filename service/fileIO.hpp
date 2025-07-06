#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "../entities/user.hpp"
#include "../entities/train.hpp"
#include "../entities/vehicle.hpp"
#include "../external/json.hpp"

using namespace std;
using json = nlohmann::json;

// Generic template - fallback
template <typename T>
class FileIO {};

// Specialization for Vehicle
template <>
class FileIO<Vehicle> {
public:
    void saveToFile(Vehicle entity);
    vector<Vehicle> readFromFile();
    void overwriteFile(const vector<Vehicle>& entities);  

    string filename = "booking.json";  // file for vehicle bookings
};

// Specialization for Train
template <>
class FileIO<Train> {
public:
    void saveToFile(Train entity);
    vector<Train> readFromFile();
    void overwriteFile(const vector<Train>& entities); 

    string filename = "train.json";  // file for train bookings
};
