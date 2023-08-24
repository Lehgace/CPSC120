// Joshua Erickson (CPSC-03)

#include <vector>
#include <iostream>
using namespace std;

void Print(vector<float> scores) {
  for (int i = 0; i < scores.size(); i++) {
    cout << scores.at(i) << ' ';
  }
  cout << endl;
}

float GetMaximum(vector<float> scores) {
  float candidate;
  if (scores.size() == 0) {
    candidate = 0.0;
  }
  else {
    candidate = scores.at(0);
    for (int i = 1; i < scores.size(); i++) {
      if (scores.at(i) > candidate ) {
        candidate = scores.at(i);
      }
    }
  }
  return candidate;
}

float GetMinimum(vector<float> scores) {
  float candidate;
  if (scores.size() == 0) {
    candidate = 0.0;
  }
  else {
    candidate = scores.at(0);
    for (int i = 1; i < scores.size(); i++) {
      if (scores.at(i) < candidate ) {
        candidate = scores.at(i);
      }
    }
  }
  return candidate;
}

vector<float> GetLowScores(vector<float> scores) {
  vector<float> failing_scores;
  for (int i = 0; i < scores.size(); i++) {
    if (scores.at(i) < 60) {
      float failing_score = scores.at(i);
      failing_scores.push_back(failing_score);
    }
  }
  return failing_scores;
}

int main(int argc, char* argv[]) {

  vector<float> scores;

  int max_arg = argc;
  for (int i = 1; i < max_arg; i++) {
    string input_score = argv[i];
    float score_value = stof(input_score);
    scores.push_back(score_value);
  }

  float highest_score = GetMaximum(scores);
  cout << "The highest score is: " << highest_score << endl;

  float lowest_score = GetMinimum(scores);
  cout << "The lowest score is: " << lowest_score << endl;

  vector<float> low_scores = GetLowScores(scores);
  if (low_scores.size() > 0) {
    cout << "Scores that can use improvement: ";
    Print(low_scores);
  }

  return 0;
}
