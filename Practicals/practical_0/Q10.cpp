#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <numeric>
using namespace std;

class Student {
private:
    string name;
    int studentNumber;
    vector<float> marks;
    
public:
    // Parameterised constructor
    Student(string n, int sn) : name(n), studentNumber(sn) {}
    
    // Method to add a mark
    void addMark(float m) {
        marks.push_back(m);
    }
    
    // Method to get average
    float getAverage() {
        if (marks.empty()) return 0;
        float sum = accumulate(marks.begin(), marks.end(), 0.0);
        return sum / marks.size();
    }
    
    // Method to get highest mark
    float getHighest() {
        if (marks.empty()) return 0;
        return *max_element(marks.begin(), marks.end());
    }
    
    // Method to get lowest mark
    float getLowest() {
        if (marks.empty()) return 0;
        return *min_element(marks.begin(), marks.end());
    }
    
    // Method to classify based on average
    string classify() {
        float avg = getAverage();
        if (avg >= 85) return "Distinction";
        else if (avg >= 70) return "Merit";
        else if (avg >= 40) return "Pass";
        else return "Fail";
    }
    
    // Method to print report
    void printReport() {
        cout << "================================================" << endl;
        cout << "  ACADEMIC REPORT" << endl;
        cout << "================================================" << endl;
        cout << "Student Name  : " << name << endl;
        cout << "Student No    : " << studentNumber << endl;
        cout << "Marks Entered : " << marks.size() << endl;
        cout << "Marks         : ";
        for (float mark : marks) {
            cout << fixed << setprecision(0) << mark << "  ";
        }
        cout << endl;
        cout << "Average       : " << fixed << setprecision(2) << getAverage() << endl;
        cout << "Highest       : " << fixed << setprecision(0) << getHighest() << endl;
        cout << "Lowest        : " << fixed << setprecision(0) << getLowest() << endl;
        cout << "Classification: " << classify() << endl;
        cout << "================================================" << endl;
    }
};

int main() {
    // Create a Student object
    Student student("Kinley Palden", 2230287);
    
    // Add at least 5 marks
    student.addMark(88);
    student.addMark(76);
    student.addMark(91);
    student.addMark(65);
    student.addMark(83);
    
    // Print the report
    student.printReport();
    
    return 0;
}
