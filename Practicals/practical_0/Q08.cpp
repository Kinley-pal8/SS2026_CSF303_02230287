#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
using namespace std;

// Function to calculate sum of digits
int digitSum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

// Function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

// Function to count vowels in a string
int countVowels(string s) {
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        char c = tolower(s[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }
    return count;
}

// Function to reverse a string
string reverseString(string s) {
    string reversed = "";
    for (int i = s.length() - 1; i >= 0; i--) {
        reversed += s[i];
    }
    return reversed;
}

int main() {
    string name = "Kinley Palden";
    int studentNo = 2230287;
    
    // Call all functions and store results
    int digSum = digitSum(studentNo);
    bool prime = isPrime(studentNo);
    int vowels = countVowels(name);
    string reversed = reverseString(name);
    
    // Display results
    cout << "========================================" << endl;
    cout << "  Function Results for " << name << endl;
    cout << "  Student No: " << studentNo << endl;
    cout << "========================================" << endl;
    cout << left << setw(30) << "digitSum(" + to_string(studentNo) + ")" << ": " << digSum << endl;
    cout << left << setw(30) << "isPrime(" + to_string(studentNo) + ")" << ": " << (prime ? "Yes" : "No") << endl;
    cout << left << setw(30) << "countVowels(" + name + ")" << ": " << vowels << endl;
    cout << left << setw(30) << "reverseString(" + name + ")" << ": " << reversed << endl;
    cout << "========================================" << endl;
    
    return 0;
}
