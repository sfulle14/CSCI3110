#include "PlayerClass.h"
#include <iomanip>
#include <iostream>
#include <time.h>

using namespace std;

PlayerClass::PlayerClass() {
  count = 0;
  score = 0;
}

void PlayerClass::AddCard(CardStruct d) {
  if (count < 13) {
    hand[count].suit = d.suit;
    hand[count].points = d.points;
    hand[count].value = d.value;

    count++;
  }
}

void PlayerClass::DisplayCards() const {
  if (count > 0) {
    cout << "SUIT" << setw(15) << right << "VALUE" << setw(15) << "POINTS"
         << endl;
    for (int i = 0; i < count; i++) {
      if (hand[i].suit == DIAMOND) {
        if (hand[i].value == 14) {
          cout << left << setw(10) << "DIAMOND" << right << setw(10) << "A"
               << right << setw(15) << hand[i].points << endl;
        } else if (hand[i].value == 11) {
          cout << left << setw(10) << "DIAMOND" << setw(10) << right << setw(10)
               << "J" << setw(15) << hand[i].points << endl;
        } else if (hand[i].value == 12) {
          cout << left << setw(10) << "DIAMOND" << setw(10) << right << setw(10)
               << "Q" << setw(15) << hand[i].points << endl;
        } else if (hand[i].value == 13) {
          cout << left << setw(10) << "DIAMOND" << setw(10) << right << setw(10)
               << "K" << setw(15) << hand[i].points << endl;
        } else {
          cout << left << setw(10) << "DIAMOND" << setw(10) << right << setw(10)
               << hand[i].value << setw(15) << hand[i].points << endl;
        }
      } else if (hand[i].suit == CLUB) {
        if (hand[i].value == 14) {
          cout << left << setw(10) << "CLUB" << right << setw(10) << "A"
               << right << setw(15) << hand[i].points << endl;
        } else if (hand[i].value == 11) {
          cout << left << setw(10) << "CLUB" << setw(10) << right << setw(10)
               << "J" << setw(15) << hand[i].points << endl;
        } else if (hand[i].value == 12) {
          cout << left << setw(10) << "CLUB" << setw(10) << right << setw(10)
               << "Q" << setw(15) << hand[i].points << endl;
        } else if (hand[i].value == 13) {
          cout << left << setw(10) << "CLUB" << setw(10) << right << setw(10)
               << "K" << setw(15) << hand[i].points << endl;
        } else {
          cout << left << setw(10) << "CLUB" << setw(10) << right << setw(10)
               << hand[i].value << setw(15) << hand[i].points << endl;
        }
      } else if (hand[i].suit == HEART) {
        if (hand[i].value == 14) {
          cout << left << setw(10) << "HEART" << right << setw(10) << "A"
               << right << setw(15) << hand[i].points << endl;
        } else if (hand[i].value == 11) {
          cout << left << setw(10) << "HEART" << setw(10) << right << setw(10)
               << "J" << setw(15) << hand[i].points << endl;
        } else if (hand[i].value == 12) {
          cout << left << setw(10) << "HEART" << setw(10) << right << setw(10)
               << "Q" << setw(15) << hand[i].points << endl;
        } else if (hand[i].value == 13) {
          cout << left << setw(10) << "HEART" << setw(10) << right << setw(10)
               << "K" << setw(15) << hand[i].points << endl;
        } else {
          cout << left << setw(10) << "HEART" << setw(10) << right << setw(10)
               << hand[i].value << setw(15) << hand[i].points << endl;
        }
      } else if (hand[i].suit == SPADE) {
        if (hand[i].value == 14) {
          cout << left << setw(10) << "SPADE" << right << setw(10) << "A"
               << right << setw(15) << hand[i].points << endl;
        } else if (hand[i].value == 11) {
          cout << left << setw(10) << "SPADE" << setw(10) << right << setw(10)
               << "J" << setw(15) << hand[i].points << endl;
        } else if (hand[i].value == 12) {
          cout << left << setw(10) << "SPADE" << setw(10) << right << setw(10)
               << "Q" << setw(15) << hand[i].points << endl;
        } else if (hand[i].value == 13) {
          cout << left << setw(10) << "SPADE" << setw(10) << right << setw(10)
               << "K" << setw(15) << hand[i].points << endl;
        } else {
          cout << left << setw(10) << "SPADE" << setw(10) << right << setw(10)
               << hand[i].value << setw(15) << hand[i].points << endl;
        }
      }
    }
  }
  cout << endl;
}

CardStruct PlayerClass::FollowOneCard(suitType s) {
  bool found = false;
  if (count >= 1) {
    for (int i = 0; i < count; i++) {
      if (s == hand[i].suit) {
        found = true;
        for (int index = i; index < count - 1; index++) {
          hand[index] = hand[index + 1];
        }
        count--;
        return hand[i];
      }
    }
  }
}

CardStruct PlayerClass::StartOneHand() {
  if (count >= 1) {
    count--;
    return hand[0];
  }
}

bool PlayerClass::IsFirstLead() const {
  bool start = false;
  if (count == 13) {
    for (int i = 0; i < count; i++) {
      if (hand[i].suit == CLUB && hand[i].value == 2) {
        start = true;
        return start;
      }
    }
  }
  return start;
}

CardStruct PlayerClass::Play2Club() {
  CardStruct playCard;
  bool found = false;
  int index;

  if (IsFirstLead()) {
    for (int i = 0; i < count; i++) {
      if (hand[i].suit == CLUB && hand[i].value == 2) {
        playCard = hand[i];
        for (index = i; index < count - 1; index++) {
          hand[index] = hand[index + 1];
        }
        count--;
        return playCard;
      }
    }
  }
  return playCard;
}

int PlayerClass::GetScore() const { return score; }

// TODO!!!
void PlayerClass::AddScore(int s) { score += s; }

int PlayerClass::GetCount() const { return count; }

void PlayerClass::Sort() {
  if (count >= 1) {
    int min;
    CardStruct minValue;
    for (int i = 0; i < MAX_PLAYER_CARDS; i++) {
      min = i;
      minValue = hand[i];
      for (int j = i + 1; j < MAX_PLAYER_CARDS; j++) {
        if (hand[j].suit < minValue.suit) {
          minValue = hand[j];
          min = j;
        }
      }
      swap(hand[min], hand[i]);
    }
  }
}

CardStruct PlayerClass::PlaySelectedCard(int choice) {
  if (isdigit(choice)) {
    CardStruct playCard;

    playCard = hand[choice];
    for (int i = choice; i < count - 1; i++) {
      hand[i] = hand[i + 1];
    }
    count--;

    return playCard;
  }
}

bool PlayerClass::IsValidChoice(suitType s, int choice) const {
  bool valid = false;

  for (int i = 0; i < count; i++) {
    if (hand[i].suit == s) {
      if (hand[choice].suit == s) {
        valid = true;
      }
    } else if (choice < count) {
      valid = true;
    }
  }

  return valid;
}