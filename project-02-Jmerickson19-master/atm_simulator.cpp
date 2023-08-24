// Joshua Erickson (CPSC-03)

#include <iostream>
using namespace std;

const string CHKBAL = "1";
const string DEPFUN = "2";
const string WITFUN = "3";
const string EXTATM = "4";

int main(int argc, char* argv[]) {

// Initialize PIN and starting balance using argv.
if (argc != 3) {
  cout << "Usage: ./atm_simulator <4-digit PIN number> <starting balance>\n";
  return 0;
}

string initialized_pin = argv[1];
int pin = stoi(initialized_pin);
string initialized_balance = argv[2];
float balance = stof(initialized_balance);

// PIN Easter Eggs
if (pin == 1996) {
  cout << "Dear Mario:\nPlease come to the castle. I've baked a cake for you.\n"
    "Yours truly--\nPrincess Toadstool (Peach)\n";
  return 0;
}
else if (pin == 1998) {
  cout << "I've been waiting for you, Hero of Time...\n";
  return 0;
}
else if (pin == 2009) {
  cout << "So, you want hear a story, eh? One about treasure hunters?\n"
    "Haha, have I got a story for you!\n";
  return 0;
}
else if (pin == 2011) {
  cout << "Hey you, you're finally awake. You were trying to cross the border"
    " right?\n";
  return 0;
}

// Welcome message and loop for PIN
int entered_pin;
int remaining_attempts;

bool valid = false;
cout << "Welcome customer, to branch #219 at Sanctuary Bank!\n";
for (int attempts = 1; attempts <= 3; attempts++) {
  cout << "Please enter your PIN number: ";
  cin >> entered_pin;
  if (entered_pin == pin) {
    cout << "It's a fine day, full of opportunity!\n";
    valid = true;
    break;
  }
  else {
    remaining_attempts = 3 - attempts;
    cout << "Invalid PIN.\n" << remaining_attempts << " attempts remaining.\n";
  }
}
// Check if PIN is valid within 3 attempts
if (valid == false) {
  cout << "Account Lockout. Try again later.\n";
  return 0;
}
// Menu prompt for customer to 1-Check balance, 2-Deposit, 3-Withdraw, or 4-Exit
// at anytime. When withdrawing, check for overdrafts.
string menu = "What would you like to do today?\n"
  "1 - Check Balance\n2 - Deposit\n3 - Withdraw\n4 - Exit\n";
string user_choice;
string withdraw_prompt;
float deposit;
float withdraw;

do {
  cout << menu;
  cin >> user_choice;
  if (user_choice == CHKBAL) {
    cout << "You have selected to check balance.\n";
    cout << "Your current balance is: $" << balance << endl;
  }
  else if (user_choice == DEPFUN) {
    cout << "You have selected to deposit funds.\n";
    cout << "How much would you like to deposit? ";
    cin >> deposit;
    if (deposit < 0.0) {
      cout << "Invalid amount entered. Deposit request cancelled.\n";
    }
    else {
      balance = balance + deposit;
      cout << "Your new balance is $" << balance << endl;
    }
  }
  else if (user_choice == WITFUN) {
    if (balance == 0.0) {
      cout << "Insufficient funds. Withdrawal request cancelled.\n";
    }
    else {
      cout << "You have selected to withdraw funds.\n";
      cout << "How much would you like to withdraw? ";
      cin >> withdraw;
      if (withdraw < 0.0) {
        cout << "Invalid amount entered. Withdraw request cancelled.\n";
      }
      else {
        if (withdraw > balance) {
          cout << "Requested withdrawal exceeds your current balance.\n";
          cout << "Would you like to withdraw $" << balance << " instead? (y/n) ";
          cin >> withdraw_prompt;
          if (withdraw_prompt[0] == 'y') {
            balance = 0.0;
            cout << "Balance after requested withdrawal is $" << balance << endl;
          }
          else if (withdraw_prompt[0] == 'n') {
            cout << "Withdrawal request cancelled.\n";
          }
          else {
            cout << "Command not recognized. Withdrawal request cancelled.\n";
          }
        }
        else {
          balance = balance - withdraw;
          cout << "Your new balance is $" << balance << endl;
        }
      }
    }
  }
  else if (user_choice == EXTATM) {
    break;
  }
  else {
    cout << "Command not recognized. Enter 1, 2, 3, or 4.\n";
  }
} while (user_choice != EXTATM);

cout << "Thank you! Come again!\n";
}
