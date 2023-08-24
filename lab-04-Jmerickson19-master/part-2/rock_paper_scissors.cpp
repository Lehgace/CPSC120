// Joshua Erickson  (CPSC-03)

#include <iostream>
#include <ctime>
using namespace std;

/*
Plays a game of Rock, Paper, Scissors. The user can enter one of 0, 1, or 2 to
represent rock, paper, and scissors respectively.
*/

const int rock = 0;
const int paper = 1;
const int scissors = 2;

int main(int argc, char* argv[])
{
  int user_choice = 0;
  string user_string = argv[1];

  if (user_string.length()!= 1 || user_string < "0" || user_string > "2") {
    string sassy_message = "I don't know what your choice is.\n"
      "Rock has been chosen on your behalf.\n";
    cout << sassy_message;
    user_choice = rock;
  }
  else {
    user_choice = stoi(user_string);

    cout << "You chose ";
    if (user_choice == rock) {
      cout << "rock";
    }
    else if (user_choice == paper) {
      cout << "paper";
    }
    else if (user_choice == scissors) {
      cout << "scissors";
    }
    cout << "." << endl;
  }

  srand(time(0)); // Don't touch this line.
  int computerChoice = rand() % 3;

  cout << "The computer chose: ";
  if (computerChoice == rock) {
    cout << "rock";
  }
  else if (computerChoice == paper) {
    cout << "paper";
  }
  else if (computerChoice == scissors) {
    cout << "scissors";
  }
  cout << "." << endl;

  string draw = "Draw!\n";
  string win = "You win!\n";
  string lose = "You lose!\n";

  if (computerChoice == user_choice) {
    cout << draw;
  }
  else if (computerChoice == rock && user_choice == paper) {
    cout << win;
  }
  else if (computerChoice == rock && user_choice == scissors) {
    cout << lose;
  }
  else if (computerChoice == paper && user_choice == rock) {
    cout << lose;
  }
  else if (computerChoice == paper && user_choice == scissors) {
    cout << win;
  }
  else if (computerChoice == scissors && user_choice == rock) {
    cout << win;
  }
  else if (computerChoice == scissors && user_choice == paper) {
    cout << lose;
  }
}
