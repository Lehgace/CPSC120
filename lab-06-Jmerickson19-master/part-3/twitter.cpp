// Joshua Erickson (CPSC-03)

#include <iostream>
using namespace std;

const char NULL_CHAR = '\0';
const int CHAR_LIMIT = 140;

int main(int argc, char* argv[])
{

  cout << "Enter your tweet: \n";
  string tweet;
  getline(cin, tweet);

  int count = 0;
  int index = 0;
  while (tweet[index] != NULL_CHAR) {
    index++;
    count++;
  }

  int overage;
  if (count > CHAR_LIMIT) {
    overage = count - CHAR_LIMIT;
    cout << "Your tweet is " << overage << " characters too long!\n";
  }
  else {
    cout << "Your tweet uses " << count << " characters.\n";
  }

  if (count > CHAR_LIMIT) {
    cout << "Truncated preview: ";
    index = 0;
    while (index < CHAR_LIMIT) {
      cout << tweet[index];
      index++;
    }
    cout << endl;
  }
  else {
    cout << "Preview: " << tweet << endl;
  }
}
