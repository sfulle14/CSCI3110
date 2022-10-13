#include <iostream>
#include <fstream>
#include <vector>
#include <list>

using namespace std;

#ifndef FLIGHTMAPCLASS_H
#define FLIGHTMAPCLASS_H

#include "type.h"

using namespace std;

class FlightMapClass
{
	public:
		//constructors and destructor
		FlightMapClass(); //default constructor

    FlightMapClass(const FlightMapClass &flight); //copy constructor

    ~FlightMapClass(); //destructor
	
		//FlightMapClass operations:

		//Read cities from a data file
		//Pre-condition: Input stream is provided
		//Post-condition: Data file is read
		//				  Cities are in ascending order
    void ReadCities(ifstream &myCities);

		//Reads flight information and build the adjacency list
		//Pre-condition: list of the flight information is provided
		//Post-condition: Flight map is built
		void BuildFlightMap(ifstream& myMap);
		
		//Displays the flight map in a formatted table
    // using overloaded << opererator
		//Pre-condition: none
		//Post-condition: Flight map is displayed
    void DisplayFlightMap();
		
	private:
	  int numCities;	     				  //number of cities
	  vector<string> cities;	      //vector of cities
	  list<flightRec> *flightMap;	  //flight map
};

#endif