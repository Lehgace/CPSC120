// Joshua Erickson (CPSC-03)

#include <iostream>
using namespace std;

const int ARRAY_SIZE = 10;

bool found_smaller_number;
int cur_small_index;

void SelectionSort (int numbers_list[], int number_of_values) {
  for (int i = 0; i < number_of_values - 1; i++) {
    found_smaller_number = false;
    for (int j = i + 1; j < number_of_values; j++) {
      if (numbers_list[i] > numbers_list[j]) {
        if (found_smaller_number) {
          // Is this number smaller than prior number found?
          if (numbers_list[j] < numbers_list[cur_small_index]) {
            cur_small_index = j;
          }
        }
        else {
          found_smaller_number = true;
          cur_small_index = j;
        }
      }
    }
    if (found_smaller_number) {
      int temp = numbers_list[i];
      numbers_list[i] = numbers_list[cur_small_index];
      numbers_list[cur_small_index] = temp;
    }
  }
}

int main(int argc, char* argv[]) {

  int numbers_list[ARRAY_SIZE];

  if (argc == 1) {
    cout << "Usage: ./sort <up to 10 values to be sorted>\n";
    return 0;
  }
  int max_arg = argc;
  if (max_arg > 11) {
    max_arg = 11;
  }

  for (int i = 1; i < max_arg; i++) {
    string number_argument = argv[i];
    int num_to_sort = stoi(number_argument);
    numbers_list[i - 1] = num_to_sort;
  }
  int num_values = max_arg - 1;

  SelectionSort (numbers_list, num_values);

  for (int k = 0; k < num_values; k++) {
     cout << numbers_list[k] << " ";
  }
  cout << endl;

  return 0;
}
