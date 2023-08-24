// Joshua Erickson  (CPSC-03)

#include <iostream>
#include <ctime>
using namespace std;

const string ROCK = "rock";
const string PAPER = "paper";
const string SCISSORS = "scissors";
const string PLAYER = "Player";
const string COMPUTER = "Computer";
const string TIE = "Tie";

string GetPlayerChoice() {
  string player_choice;
  cout << "Enter rock, paper, or scissors: ";
  cin >> player_choice;

  if (player_choice == ROCK ||
      player_choice == PAPER ||
      player_choice == SCISSORS) {
    cout << PLAYER << " chose: " << player_choice << endl;
    return player_choice;
  }
  else {
    cout << "I don't know what your choice is.\n";
    cout << "Rock has been chosen for you.\n";
    player_choice = ROCK;
    return player_choice;
  }
}

string GetComputerChoice() {
  srand(time(0));
  int random_choice = rand() % 3;
  string computer_choice;

  if (random_choice == 0) {
    computer_choice = ROCK;
  }
  else if (random_choice == 1){
    computer_choice = PAPER;
  }
  else {
    computer_choice = SCISSORS;
  }
  cout << COMPUTER << " chose: " << computer_choice << endl;
  return computer_choice;
}

string DetermineWinner(string player_choice, string computer_choice) {
  string determine_winner;
  if (computer_choice == ROCK) {
    if (player_choice == PAPER) {
      cout << PLAYER << " wins\n";
      determine_winner = PLAYER;
    }
    else if (player_choice == SCISSORS) {
      cout << COMPUTER << " wins\n";
      determine_winner = COMPUTER;
    }
    else {
      cout << TIE << endl;
      determine_winner = TIE;
    }
  }
  if (computer_choice == PAPER) {
    if (player_choice == ROCK) {
      cout << COMPUTER << " wins\n";
      determine_winner = COMPUTER;
    }
    else if (player_choice == SCISSORS) {
      cout << PLAYER << " wins\n";
      determine_winner = PLAYER;
    }
    else {
      cout << TIE << endl;
      determine_winner = TIE;
    }
  }
  if (computer_choice == SCISSORS) {
    if (player_choice == ROCK) {
      cout << PLAYER << " wins\n";
      determine_winner = PLAYER;
    }
    else if (player_choice == PAPER) {
      cout << COMPUTER << " wins\n";
      determine_winner = COMPUTER;
    }
    else {
      cout << TIE << endl;
      determine_winner = TIE;
    }
  }
  return determine_winner;
}

int main(int argc, char* argv[]) {

  string player_choice = GetPlayerChoice();
  string computer_choice = GetComputerChoice();
  string determine_winner = DetermineWinner(player_choice, computer_choice);
}
