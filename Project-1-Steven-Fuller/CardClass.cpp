// implementation file for CardClass
#include "CardClass.h"
#include <iostream>
#include <time.h>
using namespace std;

//default constructor
CardClass::CardClass(){
  for (int i = 0; i < SIZE; i++){
    if(i < 13){
      CardStruct[i].suit = DIAMOND;
      CardStruct[i].value = i+2;
      CardStruct[i].points = 0;
      if(i == 10){
        CardStruct[i].points = -100;
      }
    }
    else if(i < 26){
      CardStruct[i].suit = CLUB;
      //CardStruct[i].value = i%13+1;  // this line changed Dr. LI
      CardStruct[i].value = i%13+2;
      CardStruct[i].points = 0;
    }
    else if(i < 39){
      CardStruct[i].suit = HEART;
      CardStruct[i].value = i%13+2;  // changed
      CardStruct[i].points = 5;
      if(i > 34){
        CardStruct[i].points = 10;
      }
    }
    else{
      CardStruct[i].suit = SPADE; 
      CardStruct[i].value = i%13+2; // changed
      CardStruct[i].points = 0;
      if(i == 50){
        CardStruct[i].points = 100;
      }
    }
  }
}

//function to shuffle deck
void CardClass::ShuffleCard(){
  for(int x = 0; x < 100; x++){
    srand(time(0));
    CardType i = CardStruct[rand()%52];
    
    srand(time(0));
    CardType j = CardStruct[rand()%52];
    
    swap(i,j);
  }  
}

//function to deal the deck of cards 1 card at a time
CardType CardClass::DealCard(){

  CardType player;
  
  player.suit = CardStruct->suit;
  player.value = CardStruct->value;
  player.points = CardStruct->points;

  for(int i = 0; i < cardsLeft; i++){
    CardStruct[i] = CardStruct[i+1];
  }
  
  cardsLeft -= 1;
  
  return player;
}

//function returns the number of cards left in the deck
int CardClass::GetSize(){
  return cardsLeft;
}

//function returns if the deck is empty of not
bool CardClass::IsEmpty(){
  if(cardsLeft == 0){
    return true;
  }
  return false;
}