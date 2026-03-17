#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    int n, k;
    cout << "Enter the array size (N): ";
    cin >> n;
    cout << "Enter the window size (K): ";
    cin >> k;
    
    vector<int> arr(n);
    
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    deque<int> dq; // stores indices
    
    cout << "\nSliding window maximum: ";
    
    for (int i = 0; i < n; i++) {
        // Remove elements outside the window
        if (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }
        
        // Remove elements smaller than current element from back
        while (!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }
        
        // Add current element index to back
        dq.push_back(i);
        
        // Print the maximum of current window
        if (i >= k - 1) {
            cout << arr[dq.front()];
            if (i < n - 1) cout << " ";
        }
    }
    
    cout << "\n";
    
    return 0;
}
