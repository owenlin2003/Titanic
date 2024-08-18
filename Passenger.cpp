//
//  Passenger.cpp
//  Titanic
//
//  Created by Owen Lin on 11/16/23.
//

#include "Passenger.h"


namespace cs32 {

Passenger::Passenger() : mClass(Class::NOTKNOWN), mEmbarked(Embarcation::NOTKNOWN), mName(""), mSurvived(false), mFare(0) {
};

void Passenger::setName(std::string name) {
    mName = name;
}

std::string Passenger::getName() {
    return mName;
}

void Passenger::setEmbarcation(std::string embarked) {
    if (embarked == "C") {
        mEmbarked = Embarcation::CHERBOURG;
    }
    else if (embarked == "Q") {
        mEmbarked = Embarcation::QUEENSTOWN;
    }
    else if (embarked == "S") {
        mEmbarked = Embarcation::SOUTHHAMPTON;
    }
    else  {
        mEmbarked = Embarcation::NOTKNOWN;
    }
}

void Passenger::setClass(std::string classofFare) {
    
    if (classofFare == "1") {
        mClass = Class::FIRST;
    }
    else if (classofFare == "2") {
        mClass = Class::SECOND;
    }
    else if (classofFare == "3") {
        mClass = Class::THIRD;
    }
    else {
        mClass = Class::NOTKNOWN;
    }
}

void Passenger::setSurvived(std::string survived) {
    mSurvived = false;
    if (survived == "1") {
        mSurvived = true; }
}

void Passenger::setFare(std::string fare) {
    if (fare == ""){
        mFare = 0;
    } //bound cases
    else{
        mFare = std::stof( fare ); }
}

Embarcation Passenger::getEmbarcation() {
    return mEmbarked;
}

Class Passenger::getClass() {
    return mClass;
}

bool Passenger::getSurvived() {
    return mSurvived;
}

double Passenger::getFare() {
    return mFare;
}
    
    
}
