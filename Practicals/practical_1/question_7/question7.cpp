#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cout << "Enter the number of integers: ";
    cin >> n;
    
    // Max heap for smaller half (stores negative values for max heap behavior)
    priority_queue<int> maxHeap;
    
    // Min heap for larger half
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    cout << "Enter " << n << " integers:\n";
    
    cout << fixed << setprecision(1); // Format output to 1 decimal place
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        
        // Add to appropriate heap
        if (maxHeap.empty() || x <= maxHeap.top()) {
            maxHeap.push(x);
        } else {
            minHeap.push(x);
        }
        
        // Balance the heaps - maxHeap should have size equal to or 1 more than minHeap
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        
        // Calculate and print median
        double median;
        if ((maxHeap.size() + minHeap.size()) % 2 == 1) {
            // Odd number of elements
            median = maxHeap.top();
        } else {
            // Even number of elements
            median = (maxHeap.top() + minHeap.top()) / 2.0;
        }
        
        cout << median << "\n";
    }
    
    return 0;
}
