#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cout << "Enter the number of integers: ";
    cin >> n;
    
    vector<int> arr(n);
    
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Find maximum element
    int maxElement = *max_element(arr.begin(), arr.end());
    
    // Find minimum element
    int minElement = *min_element(arr.begin(), arr.end());
    
    // Calculate sum
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    
    cout << "\n--- Results ---\n";
    cout << "Maximum element: " << maxElement << "\n";
    cout << "Minimum element: " << minElement << "\n";
    cout << "Sum of elements: " << sum << "\n";
    
    return 0;
}
