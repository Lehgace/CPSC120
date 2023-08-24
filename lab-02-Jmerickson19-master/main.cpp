// Joshua Erickson (CPSC 03)
// This program will add, subract, and multiply two integers.

#include <iostream>
using namespace std;

int main()
{
    // Declare 2 integers
    int first_number;
    int second_number;
    string prompt1 = "Please enter an integer.";
    string prompt2 = "Please enter another integer.";
    // Prompt the user for the first integer.
    cout << prompt1 << endl;
    cin >> first_number;
    // Prompt the user for the second integer.
    cout << prompt2 << endl;
    cin >> second_number;
    // Print the sum of the two numbers with a message.
    int answer1 = first_number + second_number;
    cout << "The sum of your two integers is " << answer1 << endl;
    // Print the difference of the two numbers with a message. Assume the
    // second number is subtracted from the first.
    int answer2 = first_number - second_number;
    cout << "The difference of your two integers is " << answer2 << endl;
    // Print the product of the two numbers with a message.
    int answer3 = first_number * second_number;
    cout <<  "The product of your two numbers is " << answer3 << endl;
}
