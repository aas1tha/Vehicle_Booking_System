#include "fileIO.hpp"
#include <fstream>
using namespace std;
using json = nlohmann::json;

// ----------- VEHICLE IMPLEMENTATION -----------

void FileIO<Vehicle>::saveToFile(Vehicle entity) {
    json j;
    ifstream file(filename);
    if (file.is_open()) {
        file >> j;
        file.close();
    }

    // Convert seats to JSON
    json seatsJson = json::array();
    for (const auto& row : entity.seats) {
        json rowJson = json::array();
        for (const auto& user : row) {
            rowJson.push_back({
                {"userId", user.userId},
                {"name", user.name},
                {"aadharCard", user.aadharCard}
            });
        }
        seatsJson.push_back(rowJson);
    }

    json entityJson = {
        {"vehicleId", entity.vehicleId},
        {"name", entity.name},
        {"source", entity.source},
        {"destination", entity.destination},
        {"time", entity.time},
        {"seats", seatsJson}
    };

    j.push_back(entityJson);

    ofstream outFile(filename);
    outFile << j.dump(4);
    outFile.close();
}

vector<Vehicle> FileIO<Vehicle>::readFromFile() {
    vector<Vehicle> entities;
    ifstream file(filename);
    if (!file.is_open()) return entities;

    json j;
    file >> j;
    file.close();

    for (const auto& item : j) {
        Vehicle entity;
        entity.vehicleId = item["vehicleId"];
        entity.name = item["name"];
        entity.source = item["source"];
        entity.destination = item["destination"];
        entity.time = item["time"];

        entity.seats.clear();
        for (const auto& rowJson : item["seats"]) {
            vector<User> row;
            for (const auto& userJson : rowJson) {
                User user;
                user.userId = userJson["userId"];
                user.name = userJson["name"];
                user.aadharCard = userJson["aadharCard"];
                row.push_back(user);
            }
            entity.seats.push_back(row);
        }

        entities.push_back(entity);
    }

    return entities;
}

void FileIO<Vehicle>::overwriteFile(const vector<Vehicle>& entities) {
    json j = json::array();

    for (const auto& entity : entities) {
        json seatsJson = json::array();
        for (const auto& row : entity.seats) {
            json rowJson = json::array();
            for (const auto& user : row) {
                rowJson.push_back({
                    {"userId", user.userId},
                    {"name", user.name},
                    {"aadharCard", user.aadharCard}
                });
            }
            seatsJson.push_back(rowJson);
        }

        j.push_back({
            {"vehicleId", entity.vehicleId},
            {"name", entity.name},
            {"source", entity.source},
            {"destination", entity.destination},
            {"time", entity.time},
            {"seats", seatsJson}
        });
    }

    ofstream outFile(filename);
    outFile << j.dump(4);
    outFile.close();
}


// ----------- TRAIN IMPLEMENTATION -----------

void FileIO<Train>::saveToFile(Train entity) {
    json j;
    ifstream file(filename);
    if (file.is_open()) {
        file >> j;
        file.close();
    }

    // Convert seats to JSON
    json seatsJson = json::array();
    for (const auto& row : entity.seats) {
        json rowJson = json::array();
        for (const auto& user : row) {
            rowJson.push_back({
                {"userId", user.userId},
                {"name", user.name},
                {"aadharCard", user.aadharCard}
            });
        }
        seatsJson.push_back(rowJson);
    }

    json entityJson = {
        {"trainId", entity.trainId},
        {"name", entity.name},
        {"source", entity.source},
        {"destination", entity.destination},
        {"time", entity.time},
        {"seats", seatsJson}
    };

    j.push_back(entityJson);

    ofstream outFile(filename);
    outFile << j.dump(4);
    outFile.close();
}

vector<Train> FileIO<Train>::readFromFile() {
    vector<Train> entities;
    ifstream file(filename);
    if (!file.is_open()) return entities;

    json j;
    file >> j;
    file.close();

    for (const auto& item : j) {
        Train entity;
        entity.trainId = item["trainId"];
        entity.name = item["name"];
        entity.source = item["source"];
        entity.destination = item["destination"];
        entity.time = item["time"];

        entity.seats.clear();
        for (const auto& rowJson : item["seats"]) {
            vector<User> row;
            for (const auto& userJson : rowJson) {
                User user;
                user.userId = userJson["userId"];
                user.name = userJson["name"];
                user.aadharCard = userJson["aadharCard"];
                row.push_back(user);
            }
            entity.seats.push_back(row);
        }

        entities.push_back(entity);
    }

    return entities;
}

void FileIO<Train>::overwriteFile(const vector<Train>& entities) {
    json j = json::array();

    for (const auto& entity : entities) {
        json seatsJson = json::array();
        for (const auto& row : entity.seats) {
            json rowJson = json::array();
            for (const auto& user : row) {
                rowJson.push_back({
                    {"userId", user.userId},
                    {"name", user.name},
                    {"aadharCard", user.aadharCard}
                });
            }
            seatsJson.push_back(rowJson);
        }

        j.push_back({
            {"trainId", entity.trainId},
            {"name", entity.name},
            {"source", entity.source},
            {"destination", entity.destination},
            {"time", entity.time},
            {"seats", seatsJson}
        });
    }

    ofstream outFile(filename);
    outFile << j.dump(4);
    outFile.close();
}


// ---------- Explicit Template Instantiation ----------
template class FileIO<Vehicle>;
template class FileIO<Train>;
