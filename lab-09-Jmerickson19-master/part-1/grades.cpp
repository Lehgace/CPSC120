// Joshua Erickson (CPSC-03)

#include <iostream>
using namespace std;

const int NUM_OF_SCORES = 5;

void Initialize(float scores[], int number_of_scores) {
  for(int index = 0; index < number_of_scores; index++) {
    scores[index] = 0;
  }
}

float GetMaximum(float scores[], int number_of_scores) {
  float candidate = scores[0];
  for (int index = 1; index < number_of_scores; index++) {
    if (scores[index] > candidate ) {
      candidate = scores[index];
    }
  }
  return candidate;
}

float GetMinimum(float scores[], int number_of_scores) {
  float candidate = scores[0];
  for (int index = 1; index < number_of_scores; index++) {
    if (scores[index] < candidate) {
      candidate = scores[index];
    }
  }
  return candidate;
}

float CalculateTotal (float scores[], int number_of_scores) {
  float total = 0.0;
  for (int index = 0; index < number_of_scores; index++) {
    total += scores[index];
  }
  return total;
}

float CalculateAverage (float scores[], int number_of_scores) {
  float total = CalculateTotal(scores, number_of_scores);
  float average = total / number_of_scores;
  return average;
}

float GetCutoffScoreForGrade (char desired_letter_grade) {
  float score_needed;
  if (desired_letter_grade == 'A') {
    score_needed = 90.0;
  }
  else if (desired_letter_grade == 'B') {
    score_needed = 80.0;
  }
  else if (desired_letter_grade == 'C') {
    score_needed = 70.0;
  }
  else if (desired_letter_grade == 'D') {
    score_needed = 60.0;
  }
  return score_needed;
}

char GetGradeForScore (float average) {
  char grade;
  if (average >= 90.0) {
    grade = 'A';
  }
  else if (average >= 80.0) {
    grade ='B';
  }
  else if (average >= 70.0) {
    grade = 'C';
  }
  else if (average >= 60.0) {
    grade = 'D';
  }
  else {
    grade = 'F';
  }
  return grade;
}

float GetMinimumScoreForGrade(float scores[], int number_of_scores,
                              char desired_letter_grade) {
  float minimum = GetMinimum(scores, number_of_scores);
  float sum = CalculateTotal(scores, number_of_scores);
  sum -= minimum;
  float desired_average = GetCutoffScoreForGrade(desired_letter_grade);
  float score_needed = NUM_OF_SCORES * desired_average - sum;
  return score_needed;
}

int main(int argc, char* argv[]) {

  float scores[NUM_OF_SCORES];

  Initialize(scores, NUM_OF_SCORES);

  if (argc == 1) {
    cout << "Usage: <five score values>\n";
    return 0;
  }
  int max_arg = argc;
  if (max_arg > 6) {
    max_arg = 6;
  }

  for (int index = 1; index < max_arg; index++) {
    string argument = argv[index];
    float score_val = stof(argument);
    scores[index - 1] = score_val;
  }

  float maximum = GetMaximum(scores, NUM_OF_SCORES);
  cout << "Highest Score: " << maximum << endl;
  float minimum = GetMinimum(scores, NUM_OF_SCORES);
  cout << "Lowest Score: " << minimum << endl;
  float average = CalculateAverage(scores, NUM_OF_SCORES);
  cout << "Average: " << average << endl;
  char letter_grade = GetGradeForScore(average);
  cout << "Current Grade: " << letter_grade << endl;

  float score_needed;
  char grade_desired[4] = {'A', 'B', 'C', 'D'};
  cout << "Dropping the minimum, new assignment would need score of:\n";
  for (int i = 0; i < 4; i++) {
    score_needed = GetMinimumScoreForGrade(scores, NUM_OF_SCORES,
                                           grade_desired[i]);
    cout << grade_desired[i] << ": " << score_needed << endl;
  }
  return 0;
}
