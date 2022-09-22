// if late, give reason and pass # here
/* 
 PROGRAMMER:       	Steven Fuller
 Program Description:    
  This program creates a deck of cards, shuffles it, and deals them out one at a time to the 4 players. Then sorts the players hands by suit, prints out each players hand and displays which player has the 2 of clubs.
  This program does not take any input from the user. The only outside data that is used is the time to seed the random function.     
  The output of this function is each players hand of cards and the player that has the 2 of clubs.
*/ 
#include "CardClass.h"
#include <iostream>
#include <iomanip>

using namespace std;

//function prototypes
void SortCards(CardType player[]);
void PrintCards(CardType player[]);
void ClubOfTwo(CardType player[], int playerNum);

const int MAX_PLAYER_CARDS = 13;

int main() {

  //create the players
  CardType player1[MAX_PLAYER_CARDS];
  CardType player2[MAX_PLAYER_CARDS];
  CardType player3[MAX_PLAYER_CARDS];
  CardType player4[MAX_PLAYER_CARDS];

  //create the deck of cards
  CardClass deck;

  deck.ShuffleCard();

  //deal the deck of cards
  for (int i = 0; i < MAX_PLAYER_CARDS; i++){
    player1[i] = deck.DealCard();
    player2[i] = deck.DealCard();
    player3[i] = deck.DealCard();
    player4[i] = deck.DealCard();
  }

  //sort each players hand
  SortCards(player1);
  SortCards(player2);
  SortCards(player3);
  SortCards(player4);

  //print out the player and their hand
  cout << "\nPLAYER 1 \n";
  PrintCards(player1);
  cout << "\nPLAYER 2 \n";
  PrintCards(player2);
  cout << "\nPLAYER 3 \n";
  PrintCards(player3);
  cout << "\nPLAYER 4 \n";
  PrintCards(player4);

  //check to see who has the 2 of club and print them out
  ClubOfTwo(player1, 1);
  ClubOfTwo(player2, 2);
  ClubOfTwo(player3, 3);
  ClubOfTwo(player4, 4);
}

//function to sort a players cards by suit
void SortCards(CardType player[]){
  int min;
  CardType minValue;
  for(int i = 0; i < MAX_PLAYER_CARDS; i++){
    min = i;
    minValue = player[i];
    for (int j = i+1; j < MAX_PLAYER_CARDS; j++){
      if(player[j].suit < minValue.suit){
        minValue = player[j];
        min = j;
      }
    }
    swap(player[min], player[i]);
  }
}


//function to print out players and their cards
void PrintCards(CardType player[]){ 
  cout <<  "SUIT" << setw(15) << right <<  "VALUE" << setw(15) << "POINTS" << endl;
  
  for(int i = 0; i < MAX_PLAYER_CARDS; i++){
    if(player[i].suit == 0){
      //if(i%13 == 1){
      if(player[i].value == 14){
        cout << left<< setw(10) << "DIAMOND" << right << setw(10) << "A" << right << setw(15) << player[i].points << endl;
        cout << "here" <<endl;
      }
      //else if(i%13 == 11){
      else if(player[i].value == 11){
        cout << left<< setw(10) <<  "DIAMOND" << setw(10) <<  right << setw(10) << "J" << setw(15) << player[i].points << endl;
      }
      //else if(i%13 == 12){
      else if(player[i].value == 12){
        cout << left<< setw(10) <<  "DIAMOND" << setw(10) <<  right << setw(10) << "Q" << setw(15) << player[i].points << endl;
      }
      //else if(i%13 == 13){
      else if(player[i].value == 13){
        cout << left<< setw(10) <<  "DIAMOND" << setw(10) <<  right << setw(10) << "K" << setw(15) << player[i].points << endl;
      }
      else{
        cout << left<< setw(10) <<  "DIAMOND" << setw(10) <<  right << setw(10) << player[i].value << setw(15) << player[i].points << endl;
      }
    }
    
    if(player[i].suit == 1){
     
      //if(i%13 == 1){
       if(player[i].value == 14){
        cout << left<< setw(10) << "CLUB" << right << setw(10) << "A" << right << setw(15) << player[i].points << endl;
      }
      else if(player[i].value == 11){
        cout << left<< setw(10) <<  "CLUB" << setw(10) <<  right << setw(10) << "J" << setw(15) << player[i].points << endl;
      }
      else if(player[i].value== 12){
        cout << left<< setw(10) <<  "CLUB" << setw(10) <<  right << setw(10) << "Q" << setw(15) << player[i].points << endl;
      }
      else if(player[i].value == 13){
        cout << left<< setw(10) <<  "CLUB" << setw(10) <<  right << setw(10) << "K" << setw(15) << player[i].points << endl;
      }
      else{
        cout << left<< setw(10) <<  "CLUB" << setw(10) <<  right << setw(10) << player[i].value << setw(15) << player[i].points << endl;
      }
    }
    if(player[i].suit == 2){
      if(player[i].value == 14){
        cout << left<< setw(10) << "HEART" << right << setw(10) << "A" << right << setw(15) << player[i].points << endl;
      }
      else if(player[i].value == 11){
        cout << left<< setw(10) <<  "HEART" << setw(10) <<  right << setw(10) << "J" << setw(15) << player[i].points << endl;
      }
      else if(player[i].value == 12){
        cout << left<< setw(10) <<  "HEART" << setw(10) <<  right << setw(10) << "Q" << setw(15) << player[i].points << endl;
      }
      else if(player[i].value == 13){
        cout << left<< setw(10) <<  "HEART" << setw(10) <<  right << setw(10) << "K" << setw(15) << player[i].points << endl;
      }
      else{
        cout << left<< setw(10) <<  "HEART" << setw(10) <<  right << setw(10) << player[i].value << setw(15) << player[i].points << endl;
      }
    }
    if(player[i].suit == 3){
      if(player[i].value == 1){
        cout << left<< setw(10) << "SPADE" << right << setw(10) << "A" << right << setw(15) << player[i].points << endl;
      }
      else if(player[i].value == 11){
        cout << left<< setw(10) <<  "SPADE" << setw(10) <<  right << setw(10) << "J" << setw(15) << player[i].points << endl;
      }
      else if(player[i].value == 12){
        cout << left<< setw(10) <<  "SPADE" << setw(10) <<  right << setw(10) << "Q" << setw(15) << player[i].points << endl;
      }
      else if(player[i].value == 13){
        cout << left<< setw(10) <<  "SPADE" << setw(10) <<  right << setw(10) << "K" << setw(15) << player[i].points << endl;
      }
      else{
        cout << left<< setw(10) <<  "SPADE" << setw(10) <<  right << setw(10) << player[i].value << setw(15) << player[i].points << endl;
      }
    }
  }
}


//find the 2 of clubs
void ClubOfTwo(CardType player[], int playerNum){
  for(int i = 0; i < MAX_PLAYER_CARDS; i++){
    if(player[i].suit == CLUB and player[i].value == 2){
      cout << "\nPlayer " << playerNum << " has the card 2 of CLUB\n";
    }
  }
}