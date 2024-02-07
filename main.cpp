#include "functions.h"
#include <iostream>
using namespace std;

void mainLoop(int arr[]) {
  int choice;
  do {
    cout << "1. Find" << endl;
    cout << "2. Modify" << endl;
    cout << "3. Push Back" << endl;
    cout << "4. Remove" << endl;
    cout << "5. Print" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
      int find_number;
      int find_result;
      int modify_index;
      int modify_value;
      int push_back_value;
      int remove_index;

      case 1:
        cout << "Enter the number you want to find: ";
        cin >> find_number;
        find_result = find(arr, find_number);
        if (find_result != -1) {
          cout << "The number " << find_number << " is at index " << find_result << endl;
        } else {
          cout << "The number " << find_number << " is not in the array" << endl;
        }
        break;
      case 2:
        cout << "Enter the index of the number you want to modify: ";
        cin >> modify_index;
        cout << "Enter the new value: ";
        cin >> modify_value;
        my_modify_at_pos(arr, modify_index, modify_value);
        break;
      case 3:
        int new_value;
        cout << "Enter the new value: ";
        cin >> push_back_value;
        push_back(arr, push_back_value);
        break;
      case 4:
        cout << "Enter the index of the number you want to remove: ";
        cin >> remove_index;
        remove_or_make_zero(arr, remove_index);
        break;
      case 5:
        print_array(arr);
        break;
      case 6:
        cout << "Goodbye!" << endl;
        break;
      default:
        cout << "Invalid choice" << endl;
    }
  } while (choice != 6);
}

int main() {
    // Call the function that was declared in functions.h
    int arr[100];
    cout << "Reading file to array..." << endl;
    read_file_to_array("A1input.txt", arr);
    cout << "Read array: " << endl;
    print_array(arr);
    mainLoop(arr);
    return 0;
}
