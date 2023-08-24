// Joshua Erickson (CPSC-03)

#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {

string str_days_overdue = argv[1];
int int_days_overdue = stoi(str_days_overdue);

string return_on_time = "Your book was returned on time!\n";
string no_fine = "No fine.\n";
string book_overdue = "Your book is overdue!\n";
string first_notice = "This is your first overdue notice.\n";
string second_notice = "This is your second overdue notice.\n";
string third_notice = "This is your third overdue notice.\n";
string book_lost = "Your book is assumed lost.\n";
string bill_replacement = "This is the bill for replacement.\n";
string fine_notice = "The fine you owe is $";


float fine_owed = int_days_overdue * 0.25;

if (int_days_overdue >= 90) {
  cout << book_lost << bill_replacement << fine_notice << "90.\n";
}
else if (int_days_overdue >= 60 && int_days_overdue < 90) {
  cout << book_overdue << third_notice << fine_notice << fine_owed << ".\n";
}
else if (int_days_overdue >= 30 && int_days_overdue < 60) {
  cout << book_overdue  << second_notice << fine_notice << fine_owed << ".\n";
}
else if (int_days_overdue >= 1 && int_days_overdue < 30) {
  cout << book_overdue << first_notice << fine_notice << fine_owed << ".\n";
}
else
  cout << return_on_time << no_fine;
}
