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
    
    // Sort the array
    sort(arr.begin(), arr.end());
    
    // Remove duplicates using unique()
    auto last = unique(arr.begin(), arr.end());
    arr.erase(last, arr.end());
    
    cout << "\nUnique elements: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << " ";
    }
    cout << "\n";
    
    return 0;
}
