// Joshua Erickson (CPSC-03)
#include <iostream>
using namespace std;
int main(int argc, char* argv[]) {

if (argc != 3) {
  cout << "Usage: ./no_parking <day of week> <military time of day>" << endl;
  return 0;
}

string day_of_week = argv[1];
string Monday = "Monday";
string Tuesday = "Tuesday";
string Wednesday = "Wednesday";
string Thursday = "Thursday";
string Friday = "Friday";
string Saturday = "Saturday";
string Sunday = "Sunday";

if ((day_of_week == Monday) ||
    (day_of_week == Tuesday) ||
    (day_of_week == Wednesday) ||
    (day_of_week == Thursday) ||
    (day_of_week == Friday) ||
    (day_of_week == Saturday) ||
    (day_of_week == Sunday)) {
  day_of_week = argv[1];
}
else {
  cout << day_of_week << " is not a valid day of the week.\n";
  return 0;
}

string str_time_of_day = argv[2];
int int_time_of_day = stoi(str_time_of_day);
    // OPTIONAL CHALLENGE: how would you detect true invalid military time
    // like 199 or 1386?
if (int_time_of_day < 0 ||
    int_time_of_day > 2359) {
  cout << int_time_of_day << " isn't a time of day!\nThat's a bruh moment.\n";
  return 0;
}
else {
  int_time_of_day = stoi(str_time_of_day);
}

string yes_park = "Yes, you may park.\n";
string no_park = "No, you may not park\n";

if (day_of_week == Monday) {
  cout << no_park;
}
else if (day_of_week == Tuesday &&
         int_time_of_day >= 900 &&
         int_time_of_day < 1700) {
  cout << no_park;
}
else if (day_of_week != Sunday &&
         int_time_of_day >= 2000 &&
         int_time_of_day <= 2300) {
  cout << no_park;
}
else {
  cout << yes_park;
}
    return 0;
}
