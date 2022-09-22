// define the enum type for card suits here
// also define the card struct type here
#ifndef cardtype_h
#define cardtype_h
#include <string>

using namespace std;
//enum declaring the types of suits allowed
enum CardSuitType {DIAMOND, CLUB, HEART, SPADE};

struct CardType
{
  CardSuitType suit;
  int value;
  int points;
};


#endif