// Joshua Erickson (CPSC-03)

#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {

if (argc != 3) {
  cout << "Usage: ./x-cell.cpp <number of multiples> <number to be multiplied>\n";
  return 0;
}

string arg_multiples = argv[1];
int multiples = stoi(arg_multiples);

string arg_base_number = argv[2];
int base_number = stoi(arg_base_number);

if (multiples < 0) {
  cout << "Bruh. Enter a POSITIVE number of times to multiply stuff by.\n";
  return 0;
}

int next_number = base_number;

while (multiples > 0) {
  cout << next_number << endl;
  next_number = next_number + base_number;
  multiples = multiples - 1;
}
}
