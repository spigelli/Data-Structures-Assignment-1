# CS-303 Assignment 1

(25 points)

## Input file

[Link to input file](https://app.box.com/s/o1n0hrmq095v8kvqzdnuideary1e8j2j)

### Q1) (20 points)

Write a C++ program that can read data from an input file (link is provided
above) into a one-dimensional array (don’t use vector) and perform the following
functions:

1. A function to check if a certain integer exists in the array. If the number
   is present, return the index where the number is present.
2. A function that can modify the value of an integer when called with the index
   of the integer in the array and return the new value and old value back to
   the user.
3. A function that adds a new integer to the end of the array.
4. A function which takes an index of an array and replaces the value with
   either 0 or removes the integer altogether.

### Q2) (5 points)

A way to indicate an error, especially if there are several possible errors in
code, is through the use of exceptions. Exceptions are used to signal that an
error has occurred. You can insert code in your program that throws an exception
when a particular kind of error occurs. An exception handler allows the user to
catch or handle the exception. To avoid uncaught exceptions, you write a try
block that can throw an exception and follow it with a catch block that catches
the exception and handles it. Using the array code from question 1, perform the
following:

1. Add try and catch blocks to the user inputs for the following functions from
   question 1:
   - A function that can modify the value of an integer when called with the
     index of the integer in the array and return the new value and old value
     back to the user.
   - A function that adds a new integer to the end of the array.

### Submission Guidelines

1. You should have a header file and .cpp file. The header file should provide
   the function declaration and .cpp file should have implementation details.
2. All the functionality of the program should be implemented as functions and methods.
3. The code should be well commented.
4. Create a report (readme file) that contains instruction on how to run the
   code and screenshots of the outputs.
5. Upload your report and code files to GitHub.
6. Submit the GitHub link on Canvas by the due date.
