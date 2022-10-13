#include "type.h"

// Define the overloaded methods for struct type here
bool flightRec::operator < (const flightRec & rhs){
  if(destination < rhs.destination){
    return true;
  }
  return false;
}

bool flightRec::operator == (const flightRec& rhs){
  if(origin == rhs.origin && destination == rhs.destination){
    return true;
  }
  return false;
}

ostream& operator << (ostream& out, const flightRec& flight){
  out << flight.origin << " " << flight.flightNum << " " << flight.destination << " " << flight.price << endl;
  return out;
}

