#include "AUList.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

AUList csvtoAUList(string cityQual) { 
    AUList Airqualls;
    ifstream ReadFile("cityQual.csv"); 
    string line, curvalue;
    getline(ReadFile, line); 
    while (getline(ReadFile, line)) {
        stringstream ss(line); //turn the line into a string-stream
        int fielditer = 0;
        CityAQrecordord newrec;
        while (getline(ss, curvalue, ',')) { //Separate each variable per sample from the comma separator
            switch (fielditer) { //We need to explicitly convert values to the appropriate type (stoi=integer, stod=double)
            case 0: newrec.city = curvalue; break;
            case 1: newrec.country = curvalue; break;
            case 2: newrec.airqual = curvalue; break;
            case 3: newrec.waterqual = curvalue; break;
            }
            fielditer++;
        }
        Airqualls.PutItem(newrec);
    }
    return Airqualls;
    
}

int main() {
    AUList cityQualLS = csvtoAUList("cityQual.csv");
    cityQualLS.PrintList(); //Print the data record-by-record
    return 0;
}
