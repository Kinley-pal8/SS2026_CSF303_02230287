#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k, q;
    cin >> n >> k >> q;
    
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    
    while (q--) {
        int type;
        cin >> type;
        
        if (type == 1) {
            // Update query
            int pos, val;
            cin >> pos >> val;
            arr[pos] = val;
        } else {
            // Query for maximum in window ending at index i
            int i;
            cin >> i;
            
            int start = max(1, i - k + 1);
            int maxVal = arr[start];
            
            for (int j = start; j <= i; j++) {
                maxVal = max(maxVal, arr[j]);
            }
            
            cout << maxVal << "\n";
        }
    }
    
    return 0;
}
