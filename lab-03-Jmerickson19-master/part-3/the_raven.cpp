// Joshua Erickson (CPSC-03)
#include <iostream>
using namespace std;

int main() {

  string line1 = "Once upon a midnight dreary, while I pondered, weak and weary,\n";
  string line2 = "Over many a quaint and curious volume of forgotten lore-\n";
  string line3 = "While I nodded, nearly napping, suddenly there came a tapping,\n";
  string line4 = "As of some one gently rapping, rapping at my chamber door.\n";
  string line5 = "\"Tis some visitor,\" I muttered, \"tapping at my chamber door-\n";
  string line6 = "\t\t\t\t\b\b\b\b\b\bOnly this and nothing more.\"\n";

  string poem = line1 + line2 + line3 + line4 + line5 + line6;
  
  cout << poem;
}
