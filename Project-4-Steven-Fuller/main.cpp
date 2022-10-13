// if late, give reason and pass # here
/* 
 PROGRAMMER:       	Steven Fuller 
 Program Description:    
  This program makes a vector of cities and an adjecency list of flights from their origin to their destinations including flight number and price
  It takes an input from a data file with the number of cities in it and a list of those cities. There is a 2nd data file with a list of flights on each line is their flight number, origin, destination, and price.     
 The output is an itinerary for a customers flight path starting from their given origin and ending at their givin destination.
*/ 
#include "flightMap.h"
#include "type.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
  FlightMapClass map;
  string originCity;
  string destinationCity;

  ifstream myCities("cities.dat");
  ifstream myFlights("flights.dat");
  ifstream myRequests("requests.dat");


  map.ReadCities(myCities);
  map.BuildMap(myFlights);

  while(myRequests >> originCity >> destinationCity){
    cout << "Request is to fly from " << originCity << " to " << destinationCity << endl;

    if(!map.CheckCity(originCity)){
      cout << "Sorry, BlueSky does not fly serve " << originCity << endl;
    }
    else if(!map.CheckCity(destinationCity)){
      cout << "Sorry, BlueSky does not fly serve " << destinationCity << endl;
    }
    else{
      map.FindPath(originCity, destinationCity);
      cout << endl;
    }
  }
  return 0;
}