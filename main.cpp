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
    cout << "6. Print Raw" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cout << endl;
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
        try {
          cin >> modify_index;
        } catch (exception e) {
          cout << "Something was wrong with your input, try again." << endl;
          break;
        }
        cout << "Enter the new value: ";
        cin >> modify_value;
        int old = my_modify_at_pos(arr, modify_index, modify_value);
        cout << "Switched out " << old << " at index" << modify_index << " with a new value of" << modify_value << endl;
        break;
      case 3:
        cout << "Enter the new value: ";
        try {
          cin >> push_back_value;
        } catch (exception e) {
          cout << "Something was wrong with your input, try again." << endl;
          break;
        }
        push_back(arr, push_back_value);
        break;
      case 4:
        cout << "Enter the index of the number you want to remove: ";
        cin >> remove_index;
        remove_or_make_zero(arr, remove_index);
        break;
      case 5:
        print(arr);
        break;
      case 6:
        print_raw(arr);
        break;
      case 7:
        cout << "Goodbye!" << endl;
        break;
      
      default:
        cout << "Invalid choice" << endl;
    }
    cout << endl;
  } while (choice != 7);
}

int main() {
    // Call the function that was declared in functions.h
    int arr[100];
    cout << "Reading file to array..." << endl;
    read_file_to_array("A1input.txt", arr);
    cout << "Read array: " << endl;
    print(arr);
    cout << endl;
    mainLoop(arr);
    return 0;
}
