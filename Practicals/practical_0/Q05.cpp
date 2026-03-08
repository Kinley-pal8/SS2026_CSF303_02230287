#include <iostream>
#include <string>
using namespace std;

int main() {
    string name = "Kinley Palden";
    int studentNo = 2230287;
    int mark;
    
    // Get user input
    cout << "Enter mark: ";
    cin >> mark;
    
    // Input validation
    if (mark < 0 || mark > 100) {
        cout << "----------------------------------------" << endl;
        cout << "Error: Mark must be between 0 and 100!" << endl;
        cout << "----------------------------------------" << endl;
        return 0;
    }
    
    // Classify the mark
    string grade;
    string message;
    
    if (mark >= 75) {
        grade = "Distinction";
        message = "Excellent work, " + name + "! You have achieved a Distinction.";
    }
    else if (mark >= 60) {
        grade = "Merit";
        message = "Well done, " + name + "! You have achieved a Merit.";
    }
    else if (mark >= 40) {
        grade = "Pass";
        message = "Congratulations, " + name + "! You have passed.";
    }
    else {
        grade = "Fail";
        message = name + ", unfortunately you have not passed. Please try again.";
    }
    
    // Display result
    cout << "----------------------------------------" << endl;
    cout << "Student : " << name << " (" << studentNo << ")" << endl;
    cout << "Mark    : " << mark << endl;
    cout << "Grade   : " << grade << endl;
    cout << "Result  : " << message << endl;
    cout << "----------------------------------------" << endl;
    
    return 0;
}
