#include "bookingService.hpp"
#include <ctime>
using namespace std;

// Template implementation for Vehicle
template <>
void BookingService<Vehicle>::book(string entityId, User user, string name, string source, string destination) {
    struct Vehicle vehicle;
    vehicle.vehicleId = entityId;
    vehicle.name = name;
    vehicle.source = entityId;
    vehicle.destination = destination;
    vehicle.time = time(nullptr);
    vehicle.seats = {{user}};

    saveBooking(vehicle);
    
}


// this will empty(set NULL) the seat details with matched userId and trainId
template <>
void BookingService<Vehicle>::cancelBooking(string entityId, string userId) {
    FileIO<Vehicle> file;
    vector<Vehicle> vehicles = file.readFromFile();

    bool found = false;

    for (auto& vehicle : vehicles) {
        if (vehicle.vehicleId == entityId) {
            for (auto& row : vehicle.seats) {
                row.erase(
                    remove_if(row.begin(), row.end(), [&](const User& u) {
                        return u.userId == userId;
                    }),
                    row.end()
                );
            }
            found = true;
        }
    }

    if (found) {
        // Overwrite the file with updated list
        ofstream outFile(file.filename);
        json j;
        for (const auto& vehicle : vehicles) {
            json seatsJson = json::array();
            for (const auto& row : vehicle.seats) {
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
                {"vehicleId", vehicle.vehicleId},
                {"name", vehicle.name},
                {"source", vehicle.source},
                {"destination", vehicle.destination},
                {"time", vehicle.time},
                {"seats", seatsJson}
            });
        }
        outFile << j.dump(4);
        outFile.close();

        cout << "Booking cancelled successfully for user: " << userId << endl;
    } else {
        cout << "Booking not found for user: " << userId << " in vehicle: " << entityId << endl;
    }
}



template <>
void BookingService<Vehicle>::saveBooking(Vehicle entity) {
    FileIO<Vehicle> file;
    file.saveToFile(entity);

}


// Template implementation for Train
template <>
void BookingService<Train>::book(string entityId, User user, string name, string source, string destination) {
    Train train;
    train.trainId = entityId;
    train.name = name;
    train.source = source;
    train.destination = destination;
    train.time = time(nullptr);
    train.seats = {{user}};
    
    saveBooking(train);
}

template <>
void BookingService<Train>::cancelBooking(string entityId, string userId) {
    FileIO<Train> file;
    vector<Train> trains = file.readFromFile();

    bool found = false;

    for (auto& train : trains) {
        if (train.trainId == entityId) {
            for (auto& row : train.seats) {
                row.erase(
                    remove_if(row.begin(), row.end(), [&](const User& u) {
                        return u.userId == userId;
                    }),
                    row.end()
                );
            }
            found = true;
        }
    }

    if (found) {
        // Overwrite the file with updated list
        ofstream outFile(file.filename);
        json j;
        for (const auto& train : trains) {
            json seatsJson = json::array();
            for (const auto& row : train.seats) {
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
                {"vehicleId", train.trainId},
                {"name", train.name},
                {"source", train.source},
                {"destination", train.destination},
                {"time", train.time},
                {"seats", seatsJson}
            });
        }
        outFile << j.dump(4);
        outFile.close();

        cout << "Booking cancelled successfully for user: " << userId << endl;
    } else {
        cout << "Booking not found for user: " << userId << " in train: " << entityId << endl;
    }
}



template <>
void BookingService<Train>::saveBooking(Train entity) {
    FileIO<Train> file;
    file.saveToFile(entity);
}