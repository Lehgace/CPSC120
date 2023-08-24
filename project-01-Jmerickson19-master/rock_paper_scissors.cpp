// Joshua Erickson  (CPSC-03)

#include <iostream>
#include <ctime>
using namespace std;

const int ROCK = 0;
const int PAPER = 1;
const int SCISSORS = 2;

int main(int argc, char* argv[])
{
  if (argc != 2) {
    cout << "Usage: ./rock_paper_scissors < 0, 1, or 2 for rock, paper, scissors respectively>\n";
    return 0;
  }

  int user_choice = 0;
  string user_string = argv[1];

  if (user_string.length() != 1 || user_string < "0" || user_string > "2") {
    string sassy_message = "I don't know what your choice is.\n"
      "Rock has been chosen on your behalf.\n";
    cout << sassy_message;
    user_choice = ROCK;
  }
  else {
    user_choice = stoi(user_string);
    cout << "You chose ";
    if (user_choice == ROCK) {
      cout << "rock";
    }
    else if (user_choice == PAPER){
      cout << "paper";
    }
    else {
      cout << "scissors";
    }
    cout << "." << endl;
  }

  srand(time(0));
  int computer_choice = rand() % 3;

  cout << "The computer chose: ";
  if (computer_choice == ROCK) {
    cout << "rock";
  }
  else if (computer_choice == PAPER){
    cout << "paper";
  }
  else {
    cout << "scissors";
  }
  cout << "." << endl;

  string draw = "Draw!\n";
  string win = "You win!\n";
  string lose = "You lose!\n";

  if (computer_choice == ROCK) {
    if (user_choice == PAPER) {
      cout << win;
    }
    else if (user_choice == SCISSORS) {
      cout << lose;
    }
    else {
      cout << draw;
    }
  }
  if (computer_choice == PAPER) {
    if (user_choice == ROCK) {
      cout << lose;
    }
    else if (user_choice == SCISSORS) {
      cout << win;
    }
    else {
      cout << draw;
    }
  }
  if (computer_choice == SCISSORS) {
    if (user_choice == ROCK) {
      cout << win;
    }
    else if (user_choice == PAPER) {
      cout << lose;
    }
    else {
      cout << draw;
    }
  }
}
