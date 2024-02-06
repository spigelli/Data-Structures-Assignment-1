#include "functions.h"
#include <iostream>
using namespace std;

int main() {
    // Call the function that was declared in functions.h
    int arr[100];
    read_file_to_array("A1input.txt", arr);
    print_array(arr, 100);
    return 0;
}
