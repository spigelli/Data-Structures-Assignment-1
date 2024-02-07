#include "functions.h"
#include <iostream>
#include <fstream>

using namespace std;

/**
 * An exception to throw when inserting to a full array
 */
class FullArrayException : public exception {
  virtual const char* what() const throw() {
    return "The array is full";
  }
};

/**
 * An exception to throw when user tries to set a value to 0
 */
class ZeroValueException : public exception {
  virtual const char* what() const throw() {
    return "The value cannot be 0, 0 is reserved for empty elements in the array";
  }
};

/**
 * An exception to throw when a value is not found in the array
 */
class ValueNotFoundException : public exception {
  virtual const char* what() const throw() {
    return "The value was not found in the array";
  }
};

void read_file_to_array(std::string file_name, int arr[]) {
  // Open an input file stream
  ifstream file(file_name);
  // Read the file line by line
  string line;
  string token_in_progress = "";
  size_t line_current_index = 0;
  int arr_length = 0;
  while(getline(file, line)) {
    // Iterate over the characters in the line
    while (line_current_index < line.length()) {
      while (line_current_index < line.length() && line[line_current_index] != ' ') {
        token_in_progress += line[line_current_index];
        line_current_index++;
      }
      arr[arr_length] = stoi(token_in_progress);
      arr_length++;
      token_in_progress = "";
      line_current_index++;
    }
    line_current_index = 0;
  }
}

/**
 * Prints the array of ints in the form:
 * [1, 2, 3, 4, 5]
 * Includes 0s
 */
void print_raw(int arr[]) {
  size_t arr_length = 100;
  cout << "[";
  for (int i = 0; i < arr_length; i++) {
    cout << arr[i];
    if (i < arr_length - 1) {
      cout << ", ";
    }
  }
  cout << "]" << endl;
}

void print(int arr[]) {
  size_t arr_length = 100;
  size_t non_zero_count = 0;
  cout << "[";
  for (size_t i = 0; i < arr_length; i++) {
    if (arr[i] != 0) {
      cout << arr[i];
      non_zero_count++;
      if (i < arr_length - 1) {
        cout << ", ";
      }
    }
  }
  cout << "] (" << non_zero_count << "/100) items" << endl;
}

/**
 * Checks if a certain integer exists in the array if the number is present return the
 * index where the number is present.
 */
int find(int arr[], int number) {
  if (number == 0) {
    throw ZeroValueException();
  }
  size_t arr_length = 100;
  for (size_t i = 0; i < arr_length; i++) {
    if (arr[i] == number) {
      return i;
    }
  }
  // If we got here, the number is not in the array
  throw ValueNotFoundException();
}

/**
 * Modifies the value of an integer when called with the index of the integer in
 * the array and return the new value and old value back to the user.
 */
void my_modify_at_pos(int arr[], int index, int new_value) {
  if (new_value == 0) {
    throw ZeroValueException();
  }
  arr[index] = new_value;
}

/**
 * Adds a new value to the end of the array
 */
void push_back(int arr[], int new_value) {
  if (new_value == 0) {
    throw ZeroValueException();
  }
  size_t arr_length = 100;
  for (int i=0; i < arr_length; i++) {
    if (arr[i] == 0) {
      arr[i] = new_value;
      return;
    }
  }
  // If we got here, the array is full because we didn't return
  throw FullArrayException();
}

/**
 * Intakes an index of an array and replaces the value with either 0 or removes
 * the integer altogether.
 */
void remove_or_make_zero(int arr[], int index) {
  // Shift all elements to the left
  for (size_t i = index; i < 99; i++) {
    arr[i] = arr[i + 1];
  }
  // Set the last element to 0
  arr[99] = 0;
}