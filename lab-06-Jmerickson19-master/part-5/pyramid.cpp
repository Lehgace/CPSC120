// Joshua Erickson (CPSC-03)

#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{

  if (argc != 3) {
    cout << "Usage: ./pyramid <number of pyramid levels> <single character in double quotes>\n";
    return 0;
  }

  string arg_levels = argv[1];
  int levels;
  try {
    levels = stoi(arg_levels);
  }
  catch (...){
    cout << "Invalid argument. Enter positive integer.\n";
    return 0;
  }

  if (levels < 0) {
    cout << "Invalid integer. Enter positive integer.\n";
    return 0;
  }

  string arg_character = argv[2];
  char selected_character = arg_character[0];

  int row = 0;
  int char_count = 0;
  int char_on_row;
  while (row < levels) {
    char_on_row = row + 1;
    char_count = 0;
    while (char_count < char_on_row) {
      cout << selected_character;
      char_count++;
    }
    cout << endl;
    row++;
  }

}
