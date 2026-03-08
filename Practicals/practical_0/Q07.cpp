#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    string name = "Kinley Palden";
    int studentNo = 2230287;
    
    // Declare and populate array
    int kinley_marks[5] = {85, 72, 90, 65, 78};
    
    // Calculate statistics
    int highest = kinley_marks[0];
    int lowest = kinley_marks[0];
    int sum = 0;
    
    for (int i = 0; i < 5; i++) {
        sum += kinley_marks[i];
        if (kinley_marks[i] > highest) {
            highest = kinley_marks[i];
        }
        if (kinley_marks[i] < lowest) {
            lowest = kinley_marks[i];
        }
    }
    
    double average = sum / 5.0;
    
    // Count marks above average
    int aboveAverage = 0;
    for (int i = 0; i < 5; i++) {
        if (kinley_marks[i] > average) {
            aboveAverage++;
        }
    }
    
    // Display header
    cout << "Student: " << name << " | No: " << studentNo << endl;
    cout << "------------------------------------------" << endl;
    cout << "Index  Mark  Bar" << endl;
    
    // Display marks with bars
    for (int i = 0; i < 5; i++) {
        cout << "[" << i << "]    " << kinley_marks[i] << "    ";
        int stars = kinley_marks[i] / 10;
        for (int j = 0; j < stars; j++) {
            cout << "*";
        }
        cout << endl;
    }
    
    // Display summary statistics
    cout << "------------------------------------------" << endl;
    cout << "Highest : " << highest << endl;
    cout << "Lowest  : " << lowest << endl;
    cout << fixed << setprecision(2);
    cout << "Average : " << average << endl;
    cout << "Above Average: " << aboveAverage << " mark(s)" << endl;
    
    return 0;
}
