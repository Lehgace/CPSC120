// Joshua Erickson (CPSC-03)

#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int main(int argc, char* argv[]) {

if (argc != 2) {
  cout << "Usage: ./countdown <integer>" << endl;
  return 0;
}

string arg_seconds = argv[1];
int seconds = stoi(arg_seconds);

if (seconds <= 0) {
  cout << "No. This ain't it chief. Enter a different number." << endl;
  return 0;
}

while (seconds >= 0) {
  cout << seconds << "...\n";
  seconds = seconds - 1;
  this_thread::sleep_for(chrono::seconds(1));
}

cout << "LIFTOFF!\n";
}
