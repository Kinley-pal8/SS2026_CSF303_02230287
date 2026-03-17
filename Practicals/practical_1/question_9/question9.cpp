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
    int evenSumCount = 0;
    
    // Iterate through all possible subsets using bitmask
    for (int mask = 0; mask < totalSubsets; mask++) {
        int sum = 0;
        
        // Calculate sum for current subset
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {  // Check if i-th bit is set
                sum += arr[i];
            }
        }
        
        // Check if sum is even
        if (sum % 2 == 0) {
            evenSumCount++;
        }
    }
    
    cout << "\nNumber of subsets with even sum: " << evenSumCount << "\n";
    
    return 0;
}
