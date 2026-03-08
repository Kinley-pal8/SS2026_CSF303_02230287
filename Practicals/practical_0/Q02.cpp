#include <iostream>
#include <string>
using namespace std;

int main() {
    string name = "Kinley Palden";
    int studentNo = 2230287;
    
    // Calculate sum of digits
    int digitSum = 0;
    int temp = studentNo;
    while (temp > 0) {
        digitSum += temp % 10;
        temp /= 10;
    }
    
    // Check if odd or even
    string oddEven = (studentNo % 2 == 0) ? "Even" : "Odd";
    
    // Calculate remainder when divided by 7
    int remainder = studentNo % 7;
    
    // Multiply by 3
    int multipliedBy3 = studentNo * 3;
    
    cout << "Student Number : " << studentNo << endl;
    cout << "Digit Sum      : " << digitSum << endl;
    cout << "Odd / Even     : " << oddEven << endl;
    cout << "Remainder (% 7): " << remainder << endl;
    cout << "Multiplied by 3: " << multipliedBy3 << endl;
    
    return 0;
}
