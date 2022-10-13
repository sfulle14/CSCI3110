#include "flightMap.h"
#include <iomanip>
#include <stack>


// implement the methods of the flightMap class here

FlightMapClass::FlightMapClass() {
  numCities = 0;
  map = NULL;
}

FlightMapClass::FlightMapClass(const FlightMapClass &flight) {
  numCities = flight.numCities;
  for (int i = 0; i < numCities; i++) {
    cities.push_back(flight.cities[i]);
  }

  map = new list<flightRec>[numCities];

  for (int i = 0; i < numCities; i++) {
    map[i] = flight.map[i];
  }
}

FlightMapClass::~FlightMapClass() { delete[] map; }

void FlightMapClass::ReadCities(ifstream &myCities) {
  string temp;
  myCities >> numCities;

  for (int i = 0; i < numCities; i++) {
    myCities >> temp;
    cities.push_back(temp);
  }
}

void FlightMapClass::BuildMap(ifstream &myMap) {
  flightRec tempMap;
  int flightNum, flightPrice;
  string origin, dest;
  map = new list<flightRec>[numCities];

  while (myMap >> flightNum >> origin >> dest >> flightPrice) {
    tempMap.flightNum = flightNum;
    tempMap.origin = origin;
    tempMap.destination = dest;
    tempMap.price = flightPrice;

    for (int i = 0; i < numCities; i++) {
      if (tempMap.origin == cities[i]) {
        map[i].push_back(tempMap);
      }
    }
  }
  for(int i=0; i<numCities; i++){
    map[i].sort();
  }
}

void FlightMapClass::DisplayMap() {

  list<flightRec> curList;
  flightRec curFlight;

  cout << setw(15) << "Origin" << setw(24) << "Destination" << setw(8)
       << "Flight" << setw(7) << "Price" << endl;
  cout << "=======================================================" << endl;

  for (int i = 0; i < numCities; i++) {
    if (map[i].size() == 0) {
      continue;
    } 
    else {
      cout << "From " << setw(15) << cities[i] << " to:";

      curList = map[i];
      int count = 0;
      list<flightRec>::iterator j;
      for (j = map[i].begin(); j != map[i].end(); j++) {
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

bool FlightMapClass::CheckCity(string cityName) const{
  bool isCity = false;
  for(int i=0; i<numCities; i++){
    if(cities[i] == cityName){
      isCity = true;
    }
  }
  return isCity;
}

void FlightMapClass::DisplayAllCities() const{
  cout << "List all the Cities: " << endl;
  for(int i=0; i<numCities; i++){
    cout << cities[i] << endl;
  }
}

void FlightMapClass::MarkVisited(int city){
  visited[city] = true;
}

void FlightMapClass::UnvisitAll(){
  if(visited.size() == 0){
    for(int i=0; i<numCities; i++){
      visited.push_back(false);
    }
  }
  else{
    for(int i=0; i<numCities; i++){
      visited[i] = false;
    }
  }
}

bool FlightMapClass::IsVisited(int city) const{
    if(visited[city] == true){
      return true;
    }
  return false;
}

bool FlightMapClass::GetNextCity(string fromCity, string &nextCity){
  list<flightRec> curList; //current adjacency list
  flightRec curFlight;  //current flight info
  string cityName;  //destination city name
  bool success = false;
  list<flightRec>::iterator iter;

  curList = map[GetCityNumber(fromCity)];

  for(iter=curList.begin(); iter!=curList.end(); iter++){
    curFlight = *iter;
    cityName = curFlight.destination;

    if(!visited[GetCityNumber(cityName)]){
      success = true;
      break;
    }
  }

  if(success){
    nextCity = cityName;
  }

  return success;  
}

int FlightMapClass::GetCityNumber(string cityName) const{
  for(int i=0; i<numCities; i++){
    if(cities[i] == cityName){
      return i;
    }
  }
  return -1;
}

string FlightMapClass::GetCityName(int cityNumber) const{
  return cities[cityNumber];
}

void FlightMapClass::FindPath(string originCity, string destinationCity){
  stack<string> aStack;
  stack<string> auxStack;
  string topCity;
  string nextCity;
  string temp;
  bool success = false;
  int totalPrice = 0;
  string origin;
  string destination;
  list<flightRec> curList;
  flightRec curFlight;
  list<flightRec>::iterator iter;

  

  UnvisitAll();
  cout << "all unvisited";

  aStack.push(originCity);   //addes origin to stack
  MarkVisited(GetCityNumber(originCity));  //marks as visited

  topCity = aStack.top();  //sets topCity to the originCity

  while(!aStack.empty() && (topCity != destinationCity)){
    success = GetNextCity(topCity, nextCity);  //gets the next city in adj. list
    if(!success){
      aStack.pop();  //removes last visited city from stack
    }
    else{
      aStack.push(nextCity);
      MarkVisited(GetCityNumber(nextCity));
    }

    if(!aStack.empty()){
      topCity = aStack.top();
    }   
  }

  if(aStack.size()==0){
    cout << "Sorry, BlueSky airline does not serve " << originCity << " from " << destinationCity << endl;
  }
  else{
    

    cout << "Request is to fly from " << originCity << " to " << destinationCity << "." << endl;
    cout << "The flight itinerary is:" << endl;
    cout << "Flight #" << setw(15) << "From " << setw(15) << "To" << setw(6) << "Cost" << endl;

    while(!aStack.empty()){
      temp = aStack.top();
      aStack.pop();
      auxStack.push(temp);
    }

    origin = auxStack.top();
    auxStack.pop();
    while(!auxStack.empty()){
      curList = map[GetCityNumber(origin)];
      destination = auxStack.top();
      auxStack.pop();

      for(iter=curList.begin(); iter!=curList.end(); iter++){
        curFlight = *iter;

        if(curFlight.destination == destination){
          cout << setw(10) << curFlight.flightNum << setw(15) << curFlight.origin << setw(15) << curFlight.destination << setw(5) << "$" << setw(5) << curFlight.price << endl;

          totalPrice += curFlight.price;

          origin = curFlight.destination;
          break;
        }
      }
    }

    cout << setw(40) << "Total:" << setw(5) << "$" << setw(5) << totalPrice;
  }
}