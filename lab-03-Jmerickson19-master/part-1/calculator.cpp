//Joshua Erickson (CPSC-03)

#include <iostream>
using namespace std;

int main() {
  int first_number;
  int second_number;

  cout << "Enter two integers, separated by a space: ";
  cin >> first_number >> second_number;

  int sum = first_number + second_number;
  int difference = first_number - second_number;
  int product = first_number * second_number;

  float quotient = (float)first_number / second_number;
  int remainder = first_number % second_number;

  cout << first_number << " + " << second_number << " = " << sum << endl;
  cout << first_number << " - " << second_number << " = " << difference << endl;
  cout << first_number << " * " << second_number << " = " << product << endl;
  cout << first_number << " / " << second_number << " = " << quotient << endl;

  cout << first_number << " / " << second_number << " = " << (int)quotient;
  cout << "r" << remainder << endl;
}
