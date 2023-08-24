// Joshua Erickson (CPSC-03)

#include <iostream>
using namespace std;

const int PIN = 1998;
const int MAX_TRIES = 3;

int main() {

int pin_prompt;
int tries = 0;

do {
  cout << "Please enter your PIN: \n";
  cin >> pin_prompt;
  tries = tries + 1;

  if (pin_prompt == PIN) {
    cout << "Access Granted.\n";
    return 0;
  }
  else if (pin_prompt != PIN && tries < MAX_TRIES) {
    cout << "Incorrect PIN. \nEnter correct PIN within 3 tries or get denied.\n";
  }
  else if (pin_prompt != PIN && tries == MAX_TRIES) {
    cout << "Access Denied. Max attempts reached.\n";
  }
} while (tries != MAX_TRIES);

}
