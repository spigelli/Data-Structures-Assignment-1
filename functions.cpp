#include "functions.h"
#include <iostream>
#include <fstream>

using namespace std;

/** 
 * Simple hello world function
 */
void hello_world() {
  std::cout << "Hello, world!" << std::endl;
}

/**
 * Splits a string by a delimiter and returns a vector of the tokens
 */
vector<string> split(string str, char delimiter) {
  int start_index = 0;
  int max_index = str.length();
  vector<string> tokens;
  string token_in_progress = "";
  while (start_index < max_index) {
    while (str[start_index] != delimiter && start_index < max_index) {
      token_in_progress += str[start_index];
      start_index++;
    }
    tokens.push_back(token_in_progress);
    token_in_progress = "";
    start_index++;
  }
  return tokens;
}

/**
 * Writes a string vector to the console in the form:
 * ["a", "b", "c"]
 */
void print_vector(vector<string> vec) {
  cout << "[";
  for (size_t i = 0; i < vec.size(); i++) {
    cout << "\"" << vec[i] << "\"";
    if (i < vec.size() - 1) {
      cout << ", ";
    }
  }
  cout << "]" << endl;
}

/**
 * Reads an input file to a matrix
 */
vector<vector<int>> read_file(std::string file_name) {
  // Open an input file stream
  ifstream file(file_name);
  // Initialize the matrix
  vector<vector<int>> matrix;
  // Read the file line by line
  string line;
  vector<int> row;
  vector<string> tokens;
  while (getline(file, line)) {
    tokens = split(line, ' ');
    cout << "Read line: " << endl;
    print_vector(tokens);
    for (string token : tokens) {
      row.push_back(stoi(token));
    }
    matrix.push_back(row);
    row.clear();
  }
  return matrix;
}

/**
 * Prints a matrix to the console in the form:
 * [
 *   [1, 2, 3],
 *   [4, 5, 6],
 * ]
 */
void print_matrix(vector<vector<int>> matrix) {
  cout << "[" << endl;
  for (size_t i = 0; i < matrix.size(); i++) {
    cout << "  [";
    for (size_t j = 0; j < matrix[i].size(); j++) {
      cout << matrix[i][j];
      if (j < matrix[i].size() - 1) {
        cout << ", ";
      }
    }
    cout << "]" << endl;
  }
  cout << "]" << endl;
}
