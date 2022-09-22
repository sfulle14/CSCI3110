// header file for the CardClass
#ifndef CardClass_h
#define CardClass_h
#include "cardtype.h"
#include <string>

using namespace std;

const int SIZE = 52; // total number of cards allowed

class CardClass {
private:
  CardType CardStruct[SIZE]; // array of cards
  int cardsLeft = 52;        // count of cards left in deck

public:
  CardClass();
  void ShuffleCard();
  CardType DealCard();
  int GetSize();
  bool IsEmpty();
};

#endif