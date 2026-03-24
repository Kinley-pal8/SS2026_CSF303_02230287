#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        int maxAnd = 0;
        
        // Greedy approach: Check from MSB to LSB
        // Start with result = 0 and try to set each bit
        int result = 0;
        
        for (int bit = 29; bit >= 0; bit--) {
            int testResult = result | (1 << bit);
            
            // Check if this bit can be set for some K-length subarray
            bool canSet = false;
            
            for (int i = 0; i <= n - k; i++) {
                int andVal = arr[i];
                bool valid = true;
                
                for (int j = i + 1; j < i + k; j++) {
                    andVal &= arr[j];
                    // Early termination if required bits are missing
                    if ((andVal & testResult) != testResult) {
                        valid = false;
                        break;
                    }
                }
                
                if (valid && (andVal & testResult) == testResult) {
                    canSet = true;
                    break;
                }
            }
            
            if (canSet) {
                result = testResult;
            }
        }
        
        cout << result << "\n";
    }
    
    return 0;
}
