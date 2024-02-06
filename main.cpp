#include "functions.h"
#include <iostream>
using namespace std;

int main() {
    // Call the function that was declared in functions.h
    hello_world();
    vector<vector<int>> matrix = read_file("A1input.txt");
    cout << "Matrix:" << endl;
    print_matrix(matrix);
    return 0;
}
