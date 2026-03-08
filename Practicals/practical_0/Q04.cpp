#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    string name = "Kinley Palden";
    int studentNo = 2230287;
    int age = 21;
    int currentYear = 2026;
    
    // Calculate birth year
    int birthYear = currentYear - age;
    
    // Calculate year when they turn 100
    int yearAt100 = birthYear + 100;
    
    // Display summary
    cout << "----------------------------------------" << endl;
    cout << "Summary" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Name : " << name << endl;
    cout << "Student No : " << studentNo << endl;
    cout << "Age : " << age << endl;
    cout << "Year of Birth : " << birthYear << endl;
    cout << "Year at Age 100: " << yearAt100 << endl;
    cout << "----------------------------------------" << endl;
    
    return 0;
}
