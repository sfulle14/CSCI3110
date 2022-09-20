#include "CardClass.h"
#include "PlayerClass.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

const int MAX_ROUNDS = 13; // Maximum rounds
const int MAX_PLAYERS = 4; // Max number of players

// declare prototypes of the functions here
int FindLead(PlayerClass p[]);
void PlayRound(PlayerClass p[], CardStruct t[], int &);
void DisplayCard(const CardStruct);
int GetChoice(PlayerClass, suitType, int);
int FindCollector(const CardStruct t[], int &, suitType);
void DisplayScoreBoard(PlayerClass p[]);
int FindWinner(PlayerClass p[]);

int main() {
  // declare local variables
  CardStruct table[MAX_PLAYERS]; // This structure holds the 4 cards played by
                                 // the 4 players in one round of the game
  CardClass deckOfCards;         // deck is created
  PlayerClass players[MAX_PLAYERS]; // user and players
  int round = 1;
  int lead;
  int winner;

  cout << "**********************************************\n";
  cout << "                  HEARTS                      \n";
  cout << "**********************************************\n";
  
  srand(time(NULL));

  // shuffle the deck of cards
  deckOfCards.ShuffleCard();

  // This for loop deals ONLY ONE card at a time
  // by repetitively calling the DealCard method of CardClass
  for (int i = 0; i < MAX_ROUNDS; i++) {
    for (int p = 0; p < MAX_PLAYERS; p++) {
      players[p].AddCard(deckOfCards.DealCard());
    }
  }

  // This for loop sorts each players cards
  for (int p = 0; p < MAX_PLAYERS; p++) {
    players[p].Sort();
  }

  // Find who leads the first round
  lead = FindLead(players);

  // This while loop iterates 13 rounds of the game, one round per iteration
  // Each round, display the user's game and play according to the rule of the
  // game
  while (round <= 13) {

    // fill in the code
    // player with the 2 of clubs plays the first card
    cout << "ROUND " << round << endl << endl;
    players[0].DisplayCards();

    PlayRound(players, table, lead);

    round++;
  }

  // Find who is the winner
  winner = FindWinner(players);
  // prints the player who won the game
  if (winner == 0) {
    cout << "You won!\n";
  } else {
    cout << "Computer " << winner << " won!\n";
  }

  return 0;
}

// This function calls the PlayerClass member function to find who leads the
// first game
int FindLead(PlayerClass p[]) {
  // fill in code
  for (int i = 0; i < MAX_PLAYERS; i++) {
    if (p[i].IsFirstLead()) {
      return i;
    }
  }
}

// This function plays one round of the game
// p[] pass in the 4 PlayerClass objects, i.e., the 4 players
// t[] will hold the 4 cards for a round
// lead will:
//    (1)pass in who should lead the current round, and
//    (2)pass back to the calling function who will lead the next round of the
//    game
void PlayRound(PlayerClass p[], CardStruct t[], int &lead) {

  // declare local variables
  suitType leadingSuit;
  int highPlayer;
  int score;

  // First, print "user" if the lead is 0
  // otherwise prints computer number
  if (lead == 0) {
    cout << "User is leading the round \n";
  } else {
    cout << "Computer " << lead << " is leading the round \n";
  }

  // This for loop lets the players to each play a card
  // Make sure to collect the 4 cards played in the array t
  for (int i = 0; i < MAX_PLAYERS; i++) {

    // if a player's hand is full
    // and if the player is leading,
    // then start the game by play 2 of club
    if (lead == 0 && p[0].GetCount() == 13 && p[lead].IsFirstLead()) {
      t[0] = p[0].Play2Club();
    }
    // else if computer is leading, then the computer plays a card
    else if (lead > 0 && p[lead].GetCount() == 13 && p[lead].IsFirstLead()) {
      t[i] = p[lead].Play2Club();
    }
    // else if the user is leading, get a choice from the user
    // otherwise computer plays a card by following a leading suit
    else if (lead == 0) {
      t[i] = p[lead].PlaySelectedCard(GetChoice(p[lead], t[i - 1].suit, i));
    } else {
      t[i] = p[lead].FollowOneCard(t[i - 1].suit);
    }

    // sets the leading suit played by the players who is leading the round
    leadingSuit = t[i].suit;

    // Displays a card played by a current player
    if (lead > 0) {
      if (t[i].suit == DIAMOND) {
        cout << "Computer " << lead << ": " << t[i].value << " of "
             << "DIAMOND" << endl;
      } else if (t[i].suit == CLUB) {
        cout << "Computer " << lead << ": " << t[i].value << " of "
             << "CLUB" << endl;
      } else if (t[i].suit == HEART) {
        cout << "Computer " << lead << ": " << t[i].value << " of "
             << "HEART" << endl;
      } else {
        cout << "Computer " << lead << ": " << t[i].value << " of "
             << "SPADE" << endl;
      }
    } else {
      if (t[i].suit == DIAMOND) {
        cout << "User: " << t[i].value << " of "
             << "DIAMOND" << endl;
      } else if (t[i].suit == CLUB) {
        cout << "User: " << t[i].value << " of "
             << "CLUB" << endl;
      } else if (t[i].suit == HEART) {
        cout << "User: " << t[i].value << " of "
             << "HEART" << endl;
      } else {
        cout << "User: " << t[i].value << " of "
             << "SPADE" << endl;
      }
    }
    // Clockwise rotation, move onto the next player
    if (lead == 3) {
      lead = 0;
    } else {
      lead++;
    }
  }

  // Finds who has the highest value of a round
  // And assigns lead to who has the highest value

  highPlayer = FindCollector(t, score, leadingSuit);

  // Display which player gets how many points on this round
  if (highPlayer == 0) {
    cout << "User gets " << score << " points.\n";
  } else {
    cout << "Computer " << highPlayer << " gets " << score << " points.\n";
  }

  // Adds current round's score to the player who had the highest value
  p[highPlayer].AddScore(score);

  // Prints the score board
  DisplayScoreBoard(p);
}

// This function prints one card's suit and value
void DisplayCard(const CardStruct c) {
  // fill code
  if (c.suit == DIAMOND) {
    cout << c.value << " of " << DIAMOND << endl;
  } else if (c.suit == CLUB) {
    cout << c.value << " of " << CLUB << endl;
  } else if (c.suit == HEART) {
    cout << c.value << " of " << HEART << endl;
  } else {
    cout << c.value << " of " << SPADE << endl;
  }
}

// This function read the user's choice
// turn : if it is 0, the user is leading the round; otherwise the user is
// following in the round s : leading suit of the current game
int GetChoice(PlayerClass user, suitType s, int turn) {
  // declare local variables
  int choice;
  bool validChoice = false;

  // if the user is leading the round get a choice from the user
  if (turn == 0) {
    cout << "Please enter the card number you want to play: ";
    cin >> choice;
  }

  // if the user is playing after the lead,
  // then get a choice and check if it is a valid choice
  // continue to ask until a valid choice is made
  if (turn > 0) {
    while (!validChoice) {
      cout << "Please enter the card number you want to play: ";
      cin >> choice;
      if (user.IsValidChoice(s, choice)) {
        validChoice = true;
      }
    }
  }
  return choice;
}

// This function find who has played the card of highest value of the round
int FindCollector(const CardStruct t[], int &score, suitType leadingSuit) {
  // declare local variables
  int highCard = 0;
  int highCardPlayer;
  int cardSum = 0;

  // loop to sum up all of the points
  // and then find who has played the card of highest value for the round
  for (int i = 0; i < MAX_PLAYERS; i++) {
    cardSum += t[i].points;

    if (highCard < t[i].points) {
      highCardPlayer = i;
    }
  }
  score = cardSum;

  // the array index corresponding to the player with the highest value for the
  // round is retured.
  return highCardPlayer;
}

// This function prints each player's score
void DisplayScoreBoard(PlayerClass p[]) {
  // fill code
  cout << "\n-----Score Board-----\n";
  cout << "User: " << p[0].GetScore() << " points" << endl;
  cout << "Computer 1: " << p[1].GetScore() << " points" << endl;
  cout << "Computer 2: " << p[2].GetScore() << " points" << endl;
  cout << "Computer 3: " << p[3].GetScore() << " points" << endl;
  cout << endl;
}

// This function finds who won the game
// winner's index is retured
int FindWinner(PlayerClass p[]) {
  // fill code
  int winnerScore = p[0].GetScore();
  int winner;

  for (int i = 0; i < MAX_PLAYERS; i++) {
    if (winnerScore > p[i].GetScore()) {
      winner = i;
    }
  }
  return winner;
}