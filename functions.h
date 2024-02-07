#include <string>
using namespace std;

void read_file_to_array(std::string file_name, int arr[]);

void print_raw(int arr[]);

void print(int arr[]);

/**
 * Checks if a certain integer exists in the array if the number is present return the
 * index where the number is present.
 */
int find(int arr[], int number);

/**
 * Modifies the value of an integer when called with the index of the integer in
 * the array and return the new value and old value back to the user.
 */
int my_modify_at_pos(int arr[], int index, int new_value);

/**
 * Adds a new value to the end of the array
 */
void push_back(int arr[], int new_value);

/**
 * Intakes an index of an array and replaces the value with either 0 or removes
 * the integer altogether.
 */
void remove_or_make_zero(int arr[], int index);
