// if late, give reason and pass # here
/* 
 PROGRAMMER:       	Steven Fuller 
 Program Description:    
  This program makes a vector of cities and an adjecency list of flights from their origin to their destinations including flight number and price
  It takes an input from a data file with the number of cities in it and a list of those cities. There is a 2nd data file with a list of flights on each line is their flight number, origin, destination, and price.        
 The output is a list of all possible flights.
*/ 

#include <iostream>
#include "flightMap.h"

using namespace std;

int main() {
  FlightMapClass map;
  string origin, dest;

  ifstream myCities("cities.dat");
  ifstream myMap("flights.dat");

  map.ReadCities(myCities);

  map.BuildFlightMap(myMap);

  map.DisplayFlightMap();
  
  return 0;
}