#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    vector<int> arr(n);
    
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int totalSubsets = 1 << n;  // 2^n
    
    cout << "\nAll possible subsets:\n";
    
    // Iterate through all possible subsets using bitmask
    for (int mask = 0; mask < totalSubsets; mask++) {
        cout << "{";
        bool first = true;
        
        // Check each bit position
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {  // Check if i-th bit is set
                if (!first) cout << ", ";
                cout << arr[i];
                first = false;
            }
        }
        
        cout << "}\n";
    }
    
    return 0;
}
