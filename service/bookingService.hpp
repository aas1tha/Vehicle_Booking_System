// only declarations in hpp file
#pragma once
#include <iostream>
#include <ctime>
#include "../entities/user.hpp"
#include "../entities/vehicle.hpp"
#include "../entities/train.hpp"
#include "fileIO.hpp"
using namespace std;

template <typename T>       //generic
class BookingService {
    public:
        void book(string entityId, User user, string name, string source, string destination);  
        void cancelBooking(string entityId, string userid);

    private:
        void saveBooking(T entity) {
            FileIO<T> file;
            file.saveToFile(entity);
        }
};


// have to specify for both type(vehicle or train) make diff template for both, they have different behaviour. If both have same entities then only can we can use common func (tempplate) for them

// Template specializations for Vehicle
template <>
void BookingService<Vehicle>:: saveBooking(Vehicle entity);

// Template specializations for Train
template <>
void BookingService<Train>:: saveBooking(Train entity);
