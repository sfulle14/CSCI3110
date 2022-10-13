#include "flightMap.h"
#include <iomanip>

// implement the methods of the flightMap class here

FlightMapClass::FlightMapClass() {
  numCities = 0;
  flightMap = NULL;
}

FlightMapClass::FlightMapClass(const FlightMapClass &flight) {
  numCities = flight.numCities;
  for (int i = 0; i < numCities; i++) {
    cities.push_back(flight.cities[i]);
  }

  flightMap = new list<flightRec>[numCities];

  for (int i = 0; i < numCities; i++) {
    flightMap[i] = flight.flightMap[i];
  }
}

FlightMapClass::~FlightMapClass() { delete[] flightMap; }

void FlightMapClass::ReadCities(ifstream &myCities) {
  string temp;
  myCities >> numCities;

  for (int i = 0; i < numCities; i++) {
    myCities >> temp;
    cities.push_back(temp);
  }
}

void FlightMapClass::BuildFlightMap(ifstream &myMap) {
  flightRec tempMap;
  int flightNum, flightPrice;
  string origin, dest;
  flightMap = new list<flightRec>[numCities];

  while (myMap >> flightNum >> origin >> dest >> flightPrice) {
    tempMap.flightNum = flightNum;
    tempMap.origin = origin;
    tempMap.destination = dest;
    tempMap.price = flightPrice;

    for (int i = 0; i < numCities; i++) {
      if (tempMap.origin == cities[i]) {
        flightMap[i].push_back(tempMap);
      }
    }
  }
  for(int i=0; i<numCities; i++){
    flightMap[i].sort();
  }
}

void FlightMapClass::DisplayFlightMap() {

  list<flightRec> curList;
  flightRec curFlight;

  cout << setw(15) << "Origin" << setw(24) << "Destination" << setw(8)
       << "Flight" << setw(7) << "Price" << endl;
  cout << "=======================================================" << endl;

  for (int i = 0; i < numCities; i++) {
    if (flightMap[i].size() == 0) {
      continue;
    } 
    else {
      cout << "From " << setw(15) << cities[i] << " to:";

      curList = flightMap[i];
      int count = 0;
      list<flightRec>::iterator j;
      for (j = flightMap[i].begin(); j != flightMap[i].end(); j++) {
        curFlight = *j;

        if (count == 0) {
          cout << setw(15) << curFlight.destination << setw(8)
               << curFlight.flightNum << setw(4) << "$" << setw(3)
               << curFlight.price << endl;
          count++;
        } 
        else {
          cout << setw(39) << curFlight.destination << setw(8)
               << curFlight.flightNum << setw(4) << "$" << setw(3)
               << curFlight.price << endl;
        }
      }
    }
  }
}