//
//  OutputTableRow.cpp
//  Titanic
//
//  Created by Owen Lin on 11/26/23.
//

#include "OutputTableRow.h"
#include "Passenger.h"
#include <iostream>

namespace cs32
{
OutputTableRow::OutputTableRow() {}

void OutputTableRow::setDescription(std::string description) {
    mDescription = description;
}

void OutputTableRow::setSurvived(int survived){
    mSurvived = survived;
}

void OutputTableRow::setTotal(int total){
    mTotal = total;
}

std::string OutputTableRow::getDescription() {
    return mDescription;
}

int OutputTableRow::getSurvived(){
    return mSurvived;
}

int OutputTableRow::getTotal() {
    return mTotal;
}

double OutputTableRow::getPercentage() {
    if (mTotal == 0) {
        // Handle division by zero
        return 0.0;  // or some other indicative value
    }
    return (1.0 * mSurvived / mTotal) ;
}

void OutputTableRow::display() {
    
    std::cout << getDescription() << "   " << getSurvived() << " / " << getTotal() << "  " << getPercentage()*100 << std::endl;
    
}
    
    

}
