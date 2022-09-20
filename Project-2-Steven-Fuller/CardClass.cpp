// implementation file for CardClass
#include "CardClass.h"
#include <iostream>
#include <time.h>
using namespace std;

// default constructor
CardClass::CardClass() {
  for (int i = 0; i < SIZE; i++) {
    if (i < 13) {
      deck[i].suit = DIAMOND;
      deck[i].value = i + 2;
      deck[i].points = 0;
      if (i == 10) {
        deck[i].points = -100;
      }
    } else if (i < 26) {
      deck[i].suit = CLUB;
      deck[i].value = i % 13 + 1;
      deck[i].points = 0;
    } else if (i < 39) {
      deck[i].suit = HEART;
      deck[i].value = i % 13 + 1;
      deck[i].points = 5;
      if (i > 34) {
        deck[i].points = 10;
      }
    } else {
      deck[i].suit = SPADE;
      deck[i].value = i % 13 + 1;
      deck[i].points = 0;
      if (i == 50) {
        deck[i].points = 100;
      }
    }
  }
}

// function to shuffle deck
void CardClass::ShuffleCard() {
  for (int x = 0; x < 100; x++) {
    CardStruct i = deck[rand() % 52];

    CardStruct j = deck[rand() % 52];

    swap(i, j);
  }
}

// function to deal the deck of cards 1 card at a time
CardStruct CardClass::DealCard() {
  CardStruct player;

  player.suit = deck->suit;
  player.value = deck->value;
  player.points = deck->points;

  for (int i = 0; i < cardsLeft; i++) {
    deck[i] = deck[i + 1];
  }

  cardsLeft -= 1;

  return player;
}

// function returns the number of cards left in the deck
int CardClass::GetSize() { return cardsLeft; }

// function returns if the deck is empty of not
bool CardClass::IsEmpty() {
  if (cardsLeft == 0) {
    return true;
  }
  return false;
}