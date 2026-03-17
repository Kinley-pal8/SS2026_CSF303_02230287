#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, k;
    cout << "Enter the number of integers (N): ";
    cin >> n;
    cout << "Enter K (number of largest elements): ";
    cin >> k;
    
    vector<int> arr(n);
    
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Max heap (priority queue)
    priority_queue<int> maxHeap;
    
    // Insert all elements into max heap
    for (int i = 0; i < n; i++) {
        maxHeap.push(arr[i]);
    }
    
    cout << "\nK=" << k << " largest elements: ";
    
    // Extract and print K largest elements
    for (int i = 0; i < k && !maxHeap.empty(); i++) {
        cout << maxHeap.top();
        maxHeap.pop();
        if (i < k - 1) cout << " ";
    }
    cout << "\n";
    
    return 0;
}
