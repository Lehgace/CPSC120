// Joshua Erickson (CPSC-03)

#include <iostream>
using namespace std;

const char NULL_CHAR = '\0';
const int CHAR_LIMIT = 140;

int main(int argc, char* argv[]) {

  cout << "Enter your tweet: \n";
  string tweet;
  getline(cin, tweet);

  int count = 0;
  int index;
  for (index = 0; tweet[index] != NULL_CHAR; index++) {
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

  int limit;
  if (count > CHAR_LIMIT) {
    cout << "Truncated preview: " << endl;
    for (index = count - 1; index >= count - CHAR_LIMIT; index-- ) {
      cout << tweet[index];
    }
    cout << endl;
  }
  else {
    cout << "Preview: " << endl;
    for (index = count - 1; index >= 0; index--) {
      cout << tweet[index];
    }
    cout << endl;
  }

}
