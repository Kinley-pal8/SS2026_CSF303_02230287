#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string fullName = "Kinley Palden";
    
    // Total character count including spaces
    int totalLength = fullName.length();
    
    // Convert to uppercase
    string uppercase = fullName;
    for (int i = 0; i < uppercase.length(); i++) {
        uppercase[i] = toupper(uppercase[i]);
    }
    
    // Convert to lowercase
    string lowercase = fullName;
    for (int i = 0; i < lowercase.length(); i++) {
        lowercase[i] = tolower(lowercase[i]);
    }
    
    // Extract initials
    string initials = "";
    initials += toupper(fullName[0]);
    initials += ".";
    for (int i = 1; i < fullName.length(); i++) {
        if (fullName[i-1] == ' ') {
            initials += toupper(fullName[i]);
            initials += ".";
        }
    }
    
    // Length of first name only
    int firstNameLen = 0;
    for (int i = 0; i < fullName.length(); i++) {
        if (fullName[i] == ' ') break;
        firstNameLen++;
    }
    
    cout << "Full Name       : " << fullName << endl;
    cout << "Total Length    : " << totalLength << endl;
    cout << "Uppercase       : " << uppercase << endl;
    cout << "Lowercase       : " << lowercase << endl;
    cout << "Initials        : " << initials << endl;
    cout << "First Name Len  : " << firstNameLen << endl;
    
    return 0;
}
