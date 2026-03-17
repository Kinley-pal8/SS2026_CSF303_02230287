#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, target;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the target sum: ";
    cin >> target;
    
    vector<int> arr(n);
    
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int totalSubsets = 1 << n;  // 2^n
    int count = 0;
    
    // Iterate through all possible subsets using bitmask
    for (int mask = 0; mask < totalSubsets; mask++) {
        int sum = 0;
        
        // Calculate sum for current subset
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {  // Check if i-th bit is set
                sum += arr[i];
            }
        }
        
        // Check if sum equals target
        if (sum == target) {
            count++;
        }
    }
    
    cout << "\nNumber of subsets with sum equal to " << target << ": " << count << "\n";
    
    return 0;
}
