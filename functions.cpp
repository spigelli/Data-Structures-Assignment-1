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
void print_array(int arr[], int arr_length) {
  cout << "[";
  for (int i = 0; i < arr_length; i++) {
    cout << arr[i];
    if (i < arr_length - 1) {
      cout << ", ";
    }
  }
  cout << "]" << endl;
}