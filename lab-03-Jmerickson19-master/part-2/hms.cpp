// Joshua Eickson (CPSC-03)

#include <iostream>
using namespace std;

const int seconds_in_day = 86400;
const int seconds_in_hour = 3600;
const int seconds_in_minute = 60;

int main() {

  int total_seconds;

  cout << "Enter an integer to represent seconds to convert ";
  cin >> total_seconds;

  int days = total_seconds / seconds_in_day;
  int days_left = total_seconds % seconds_in_day;
  
  int hours = days_left / seconds_in_hour;
  int hours_left = days_left % seconds_in_hour;

  int minutes = hours_left / seconds_in_minute;
  int seconds = hours_left % seconds_in_minute;


  cout << days << " days " << hours << ":" << minutes << ":" << seconds << endl;
  return 0;
}
