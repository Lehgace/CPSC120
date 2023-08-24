// Joshua Erickson (CPSC-03)

#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {

  if (argc <= 1) {
    cout << "Usage: ./average <numbers>" << endl;
    return 0;
  }

  float sum_value = 0.0;

  int index;
  float value;
  for (index = 1; index < argc; index++) {
    value = stof(argv[index]);
    sum_value = sum_value + value;
  }

  float average = sum_value / (argc - 1);
  cout << average << endl;
}
