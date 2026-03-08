#include <iostream>
#include <string>
using namespace std;

int main() {
    string firstName = "Kinley";
    string fullName = "Kinley Palden";
    int studentNo = 2230287;
    
    // Part 1: Print first name N times (N = length of first name)
    int nameLength = firstName.length();
    cout << "Name repeated (" << nameLength << " times):" << endl;
    for (int i = 0; i < nameLength; i++) {
        cout << firstName << endl;
    }
    
    // Part 2: Print triangle of asterisks (height = length of full name)
    int fullNameLength = fullName.length();
    cout << "Triangle (height = " << fullNameLength << "):" << endl;
    for (int i = 1; i <= fullNameLength; i++) {
        for (int j = 0; j < i; j++) {
            cout << "*";
        }
        cout << endl;
    }
    
    // Part 3: Print multiplication table for last digit of student number
    int lastDigit = studentNo % 10;
    cout << "Times Table for " << lastDigit << " (last digit of " << studentNo << "):" << endl;
    for (int i = 1; i <= 10; i++) {
        cout << lastDigit << " x " << i << " = " << (lastDigit * i) << endl;
    }
    
    return 0;
}
