// Joshua Erickson (CPSC-03)
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<string> GetKnownWords(string file_name) {
  vector<string> known_words;
  ifstream words_file(file_name);
  for (string word; getline(words_file, word);) {
    known_words.push_back(word);
  }
  return known_words;
}

vector<string> GetMaskedPossibilities(string word) {
  vector<string> possibilities;
  for (int i = 0; i < word.length(); i++) {
    string word_copy = word;
    word_copy[i] = '*';
    possibilities.push_back(word_copy);
  }
  return possibilities;
}

int main(int argc, char* argv[]) {
  vector<string> known_words = GetKnownWords("known_words_short.txt");
  unordered_map<string, string> spell_suggester;
  unordered_map<string, bool> dictionary;
  for (string word : known_words) {
    vector<string> possibilities = GetMaskedPossibilities(word);
    for (string possibility : possibilities) {
      spell_suggester[possibility] = word;
    }
    dictionary[word] = true;
  }

  while (true) {
    string user_input;
    cout << "Enter a word: ";
    cin >> user_input;
    if (dictionary.find(user_input) == dictionary.end()) {
      cout << user_input << " is misspelled." << endl;
      vector<string> possibilities = GetMaskedPossibilities(user_input);
      for (string possibility : possibilities) {
        if (spell_suggester.find(possibility) != spell_suggester.end()) {
          cout << "Did you mean " << spell_suggester[possibility] << endl;
        }
      }
    }
  }

  return 0;
}
