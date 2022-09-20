#ifndef mytype_H
#define mytype_H

// enum declaring the types of suits allowed
enum suitType { DIAMOND, CLUB, HEART, SPADE };

struct CardStruct {
  suitType suit;
  int value;
  int points;
};

#endif