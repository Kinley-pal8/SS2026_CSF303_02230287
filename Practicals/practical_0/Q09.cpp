#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;

int main() {
    vector<int> v2230287(6);
    
    // Prompt user to enter 6 values
    cout << "Enter 6 values: ";
    for (int i = 0; i < 6; i++) {
        cin >> v2230287[i];
    }
    
    // Display original vector
    cout << "Original  : ";
    for (int val : v2230287) {
        cout << val << "  ";
    }
    cout << endl;
    
    // Sort the vector
    sort(v2230287.begin(), v2230287.end());
    
    // Display sorted vector
    cout << "Sorted    : ";
    for (int val : v2230287) {
        cout << val << "  ";
    }
    cout << endl;
    
    // Find min and max
    int minVal = *min_element(v2230287.begin(), v2230287.end());
    int maxVal = *max_element(v2230287.begin(), v2230287.end());
    
    // Calculate sum
    int sum = accumulate(v2230287.begin(), v2230287.end(), 0);
    
    // Calculate average
    double average = sum / 6.0;
    
    // Display statistics
    cout << "Min       : " << minVal << endl;
    cout << "Max       : " << maxVal << endl;
    cout << "Sum       : " << sum << endl;
    cout << fixed << setprecision(2);
    cout << "Average   : " << average << endl;
    
    // Remove values below average
    auto it = remove_if(v2230287.begin(), v2230287.end(), 
                        [average](int val) { return val < average; });
    v2230287.erase(it, v2230287.end());
    
    // Display final vector
    cout << "After removing below average: " << endl;
    for (int val : v2230287) {
        cout << val << "  ";
    }
    cout << endl;
    
    return 0;
}
