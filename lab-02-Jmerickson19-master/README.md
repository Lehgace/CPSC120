# CPSC 120 - Lab 2
Now that you have your github accounts set up, understand how to git clone the starter code repository, understand the "Hello World" program, how to change it and upload your change, it is time to start coding more interesting programs that can handle and process user input.

## Background
Hard-coded values are useful in some cases, but more often than not we would want a program to execute a task or behave a certain way based on what the user asks for. In this lab, we will be exploring the basics of asking the user for input, assigning those input values to variables, and processing those variables to produce a desired output.

## Objective
* Understand how to use std::cout to print useful information to the console
* Understand the difference between hard-coded values and variables
* How to declare and assign variables of the int (integer) data type
* Introduction to basic operators operators for int, specifically addition, subtraction, and multiplication
* Understand how to use std::cin to request user input to affect a program's output

## Instructions
In this lab, you will be creating a program that prompts the user for 2 integers, and prints their sum (addition), difference (subtraction), and product (multiplication).

You will be given the following starter code. Each line that has a TODO ("to do")

```
// TODO: Put your name and lab section.
// TODO: Create a comment that describes what this program does.
#include <iostream>
using namespace std;

int main()
{
    // TODO: Declare 2 integers.

    // TODO: Prompt the user for the first integer.

    // TODO: Prompt the user for the second integer.

    // TODO: Print the sum of the two numbers with a message.

    // TODO: Print the difference of the two numbers with a message. Assume the
    // second number is subtracted from the first.

    // TODO: Print the product of the two numbers with a message.
}
```

### Tips
#### Declaring Variables
Variables are useful for referencing data that might get used in multiple places, and can be assigned or altered as needed. But before they can be used, they first need to be declared so the compiler knows what your code is talking about.
```
int month;      // Declares a variable called month, but doesn't initialize it. The value is meaingless until assigned.
int day = 4;    // Declares a variable called day and initializes it to 24, so it's ready for use immediately.
month = 9;      // Assigns 9 to month, so now month's value can safely be used!
```
##### Tricky stuff to watch out for
```
dollars = 5;
```
If this is the first mention of `dollars`, this will fail with a compile error, since the compiler doesn't know what `dollars` is. To fix it, use
```
int dollars = 5;
```
Then later in your code, you are free to use `dollars` as you please.


```
int int = 4;
```
This also throws a compile error! `int` is a reserved word to declare an integer, so the second `int` will fail. Instead, call it something else that's not already taken. Most IDEs like Atom will change color for reserved words. Instead, use something like
```
int my_number = 4;
```

#### cout
The general format for cout will generally look something like "cout << stuff;" where "stuff" is what you actually want to print. For example,
```
cout << 4;

> 4

cout << "Hello, world!";

> Hello, world!
```
Remember the semicolon `;` at the end! If you'd like to print multiple things at once in order, separate them using `<<` in between. For example,
```
cout << "Hi " << "my name" << " " << "is" << " Jeff!" << endl;

> Hi my name is Jeff
```

cout supports printing thigns of any type, regardless if it's a string or a number! For example,
```
cout << "The sum of 3 and 4 is " << 7;
> The sum of 3 and 4 is 7
```

#### cin
The general format for cin will usually look something like "cin >> stuff;" where "stuff" needs to be declared beforehand. Calling cin on it would then assign whatever the user types something when prompted and presses enter when they're done. For example,
```
int salary_you_want_for_your_job_offer;    // Must declare the variable first so when you cin later it knows what you are talking about.
cin >> salary_you_want_for_your_job_offer; // This line won't work if the line above isn't there at some point before.
```
Note the use of `>>` for `cin` vs `<<` for `cout`!

##### Wait a minute, what if I want to cin a word or sentence with spaces?
You won't need to worry about that for this lab, but for those of you who are curious
```
string words;
cin >> words;

> Hello, world!

cout << words;
> Hello
```
What happened? `cin` stops at what we call whitespace, which is either a space, tab, or new line. If you would like to use `cin` for sentences, there is a `getline` method that will get covered in a future topic so hang tight!

#### Arithmetic operators
C++ supports a variety of basic operators for manipulating numbers. For this lab, we are concerned with
* Addition: use `+`
* Subtraction: use `-`
* Multiplication: use `*`

For example,
```
int x = 3 + 4; // Create an integer, call it x, and assign it the value 3 added to 4 (which should be 7).
int y = 5 - 2; // Create an integer, call it y, and assign it the value 5 subtract 2 (which should be 3).
int z = 2 * 6; // Create an integer, call it z, and assign it the value 6 times 2 (which should be 12).
```

## Testing Your Code
Computers only ever do exaxtly what they are told, exactly the way they are told it, and never anything else. Thus, code is easier to get wrong than it is to get right, even if it's not obvious from reading it! How can you trust that it indeed does what it appears to be doing? Test, test, test!

### Test strategy
Start simple, and work your way up. Good tests are specific, cover a broad range of fundamentally different possibilities, can identify issues quickly, easily, and directly, without need for much set up, and can almost be diagnosed by inspection if the code fails to execute the test correctly.

### Cases to try
0s can often lead to interesting behavior, such as always causing a product with it also to be 0
1. (0, 0): Expected sum: 0 difference: 0 product: 0
2. (0, 1): Expected sum: 1 difference: -1 product: 0
3. (1, 0): Expected sum: 1 difference: 1 product: 0
4. (1, 1): Expected sum: 2 difference: 0 product: 1

Numbers can be negative!
1. (-1, -1): Expected sum: -2 difference: 0 product: 1
2. (-1, 1): Expected sum: 0 difference: -2 product: -1
2. (1, -1) Expected sum: 0 difference 2 product: -1

Finally, normal people numbers
1. (1, 2): Expected sum: 3 difference -1 product: 2
2. (2, 1): Expected sum: 3 difference: 1 product: 2
3. (15, 6): Expected sum: 21 difference: 9 product: 90

The test cases above are by no means exhaustive with what you can do with an int (hint: there are limitations to how big or small a number can actually get in C++). Feel free to come up with your own as well! We will go into depth on more testing strategies, organizing test cases, coming up with meaningful tests as the semester progresses.

## Grading
1. (1 point): Your code has your name and lab section in a comment at the top
2. (1 point): Your code has a comment at the top after your name that has a breif yet informitive description of what the code does.
2. (1 point): Your program compiles
3. (1 point): Your program has meaningful prompt messages for the two numbers
4. (1 point): Your program prompts the user for two integers
5. (1 point): Your program correctly computes the sum of the two numbers for the test cases provided
6. (1 point): Your program correctly computes the difference of the two numbers, specifically the first number minus the second for the test cases provided
7. (1 point): Your program correctly computes the product of the two numbers for the test cases provided
8. (1 point): Your program has meaningful output messages for each of the computations
9. (1 point): Your program uses clear, informative variable names that describe what each variable represents concisely
