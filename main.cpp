#include <iostream>
#include "entities/vehicle.hpp"
#include "entities/user.hpp"
#include "service/bookingService.hpp"

using namespace std;

int main() {
    string userId;
    string name;
    string aadharCard;

    cout << "Enter User ID: ";
    getline(cin, userId);

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Aadhar Card Number: ";
    getline(cin, aadharCard);

    cout << "Enter the option: " << endl;
    cout << "Enter 1 to book the train" << endl;
    cout << "Enter 2 to cancel the booking" << endl;

    int option;
    cin >> option;
    cin.ignore();  // clear leftover newline before getline

    // signup/login user using userid --> user.json
    // fetch train using train name --> train.json
    // booking --> fetch train using trainId, fetch seats, store user there, booking.json

    switch(option) {
        case 1: {
            string trainId, trainName, source, destination;

            cout << "Enter Train ID: ";
            getline(cin, trainId);

            cout << "Enter Train Name: ";
            getline(cin, trainName);

            cout << "Enter Source Station: ";
            getline(cin, source);

            cout << "Enter Destination Station: ";
            getline(cin, destination);

            User user;
            user.userId = userId;
            user.name = name;
            user.aadharCard = aadharCard;

            BookingService<Vehicle> bookingService;
            bookingService.book(trainId, user, trainName, source, destination);

            cout << "Train booked successfully!" << endl;
            break;
        }

        case 2: {
            string trainId;

            cout << "Enter Train ID to cancel booking: ";
            getline(cin, trainId);

            BookingService<Vehicle> bookingService;
            bookingService.cancelBooking(trainId, userId);
            break;
        }

        default:
            cout << "Invalid option" << endl;
            break;
    }

    return 0;
}

