//
//  PassengerOutputTable.cpp
//  Titanic
//
//  Created by Owen Lin on 11/26/23.
//

#include "PassengerOutputTable.h"
#include <iostream>
#include <map>
#include <string>
namespace cs32
{
PassengerOutputTable::PassengerOutputTable(std::vector< Passenger* > passengers)
    : mPassengersList(passengers), mField(Field::NOVALUE) {

}

void PassengerOutputTable::setOutputField(Field f){
    mField = f;
}

void PassengerOutputTable::setDescription(std::string description) {
    mDescription = description;
}

Field PassengerOutputTable::getOutputField() {
    return mField;
}

std::string PassengerOutputTable::getDescription() {
    return mDescription;
}

void PassengerOutputTable::display() {
    
    std::cout << getDescription() << std::endl;  // Example: Print table description
    
    
    switch (getOutputField()) {
        case Field::BYCLASS:
            displayByClass();
            break;
        case Field::BYEMBARCATION:
            displayByEmbarcation();
            break;
        case Field::BYFARE:
            displayByFare();
            break;
        case Field::NOVALUE:
            break;
            
    }
}

size_t PassengerOutputTable::rowCount() {
    return mRows.size();
}


OutputTableRow PassengerOutputTable::getRow(int index) {
    return mRows.at(index);
}



//my new helper functions

void PassengerOutputTable::displayByClass() {
    std::map<Class, std::pair<int, int>> classCounts;

    // Initialize classCounts for all classes
    classCounts[Class::FIRST] = std::make_pair(0, 0);
    classCounts[Class::SECOND] = std::make_pair(0, 0);
    classCounts[Class::THIRD] = std::make_pair(0, 0);
    classCounts[Class::NOTKNOWN] = std::make_pair(0, 0);

    // Count survivors and total passengers for each class
    for (auto& passenger : mPassengersList) {
        Class passengerClass = passenger->getClass();
        classCounts[passengerClass].second += 1;
        if (passenger->getSurvived()) {
            classCounts[passengerClass].first += 1;
        }
    }

    // Clear and resize mRows to match the number of classes
    mRows.clear();
    mRows.resize(4);

    // Set descriptions and populate the rows with data
    mRows[0].setDescription("First Class");
    mRows[1].setDescription("Second Class");
    mRows[2].setDescription("Third Class");
    mRows[3].setDescription("Not Known");

    for (int i = 0; i < 4; ++i) {
        mRows[i].setSurvived(classCounts[static_cast<Class>(i)].first);
        mRows[i].setTotal(classCounts[static_cast<Class>(i)].second);
    }

    // Display each row
    for (auto& row : mRows) {
        row.display();
    }
}


//
void PassengerOutputTable::displayByEmbarcation() {
    std::map<Embarcation, std::pair<int, int>> embarkationCounts;

    // Initialize embarkationCounts for all embarkation points
    embarkationCounts[Embarcation::CHERBOURG] = std::make_pair(0, 0);
    embarkationCounts[Embarcation::QUEENSTOWN] = std::make_pair(0, 0);
    embarkationCounts[Embarcation::SOUTHHAMPTON] = std::make_pair(0, 0);
    embarkationCounts[Embarcation::NOTKNOWN] = std::make_pair(0, 0);

    // Count survivors and total passengers
    for (auto& passenger : mPassengersList) {
        Embarcation embarkation = passenger->getEmbarcation();
        embarkationCounts[embarkation].second += 1;
        if (passenger->getSurvived()) {
            embarkationCounts[embarkation].first += 1;
        }
    }

    // Clear and resize mRows
    mRows.clear();
    mRows.resize(4);

    // Set descriptions and populate the rows with data
    mRows[0].setDescription("Cherbourg");
    mRows[1].setDescription("Queenstown");
    mRows[2].setDescription("Southampton");
    mRows[3].setDescription("Not Known");

    for (int i = 0; i < 4; ++i) {
        mRows[i].setSurvived(embarkationCounts[static_cast<Embarcation>(i)].first);
        mRows[i].setTotal(embarkationCounts[static_cast<Embarcation>(i)].second);
    }

    // Display each row
    for (auto& row : mRows) {
        row.display();
    }
}


void PassengerOutputTable::displayByFare() {
    std::map<int, std::pair<int, int>> fareCounts;

    // Initialize fareCounts for all fare brackets
    for (int i = 0; i < 5; ++i) {
        fareCounts[i] = std::make_pair(0, 0);
    }

    // Count survivors and total passengers in fare brackets
    for (auto& passenger : mPassengersList) {
        double fare = passenger->getFare();
        int bracket = getFareBracket(fare);
        fareCounts[bracket].second += 1;
        if (passenger->getSurvived()) {
            fareCounts[bracket].first += 1;
        }
    }

    // Clear and resize mRows
    mRows.clear();
    mRows.resize(5);

    // Set descriptions and populate the rows with data
    mRows[0].setDescription("Not Known");
    mRows[1].setDescription("0.01 to 10.00");
    mRows[2].setDescription("10.01 to 25.00");
    mRows[3].setDescription("25.01 to 50.00");
    mRows[4].setDescription("50.01 or more");

    for (int i = 0; i < 5; ++i) {
        mRows[i].setSurvived(fareCounts[i].first);
        mRows[i].setTotal(fareCounts[i].second);
    }

    // Display each row
    for (auto& row : mRows) {
        row.display();
    }
}


// Helper function to determine fare bracket
int PassengerOutputTable::getFareBracket(double fare) {
    if (fare < 0.01) return 0;  // Not Known
    if (fare <= 10.00) return 1; // 0.01 to 10.00
    if (fare <= 25.00) return 2; // 10.01 to 25.00
    if (fare <= 50.00) return 3; // 25.01 to 50.00
    return 4;                    // 50.01 or more
}
}
