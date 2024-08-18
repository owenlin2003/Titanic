//
//  PassengerDatabase.cpp
//  Titanic
//
//  Created by Owen Lin on 11/16/23.
//

#include "PassengerDatabase.h"
#include "CSVFile.h"

namespace cs32 {

// Constructor: Initializes the database with no data loaded.
PassengerDatabase::PassengerDatabase() : isLoaded(false) {
}

// Destructor: Responsible for freeing memory allocated to passengers.
PassengerDatabase::~PassengerDatabase() {
    clearAllPassengers();
}
// Load passenger data from a CSV file.
int PassengerDatabase::load(std::string filePath) {
    CSVFile file(this);
    int recordCount = file.readFile(filePath);
    isLoaded = true; // Mark the database as loaded.
    return recordCount;
};

// Clear all passenger data from the database.
void PassengerDatabase::clearAllPassengers() {
    // Simply clears the vector of passengers without deallocating memory.
    while(!passengers.empty()){
        
        delete passengers.back();
        passengers.pop_back();
        
    }
}

// Check if the database is loaded.
bool PassengerDatabase::loaded() {
    return isLoaded;
}

// Retrieve a passenger by their name.
Passenger* PassengerDatabase::getPassenger_byName(std::string name) {
    // Search through the list of passengers.
    for (size_t i = 0; i < passengers.size(); ++i) {
        if (passengers[i]->getName() == name)
            return passengers[i]; // Return the passenger if found.
    }
    return nullptr; // Return nullptr if no match is found.
}

// Get all passengers in the database.
std::vector<Passenger*> PassengerDatabase::getPassengers() {
    return passengers;
}

// Retrieve passengers based on their class, survival status, and minimum fare.
std::vector<Passenger*> PassengerDatabase::getPassengers_byClass(Class paidClass, bool survived, double minimumFare) {
    std::vector<Passenger*> passengerByClass;
    for (size_t i = 0; i < passengers.size(); ++i) {
        // Filter passengers based on criteria.
        if (passengers[i]->getClass() == paidClass && passengers[i]->getSurvived() == survived && passengers[i]->getFare() >= minimumFare)
            passengerByClass.push_back(passengers[i]);
    }
    return passengerByClass;
}

// Retrieve passengers based on their embarkation point, survival status, and minimum fare.
std::vector<Passenger*> PassengerDatabase::getPassengers_byEmbarcation(Embarcation embarked, bool Survived, double minimumFare) {
    std::vector<Passenger*> passengerByEmbarcation;
    for (size_t i = 0; i < passengers.size(); ++i) {
        // Filter passengers based on criteria.
        if (passengers[i]->getEmbarcation() == embarked && passengers[i]->getSurvived() == Survived && passengers[i]->getFare() >= minimumFare)
            passengerByEmbarcation.push_back(passengers[i]);
    }
    return passengerByEmbarcation;
}

// Method to process each row of data from a CSV file.
void PassengerDatabase::csvData(std::map<std::string, std::string> row) {
    // Create a new Passenger object and populate it with data from the CSV row.
    Passenger* p = new Passenger();
    p->setName(row.find("name")->second);
    p->setClass(row.find("pclass")->second);
    p->setEmbarcation(row.find("embarked")->second);
    p->setSurvived(row.find("survived")->second);
    p->setFare(row.find("fare")->second);

    // Add the new Passenger to the database.
    passengers.push_back(p);
}

} // namespace cs32
