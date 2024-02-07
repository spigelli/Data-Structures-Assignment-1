#include "functions.h"
#include <iostream>
#include <fstream>

using namespace std;

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
 * Prints an array of ints in the form:
 * [1, 2, 3, 4, 5]
 */
void print_array(int arr[]) {
  // TODO: Print only non zero elements
  // TODO: Add a print raw command to print the raw array
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

/**
 * Checks if a certain integer exists in the array if the number is present return the
 * index where the number is present.
 */
int find(int arr[], int number) {
  // TODO: Handle the case where the number is not in the array
  // TODO: don't count 0s
  size_t arr_length = 100;
  for (int i = 0; i < arr_length; i++) {
    if (arr[i] == number) {
      return i;
    }
  }
}

/**
 * Modifies the value of an integer when called with the index of the integer in
 * the array and return the new value and old value back to the user.
 */
void my_modify_at_pos(int arr[], int index, int new_value) {
  // TODO: don't allow integers that are 0
  arr[index] = new_value;
}

/**
 * Adds a new value to the end of the array
 */
void push_back(int arr[], int new_value) {
  // TODO: Handle the case where the array is full
  // TODO: Fill 0s in the array first
  // TODO: Disallow 0s
  size_t arr_length = 100;
  arr[arr_length] = new_value;
}

/**
 * Intakes an index of an array and replaces the value with either 0 or removes
 * the integer altogether.
 */
void remove_or_make_zero(int arr[], int index) {
  arr[index] = 0;
}