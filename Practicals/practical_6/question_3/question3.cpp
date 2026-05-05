#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class ManachersAlgorithm {
public:
    string transformString(const string& s) {
        string result = "|";
        for (char c : s) {
            result += c;
            result += "|";
        }
        return result;
    }
    
    bool isPalindrome(const string& s) {
        int n = s.length();
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - 1 - i]) return false;
        }
        return true;
    }
    
    string findLongestPalindrome(const string& text) {
        if (text.empty()) return "";
        
        // Transform the string
        string transformed = transformString(text);
        int n = transformed.length();
        
        // P[i] = radius of palindrome centered at i
        vector<int> P(n, 0);
        int center = 0;
        int right = 0;
        
        for (int i = 1; i < n - 1; i++) {
            int mirror = 2 * center - i;
            
            // Use previously computed results
            if (i < right) {
                P[i] = min(right - i, P[mirror]);
            }
            
            // Expand palindrome around i
            while (i + P[i] + 1 < n && i - P[i] - 1 >= 0 && 
                   transformed[i + P[i] + 1] == transformed[i - P[i] - 1]) {
                P[i]++;
            }
            
            // Update center and right boundary
            if (i + P[i] > right) {
                center = i;
                right = i + P[i];
            }
        }
        
        // Find longest palindrome
        int maxLen = 0;
        int centerIndex = 0;
        for (int i = 0; i < n; i++) {
            if (P[i] > maxLen) {
                maxLen = P[i];
                centerIndex = i;
            }
        }
        
        // Extract palindrome from original string
        int startIndex = (centerIndex - maxLen) / 2;
        return text.substr(startIndex, maxLen);
    }
};

int main() {
    cout << "=== MANACHER'S ALGORITHM ===" << endl;
    cout << "Find Longest Palindrome Substring in O(n) time\n" << endl;
    
    ManachersAlgorithm ma;
    
    vector<string> testCases = {
        "babad",
        "cbbd",
        "racecar",
        "abcdefg",
        "bananas",
        "forgeeksskeegfor",
        "a",
        "ac"
    };
    
    for (const string& test : testCases) {
        string result = ma.findLongestPalindrome(test);
        cout << "Input: \"" << test << "\" -> Palindrome: \"" << result << "\"" << endl;
    }
    
    return 0;
}
