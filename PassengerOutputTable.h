//
//  PassengerOutputTable.h
//  Titanic
//
//  Created by Owen Lin on 11/26/23.
//

#ifndef PassengerOutputTable_h
#define PassengerOutputTable_h
#include "Passenger.h"
#include "OutputTableRow.h"
#include <vector>
#include <string>

namespace cs32
{
class PassengerOutputTable
{
public:
    PassengerOutputTable(std::vector< Passenger* > passengers);
    void setOutputField(Field f);
    void setDescription(std::string description);
    Field getOutputField();
    std::string getDescription();
    
    void display();
    size_t rowCount();
    OutputTableRow getRow(int index);
    
private:
    void displayByClass();
    void displayByEmbarcation();
    void displayByFare();
    std::vector<Passenger*> mPassengersList;
    std::vector<OutputTableRow> mRows;
    Field mField;
    std::string mDescription;

    int getFareBracket(double fare);
};


}

#endif /* PassengerOutputTable_h */

